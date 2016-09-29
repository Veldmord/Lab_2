cmake_minimum_required(VERSION 2.8) 

project(hello_world)

include_directories(include)

set(SOURCE examples/main.cpp)

set(SOURCE_LIB sources/print_hello_world.cpp)

add_library(test STATIC ${SOURCE_LIB})

add_executable(main ${SOURCE})

target_link_libraries(main test)		
									
