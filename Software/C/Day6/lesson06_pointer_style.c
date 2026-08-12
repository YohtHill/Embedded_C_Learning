/*
 * D6 补充：字符串函数的"指针写法"详解
 *
 * 之前你用下标写法（s[len]）实现了三个函数，
 * 标准库用的是更精炼的"指针写法"（*s++）。
 * 两者完全等价，本 demo 演示指针写法并解释原理。
 */

#include <stdio.h>

/* ========== 指针写法 1：strlen ========== */
int my_strlen_ptr(const char *s) {
    int len = 0;
    while (*s != '\0') {   /* *s 读取当前字符 */
        s++;               /* s 指向下一个字符 */
        len++;
    }
    return len;
}

/* 更精炼版：把"判断+移动"合起来 */
int my_strlen_ptr2(const char *s) {
    int len = 0;
    while (*s++) {         /* ① *s 取出当前字符 ② s++ 移动指针 */
        len++;             /* 字符非'\0'就计数 */
    }
    return len;
}

/* ========== 指针写法 2：strcpy ========== */
void my_strcpy_ptr(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;      /* 复制一个字符 */
        dest++;            /* 两个指针都前移 */
        src++;
    }
    *dest = '\0';          /* 补上结束符 */
}

/* 精炼版：赋值+判断+双移动一步到位 */
void my_strcpy_ptr2(char *dest, const char *src) {
    while ((*dest++ = *src++)) ;   /* 先赋值，再判断赋值结果是否为'\0' */
    /* 当 src 是 '\0' 时，赋值后 *dest 也是'\0'，整个表达式为0，循环停止 */
}

/* ========== 指针写法 3：strcat ========== */
void my_strcat_ptr(char *dest, const char *src) {
    while (*dest != '\0') {   /* 先走到 dest 的末尾 */
        dest++;
    }
    while (*src != '\0') {    /* 再把 src 逐个接在后面 */
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

/* 简化版：拼接部分用 *dest++ = *src++ 一步到位 */
void my_strcat_ptr2(char *dest, const char *src) {
    while (*dest != '\0') {          /* ① 找 dest 末尾（这一步不能省） */
        dest++;
    }
    while ((*dest++ = *src++)) ;     /* ② 拼接：赋值+移动一步到位，'\0'自动带上 */
}

int main() {
    printf("===== 指针写法验证 =====\n");

    /* strlen */
    printf("my_strlen_ptr(\"Hello\")   = %d\n", my_strlen_ptr("Hello"));
    printf("my_strlen_ptr2(\"embedded\") = %d\n", my_strlen_ptr2("embedded"));

    /* strcpy */
    char b1[32], b2[32];
    my_strcpy_ptr(b1, "Hello World");
    my_strcpy_ptr2(b2, "Pointer Style");
    printf("my_strcpy_ptr  : %s\n", b1);
    printf("my_strcpy_ptr2 : %s\n", b2);

    /* strcat */
    char c1[32] = "Hello ";
    my_strcat_ptr(c1, "World!");
    printf("my_strcat_ptr  : %s\n", c1);

    char c2[32] = "Hello ";
    my_strcat_ptr2(c2, "World!");
    printf("my_strcat_ptr2 : %s (简化版)\n", c2);

    return 0;
}
