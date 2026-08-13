/*
 * math_utils.h —— 数学工具模块头文件（.h 只放声明）
 */
#ifndef __MATH_UTILS_H
#define __MATH_UTILS_H

/* 函数声明 */
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div_int(int a, int b);   /* 命名避开 stdlib.h 里的 div() */

#endif /* __MATH_UTILS_H */
