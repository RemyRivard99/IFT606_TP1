
set(Boost_USE_STATIC_LIBS ON)

if (UNIX)
find_package(ZLIB REQUIRED) 
find_package(Boost 1.71.0 REQUIRED COMPONENTS iostreams filesystem unit_test_framework)
else ()
find_package(Boost 1.71.0 REQUIRED COMPONENTS iostreams filesystem zlib unit_test_framework)
endif ()
		
#Exec
add_executable(cryptoTests 
    boosttests.cpp
)

#Crypto
target_link_libraries(cryptoTests
    PRIVATE
    crypto
)

target_include_directories(cryptoTests
    PRIVATE
    crypto
)

#Tests
if (UNIX)
target_link_libraries(cryptoTests 
    PUBLIC 
		${Boost_LIBRARIES}
		${ZLIB_LIBRARIES}
)
else ()
target_link_libraries(cryptoTests 
    PUBLIC 
		${Boost_LIBRARIES}
		${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
endif ()	
target_include_directories(cryptoTests 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
		${Boost_INCLUDE_DIRS}
)
