/*
 * 第 2 课：变量与数据类型
 * —— 嵌入式开发的基石
 *
 * 嵌入式开发里，理解每种类型占多少字节、能存多大范围，非常重要！
 * 因为单片机的 RAM 和 Flash 都非常小（几 KB 到几百 KB），
 * 选错类型会浪费宝贵的内存。
 */

#include <stdio.h>

int main() {
    /* ============ 1. 有符号整数类型 ============ */
    char   a = 100;      /* 1 字节：-128 ~ 127      */
    short  b = 30000;    /* 2 字节：-32768 ~ 32767  */
    int    c = 100000;   /* 4 字节：约 ±21 亿       */
    long   d = 1000000;  /* 4 字节（Windows）       */

    /* ============ 2. 无符号类型（嵌入式最常用！） ============ */
    unsigned char  e = 200;   /* 1 字节：0 ~ 255（存寄存器值/字节数据） */
    unsigned short f = 60000; /* 2 字节：0 ~ 65535                     */
    unsigned int   g = 4000000000u; /* 4 字节：0 ~ 约 42 亿           */

    /* ============ 3. 小数类型 ============ */
    float  h = 3.14f;   /* 4 字节：单精度（ADC 电压换算常用） */
    double i = 3.14159; /* 8 字节：双精度                     */

    /* ============ 输出各种类型的值 ============ */
    printf("a = %d\n", a);            /* %d 打印有符号整数 */
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("d = %ld\n", d);           /* %ld 打印 long */
    printf("e = %u\n", e);            /* %u 打印无符号整数 */
    printf("f = %u\n", f);
    printf("g = %u\n", g);
    printf("h = %.2f\n", h);          /* %.2f 保留2位小数 */
    printf("i = %.5f\n", i);

    /* ============ 4. 用 sizeof 查看各类型占用的字节数 ============ */
    /* sizeof 是一个运算符，返回类型或变量占用的字节数，单位是字节 */
    printf("\n===== 各类型占用字节数 =====\n");
    printf("char           : %zu 字节\n", sizeof(char));
    printf("short          : %zu 字节\n", sizeof(short));
    printf("int            : %zu 字节\n", sizeof(int));
    printf("long           : %zu 字节\n", sizeof(long));
    printf("unsigned char  : %zu 字节\n", sizeof(unsigned char));
    printf("unsigned short : %zu 字节\n", sizeof(unsigned short));
    printf("unsigned int   : %zu 字节\n", sizeof(unsigned int));
    printf("float          : %zu 字节\n", sizeof(float));
    printf("double         : %zu 字节\n", sizeof(double));

    /* 也可以直接对变量名用 sizeof */
    printf("\n===== 对变量用 sizeof =====\n");
    printf("变量 a (char)          : %zu 字节\n", sizeof(a));
    printf("变量 e (unsigned char) : %zu 字节\n", sizeof(e));
    printf("变量 h (float)         : %zu 字节\n", sizeof(h));

    /* ============ 5. 对数组用 sizeof ============ */
    unsigned char buffer[64];
    printf("\n===== 数组的 sizeof =====\n");
    printf("buffer : %zu 字节\n", sizeof(buffer));

    int x;
    printf("变量 x (int) : %zu 字节\n", sizeof(x));

    return 0;
}
