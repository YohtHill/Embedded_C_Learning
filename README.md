# Embedded Learning（嵌入式学习）

> 从零开始系统学习嵌入式开发，涵盖**软件**与**硬件**两大方向。

## 仓库结构

```
Embedded Learning/
├── Software/           # 软件学习
│   └── C/              # C 语言学习（从基础到进阶）
├── Hardware/           # 硬件学习
│   ├── PCB_Prj/        # PCB 工程项目（3 块板卡）
│   ├── ExperimentTest/ # 实验测试（纹波/电源测试等）
│   └── Note/           # 硬件设计笔记（PCB/FPC/ESD/指纹模组）
└── Review/             # 复习与规划
    ├── LearningStage/  # 三阶段学习规划
    └── DailyReview/    # 每日学习总结
```

## 学习路线

### 第一阶段：C 语言基础 ✅
- Hello World、变量、类型、sizeof
- 运算符、类型转换、溢出与补码
- 流程控制、九九乘法表、求和
- 函数、指针、swap 陷阱
- 数组、冒泡排序、字符串
- → 详见 [Software/C/README.md](Software/C/README.md)

### 第二阶段：C 进阶 + STM32 基础 🔄
- 结构体、共用体、枚举 ✅（D8、D9）
- 预处理与宏、条件编译、调试宏 ✅（D10）
- 多文件工程、头文件、static/extern
- STM32 寄存器点灯、GPIO、中断、定时器、串口
- → 详见 [Review/LearningStage/Stage2_规划.md](Review/LearningStage/Stage2_规划.md)

### 第三阶段：嵌入式深入与项目 ⬜
- 标准库/HAL 库、ADC/DMA/PWM
- FreeRTOS 实时系统
- 综合实战项目
- → 详见 [Review/LearningStage/Stage3_规划.md](Review/LearningStage/Stage3_规划.md)

## 当前进度

| 模块 | 状态 |
|------|------|
| C 语言基础（D1~D7）| ✅ 完成 |
| C 进阶（D8~D10：结构体/共用体/枚举/宏）| 🔄 已学 3 课 |
| 硬件笔记（PCB/FPC）| ✅ 实习积累 |
| 实验测试 | 📊 持续更新 |

## 开发环境

- 系统：Windows
- 编译器：MSYS2 + MinGW-w64 (gcc)
- 编辑器：VS Code
- 版本控制：Git + GitHub
