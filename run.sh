#!/bin/bash
set -e

# 创建 build 目录
mkdir -p build
cd build

# 运行 CMake 生成构建文件
cmake ..

# 编译
make -j$(nproc)

# 运行可执行文件
./shadow-engine