@echo off
REM 创建 build 目录
if not exist build (
    mkdir build
)

REM 进入 build 目录
cd build

REM 运行 CMake 生成构建文件（使用默认生成器）
cmake ..

REM 编译（使用 cmake --build 以兼容 MSVC / MinGW）
cmake --build . --config Release

REM 运行可执行文件
shadow-engine.exe

REM 返回上级目录
cd ..