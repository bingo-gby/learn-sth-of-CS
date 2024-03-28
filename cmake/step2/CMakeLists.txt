
cmake_minimum_required(VERSION 3.15)
project(Tutorial)

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)   

add_subdirectory(functions) # 告诉cmake递归进functions目录，执行CMakeLists.txt文件，用于添加库文件

add_executable(${PROJECT_NAME} tutorial.cpp)

# 链接库文件  将库文件加入最后的可执行文件
target_link_libraries(${PROJECT_NAME} PUBLIC functions) 

# 添加头文件路径，确保能够搜索到头文件
target_include_directories(${PROJECT_NAME} PUBLIC
                           ${PROJECT_SOURCE_DIR}/functions
                           )


