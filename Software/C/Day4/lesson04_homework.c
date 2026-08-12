/*
 * D4 练习：用指针让 main 里的变量真的翻倍
 *
 * 练习目标：
 *  1. 写一个 double_it 函数，用指针把变量的值乘 2
 *  2. 在 main 里调用，验证 main 里的变量真的变了
 *  3. 对比：如果不用指针，main 里的值会不会变？为什么？
 */

#include <stdio.h>

void double_it(int *pa)
{
    *pa = *pa *2;
}
void fake_double_it(int a)
{
    a = a*2;
}

int main()
{
    int x = 5;
    int y = 10;
    int a = 5;
    int b =10;
    printf("调用真函数前，x = %d , y = %d\n",x,y);
    printf("调用假函数前，x = %d , y = %d\n",a,b);
    double_it(&x);
    double_it(&y);
    fake_double_it(a);
    fake_double_it(b);
    printf("调用真函数后，x = %d , y = %d\n",x,y);
    printf("调用假函数后，x = %d , y = %d\n",a,b);
    return 0;
}