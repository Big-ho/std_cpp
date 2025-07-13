cmake_minimum_required(VERSION 3.10)

project(std_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# clang-tidy 설정 (빌드 시 자동 실행)
set(CMAKE_CXX_CLANG_TIDY
  clang-tidy
  -checks=modernize-*,readability-*,bugprone-*,-bugprone-easily-swappable-parameters
  -warnings-as-errors=*,
  -header-filter=.*,
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# src 폴더의 모든 cpp 파일을 재귀적으로 포함
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# src/main.cpp 파일만 빼고 SRC_FILES에 저장
list(FILTER SRC_FILES EXCLUDE REGEX "src/main.cpp")


# 메인 실행 파일
add_executable(std_cpp ${SRC_FILES} src/main.cpp)
target_include_directories(std_cpp PUBLIC include src)

# 테스트 실행 파일
add_executable(std_cpp_test ${SRC_FILES} test/main.cpp)
target_include_directories(std_cpp_test PRIVATE include src)