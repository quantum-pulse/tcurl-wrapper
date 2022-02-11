
#ifndef CURL_MGR
#define CURL_MGR

#include <string>
#include <memory>

class curl_mgr{

public:
    curl_mgr(const std::string & url);
    ~curl_mgr();

    std::string & operator()();
    std::string & rbuffer();
    int status();

private:

    void fetch();

    std::string url_;
    std::string rbuf_;
  
    struct cache; 
    std::unique_ptr<cache> cache_;
};

#endif
