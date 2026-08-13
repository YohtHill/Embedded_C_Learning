/*
 * 2A-4：多文件工程（.h/.c 分离 + 头文件保护）
 *
 * 嵌入式场景：
 *  - 工程按模块拆分成多个 .c 文件，每个模块配一个 .h 头文件
 *  - .h 里只放"声明"（函数原型、宏、typedef、extern 变量）
 *  - .c 里放"定义"（函数实现、全局变量定义）
 *  - include guard（#ifndef/#define/#endif）防止头文件被重复包含
 *
 * 关键理解：
 *  - 声明 vs 定义：声明告诉编译器"这东西存在"，定义才真正分配内存
 *  - 头文件 = 模块的"接口说明书"；.c = 模块的"内部实现"
 *  - 别人只需要看 .h 就知道怎么用你的模块，不用看实现
 *
 * 多文件编译命令（在 Day11 目录下）：
 *   gcc lesson11_main.c led.c math_utils.c -o lesson11_main.exe
 */
#include <stdio.h>
#include "led.h"         /* 自定义头文件用双引号 "" */
#include "math_utils.h"

int main(void) {
    printf("===== 2A-4 多文件工程（.h/.c 分离）=====\n\n");

    printf("--- LED 模块（led.h + led.c）---\n");
    led_init();
    led_on();
    led_off();
    led_toggle();
    led_toggle();

    printf("\n--- 数学工具模块（math_utils.h + math_utils.c）---\n");
    printf("add(3, 5)      = %d\n", add(3, 5));
    printf("sub(10, 4)     = %d\n", sub(10, 4));
    printf("mul(6, 7)      = %d\n", mul(6, 7));
    printf("div_int(20, 5) = %d\n", div_int(20, 5));
    printf("div_int(20, 0) = %d（除零保护）\n", div_int(20, 0));

    printf("\n===== 多文件编译命令 =====\n");
    printf("gcc lesson11_main.c led.c math_utils.c -o lesson11_main.exe\n");
    printf("（把多个 .c 一起编译，.h 不需要出现在命令里）\n");

    return 0;
}
