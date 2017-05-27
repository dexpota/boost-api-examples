add_executable(program_options program_options.cpp)
add_executable(program_options_simple simple/main.cpp)

target_link_libraries(program_options ${Boost_LIBRARIES})
target_link_libraries(program_options_simple ${Boost_LIBRARIES})
