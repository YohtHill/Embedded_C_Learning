/*
 * D9 作业：共用体 union + 枚举 enum 实战
 *
 * 作业1：大小端判断 —— 用 union 判断本机是大端还是小端
 * 作业2：串口数据帧解析 —— 用 union 解析 4 字节帧 [0x12,0x34,0x56,0x78]
 * 作业3：LED 状态机 —— 用 enum 定义状态，模拟按键切换
 */

#include <stdio.h>

/* ===== 作业1：大小端判断 ===== */
/* 小端：低位字节存在低地址；大端：高位字节存在低地址 */
int isLittleEndian(void) {
    union {
        unsigned int   i;
        unsigned char  b;
    } u;
    u.i = 1;              /* 0x00000001 */
    return u.b == 1;      /* b 取低地址字节：小端=1，大端=0 */
}

/* ===== 作业2：union 解析 4 字节数据帧 ===== */
typedef union {
    unsigned int   value;    /* 按 32 位整型读 */
    unsigned char  bytes[4]; /* 按 4 个字节读 */
} Frame4;

/* ===== 作业3：enum LED 状态机 ===== */
typedef enum {
    LED_OFF = 0,
    LED_ON,
    LED_BLINK
} LedState;

/* 返回状态名字符串（辅助打印用）*/
const char* stateName(LedState s) {
    switch (s) {
        case LED_OFF:   return "OFF(熄灭)";
        case LED_ON:    return "ON(点亮)";
        case LED_BLINK: return "BLINK(闪烁)";
        default:        return "未知";
    }
}

int main(void) {
    printf("===== 作业1：大小端判断 =====\n");
    printf("本机是%s端\n", isLittleEndian() ? "小" : "大");

    printf("\n===== 作业2：union 解析 4 字节数据帧 =====\n");
    Frame4 f;
    /* 模拟串口收到 [0x12, 0x34, 0x56, 0x78] */
    f.bytes[0] = 0x12;
    f.bytes[1] = 0x34;
    f.bytes[2] = 0x56;
    f.bytes[3] = 0x78;
    printf("按字节读: %02X %02X %02X %02X\n",
           f.bytes[0], f.bytes[1], f.bytes[2], f.bytes[3]);
    printf("按整型读: 0x%08X\n", f.value);
    /* 思考：如果是在小端机器，0x78563412 表示 bytes[0] 是最低位
     *       如果按网络字节序解析，需要字节序转换 */

    printf("\n===== 作业3：LED 状态机 =====\n");
    /* 模拟按键序列：1=OFF  2=ON  3=BLINK，自动跑一遍 */
    int keys[] = {1, 2, 3, 2, 1};
    LedState led = LED_OFF;
    printf("初始状态: %s\n", stateName(led));

    for (int i = 0; i < 5; i++) {
        switch (keys[i]) {
            case 1:  led = LED_OFF;   break;
            case 2:  led = LED_ON;    break;
            case 3:  led = LED_BLINK; break;
            default: break;           /* 忽略无效按键 */
        }
        printf("按键 %d -> %s\n", keys[i], stateName(led));
    }

    return 0;
}
