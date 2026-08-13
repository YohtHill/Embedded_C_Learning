/*
 * math_utils.c —— 数学工具模块实现（.c 放定义）
 */
#include "math_utils.h"
#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }

int div_int(int a, int b) {
    if (b == 0) {
        printf("[math] 错误：除数不能为 0，返回 0\n");
        return 0;
    }
    return a / b;
}
