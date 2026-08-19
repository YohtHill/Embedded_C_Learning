# Embedded Learning

> Systematic embedded development learning from scratch, covering both **Software** and **Hardware**.

[中文](README.md) | **English**

## Repository Structure

```
Embedded Learning/
├── Software/           # Software learning
│   └── C/              # C language learning (from basics to advanced)
├── Hardware/           # Hardware learning
│   ├── PCB_Prj/        # PCB projects (schematic/PCB/Gerber/BOM/SMT)
│   ├── ExperimentTest/ # Experiments (ripple, power source testing, etc.)
│   └── Note/           # Hardware design notes (PCB/FPC/ESD/fingerprint modules)
└── Review/             # Review & planning
    ├── LearningStage/  # Three-stage learning plan
    ├── DailyReview/    # Daily study summaries
    └── WeeklyReport/   # Weekly work summaries
```

## PCB Projects

| Project | Description | Status | Updated |
|---------|-------------|--------|---------|
| CCM4201S_MAIN_Board_V1 | Development board | ✅ Completed | 2026-08-19 |
| BM43112DC02 | Fingerprint module | ✅ Completed | 2026-08-17 |
| VB2032-241203 | Fingerprint module | ✅ Completed | 2026-08-13 |
| BF83080C_V1.0 | Fingerprint module | ✅ Completed | 2026-08-12 |
| BM22192DA06 | Fingerprint module | ✅ Completed | 2026-08-07 |
| BM3218+BF83112 | Fingerprint module | ✅ Completed | 2026-08-03 |

> Each project includes: Schematic (SCH), PCB layout (PCB), manufacturing files (Gerber), BOM, and SMT assembly files.

## Learning Roadmap

### Stage 1: C Language Basics ✅
- Hello World, variables, types, sizeof
- Operators, type casting, overflow & two's complement
- Control flow, multiplication table, summation
- Functions, pointers, the swap pitfall
- Arrays, bubble sort, strings
- → See [Software/C/README_EN.md](Software/C/README_EN.md)

### Stage 2: C Advanced + STM32 Basics 🔄
- Structs, unions, enums ✅ (D8, D9)
- Preprocessor & macros, conditional compilation, debug macros ✅ (D10)
- Multi-file projects, header files, static encapsulation ✅ (D11)
- Function pointers, memory management (2A-5) ⬜
- STM32 register-based LED, GPIO, interrupts, timers, UART (2B/2C) ⬜
- → See [Review/LearningStage/Stage2_规划.md](Review/LearningStage/Stage2_规划.md)

### Stage 3: Embedded Deep Dive & Projects ⬜
- Standard/HAL libraries, ADC/DMA/PWM
- FreeRTOS real-time OS
- Comprehensive hands-on projects
- → See [Review/LearningStage/Stage3_规划.md](Review/LearningStage/Stage3_规划.md)

## Current Progress

| Module | Status |
|--------|--------|
| C Language Basics (D1~D7) | ✅ Completed |
| C Advanced (D8~D11: struct/union/enum/macro/multi-file) | ✅ 4 lessons done (2A-1~2A-4) |
| PCB Projects | ✅ All 6 projects completed (latest: CCM4201S dev board) |
| Hardware Notes (PCB/FPC) | ✅ Internship accumulation |
| Experiments | 📊 Continuously updated |

## Development Environment

- OS: Windows
- Compiler: MSYS2 + MinGW-w64 (gcc)
- Editor: VS Code
- Version control: Git + GitHub
