cmake_minimum_required(VERSION 3.6)
project(sort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES sources/insertion_sort.cpp)
add_executable(sort ${SOURCE_FILES})

if(BUILD_TESTS)
    enable_testing()
    file(GLOB ${PROJECT_NAME}_TEST_SOURCES sources/*.cpp)
    add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
    target_link_libraries(check ${PROJECT_NAME} ${DEPENDS_LIBRARIES} Catch::Catch)
    add_test(NAME check COMMAND check "-s" "-r" "compact" "--use-colour" "yes")
    add_coverage(check)
endif()