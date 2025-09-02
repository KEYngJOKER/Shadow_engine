# Shadow_engine
Shadow_engine 是一个使用 C++ 编写的多线程游戏引擎 Demo，展示了无锁队列、异步日志系统和双缓冲数据交换的实现。 
项目包含：  无锁队列：基于环形缓冲区的单生产者单消费者队列，避免锁竞争。 
异步日志系统：独立日志线程，非阻塞记录运行信息。 双缓冲数据交换：逻辑与渲染线程安全交换游戏状态数据。 
多线程架构：模拟游戏逻辑与渲染的并行执行。 适合学习高性能 C++ 多线程编程与游戏引擎基础架构。

![alt text](image.png)

# Shadow_engine

Shadow_engine 是一个 C++ 多线程游戏 Demo，加入无锁队列、异步日志系统和双缓冲数据交换的实现。

## 特性
- 无锁队列（单生产者单消费者）
- 异步日志系统
- 双缓冲数据交换
- 多线程架构模拟游戏逻辑与渲染

## 构建与运行
Linux
```bash
pwd
cd shadow_engine
./run.sh
或者（重编译）
./rebuild.sh
```

Windows:
双击run.bat或者rebuild.bat