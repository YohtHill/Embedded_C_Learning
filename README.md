# Embedded Learning（嵌入式学习）

> 从零开始系统学习嵌入式开发，涵盖**软件**与**硬件**两大方向。

## 仓库结构

```
Embedded Learning/
├── Software/           # 软件学习
│   └── C/              # C 语言学习（从基础到进阶）
├── Hardware/           # 硬件学习
│   ├── PCB_Prj/        # PCB 工程（原理图/PCB/Gerber/BOM/SMT）
│   ├── ExperimentTest/ # 实验测试（纹波/电源测试等）
│   └── Note/           # 硬件设计笔记（PCB/FPC/ESD/指纹模组）
└── Review/             # 复习与规划
    ├── LearningStage/  # 三阶段学习规划
    ├── DailyReview/    # 每日学习总结
    └── WeeklyReport/   # 每周工作总结
```

## PCB 工程

| 项目 | 说明 | 状态 | 更新日期 |
|------|------|------|---------|
| BM43112DC02 | 指纹模组 | ✅ 项目完成 | 2026-08-17 |
| VB2032-241203 | 指纹模组 | ✅ 项目完成 | 2026-08-13 |
| BF83080C_V1.0 | 指纹模组 | ✅ 项目完成 | 2026-08-12 |
| BM22192DA06 | 指纹模组 | ✅ 项目完成 | 2026-08-07 |
| BM3218+BF83112 | 指纹模组 | ✅ 项目完成 | 2026-08-03 |

> 每个工程包含：原理图（SCH）、PCB 设计（PCB）、制造文件（Gerber）、BOM 及 SMT 贴片文件。

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
- 多文件工程、头文件、static 封装 ✅（D11）
- 函数指针、内存管理（2A-5）⬜
- STM32 寄存器点灯、GPIO、中断、定时器、串口（2B/2C）⬜
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
| C 进阶（D8~D11：结构体/共用体/枚举/宏/多文件工程）| ✅ 已完成 4 课（2A-1~2A-4）|
| PCB 工程 | ✅ 5 个项目全部完成（BM43112DC02 最新）|
| 硬件笔记（PCB/FPC）| ✅ 实习积累 |
| 实验测试 | 📊 持续更新 |

## 开发环境

- 系统：Windows
- 编译器：MSYS2 + MinGW-w64 (gcc)
- 编辑器：VS Code
- 版本控制：Git + GitHub
