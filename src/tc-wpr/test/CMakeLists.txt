
add_executable(test_curl_mgr
   test_curl_mgr.cxx 
)

target_link_libraries(test_curl_mgr tc-wpr boost_unit_test_framework)

target_include_directories(test_curl_mgr PUBLIC
  $<BUILD_INTERFACE:${CMAKE_INCLUDE_PATH}>
  $<INSTALL_INTERFACE:include>
)

set_target_properties( test_curl_mgr PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TEST_RUNTIME_OUTPUT_DIRECTORY})
add_test( test_curl_mgr ${TEST_RUNTIME_OUTPUT_DIRECTORY}/test_curl_mgr)
#==============================================================================================================
