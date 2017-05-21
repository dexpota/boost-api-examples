add_library(hello MODULE hello.cpp)
target_link_libraries(hello LINK_PUBLIC ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

set_target_properties(hello PROPERTIES PREFIX "")
set_target_properties(hello PROPERTIES OUTPUT_NAME "hello_ext")
set_target_properties(hello PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
