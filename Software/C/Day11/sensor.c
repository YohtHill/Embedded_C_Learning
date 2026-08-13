/*
 * sensor.c —— 作业：温度传感器模块实现（.c 放定义）
 *
 * 用时间戳低几位模拟"ADC 噪声"，教学演示用；
 * 真实嵌入式里 sensor_read() 会去读 ADC 寄存器。
 */
#include "sensor.h"
#include <stdio.h>
#include <time.h>

/* 模块私有变量：static 限制在本文件内，外部无法访问（封装）*/
static uint16_t s_adc = 0;

void sensor_init(void) {
    s_adc = 2048;    /* 初始 ADC 值：12 位满量程 4096 的一半 ≈ 25℃ */
    printf("[sensor] 初始化完成（ADC = %u）\n", s_adc);
}

sensor_data_t sensor_read(void) {
    sensor_data_t d;

    /* 模拟一次采样：ADC 值上下抖动 0~2（伪噪声）*/
    s_adc = s_adc + (unsigned)(time(NULL) % 3) - 1;
    d.adc_raw = s_adc;

    /* 线性换算：2048 → 25.0℃（1 LSB ≈ 0.25℃ → 除以 4）*/
    d.temp = (int16_t)((s_adc - 2048) / 4) + 250;
    d.valid = 1;

    return d;   /* 返回结构体：大数据一般传指针，小结构体可直接返回 */
}

void sensor_print(const sensor_data_t *data) {
    if (data->valid) {
        printf("  温度 = %d.%d ℃（ADC 原始值 = %u）\n",
               data->temp / 10, (data->temp < 0 ? -data->temp : data->temp) % 10,
               data->adc_raw);
    } else {
        printf("  数据无效\n");
    }
}
