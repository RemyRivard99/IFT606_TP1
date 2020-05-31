add_library(crypto
    crypto.h 
    crypto.cpp)

if (UNIX)
target_link_libraries(crypto 
    PUBLIC 
		${Boost_LIBRARIES}
		${ZLIB_LIBRARIES}
)
else ()
target_link_libraries(crypto 
    PUBLIC 
		${Boost_LIBRARIES}
)
endif ()	
target_include_directories(crypto 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
		${Boost_INCLUDE_DIRS}
)