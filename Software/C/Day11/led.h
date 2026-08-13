/*
 * led.h —— LED 模块头文件（.h 只放声明）
 *
 * 头文件保护（include guard）：防止同一个头文件被多次包含
 *   #ifndef __LED_H  若 __LED_H 未定义过 → 进入
 *   #define __LED_H  定义 __LED_H 标记（下次再 include 就跳过）
 *   #endif           结束
 */
#ifndef __LED_H
#define __LED_H

#include <stdint.h>

#define LED_PIN  5        /* 引脚号：PB5（对外暴露的配置宏）*/

/* 函数声明（原型）：实现放在 led.c */
void led_init(void);
void led_on(void);
void led_off(void);
void led_toggle(void);

#endif /* __LED_H */
