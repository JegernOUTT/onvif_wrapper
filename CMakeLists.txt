cmake_minimum_required(VERSION 3.0)
project(onvif_wrapper)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/modules/)

set(GSOAP_ROOT /usr/local)
find_package(GSOAP REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)
find_package(ZLIB REQUIRED)

include(onvif_gsoap/CMakeLists.txt)

include_directories(include)
include_directories(onvif_gsoap/include)

file(GLOB SOURCE_FILES  source/*.cpp)
file(GLOB INCLUDE_FILES "include/*.h" "include/*.hpp")

add_library(onvif_wrapper        SHARED ${SOURCE_FILES})
add_library(onvif_wrapper_static STATIC ${SOURCE_FILES})

set(SSL_STATIC_LIB /usr/local/lib/libssl.a)
set(SSLCRYPTO_STATIC_LIB /usr/local/lib/libcrypto.a)

add_executable(onvif_wrapper_test test/Test.cpp)
target_link_libraries(onvif_wrapper_test
                                        onvif_wrapper_static
                                        ${GSOAP_SSL_CXX_LIBRARIES}
                                        ${OPENSSL_LIBRARIES}
                                        ${CMAKE_THREAD_LIBS_INIT}
                                        ${CMAKE_DL_LIBS}
                                        ${ZLIB_LIBRARIES}
                                        onvif_gsoap_static)

add_test(NAME Test COMMAND onvif_wrapper_test)

install(FILES ${INCLUDE_FILES}       DESTINATION include/onvif_wrapper)
install(TARGETS onvif_wrapper        DESTINATION lib/)
install(TARGETS onvif_wrapper_static DESTINATION lib/)
install(TARGETS onvif_gsoap          DESTINATION lib/)
install(TARGETS onvif_gsoap_static   DESTINATION lib/)
