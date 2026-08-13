/*
 * sensor.h —— 作业：温度传感器模块头文件（.h 只放声明 + 类型定义）
 *
 * 练习点：
 *  1. include guard 头文件保护
 *  2. 用 typedef 定义模块对外"数据类型"（封装）
 *  3. 只声明接口，不暴露内部实现（s_adc 藏在 sensor.c 里）
 */
#ifndef __SENSOR_H
#define __SENSOR_H

#include <stdint.h>

/* 温度传感器数据类型（模块对外暴露的结构体）*/
typedef struct {
    int16_t  temp;     /* 温度值：单位 0.1℃，如 253 = 25.3℃ */
    uint16_t adc_raw;  /* 原始 ADC 采样值（12 位，0~4095）*/
    uint8_t  valid;    /* 数据有效性：1=有效 / 0=无效 */
} sensor_data_t;

/* 模块接口声明（实现放 sensor.c）*/
void sensor_init(void);
sensor_data_t sensor_read(void);
void sensor_print(const sensor_data_t *data);

#endif /* __SENSOR_H */
