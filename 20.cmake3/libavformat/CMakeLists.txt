#指定CMake最低编译版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

#给工程取一个名字
PROJECT (FORMAT)

#生成可执行文件
ADD_EXECUTABLE(format format.cpp)
