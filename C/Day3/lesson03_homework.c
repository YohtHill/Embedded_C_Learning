#include<stdio.h>

void print_multiplication_table(int n);   // ① 函数声明（告诉编译器有这个函数）
void SumUptoN(int n);

int main() {
    //print_multiplication_table(9);        // ② main 先调用
    SumUptoN(100);  // 调用求和函数
    return 0;
}

//Task 1
void print_multiplication_table(int n) {  // ③ 函数定义（具体实现放后面）
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d*%d=%-4d", j, i, i * j);
        }
        printf("\n");
    }
}

// task 2
void SumUptoN(int n)
{
    int sum =0;
    for (int i = 1; i<=n;i++)
    {
        sum = i*(i+1)/2;
    }
    printf("1+2+...+%d = %d\n", n, sum);
}

// task 3