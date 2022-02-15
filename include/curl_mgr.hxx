
#ifndef CURL_MGR_HXX
#define CURL_MGR_HXX

#include <string>
#include <memory>

class curl_mgr{

public:
    curl_mgr(const std::string & url);
    ~curl_mgr();

    std::string & operator()();

    bool has_network();
    void extract();
    std::string & rbuffer();
    int status();

private:

    void init();
    std::string url_;
    std::string rbuf_;
  
    struct cache; 
    std::unique_ptr<cache> cache_;
};

#endif
