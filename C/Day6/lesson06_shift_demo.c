/*
 * D6 补充：左移运算符 << 与寄存器位操作
 *
 * 演示：
 *  1. 1 << n 的效果（二进制、十进制）
 *  2. |= (1<<n) 置1、&= ~(1<<n) 清0
 *  3. 模拟寄存器操作（用普通变量模拟 GPIOB_ODR）
 */

#include <stdio.h>

/* 打印一个 unsigned int 的二进制（32位） */
void print_bin(unsigned int v) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (v >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
}

int main() {
    printf("===== 1. 1 << n 的效果 =====\n");
    for (int n = 0; n <= 8; n++) {
        unsigned int v = (1u << n);
        printf("1 << %d = %2u   二进制: ", n, v);
        print_bin(v);
        printf("\n");
    }

    printf("\n===== 2. 模拟 GPIOB_ODR 寄存器操作 =====\n");
    /* 用一个 unsigned int 变量模拟 ODR 寄存器（初始全 0） */
    unsigned int ODR = 0;
    printf("初始 ODR：");
    print_bin(ODR);
    printf("\n\n");

    /* 点亮 PB0：把 bit0 置 1 */
    ODR |= (1 << 0);
    printf("PB0 置1后：");
    print_bin(ODR);
    printf("   <- bit0=1，PB0输出高(LED亮)\n");

    /* 点亮 PB5：把 bit5 置 1 */
    ODR |= (1 << 5);
    printf("PB5 置1后：");
    print_bin(ODR);
    printf("   <- bit5=1\n");

    /* 熄灭 PB0：把 bit0 清 0 */
    ODR &= ~(1 << 0);
    printf("PB0 清0后：");
    print_bin(ODR);
    printf("   <- bit0=0，PB0输出低(LED灭)\n");

    printf("\n===== 3. 关键公式 =====\n");
    printf("(1 << n)      -> 制造'只有第n位是1'的数（选中一位）\n");
    printf("|= (1 << n)   -> 把第n位置1（不影响其他位）\n");
    printf("&= ~(1 << n)  -> 把第n位清0（不影响其他位）\n");

    return 0;
}
