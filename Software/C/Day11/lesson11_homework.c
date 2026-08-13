/*
 * 作业（2A-4 多文件工程）：封装一个"温度传感器模块"
 *
 * 要求：
 *  1. 已给好 sensor.h（声明 + 类型定义）、sensor.c（实现）、本 main 文件
 *  2. main 里只 include "sensor.h"，就能使用整个模块 ✅
 *  3. 思考：s_adc 是 static 的，main 里能访问到吗？→ 不能，这叫封装
 *  4. 挑战：把 LED 模块也改成"多文件版"（led.h/led.c），再写一个
 *     main 同时点亮 LED 和读温度
 *
 * 编译命令（在 Day11 目录下）：
 *   gcc lesson11_homework.c sensor.c -o lesson11_homework.exe
 */
#include <stdio.h>
#include "sensor.h"

int main(void) {
    printf("===== 作业：多文件「温度传感器模块」=====\n\n");

    sensor_init();

    for (int i = 0; i < 5; i++) {
        sensor_data_t d = sensor_read();
        printf("第 %d 次读取：", i + 1);
        sensor_print(&d);
    }

    printf("\n（sensor.c 里的 static 变量 s_adc，main 里无法访问 = 封装）\n");

    return 0;
}
