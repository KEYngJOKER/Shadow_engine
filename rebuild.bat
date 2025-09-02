@echo off
REM 删除 build 目录
if exist build (
    rmdir /s /q build
)

REM 重新创建 build 目录
mkdir build
cd build

REM 运行 CMake
cmake ..

REM 编译
cmake --build . --config Release

REM 运行
shiny-spoon.exe

REM 返回上级目录
cd ..