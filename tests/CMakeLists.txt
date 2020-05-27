add_executable(cryptoTests 
    unittests.cpp
	catch.hpp
)

target_link_libraries(cryptoTests
    PRIVATE
    crypto
)

target_include_directories(cryptoTests
    PRIVATE
    crypto
)



