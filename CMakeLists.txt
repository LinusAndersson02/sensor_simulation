cmake_minimum_required(VERSION 3.16)
project(sim_sensor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Werror)

# ---- executable ----
file(GLOB SRC src/*.cpp)
add_executable(simulator ${SRC})
target_include_directories(simulator PUBLIC include)
target_link_libraries(simulator PRIVATE nlohmann_json::nlohmann_json)

# ---- unit tests ----
enable_testing()
find_package(Catch2 REQUIRED)
add_executable(tests tests/test_dummy.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
add_test(NAME all_tests COMMAND tests)

# ---- docs (optional) ----
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(DOXYGEN_GENERATE_HTML YES)
    doxygen_add_docs(docs_doxygen include COMMENT "Generate API docs")
endif()
