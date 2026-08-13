/*
 * led.c —— LED 模块实现（.c 放定义）
 *
 * 用 volatile 变量模拟 GPIO 的 ODR（输出数据寄存器）
 * 复习 D10 的位操作：|= 置位点亮、&=~ 清位熄灭、^= 取反翻转
 */
#include "led.h"          /* 包含自己的头文件，保证声明与定义一致 */
#include <stdio.h>

/* 模拟寄存器：ODR 低 8 位（实际硬件里这是内存映射地址）*/
static volatile uint8_t ODR = 0x00;

void led_init(void) {
    /* 配置引脚为输出，初始熄灭 */
    ODR &= ~(1u << LED_PIN);
    printf("[led] init  : PB%d 配置为输出，初始熄灭\n", LED_PIN);
}

void led_on(void) {
    ODR |= (1u << LED_PIN);       /* 置位：点亮 */
    printf("[led] ON    : ODR = 0x%02X\n", ODR);
}

void led_off(void) {
    ODR &= ~(1u << LED_PIN);      /* 清位：熄灭 */
    printf("[led] OFF   : ODR = 0x%02X\n", ODR);
}

void led_toggle(void) {
    ODR ^= (1u << LED_PIN);       /* 取反：翻转 */
    printf("[led] TOGGLE: ODR = 0x%02X\n", ODR);
}
