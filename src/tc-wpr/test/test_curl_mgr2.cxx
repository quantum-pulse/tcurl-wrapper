
#include "curl_mgr.hxx"

#define BOOST_TEST_MODULE test_curl_mgr2
#include <boost/test/unit_test.hpp>
#include <tools>
using namespace std;

/* usage of rbuffer method */
BOOST_AUTO_TEST_CASE(test_curl_mgr_extract1)
{
    string url="https://llvm.org/docs/CommandGuide/llvm-cov.html"; 
    curl_mgr l_mgr(url);
    try{
        l_mgr.extract();
    }
    catch(runtime_error & re){
        auto l_msg=re.what();
        BOOST_CHECK_EQUAL(l_msg,"network is down");
    }

    if(l_mgr.has_network()){
        auto l_status=l_mgr.status();
        BOOST_CHECK_EQUAL(l_status,0);
        auto size_buffer=l_mgr.rbuffer().size();
        BOOST_CHECK_EQUAL(size_buffer,45598);
    }
}
