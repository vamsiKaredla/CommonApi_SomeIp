cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")
set(COMMON_API_INC_DIR "${CMAKE_SOURCE_DIR}/capicxx-core-runtime/include")
set(COMMON_SOMEIP_INC_DIR "${CMAKE_SOURCE_DIR}/capicxx-someip-runtime/include")
set(VSOMEIP_INC_DIR "${CMAKE_SOURCE_DIR}/vsomeip/interface/")
set(STUB_DIR ${CMAKE_SOURCE_DIR}/build/src-gen)
include_directories(
    include
    ${STUB_DIR}
    ${COMMON_API_INC_DIR}
    ${COMMON_SOMEIP_INC_DIR}
    ${VSOMEIP_INC_DIR}
)
link_directories(
	${COMMON_API_INC_DIR}/../build
   	${COMMONAPI_SOMEIP_INC_DIR}/../build
    	${VSOMEIP_INC_DIR}/../build
)

add_executable(HelloWorldService
	src/HelloWorldService.cpp
	src/HelloWorldStubImpl.cpp
	${STUB_DIR}/v1/commonapi/HelloWorldSomeIPStubAdapter.cpp
	${STUB_DIR}/v1/commonapi/HelloWorldSomeIPDeployment.cpp
)
target_link_libraries(HelloWorldService CommonAPI CommonAPI-SomeIP vsomeip3)

install(TARGETS HelloWorldService DESTINATION bin)
