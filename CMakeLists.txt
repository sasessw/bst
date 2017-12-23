cmake_minimum_required(VERSION 3.6)
project(sort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES sources/insertion_sort.cpp)
add_executable(sort ${SOURCE_FILES})

option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build tests" OFF)

include(cmake/HunterGate.cmake)

HunterGate(
        URL "https://github.com/SimonRussia/hunter/archive/v0.19.137.1.tar.gz"
        SHA1 "ef53eaa092c18d1ae26299daa4ea84d0f1d979ef"
)

project(sort)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
find_package(codecov)

hunter_add_package(Catch)
find_package(Catch CONFIG REQUIRED)

if(BUILD_TESTS)
    enable_testing()
    file(GLOB ${PROJECT_NAME}_TEST_SOURCES sources/insertion_sort.cpp)
    add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
    target_link_libraries(check ${PROJECT_NAME} ${DEPENDS_LIBRARIES} Catch::Catch)
    add_test(NAME check COMMAND check "-s" "-r" "compact" "--use-colour" "yes")
    add_coverage(check)
endif()