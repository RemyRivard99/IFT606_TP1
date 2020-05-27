cmake_minimum_required(VERSION 3.12)
project(IFT606_TP1
    VERSION 1.0
    LANGUAGES C CXX
    DESCRIPTION "dev1")

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)

if (UNIX)
find_package(ZLIB REQUIRED) 
find_package(Boost 1.71.0 REQUIRED COMPONENTS iostreams filesystem)
else ()
find_package(Boost 1.71.0 REQUIRED COMPONENTS iostreams filesystem zlib)
endif ()
		
set(CXX_STANDARD 17)

add_subdirectory(crypto)
add_subdirectory(tests)

add_executable(cryptoMain cryptoMain.cpp)

target_link_libraries(cryptoMain
    PRIVATE
        crypto
)