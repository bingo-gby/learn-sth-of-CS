

# mkdir build
创建一个名为build的目录
# cd build
然后进入

# cmake -G"MinGW Makefiles" ..
运行cmake命令来生成Makefile或其他构建系统文件
这里的".."表示上级目录，即包含CMakeLists.txt文件的目录,且代表使用MinGW 编译器


# cmake --build .
如果CMake配置成功，接下来使用cmake命令来实际构建项目
这里使用"--build"选项来指定构建目录，.代表在本目录下生成exe文件

    如果是linux下，就可以直接用shell写