cmake_minimum_required(VERSION 3.10)
project(std_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# clang-tidy 설정 (빌드 시 자동 실행)
set(CMAKE_CXX_CLANG_TIDY
  clang-tidy
  -checks=modernize-*,readability-*,bugprone-*,-bugprone-easily-swappable-parameters
  -warnings-as-errors=*,
  -header-filter=.*,
)

set(library_name ${PROJECT_NAME})


# src 폴더의 모든 cpp 파일을 재귀적으로 포함
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# src/main.cpp 파일만 빼고 SRC_FILES에 저장
list(FILTER SRC_FILES EXCLUDE REGEX "src/main.cpp")

find_package(OpenCV REQUIRED)

# 메인 실행 파일
add_executable(${PROJECT_NAME} ${SRC_FILES} src/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include src)
target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})

# 테스트 실행 파일
add_executable(${PROJECT_NAME}_test ${SRC_FILES} test/main.cpp)
target_include_directories(${PROJECT_NAME}_test PRIVATE include src)
target_link_libraries(${PROJECT_NAME}_test PRIVATE ${OpenCV_LIBS})
