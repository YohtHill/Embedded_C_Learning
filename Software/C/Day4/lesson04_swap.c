/*
 * D4：函数与参数传递（swap 陷阱）
 * —— 为指针打基础！
 *
 * 今天的核心问题：
 *   写一个 swap 函数想交换两个数，
 *   你会发现……交换不了！
 *   搞清楚为什么，就理解了 C 语言的"值传递"。
 */

#include <stdio.h>

/* ========== 版本 1：尝试交换（你会发现失败！）========== */
void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    /* 这里的交换只发生在 swap 内部的"副本"上 */
}

/* ========== 版本 2：用指针，真正交换！========== */
/* int *pa 表示：pa 里存的是"一个 int 变量的地址" */
/* *pa 表示：顺着地址，找到那个 int 变量 */
void swap_by_pointer(int *pa, int *pb) {
    int temp = *pa;   /* 读出地址 pa 指向的值（也就是 x） */
    *pa = *pb;        /* 把 y 的值写入 x 的地址 */
    *pb = temp;       /* 把原 x 的值写入 y 的地址 */
}

int main() {
    printf("===== 版本 1：swap(a, b) 按值传递 =====\n");
    int x = 5, y = 10;
    printf("交换前：x = %d, y = %d\n", x, y);
    swap(x, y);
    printf("交换后：x = %d, y = %d  <- 没变！为什么？\n", x, y);

    printf("\n===== 用内存地址看原因 =====\n");
    printf("&x = %p (x 的内存地址)\n", (void*)&x);
    printf("&y = %p (y 的内存地址)\n", (void*)&y);

    printf("\n===== 版本 2：swap_by_pointer(&x, &y) 传地址 =====\n");
    printf("再次交换前：x = %d, y = %d\n", x, y);
    swap_by_pointer(&x, &y);   /* 传 x、y 的地址 */
    printf("交换后：x = %d, y = %d  <- 这次真的交换了！\n", x, y);

    return 0;
}
