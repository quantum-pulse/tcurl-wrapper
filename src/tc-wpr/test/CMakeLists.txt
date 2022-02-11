
add_executable(test_curl_mgr1
   test_curl_mgr1.cxx 
)

target_link_libraries(test_curl_mgr1 tc-wpr boost_unit_test_framework)

target_include_directories(test_curl_mgr1 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_INCLUDE_PATH}>
  $<INSTALL_INTERFACE:include>
)

set_target_properties( test_curl_mgr1 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TEST_RUNTIME_OUTPUT_DIRECTORY})
add_test( test_curl_mgr1 ${TEST_RUNTIME_OUTPUT_DIRECTORY}/test_curl_mgr1)
#==============================================================================================================

add_executable(test_curl_mgr2
   test_curl_mgr2.cxx 
)

target_link_libraries(test_curl_mgr2 tc-wpr boost_unit_test_framework)

target_include_directories(test_curl_mgr2 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_INCLUDE_PATH}>
  $<INSTALL_INTERFACE:include>
)

set_target_properties( test_curl_mgr2 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TEST_RUNTIME_OUTPUT_DIRECTORY})
add_test( test_curl_mgr2 ${TEST_RUNTIME_OUTPUT_DIRECTORY}/test_curl_mgr2)
#==============================================================================================================

add_executable(test_curl_mgr3
   test_curl_mgr3.cxx 
)

target_link_libraries(test_curl_mgr3 tc-wpr boost_unit_test_framework)

target_include_directories(test_curl_mgr3 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_INCLUDE_PATH}>
  $<INSTALL_INTERFACE:include>
)

set_target_properties( test_curl_mgr3 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TEST_RUNTIME_OUTPUT_DIRECTORY})
add_test( test_curl_mgr3 ${TEST_RUNTIME_OUTPUT_DIRECTORY}/test_curl_mgr3)
#==============================================================================================================
