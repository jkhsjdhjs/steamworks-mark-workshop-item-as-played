cmake_minimum_required(VERSION 3.13)
project(steamworks_mark_workshop_item_as_played)

set(CMAKE_CXX_STANDARD 17)

include_directories(steam)

find_library(
    STEAM_API
    NAMES steam_api
    PATHS ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} ${STEAM_API})
