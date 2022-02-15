
#include "curl_mgr.hxx"

#define BOOST_TEST_MODULE test_curl_mgr1
#include <boost/test/unit_test.hpp>
#include <tools>
#include <memory>
using namespace std;

/* usage of status method that returns the status of the query*/ 
BOOST_AUTO_TEST_CASE(test_curl_mgr_init)
{
    string url="https://llvm.org/docs/CommandGuide/llvm-cov.html"; 
    unique_ptr<curl_mgr> l_mgr=nullptr;
    try{
        l_mgr=make_unique<curl_mgr>(url);
    }
    catch(runtime_error & re){
        auto l_msg=re.what();
        BOOST_CHECK_EQUAL(l_msg,"couldn't create curl object");
    }

    if(l_mgr) BOOST_CHECK_EQUAL(l_mgr->status(),0);
}

BOOST_AUTO_TEST_CASE(test_curl_mgr_has_network)
{
    string url="https://llvm.org/docs/CommandGuide/llvm-cov.html";
    unique_ptr<curl_mgr> l_mgr=nullptr;
    try{
        l_mgr=make_unique<curl_mgr>(url);
    }
    catch(runtime_error & re){
        auto l_msg=re.what();
    }

    if(!l_mgr->has_network()){
        BOOST_CHECK_EQUAL(l_mgr->has_network(),false);
    }
    else{
        BOOST_CHECK_EQUAL(l_mgr->has_network(),true);
    }
}
