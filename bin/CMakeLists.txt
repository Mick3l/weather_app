add_executable(main main.cpp)

target_link_libraries(main PRIVATE weather)

target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR})

add_executable(test test.cpp)
