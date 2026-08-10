/*
 * D7：复盘 —— 不看旧代码，凭记忆重写！
 *
 * 规则：不要翻看 Day1~Day6 的代码，凭记忆独立完成下面 5 个任务。
 * 每个任务都是前 6 天学过的核心内容。
 *
 * 写完后编译运行，检查输出是否正确。
 */

#include <stdio.h>

/* ========== 任务 1：变量与类型（D1）========== */
/* 声明三个变量：温度(25)、计数(5000)、电压(3.3)，用合适的类型，并打印 */
void task1_variables() {
    /* TODO: 在这里写 */
    int temperature = 25; 
    int count = 5000;
    float voltage = 3.3f;
    printf("温度 = %d, 计数 = %d, 电压 = %.1f\n", temperature, count, voltage);
}

/* ========== 任务 2：整数除法与溢出（D2）========== */
/* 打印 5/2、5/2.0、char c=300 的值，并打印注释说明为什么 */
void task2_operator() {
    /* TODO: 在这里写 */
    printf("5/2 = %d\n", 5/2); // 整数除法，结果为2
    printf("5/2.0 = %f\n",5/2.0); // 浮点除法，结果为2.5
    char c = 300; // char类型范围是-128到127，300会溢出
    printf("char c = %d\n",c); // 输出结果为44，因为300-256=44
}

/* ========== 任务 3：流程控制（D3）========== */
/* 打印九九乘法表 */
void task3_multiplication_table() {
    /* TODO: 在这里写 */
    for(int i = 1; i<10; i++)
    {
        for(int j = 1; j<=i; j++)
        {
            printf("%d * %d = %-4d", i,j,i*j);
        }
        printf("\n");
    }
}

/* ========== 任务 4：指针交换（D4）========== */
/* 写一个用指针交换两个 int 的函数，并在 main 里验证 */
void swap_by_pointer(int *pa, int *pb) {
    /* TODO: 在这里写 */
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

/* ========== 任务 5：数组 + 最大值（D5）========== */
/* 找数组 {34, 7, 23, 32, 5, 62, 31} 的最大值和下标 */
void task5_find_max() {
    /* TODO: 在这里写 */
    int arr[] = {34, 7, 23, 32, 5, 62, 31};
    int size = sizeof(arr)/sizeof(arr[0]);
    int max = arr[0];
    int max_index = 0;
    for(int i = 1; i<size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            max_index = i;
        }
    }
    printf("最大值 = %d，下标 = %d\n", max, max_index);

}

int main() {
    printf("===== 复盘任务开始 =====\n\n");

    printf("--- 任务1：变量与类型 ---\n");
    task1_variables();

    printf("\n--- 任务2：整数除法与溢出 ---\n");
    task2_operator();

    printf("\n--- 任务3：九九乘法表 ---\n");
    task3_multiplication_table();

    printf("\n--- 任务4：指针交换 ---\n");
    int x = 5, y = 10;
    printf("交换前 x=%d, y=%d\n", x, y);
    swap_by_pointer(&x, &y);
    printf("交换后 x=%d, y=%d (应该是10,5)\n", x, y);

    printf("\n--- 任务5：找最大值 ---\n");
    task5_find_max();

    printf("\n===== 复盘完成！=====\n");
    return 0;
}
