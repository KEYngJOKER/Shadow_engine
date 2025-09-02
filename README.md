# Shadow_engine

Shadow_engine 是一个使用 **C++** 编写的多线程游戏引擎 Demo，展示了 **无锁队列**、**异步日志系统** 和 **双缓冲数据交换** 的实现。  
适合学习高性能 C++ 多线程编程与游戏引擎基础架构。

## 特性
- **无锁队列**：基于环形缓冲区的单生产者单消费者队列，避免锁竞争
- **异步日志系统**：独立日志线程，非阻塞记录运行信息
- **双缓冲数据交换**：逻辑与渲染线程安全交换游戏状态数据
- **多线程架构**：模拟游戏逻辑与渲染的并行执行

![示例截图](image.png)

---

Windows
双击 build_run.bat 编译并运行
双击 rebuild.bat 清理 + 重编译并运行
需要提前安装 CMake 和 MSVC 或 MinGW-w64，并将其加入系统 PATH。

跨平台 Python 脚本（推荐）
如果已安装 Python 3，可以使用以下命令在 Windows / Linux 下统一运行：

# 编译并运行
```
python run.py
```
# 清理 + 重编译 + 运行
```
python clean.py
```
# Python 脚本会自动检测：
```
CMake 是否可用
编译器（Windows 下优先 MSVC，否则 MinGW；Linux 下使用 g++）
自动创建 build 目录并运行可执行文件
```
依赖
```
C++17 编译器（g++ / clang / MSVC）
CMake 3.10+
Python 3（可选，用于跨平台脚本）
```

目录结构
```
Shadow_engine/
│── CMakeLists.txt
│── src/
│   ├── main.cpp
│   ├── LockFreeQueue.h
│   ├── AsyncLogger.h
│   ├── DoubleBuffer.h
│── run.py
│── clean.py
│── README.md
```
