cmake_minimum_required(VERSION 3.0)
project(webserver)
add_definitions("-Wall -std=c++14")
file(GLOB SOURCE "./*.cpp")
add_executable(webserver ${SOURCE})
# add_subdirectory(src/pool)
add_subdirectory(src/server)
# add_subdirectory(src/config)

target_link_libraries(${PROJECT_NAME}
    server)
