# DC Power Ripple & Noise Measurement

## Experiment Objective

Precisely measure the **ripple** and **noise** at the DC power output, evaluate power output quality, verify whether design requirements are met, and provide a basis for product design and power optimization.

[中文](README.md) | **English**

## Experiment Info

| Item | Value |
|------|-------|
| Date | 2026-07-14 |
| Reporter | Pi Jiakun |
| Samples | LRC board, SP board (fingerprint modules) |

## Equipment

| Equipment | Model | Purpose |
|-----------|-------|---------|
| Oscilloscope | Tektronix | Ripple & noise waveform acquisition |
| Probe | TPP0500B (500MHz) | Signal probing |
| Ground spring | — | Reduce measurement loop EMI |

## Measurement Conditions

- Coupling: AC coupling
- Bandwidth limit: 20 MHz
- Time base: 200 µs/div
- Sample rate: 2.50 GS/s
- Record length: 10 M points
- Probe attenuation: 10:1
- Grounding: ground spring

## Samples

| Sample | Description |
|--------|-------------|
| LRC board | Fingerprint module with LRC LDO, main MCU, R1-R15, C1-C4, L1-L2 |
| SP board | Fingerprint module with SP LDO, main MCU, R1-R15, C1-C15, D1-D8 |

## Files

- **Report**: [Ripple & noise measurement report (Chinese)](RippleTesting_Report/直流电源输出纹波与噪声测量实验结果报告.md)
- **Waveforms**: `Ripple_Testing_Img/` stores measurement waveform screenshots
