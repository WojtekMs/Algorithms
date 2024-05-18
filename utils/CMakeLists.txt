add_library(algo_utils STATIC assertions.hpp)

cmake_path(GET CMAKE_CURRENT_SOURCE_DIR PARENT_PATH PROJECT_PATH)
set_target_properties(algo_utils PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(algo_utils PUBLIC ${PROJECT_PATH})