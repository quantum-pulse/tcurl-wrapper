
message("CMAKE_INCLUDE_PATH=${CMAKE_INCLUDE_PATH}")

add_library(tc-wpr SHARED 
  curl_mgr.cxx
)

target_link_libraries(tc-wpr curl)


target_include_directories(tc-wpr PUBLIC
  $<BUILD_INTERFACE:${CMAKE_INCLUDE_PATH}>
  $<INSTALL_INTERFACE:include>
)

add_subdirectory(test)
