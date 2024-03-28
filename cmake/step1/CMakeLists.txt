# 1
# cmake_minimum_required(VERSION 3.15)

# project(Tutorial) # 设置工程名

# add_executable(Tutorial tutorial.cpp) # 添加可执行文件


# 2 优化 cmakelists.txt

cmake_minimum_required(VERSION 3.15)

project(Tutorial) # 设置工程名

set(SRC_LIST tutorial.cpp)  # 将要编译的源文件放在一个变量中

add_executable(${PROJECT_NAME} ${SRC_LIST}) # 避免重复使用tutorial




