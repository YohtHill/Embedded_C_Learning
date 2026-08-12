# 实验测试（ExperimentTest）

> 记录实习/开发过程中的硬件实验测试，包括实验报告、测试数据与分类图片。

## 目录内容

| 文件夹 | 内容 | 说明 |
|--------|------|------|
| [RippleTesting/](RippleTesting/) | 直流电源纹波与噪声测量 | 测量 LRC 板、SP 板两块指纹模组的电源输出纹波/噪声 |
| [PowerSourceTesting/](PowerSourceTesting/) | 电源测试模组（BF85112B）| 测试 BF85112B 芯片在不同时间基准下的电源/指纹/待机状态 |

## 测试概览

### 1. 纹波与噪声测量（RippleTesting）
- **目的**：评估直流电源输出质量，验证是否满足设计要求
- **设备**：Tektronix 示波器 + TPP0500B 探头（500MHz）+ 接地弹簧
- **条件**：AC 耦合、20MHz 带宽限制、200µs/div
- **样品**：LRC 板、SP 板（指纹模组，替换不同 LDO）
- **报告**：[直流电源输出纹波与噪声测量实验结果报告.md](RippleTesting/RippleTesting_Report/直流电源输出纹波与噪声测量实验结果报告.md)

### 2. 电源测试模组（PowerSourceTesting）
- **对象**：BF85112B 芯片（样品 2、3）
- **时间基准**：50ms / 100ms / 150ms / 200ms / 250ms / 300ms
- **状态分类**：Capture（波形采集）、FD（指纹检测）、Idle（待机）
- **图片**：按样品 + 时间 + 状态三级分类存放

## 目录结构

```
ExperimentTest/
├── README.md                      本说明
├── RippleTesting/
│   ├── RippleTesting_Report/      纹波测量实验报告
│   └── Ripple_Testing_Img/        纹波测试波形图
└── PowerSourceTesting/
    ├── PowerSourceTesting_Report/ 电源测试报告（待补充）
    └── PowerSourceTesting_Img/    电源测试图片（按样品/时间分类）
        ├── BF85112B_2/
        │   ├── 50ms/ ~ 300ms/     各时间基准下的测试图
        └── BF85112B_3/
            ├── 50ms/ ~ 300ms/
```

---

*持续更新，记录每一次硬件实验测试。*
