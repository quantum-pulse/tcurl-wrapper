
#include <netdb.h>

#include "curl_mgr.hxx"
#include <curl/curl.h>

using namespace std;

namespace{
    //usefull static function use by curl lib 
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }
}

//start of cache implementation-------------------------------------------------------------
struct curl_mgr::cache{

    cache():curl_(curl_easy_init()),res_(CURLE_FAILED_INIT) {}
    ~cache() {
        curl_easy_cleanup(curl_);
    } 

    void manage_result(CURLcode & _code){
        switch(_code){
            case CURLE_FAILED_INIT:{
                throw runtime_error("couldn't create curl object");
            }
            case CURLE_COULDNT_RESOLVE_HOST:{
                throw runtime_error("network is down");
            }
            case CURLE_URL_MALFORMAT:{
                throw runtime_error("url doesn't have a correct format");
            }
            case CURLE_OK:{break;}
        }
    }
    CURL * curl_;
    CURLcode res_;
};
//end of cache implementation---------------------------------------------------------------

curl_mgr::curl_mgr(const std::string & url):url_(url),cache_(make_unique<cache>()) { 
    init();
}

curl_mgr::~curl_mgr() {
}

string & curl_mgr::operator()() { 
    return rbuf_;
}

string & curl_mgr::rbuffer() { 
    return rbuf_;
}

int curl_mgr::status() {
    return cache_->res_;  
}

void curl_mgr::init() {
    if(cache_->curl_) {
        curl_easy_setopt(cache_->curl_, CURLOPT_URL,url_.c_str());
        cache_->res_ = CURLE_OK;
    }
    cache_->manage_result(cache_->res_);
}

bool curl_mgr::has_network() {
   //hack to check if the internet is accesible from host
   return (!gethostbyname("google.com"))?false:true;
}

void curl_mgr::extract() {
    if(cache_->curl_) {
        curl_easy_setopt(cache_->curl_, CURLOPT_WRITEFUNCTION, ::WriteCallback);
        curl_easy_setopt(cache_->curl_, CURLOPT_WRITEDATA, &rbuf_);
        cache_->res_ = curl_easy_perform(cache_->curl_);
    }
    cache_->manage_result(cache_->res_);
}
