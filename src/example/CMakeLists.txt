
add_executable(extractor main.cxx) 

target_link_libraries(extractor tc-wpr)

target_include_directories(extractor PUBLIC
  $<BUILD_INTERFACE:${CMAKE_INCLUDE_PATH}>
  $<INSTALL_INTERFACE:include>
)
