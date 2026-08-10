/*
 * D6：字符串 —— 自己实现 strlen / strcpy / strcat
 *
 * 核心概念：
 *  - 字符串 = 字符数组，以 '\0'（空字符，值为0）结尾
 *  - "Hello" 实际占 6 个字节：H e l l o \0
 *  - 操作字符串就是遍历字符数组，遇到 '\0' 停
 *
 * 练习要求：先不看库源码，自己实现下面三个函数！
 */

#include <stdio.h>

/* ========== 练习 1：自己实现 strlen（求字符串长度）========== */
/* 思路：从开头数，数到 '\0' 为止（不含 '\0'）*/
int my_strlen(const char *s) {
    /* TODO: 在这里实现 */
    int len = 0;
    while(s[len] != '\0')
    {
        len++;
    }
    /* 提示：int len = 0; while (s[len] != '\0') len++; return len; */
    return len;
}

/* ========== 练习 2：自己实现 strcpy（字符串拷贝）========== */
/* 思路：把 src 的每个字符（含'\0'）复制到 dest */
void my_strcpy(char *dest, const char *src) {
    /* TODO: 在这里实现 */
    int i = 0;
    while(src[i] !='\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    /* 提示：int i = 0; while (src[i] != '\0') { dest[i]=src[i]; i++; } dest[i]='\0'; */
}

/* ========== 练习 3：自己实现 strcat（字符串拼接）========== */
/* 思路：先走到 dest 的末尾('\0')，然后把 src 接在后面 */
void my_strcat(char *dest, const char *src) {
    /* TODO: 在这里实现 */
    int i = 0;
    int j = 0;
    while(dest[i] !='\0')
    {
        i++;
    }
    /* 提示：先找 dest 结尾，再复制 src */
    while(src[j]!='\0')
    {
        dest[i+j] = src[j];
        j++;
    }
    dest[i+j] = '\0';
}

int main() {
    /* ========== 先理解字符串本质 ========== */
    printf("===== 字符串本质 =====\n");
    char str[] = "Hello";
    printf("字符串: %s\n", str);
    printf("str[0]=%c str[4]=%c\n", str[0], str[4]);
    printf("str[5]='\\0'(结束符)，所以字符串长度=5\n\n");

    /* ========== 测试我的 strlen ========== */
    printf("===== 测试 my_strlen =====\n");
    printf("my_strlen(\"Hello\") = %d (应该是5)\n", my_strlen("Hello"));
    printf("my_strlen(\"embedded\") = %d (应该是8)\n", my_strlen("embedded"));
    printf("my_strlen(\"\") = %d (应该是0)\n", my_strlen(""));

    /* ========== 测试我的 strcpy ========== */
    printf("\n===== 测试 my_strcpy =====\n");
    char buf1[32];
    my_strcpy(buf1, "Hello World");
    printf("拷贝结果: %s\n", buf1);

    /* ========== 测试我的 strcat ========== */
    printf("\n===== 测试 my_strcat =====\n");
    char buf2[32] = "Hello ";
    my_strcat(buf2, "World!");
    printf("拼接结果: %s\n", buf2);

    return 0;
}
