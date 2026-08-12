/*
 * D10 作业：宏定义实战（自己动手写！）
 *
 * 作业1：写 LED 位操作宏 LED_ON() / LED_OFF()
 * 作业2：写 MAX3（三个数最大值）函数宏（可用已给的 MAX）
 * 作业3：补全 DBG 调试宏（用 __FILE__/__LINE__/__func__）
 * 作业4：写 ASSERT 断言失败报告宏
 *
 * 规则：只填 TODO 位置，main 测试代码不用改。
 *       填完后编译运行，输出符合预期即通过。
 *       （注意：TODO 没填完之前编译会报错，这是正常的，填好就好了）
 */

#include <stdio.h>

/* ===== 作业1：寄存器宏 ===== */
/* 背景：GPIOA_ODR 是 32 位输出寄存器，第 LED_PIN 位控制 LED 亮灭
 * 提示：置 1 用  GPIOA_ODR |=  (1 << LED_PIN)
 *       清 0 用  GPIOA_ODR &= ~(1 << LED_PIN)   */
static volatile unsigned int fake_ODR = 0;    /* 模拟 GPIOA->ODR（已给，别改） */
#define GPIOA_ODR    fake_ODR
#define LED_PIN      5

/* TODO 作业1a：LED_ON() —— 把第 LED_PIN 位置 1 */
#define LED_ON()     (GPIOA_ODR |=  (1 << LED_PIN))

/* TODO 作业1b：LED_OFF() —— 把第 LED_PIN 位清 0 */
#define LED_OFF()    (GPIOA_ODR &= ~(1 << LED_PIN))

/* ===== 作业2：MAX3 函数宏 ===== */
#define MAX(a, b)    ((a) > (b) ? (a) : (b))   /* 已给：两数取大 */

/* TODO 作业2：用 MAX 写出 MAX3(a,b,c)（三数取大） */
#define MAX3(a, b, c)    MAX(MAX(a, b), c)

/* ===== 作业3：调试开关 ===== */
/* 想关闭调试？注释掉下面这一行再编译，DBG 输出会全部消失 */
#define DEBUG

/* TODO 作业3：补全 DBG 宏
 *  要求：调用 DBG(fmt, ...) 时打印 [文件名:行号 函数名] + 消息
 *  提示：__FILE__ __LINE__ __func__，变参用 ##__VA_ARGS__ */
#ifdef DEBUG
    #define DBG(fmt, ...)    printf("[%s:%d %s] " fmt "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#else
    #define DBG(fmt, ...)    /* 留空：调试代码被剔除 */
#endif

/* ===== 作业4：断言失败报告宏 ===== */
/* 要求：条件为假时打印 [文件:行号 函数名] + 错误信息，不中断程序
 * 提示：用 do { ... } while(0) 包裹多行，宏才安全 */
/* TODO 作业4：补全 ASSERT(cond, msg) */
#define ASSERT(cond, msg)    do { \
    if (!(cond)) { \
        printf("[%s:%d %s] ASSERTION FAILED: %s\n", __FILE__, __LINE__, __func__, msg); \
    } \
} while(0)

int main(void) {
    /* ---- 作业1：用宏操作"寄存器"（模拟）---- */
    printf("===== 作业1：寄存器宏 =====\n");
    printf("GPIOA_ODR 地址 = %p（模拟变量地址）\n", (void *)&GPIOA_ODR);

    LED_ON();
    printf("LED 点亮: GPIOA_ODR = 0x%08X（第%d位=1）\n",
           (unsigned int)GPIOA_ODR, LED_PIN);
    LED_OFF();
    printf("LED 熄灭: GPIOA_ODR = 0x%08X（第%d位=0）\n",
           (unsigned int)GPIOA_ODR, LED_PIN);

    /* ---- 作业2：MAX3 ---- */
    printf("\n===== 作业2：MAX3 =====\n");
    printf("MAX3(3, 7, 5) = %d\n", MAX3(3, 7, 5));
    printf("MAX3(9, 2, 6) = %d\n", MAX3(9, 2, 6));
    printf("MAX3(-1, -5, -3) = %d\n", MAX3(-1, -5, -3));

    /* ---- 作业3：调试输出 ---- */
    printf("\n===== 作业3：调试开关 =====\n");
    int temp = 25;
    DBG("温度传感器读数 = %d 度", temp);
    DBG("电压 = %.2f V", 3.3);
    printf("提示：注释掉上方 #define DEBUG 再编译，上面 2 行会消失\n");

    /* ---- 作业4：断言 ---- */
    printf("\n===== 作业4：断言报告 =====\n");
    int x = 10;
    ASSERT(x > 0,  "x 应该大于 0");   /* 通过，无输出 */
    ASSERT(x < 5,  "x 应该小于 5");   /* 失败，打印定位信息 */
    printf("程序继续运行...\n");

    return 0;
}
