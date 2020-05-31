cmake_minimum_required(VERSION 3.12)
project(TP1_Crypto
    VERSION 1.0
    LANGUAGES C CXX
    DESCRIPTION "asdnask")

set(Boost_USE_STATIC_LIBS on)
set(CXX_STANDARD 17)

add_subdirectory(crypto)
add_subdirectory(tests)

add_executable(crypto1 cryptoMain.cpp)

target_link_libraries(crypto1 PRIVATE crypto)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/crypto)