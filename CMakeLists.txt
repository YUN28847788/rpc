Cmake_minimum_required(VERSION 3.0)
project(mprpc)

#配置编译选项
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

#生成debug版本 进行gdb调试
set(CMAKE_BUILD_TYPE Debug)

#配置最终的可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#设置项目库文件输出路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


#配置头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${PROJECT_SOURCE_DIR}/example)
# include_directories(${PROJECT_SOURCE_DIR}/include/server/db)
# include_directories(${PROJECT_SOURCE_DIR}/thirdparty)
# 配置库文件搜索路径
link_directories(${PROJECT_SOURCE_DIR}/lib)


# src包含了mprpc框架所有的相关代码
add_subdirectory(src)
# example包含了mprpc框架使用的示例代码
add_subdirectory(example)
