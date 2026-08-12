/*
 * D2：运算符与类型转换
 * —— 嵌入式里最容易出错的坑！
 *
 * 重点实验：
 *  1. 5/2、5/2.0、5.0/2 的区别（整数除法 vs 浮点除法）
 *  2. char c = 300 会发生什么（溢出）
 *  3. 常见的算术/关系/逻辑运算符
 */

#include <stdio.h>

int main() {
    printf("===== 1. 整数除法 vs 浮点除法 =====\n");

    int a = 5 / 2;          /* 两个整数相除 → 结果也是整数，5/2=2（舍去小数） */
    printf("int a = 5/2   = %d\n", a);      /* 结果是 2，不是 2.5！ */

    float b = 5 / 2;        /* 注意：先算 5/2=2（整数），再存进 float → 2.0 */
    printf("float b = 5/2 = %.1f\n", b);    /* 结果是 2.0，不是 2.5！ */

    float c = 5 / 2.0;      /* 有 2.0（浮点）参与，整个除法按浮点算 → 2.5 */
    printf("float c = 5/2.0 = %.1f\n", c);  /* 结果是 2.5 ✅ */

    float d = 5.0 / 2;      /* 同理，5.0 是浮点 → 2.5 */
    printf("float d = 5.0/2 = %.1f\n", d);  /* 结果是 2.5 ✅ */

    printf("\n===== 2. 类型溢出实验 =====\n");

    char e = 300;           /* char 只能存 -128~127，300 放不下 → 溢出！ */
    printf("char e = 300，实际存的是 %d\n", e);
    printf("  解释：300 在内存里是 0x012C，截断成 char 取低 8 位 = 0x2C = 44\n");
    printf("  所以 e 实际 = 44\n");

    unsigned char f = 300;  /* unsigned char 范围 0~255，300 也放不下 */
    printf("unsigned char f = 300，实际存的是 %u\n", f);
    printf("  300 取低 8 位 = 0x2C = 44\n");

    printf("\n===== 3. 常见运算符速览 =====\n");
    int x = 10, y = 3;
    printf("10 + 3 = %d\n", x + y);
    printf("10 - 3 = %d\n", x - y);
    printf("10 * 3 = %d\n", x * y);
    printf("10 / 3 = %d（整数除法）\n", x / y);
    printf("10 %% 3 = %d（取余数）\n", x % y);

    printf("10 > 3 : %d（1=真, 0=假）\n", x > y);
    printf("10 == 3: %d\n", x == y);

    printf("(10>3) && (10>5) = %d（与）\n", (x > y) && (x > 5));
    printf("(10<3) || (10>5) = %d（或）\n", (x < y) || (x > 5));

    return 0;
}
