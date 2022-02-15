
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

    CURL * curl_;
    CURLcode res_;
};
//end of cache implementation---------------------------------------------------------------

curl_mgr::curl_mgr(const std::string & url):url_(url),cache_(make_unique<cache>()) { 
    fetch();
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

void curl_mgr::fetch() {
    if(cache_->curl_) {
        curl_easy_setopt(cache_->curl_, CURLOPT_URL,url_.c_str());
        curl_easy_setopt(cache_->curl_, CURLOPT_WRITEFUNCTION, ::WriteCallback);
        curl_easy_setopt(cache_->curl_, CURLOPT_WRITEDATA, &rbuf_);
        cache_->res_ = curl_easy_perform(cache_->curl_);
    }
}
