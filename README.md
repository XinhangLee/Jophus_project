# Josephus Problem (约瑟夫环问题)

## 项目简介

这是一个用 **C 语言** 实现的约瑟夫环问题（Josephus Problem）解决方案。
该问题描述了一组人围坐成一圈，每个人都按顺序编号，按指定的间隔进行“杀戮”，直到最后剩下一个人。我们的任务是模拟这一过程并找出最后存活的人。

本项目通过使用 **循环链表** 来模拟约瑟夫环问题，主要实现了以下功能：
- 初始化一个循环链表
- 将 `n` 个人按顺序坐在圆圈中（ `n` 由 `NUM` 决定）
- 按照`间隔`逐个删除节点，直到只剩下一个节点
- 找出最后存活的人,输出`编号`。

## 项目结构

project/
├── CMakeLists.txt      # CMake 构建配置文件
├── Josephus.c          # 主程序，包含约瑟夫环问题的逻辑
├── LinkList/           # 链表相关实现
│   ├── LinkList.c      # 循环链表的实现
│   └── LinkList.h      # 循环链表的头文件
└── README.md           # 项目的说明文档

- `Josephus.c`: 主程序，负责模拟约瑟夫环问题的过程。
- `LinkList/LinkList.c`: 循环链表的实现文件，包含链表的增删操作等。
- `LinkList/LinkList.h`: 循环链表的头文件，声明链表结构和相关函数。

## 编译与运行

### 环境要求

- 操作系统：任何支持 C 语言的操作系统（Windows、macOS、Linux）。
- 编译器：支持 C99 或以上的标准（如 GCC 或 Clang）。

### 编译步骤

1. **安装 CMake**

   如果你尚未安装 CMake，可以参考 [CMake 官网](https://cmake.org/install/) 获取安装方法。

2. **克隆项目**

   使用 Git 克隆该项目到本地：

   ```bash
   git clone https://github.com/XinhangLee/Jophus_project.git

3. **进入项目目录并构建**

   打开终端或命令行工具，进入项目文件夹，然后运行以下命令来构建项目：

   cd project_linklist
   cmake .
   make

   make 命令会根据 CMake 配置生成并编译项目，生成可执行文件。

4. **运行项目**

   编译成功后，运行以下命令来执行程序：

   ./project_linklist

   程序会输出约瑟夫环问题的求解结果。例如：

    I hate Josephus game!
    1 2 3 4 5 6 7 8 9 10 11 12
    12 : 7

   这表示 12 个人参与游戏，最后剩下的是第 7 个人。

### 代码说明
#### Josephus.c 主程序逻辑：

    SitAroundCircle：将 n 个人按顺序加入到循环链表中。
    KillUntilOne：模拟约瑟夫环的“杀戮”过程，直到剩下一个人。
    GetSurvivor：返回最后剩下的人的编号。

#### LinkList/LinkList.c  循环链表的实现：

    Init：初始化链表。
    Append：将新节点添加到链表尾部。
    Delete：删除指定节点，模拟“杀戮”过程。
    Print：打印链表中所有人的编号。  
    IsEmpty：检查链表是否为空。
    IsSingleton：检查链表是否只有一个元素。

#### LinkList/LinkList.h 包含了循环链表的声明，包括节点结构体和所有链表操作函数的声明。

### 项目扩展
    你可以通过以下方式扩展该项目：

        支持不同的间隔（目前程序默认删除第一个人，间隔可以调整）。
        处理异常输入，如人数为 0 或负数。
        优化链表操作，提高代码效率。
