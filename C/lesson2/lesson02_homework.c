#include<stdio.h>
int main()
{
    char DHT_Sensor_Data = 25;      /* 温度 25℃，char 就够（-128~127） */
    unsigned short count = 5000;    /* 5000 用 unsigned short 省内存 */
    float Voltage = 3.3f;           /* 电压 3.3V，加 f 明确是 float */

    printf("DHT_Sensor_Data = %d\n", DHT_Sensor_Data);   /* %d 打印数值 25 */
    printf("count = %u\n", count);                       /* %u 匹配 unsigned */
    printf("Voltage = %.1f\n", Voltage);
    return 0;
}