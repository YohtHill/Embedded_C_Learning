#include<stdio.h>
typedef struct student
{
    char name[20];
    int id;
    float score;
}student_t;

void change_by_value(student_t s) {
    s.score = 100;      // 改副本
}

void change_by_pointer(student_t *ps) {
    ps->score = 100;    // 改真变量
}

int main()
{
    student_t S1 = {"Zhangsan",2024001,88.5};
    printf("初始: 姓名:%s 学号:%d 成绩:%.1f\n",S1.name,S1.id,S1.score);

    /* 测试1：按值传递（应改不到）*/
    change_by_value(S1);
    printf("值传递后成绩: %.1f（不变，因为改的是副本）\n", S1.score);

    /* 测试2：按指针传递（应改到）*/
    change_by_pointer(&S1);
    printf("指针传递后成绩: %.1f（变了，因为改的是真变量）\n", S1.score);

    return 0;
    //如果把整个结构体传给函数（按值传递），函数里改 score，main 里的会变吗？为什么？
    //不会变，因为传给函数的是结构体的副本，函数里改的是副本的 score，main 里的 S1.score 不会变。
}