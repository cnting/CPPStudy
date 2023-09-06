#指定CMake最低编译版本
CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

#给工程取一个名字
PROJECT (HELLO)

#指定头文件在哪个目录
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

#链接lib目录下的libmath.so
#指定so在哪个目录下
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

#生成可执行文件
ADD_EXECUTABLE(hello hello.cpp)

#为hello添加编译链接库
TARGET_LINK_LIBRARIES(hello math)
