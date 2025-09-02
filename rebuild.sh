#!/bin/bash
set -e

# 删除 build 目录
rm -rf build

# 重新创建并进入 build
mkdir build
cd build

# 运行 CMake
cmake ..

# 编译
make -j$(nproc)

# 运行
./shadow-engine