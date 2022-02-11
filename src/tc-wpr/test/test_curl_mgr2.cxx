
#include "curl_mgr.hxx"

#define BOOST_TEST_MODULE test_auction
#include <boost/test/unit_test.hpp>
#include <tools>
using namespace std;

/* usage of status method that returns the status of the query*/ 
BOOST_AUTO_TEST_CASE(test_curl_mgr_status)
{
    string url="https://llvm.org/docs/CommandGuide/llvm-cov.html"; 
    curl_mgr l_mgr(url);
    auto l_status=l_mgr.status();
    BOOST_CHECK_EQUAL(l_status,0);
    auto size_buffer=l_mgr.rbuffer().size();
    BOOST_CHECK_EQUAL(size_buffer,45598);
}

/* usage of rbuffer method */
BOOST_AUTO_TEST_CASE(test_curl_mgr_rbuffer1)
{
    string url="https://llvm.org/docs/CommandGuide/llvm-cov.html"; 
    curl_mgr l_mgr(url);
    auto l_status=l_mgr.status();
    BOOST_CHECK_EQUAL(l_status,0);
    auto size_buffer=l_mgr.rbuffer().size();
    BOOST_CHECK_EQUAL(size_buffer,45598);
}

/* usage of functor */
BOOST_AUTO_TEST_CASE(test_curl_mgr_rbuffer2)
{
    string url="https://llvm.org/docs/CommandGuide/llvm-cov.html"; 
    curl_mgr l_mgr(url);
    auto l_status=l_mgr.status();
    BOOST_CHECK_EQUAL(l_status,0);
    auto size_buffer=l_mgr().size();
    BOOST_CHECK_EQUAL(size_buffer,45598);
} 
