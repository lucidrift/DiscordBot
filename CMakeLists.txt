cmake_minimum_required(VERSION 3.2)
project(LucidRift_DiscordBot)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCE_FILES src/*.cxx)
file(GLOB_RECURSE ${PROJECT_NAME}_HEADER_FILES src/*.hxx)

add_executable(${PROJECT_NAME}_Service ${${PROJECT_NAME}_SOURCE_FILES} ${${PROJECT_NAME}_HEADER_FILES})
target_link_libraries(${PROJECT_NAME}_Service PRIVATE dpp)
