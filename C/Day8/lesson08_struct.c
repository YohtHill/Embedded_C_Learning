/*
 * 2A-1：结构体 struct —— 把相关数据打包成整体
 *
 * 嵌入式场景：
 *  - 传感器数据打包（温度+湿度+状态）
 *  - 描述寄存器组（STM32 库的 GPIO_TypeDef 就是结构体）
 *  - 通信数据帧组织
 */

#include <stdio.h>
#include <string.h>

/* ========== 1. 定义结构体类型 ========== */
/* 定义一个"传感器数据"结构体，包含 3 个成员 */
struct SensorData {
    float temperature;   /* 温度 */
    int   humidity;      /* 湿度 % */
    int   status;        /* 状态：0=正常 1=异常 */
};

/* ========== 2. 定义结构体 + typedef（嵌入式最常用）========== */
/* typedef 给结构体起个简短别名，以后不用写 struct 关键字 */
typedef struct {
    char   name[16];     /* 设备名 */
    int    id;           /* 设备ID */
    float  version;      /* 版本号 */
} DeviceInfo;

int main() {
    /* ========== 3. 结构体变量的声明与初始化 ========== */
    printf("===== 1. 结构体声明与初始化 =====\n");

    /* 方法1：声明后逐个赋值 */
    struct SensorData s1;
    s1.temperature = 25.3f;
    s1.humidity = 60;
    s1.status = 0;

    /* 方法2：声明时用花括号初始化（按成员顺序）*/
    struct SensorData s2 = {30.5f, 45, 1};

    /* 用 . 访问成员 */
    printf("s1: 温度=%.1f, 湿度=%d%%, 状态=%s\n",
           s1.temperature, s1.humidity, s1.status == 0 ? "正常" : "异常");
    printf("s2: 温度=%.1f, 湿度=%d%%, 状态=%s\n",
           s2.temperature, s2.humidity, s2.status == 0 ? "正常" : "异常");

    /* ========== 4. typedef 后的结构体（不用写 struct）========== */
    printf("\n===== 2. typedef 结构体 =====\n");
    DeviceInfo d1;
    strcpy(d1.name, "STM32F103");
    d1.id = 1;
    d1.version = 2.5f;
    printf("设备: %s, ID=%d, 版本=%.1f\n", d1.name, d1.id, d1.version);

    /* ========== 5. 结构体指针（重点！）========== */
    printf("\n===== 3. 结构体指针 =====\n");
    struct SensorData *ps = &s1;   /* ps 指向 s1 */

    /* 用 -> 通过指针访问成员（-> 相当于 (*ps).成员）*/
    printf("通过指针访问: 温度=%.1f\n", ps->temperature);
    printf("等价写法 (*ps).: 温度=%.1f\n", (*ps).temperature);

    /* 修改结构体成员 */
    ps->temperature = 26.8f;       /* 通过指针改值 */
    printf("修改后 s1 温度 = %.1f（指针改到了原变量）\n", s1.temperature);

    /* ========== 6. sizeof 结构体 ========== */
    printf("\n===== 4. 结构体大小 =====\n");
    printf("struct SensorData 大小 = %zu 字节\n", sizeof(struct SensorData));
    printf("（注意：可能比各成员之和略大，因为有内存对齐）\n");

    return 0;
}
