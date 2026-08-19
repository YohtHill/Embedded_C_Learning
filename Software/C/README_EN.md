# Embedded C Language Learning Notes

Learning embedded software development from scratch using the C language.

[中文](README.md) | **English**

## Study Plan (D1~D11)

| Day | Topic | Status |
|-----|-------|--------|
| D1 | Hello World, variables, basic types, sizeof | ✅ |
| D2 | Operators & type conversion experiments | ✅ |
| D3 | if/for/while, multiplication table, summation | ✅ |
| D4 | Functions & parameter passing swap, pointers | ✅ |
| D5 | Arrays, bubble sort, finding the maximum | ✅ |
| D6 | Strings strlen/strcpy/strcat, pointer style | ✅ |
| D7 | Review & rewrite | ✅ |
| D8 | Struct, typedef, pass-by-value vs pass-by-pointer | ✅ |
| D9 | Union, enum, state machine, data frame parsing | ✅ |
| D10 | #define macros, function-like macros, conditional compilation, debug macros | ✅ |
| D11 | Multi-file projects .h/.c separation, header guards, modularization, static encapsulation | ✅ |

## Study Diary

### 2026-08-10 (D1~D7 all completed 🎉)

**Completed today:**
- D1: Hello World, variable types, sizeof (char=1, int=4, double=8)
- D2: Integer division (5/2=2), overflow (char c=300 → 44), two's complement (0xFF=-1)
- D3: if/for/while, multiplication table (nested loops), sum 1~100 (loop + formula), char delay busy-loop
- D4: Pass-by-value vs pointers (the swap pitfall), using pointers to truly modify variables outside functions
- D5: Arrays (array name = first address), find max and index, bubble sort
- D6: Implemented strlen/strcpy/strcat myself, pointer style (*s++), left-shift operator and register operations
- D7: Review of 5 problems, all solved independently ✅

**Core takeaways (embedded mindset):**
- Pointer = a variable storing an address; *p directly operates on memory
- Register = a special memory address in the MCU, operated via `*(volatile unsigned int*)address`
- Bitwise ops `(1<<n)` set bits, `(v>>i)&1` read bits = basis of register read/write
- Overflow/two's complement/delta-thinking (tick wraparound handling)
- delay (busy wait) vs timer interrupts

**Engineering practice:**
- Set up VS Code + gcc compilation environment (including UTF-8 encoding handling)
- Installed and configured Git; code pushed to GitHub
- Used `.gitignore` to exclude exe build artifacts

### 2026-08-12 (D8 struct —— 2A-1 completed ✅)

**Completed today:**
- D8: struct definition, `typedef` aliases, declaration & initialization, member access
- Homework: `student_t` student struct, verifying **pass-by-value vs pass-by-pointer** (modifying a copy vs the real variable, echoing the D4 swap pitfall)
- Passing the whole struct by value = copying it; the function can't modify the original; passing a pointer can

**Core takeaways (embedded mindset):**
- Struct = packing related data as a whole (sensor temperature + humidity + status)
- **STM32 library register group `GPIO_TypeDef` is a struct**, describing registers with structs
- `typedef struct {...} alias;` is the most common embedded idiom, avoiding the `struct` keyword
- Large data passed by value is costly → prefer pointers

### 2026-08-12 (D9 union + enum —— 2A-2 completed ✅)

**Completed today:**
- D9: `union` (members share memory), `enum` (named integer constants)
- Homework 1: use union to detect **endianness** (`u.i=1`, check `u.b`)
- Homework 2: union to parse a 4-byte serial frame (byte-wise / integer-wise read, little-endian `0x78563412`)
- Homework 3: enum LED state machine (OFF/ON/BLINK), simulate button switching

**Core takeaways (embedded mindset):**
- **union = multiple views of the same memory**: register high/low byte access (`Reg16.value` / `Reg16.byte.low/high`)
- **Data frame parsing tool**: the same buffer can be read as a struct or as a raw byte stream
- **enum = standard practice for state machines/error codes**: `LED_OFF=0, LED_ON=1, LED_BLINK=2`, dispatched with `switch`
- Little-endian machine: low byte stored at low address (this machine: `bytes = 78 56 34 12`)
- `typedef enum {...} alias;` common embedded idiom

### 2026-08-12 (D10 #define macros —— 2A-3 completed ✅)

**Completed today:**
- D10: `#define` macros — pure text substitution at the preprocessing stage (not a function!)
- Object-like macros: naming constants/pins/register addresses (eliminating "magic numbers")
- Function-like macros: `MAX(a,b)`, `ABS(x)`, `IS_SET(reg,n)`, avoiding function call overhead
- Parenthesis pitfall: `SQUARE_BAD(2+3)=11` (missing parentheses), `SQUARE_GOOD(2+3)=25`
- Conditional compilation: `#ifdef DEBUG` debug switch, `#if/#elif` platform selection, header guards
- Special macros: `__FILE__` / `__LINE__` / `__func__` / `__DATE__` / `__TIME__` for debugging
- Homework: register macro read/write, MAX3, debug switch, `ASSERT` assertion reporting macro

**Core takeaways (embedded mindset):**
- **Macro = text substitution before compilation**, happens in preprocessing, no types, no call overhead
- **Register address macro**: `#define GPIOA_ODR (*(volatile unsigned int *)(base+0x0C))`
- **LED bit-operation macros**: `LED_ON()` = `ODR |= (1<<pin)`, `LED_OFF()` = `ODR &= ~(1<<pin)`
- **Debug switch**: wrap debug code with `#ifdef DEBUG`; comment out the macro definition for release builds to strip it automatically
- **Assertion macro**: `ASSERT(cond, msg)` locates problems precisely with `__LINE__`/`__func__`
- **Header guards**: `#ifndef _XXX_H_ / #define ... / #endif` prevent duplicate inclusion

### 2026-08-13 (D11 multi-file project .h/.c separation —— 2A-4 completed ✅)

**Completed today:**
- D11: multi-file projects (`.h`/`.c` separation + header guards)
- `.h` header files: only **declarations** (function prototypes, macros, typedef, extern), plus include guards
- `.c` source files: **definitions** (function implementations, global variables), `static` private variables for "encapsulation"
- Multi-file compilation: `gcc lesson11_main.c led.c math_utils.c -o app.exe` (.h files don't appear in the command)
- Homework: encapsulated "temperature sensor module" (sensor.h/sensor.c), returning data via a struct

**Core takeaways (embedded mindset):**
- **Declaration vs definition**: declaration tells the compiler "this exists"; definition actually allocates memory
- **Header file = interface manual**: others only need the .h to know how to use the module, without seeing the implementation
- **Include guard**: `#ifndef/#define/#endif` prevents duplicate header inclusion (foreshadowed in D10, used today)
- **static encapsulation**: module-private variables marked static are inaccessible externally
- **Standard embedded project structure**: an STM32 project is a set of .c + .h files organized by module (bsp_led.c / bsp_uart.c...)

## Development Environment

- OS: Windows
- Compiler: MSYS2 + MinGW-w64 (gcc 16.1.0)
- Editor: VS Code
- Version control: Git

## Directory Structure

```
├── C/
│   ├── Day1/   # D1: Hello World, variables, sizeof, homework 1
│   ├── Day2/   # D2: Operators, type casting
│   ├── Day3/   # D3: Control flow, multiplication table, delay demo
│   ├── Day4/   # D4: Functions, pointer swap, homework
│   ├── Day5/   # D5: Arrays, bubble sort, homework
│   ├── Day6/   # D6: Strings, pointer style, left-shift register demo
│   ├── Day7/   # D7: Review (5 problems all passed)
│   ├── Day8/   # D8: struct, typedef, pass-by-value vs pass-by-pointer homework
│   ├── Day9/   # D9: union, enum, state machine, data frame parsing
│   ├── Day10/  # D10: #define macros, function-like macros, conditional compilation, debug/assertion macros
│   └── Day11/  # D11: multi-file project (.h/.c separation, header guards, modularization, static encapsulation)
└── Note/       # Internship hardware learning notes (PCB, FPC, ESD, fingerprint modules) → see Note/README.md
```
