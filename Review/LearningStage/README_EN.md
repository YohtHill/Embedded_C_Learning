# Embedded Learning Roadmap (Three-Stage Overview)

> Learning goal: master embedded software development from zero, ultimately able to develop STM32 projects independently.

[中文](README.md) | **English**

## Three-Stage Overview

| Stage | Topic | Status | Hardware Needed | Content |
|-------|-------|--------|-----------------|---------|
| **Stage 1** | C language basics | ✅ Completed | ❌ No | Variables, operators, control flow, functions, pointers, arrays, strings |
| **Stage 2** | C advanced + STM32 basics | 🔄 In progress | 2A no / 2B yes | Structs, multi-file projects, register LED, interrupts, timers, UART |
| **Stage 3** | Embedded deep dive & integrated projects | ⬜ Not started | ✅ Yes | Library development, FreeRTOS, comprehensive projects |

## Detailed Documents

| Document | Description |
|----------|-------------|
| [Stage1_总结.md](Stage1_总结.md) | Stage 1 (C language basics) full summary |
| [Stage2_规划.md](Stage2_规划.md) | Stage 2 (C advanced + STM32 basics) detailed plan |
| [Stage3_规划.md](Stage3_规划.md) | Stage 3 (embedded deep dive & projects) plan |

## Development Environment

- OS: Windows
- Compiler: MSYS2 + MinGW-w64 (gcc 16.1.0)
- Editor: VS Code
- Version control: Git + GitHub
- Hardware (to purchase before 2B): STM32F103C8T6 blue pill board + ST-Link V2
