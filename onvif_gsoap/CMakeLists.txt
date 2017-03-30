cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)
set(GSOAP_ROOT /usr/local)

add_definitions(-DWITH_OPENSSL -DWITH_GZIP -DWITH_IPV6 -DWITH_COOKIES -DWITH_DOM -DLINUX)

include_directories(onvif_gsoap/include)
include_directories(onvif_gsoap/3rdparty/gsoap-2.8/gsoap)
include_directories(onvif_gsoap/3rdparty/gsoap-2.8/gsoap/src)
include_directories(onvif_gsoap/3rdparty/gsoap-2.8/gsoap/wsdl)
include_directories(onvif_gsoap/3rdparty/gsoap-2.8/gsoap/import)
include_directories(onvif_gsoap/3rdparty/gsoap-2.8/gsoap/plugin)

file(GLOB SOURCE_FILES onvif_gsoap/source/*.cpp)

add_library(onvif_gsoap_static  STATIC ${SOURCE_FILES} "onvif_gsoap/include/soapH.h")
add_library(onvif_gsoap         SHARED ${SOURCE_FILES} "onvif_gsoap/include/soapH.h")
