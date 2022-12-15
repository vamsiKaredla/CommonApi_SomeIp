cmake_minimum_required(VERSION 2.8)
project(CommonAPi_someip)
message("=============="${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/build/usr)
add_subdirectory(vsomeip)
add_subdirectory(capicxx-core-runtime)
add_subdirectory(capicxx-someip-runtime)
add_subdirectory(serviceApplication)
add_subdirectory(clientApplication)


