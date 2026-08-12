/*
 * 2A-3：宏定义 #define —— 预处理阶段的文本替换
 *
 * 嵌入式场景：
 *  - 对象宏：寄存器地址、引脚号、常量统一命名（消灭"魔法数字"）
 *  - 函数宏：MAX/MIN/位操作，省去函数调用开销
 *  - 条件编译：调试开关、平台选择、头文件保护
 *  - 特殊宏 __FILE__ / __LINE__：调试定位
 *
 * 关键理解：宏是"文本替换"，发生在编译之前（预处理），不是函数！
 */

#include <stdio.h>

/* ========== 1. 对象宏（Object-like Macro）========== */
/* 纯文本替换：没有类型、没有分号、不占内存 */
#define LED_PIN       5            /* 引脚号 PB5 */
#define BAUD_RATE     115200       /* 串口波特率 */
#define ARRAY_SIZE    8
#define PI            3.14159f

/* 寄存器地址宏（嵌入式经典写法）：地址 转成 volatile 指针 */
#define GPIOA_BASE    0x40010800UL
#define GPIOA_CRL     ((volatile unsigned int *)GPIOA_BASE)  /* 配置寄存器低32位 */

/* ========== 2. 函数宏（Function-like Macro）========== */
/* 注意：参数和整体都要加括号！否则有优先级陷阱 */
#define MAX(a, b)     ((a) > (b) ? (a) : (b))
#define ABS(x)        ((x) < 0 ? -(x) : (x))
#define IS_SET(reg,n) (((reg) & (1 << (n))) != 0)

/* 陷阱演示：忘加括号的宏 */
#define SQUARE_BAD(x)  x * x
#define SQUARE_GOOD(x) ((x) * (x))

/* ========== 3. 条件编译 ========== */
/* 调试开关：定义 DEBUG 编译调试代码，注释掉则调试代码被"剔除" */
#define DEBUG

#ifdef DEBUG
    #define DBG_PRINT(fmt, ...)  printf("[%s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
    #define DBG_PRINT(fmt, ...)
#endif

/* 平台选择：一份代码，不同平台编译不同分支 */
#define PLATFORM_STM32 1
#define PLATFORM_AVR   2
#define CURRENT_PLATFORM PLATFORM_STM32

int main(void) {
    printf("===== 1. 对象宏（常量命名）=====\n");
    printf("LED_PIN = %d, BAUD_RATE = %d, ARRAY_SIZE = %d\n",
           LED_PIN, BAUD_RATE, ARRAY_SIZE);
    printf("PI = %.5f\n", PI);
    printf("GPIOA_BASE = 0x%08X\n", (unsigned int)GPIOA_BASE);
    printf("GPIOA_CRL 地址 = %p（宏展开成指针）\n", (void *)GPIOA_CRL);

    printf("\n===== 2. 函数宏 =====\n");
    printf("MAX(3, 7) = %d\n", MAX(3, 7));
    printf("ABS(-5) = %d, ABS(8) = %d\n", ABS(-5), ABS(8));

    unsigned int reg = 0x0A;       /* 二进制 1010 */
    printf("reg = 0x0A：第1位=%s, 第3位=%s\n",
           IS_SET(reg, 1) ? "1" : "0",
           IS_SET(reg, 3) ? "1" : "0");

    printf("\n----- 括号陷阱（重点！）-----\n");
    printf("SQUARE_BAD(2+3)  = %d  ← 错误！2+3*2+3=11\n", SQUARE_BAD(2+3));
    printf("SQUARE_GOOD(2+3) = %d  ← 正确！(2+3)*(2+3)=25\n", SQUARE_GOOD(2+3));

    printf("\n===== 3. 条件编译 =====\n");
    DBG_PRINT("温度传感器读数 = %d 度", 25);
    DBG_PRINT("电压 = %.2f V", 3.3);
    printf("（注释掉 #define DEBUG 重新编译，上面的调试行会消失）\n");

#if CURRENT_PLATFORM == PLATFORM_STM32
    printf("当前平台: STM32（只编译这一分支）\n");
#elif CURRENT_PLATFORM == PLATFORM_AVR
    printf("当前平台: AVR\n");
#else
    printf("当前平台: 未知\n");
#endif

#ifdef DEBUG
    printf("DEBUG 已定义 → 编译了调试代码\n");
#else
    printf("DEBUG 未定义 → 调试代码被剔除\n");
#endif

    printf("\n===== 4. 特殊宏（调试利器）=====\n");
    printf("当前文件: %s\n", __FILE__);
    printf("当前行号: %d\n", __LINE__);
    printf("当前函数: %s\n", __func__);
    printf("编译时间: %s %s\n", __DATE__, __TIME__);

    return 0;
}
