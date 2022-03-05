project(config)

add_library(${PROJECT_NAME} config.cpp)

target_link_libraries(${PROJECT_NAME} jsoncpp)
