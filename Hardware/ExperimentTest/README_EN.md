# Experiments (ExperimentTest)

> Records hardware experiments during internship/development, including experiment reports, test data, and categorized images.

[中文](README.md) | **English**

## Contents

| Folder | Content | Description |
|--------|---------|-------------|
| [RippleTesting/](RippleTesting/) | DC power ripple & noise measurement | Measured power output ripple/noise of LRC and SP fingerprint modules |
| [PowerSourceTesting/](PowerSourceTesting/) | Power source testing module (BF85112B) | Tested BF85112B chip power/fingerprint/idle states at different time bases |
| [DifferentialSignalTesting/](DifferentialSignalTesting/) | Differential signal overshoot test | Evaluated 10cm flat-cable DP/DM overshoot, validated series-resistor solution |

## Test Overview

### 1. Ripple & Noise Measurement (RippleTesting)
- **Purpose**: Evaluate DC power output quality, verify design requirements are met
- **Equipment**: Tektronix oscilloscope + TPP0500B probe (500MHz) + ground spring
- **Conditions**: AC coupling, 20MHz bandwidth limit, 200µs/div
- **Samples**: LRC board, SP board (fingerprint modules, different LDOs)
- **Report**: [Ripple & noise measurement report (Chinese)](RippleTesting/RippleTesting_Report/直流电源输出纹波与噪声测量实验结果报告.md)

### 2. Power Source Testing (PowerSourceTesting)
- **Target**: BF85112B chip (samples 2, 3)
- **Time bases**: 50ms / 100ms / 150ms / 200ms / 250ms / 300ms
- **States**: Capture (waveform acquisition), FD (fingerprint detection), Idle (standby)
- **Images**: Categorized by sample + time + state (3-level)

### 3. Differential Signal Overshoot Test (DifferentialSignalTesting)
- **Background**: Customer FP/DM signals routed via a 10cm cable, overshoot exceeded 4V; assessed impact on the MCU
- **Purpose**: Verify whether series resistors (R5/R8) can solve the overshoot issue
- **Equipment**: Tektronix oscilloscope + TPP0500B probe (DC coupling, full bandwidth, 2.00 V/div)
- **Test points**: near host side, module side (through 10cm FPC)
- **Groups**: 0Ω (original) → 10R → 3.3R comparison
- **Report**: [Differential signal overshoot report (Chinese)](DifferentialSignalTesting/DifferentialSignalTesting_Report/差分信号过冲测试报告.md)

## Directory Structure

```
ExperimentTest/
├── README.md                       This guide
├── RippleTesting/
│   ├── RippleTesting_Report/       Ripple measurement report
│   └── Ripple_Testing_Img/         Ripple test waveforms
├── PowerSourceTesting/
│   ├── PowerSourceTesting_Report/  Power test report (to be added)
│   └── PowerSourceTesting_Img/     Power test images (by sample/time)
│       ├── BF85112B_2/
│       │   ├── 50ms/ ~ 300ms/      Test images per time base
│       └── BF85112B_3/
│           ├── 50ms/ ~ 300ms/
└── DifferentialSignalTesting/
    ├── DifferentialSignalTesting_Report/  Differential overshoot report
    └── DifferentialSignalTesting_Img/     Overshoot waveforms (0R/10R/3.3R groups)
```

---

*Continuously updated, recording every hardware experiment.*
