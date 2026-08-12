/*
 * 2A-2：共用体 union + 枚举 enum
 *
 * 嵌入式场景：
 *  - union：寄存器高低字节访问、串口数据帧解析、类型转换
 *  - enum：状态机、错误码、命令字定义
 */

#include <stdio.h>
#include <string.h>

/* ========== 1. union 共用体 ========== */
/* 所有成员共享同一块内存，大小 = 最大成员 */
union UData {
    int    i;          /* 4 字节 */
    float  f;          /* 4 字节 */
    char   bytes[4];   /* 4 字节 */
};

/* 嵌入式经典：16 位寄存器高低字节访问 */
union Reg16 {
    unsigned short value;          /* 整个 16 位寄存器 */
    struct {                       /* 拆成高低字节 */
        unsigned char low;
        unsigned char high;
    } byte;
};

/* ========== 2. enum 枚举 ========== */
/* 状态机：LED 三种状态 */
enum LedState {
    LED_OFF = 0,
    LED_ON,
    LED_BLINK
};

/* 错误码（可定义任意整数值）*/
enum ErrCode {
    OK         = 0,
    ERR_TIMEOUT = -1,
    ERR_PARAM   = -2,
    ERR_MEM     = -3
};

/* ========== 3. union + struct 结合：数据帧解析 ========== */
/* 模拟串口数据帧：2 字节头 + 2 字节数据 + 1 字节校验 */
struct Frame {
    unsigned char header[2];
    unsigned char data[2];
    unsigned char crc;
};

union FrameUnion {
    struct Frame frame;     /* 按帧结构读 */
    unsigned char raw[5];   /* 按原始字节流读 */
};

int main(void) {
    printf("===== 1. union 共用体 =====\n");
    printf("sizeof(union UData) = %d 字节（int/float/char[4] 都是 4 字节，共享同一块内存）\n",
           (int)sizeof(union UData));

    union UData u;
    u.i = 0x12345678;
    printf("i     = 0x%08X\n", u.i);
    printf("bytes = %02X %02X %02X %02X（小端机器：低位在前）\n",
           u.bytes[0], u.bytes[1], u.bytes[2], u.bytes[3]);

    printf("\n===== 2. 寄存器高低字节访问 =====\n");
    union Reg16 reg;
    reg.value = 0xABCD;
    printf("value = 0x%04X\n", reg.value);
    printf("low   = 0x%02X, high = 0x%02X（小端：low 在低地址）\n",
           reg.byte.low, reg.byte.high);

    printf("\n===== 3. enum 枚举 =====\n");
    printf("LED_OFF=%d, LED_ON=%d, LED_BLINK=%d\n", LED_OFF, LED_ON, LED_BLINK);
    printf("ERR_PARAM=%d\n", ERR_PARAM);

    /* 状态机：switch 处理枚举 */
    enum LedState led = LED_ON;
    switch (led) {
        case LED_OFF:   printf("当前状态：熄灭\n"); break;
        case LED_ON:    printf("当前状态：点亮\n"); break;
        case LED_BLINK: printf("当前状态：闪烁\n"); break;
        default:        printf("未知状态\n");        break;
    }

    printf("\n===== 4. union + struct 数据帧解析 =====\n");
    union FrameUnion fu;
    /* 模拟串口收到原始字节流 0xAA 0x55 0x12 0x34 0x1C */
    memcpy(fu.raw, (unsigned char[]){0xAA, 0x55, 0x12, 0x34, 0x1C}, 5);
    printf("原始字节流: ");
    for (int i = 0; i < 5; i++) {
        printf("%02X ", fu.raw[i]);
    }
    printf("\n");
    /* 同一个缓冲区，用结构体视图解析 */
    printf("按帧解析: 头=%02X%02X 数据=%02X%02X CRC=%02X\n",
           fu.frame.header[0], fu.frame.header[1],
           fu.frame.data[0],   fu.frame.data[1],
           fu.frame.crc);

    printf("\n===== 5. enum 错误码用法 =====\n");
    enum ErrCode err = ERR_PARAM;
    printf("函数返回错误码：%d（%s）\n", err, err == OK ? "成功" : "失败");

    return 0;
}
