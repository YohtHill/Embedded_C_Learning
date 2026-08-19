# 电源测试模组（Power Source Testing）

> 对 **BF85112B** 电源芯片模组进行测试，观察不同时间基准下的电源状态。

[中文](README.md) | [English](README_EN.md)

## 测试对象

- **BF85112B** 芯片模组
- 样品编号：BF85112B_2、BF85112B_3

## 测试时间基准

在以下时间基准下分别测试：

```
50ms / 100ms / 150ms / 200ms / 250ms / 300ms
```

## 测试状态分类

每个时间基准下拍摄多张测试图，按状态区分：

| 状态 | 说明 |
|------|------|
| **Capture** | 波形采集 |
| **FD** | 指纹检测（FingerDetect）|
| **Idle** | 待机状态 |

## 图片目录结构

```
PowerSourceTesting_Img/
├── BF85112B_2/          # 样品 2
│   ├── 50ms/            # 50ms 基准
│   │   ├── 50ms_Capture.png
│   │   ├── 50ms_FD.png
│   │   └── 50ms_Idle.png
│   ├── 100ms/ ~ 300ms/  # 其他时间基准
└── BF85112B_3/          # 样品 3
    ├── 50ms/ ~ 300ms/
```

## 说明

- 图片按 **样品 → 时间基准 → 状态** 三级分类存放
- `PowerSourceTesting_Report/` 为报告目录（待补充）
