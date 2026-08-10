/*
 * D5：数组、冒泡排序、找最大值
 * —— 嵌入式最常用的数据结构
 *
 * 嵌入式场景：
 *  - 存一串 ADC 采样值：unsigned short samples[100];
 *  - 存串口收到的数据：unsigned char rx_buffer[64];
 *  - 存温度历史记录做平均
 */

#include <stdio.h>

/* ========== 找最大值和它的下标 ========== */
int find_max(int arr[], int size) {
    int max = arr[0];       /* 先假设第一个是最大 */
    int max_index = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_index = i;
        }
    }
    printf("最大值 = %d，下标 = %d\n", max, max_index);
    return max;
}

/* ========== 冒泡排序（从小到大）========== */
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {      /* 外层：需要比较几轮 */
        for (int j = 0; j < size - 1 - i; j++) { /* 内层：每轮比较相邻的 */
            if (arr[j] > arr[j + 1]) {         /* 前 > 后，就交换 */
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/* ========== 打印数组 ========== */
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("===== 1. 数组的基本使用 =====\n");
    int arr[5] = {10, 20, 30, 40, 50};   /* 声明5个int的数组并初始化 */
    printf("第1个元素 arr[0] = %d\n", arr[0]);
    printf("第3个元素 arr[2] = %d\n", arr[2]);
    printf("数组长度 = %d\n", (int)(sizeof(arr) / sizeof(arr[0])));

    printf("\n===== 2. 数组名 = 首地址（和指针的关系！）=====\n");
    printf("arr 本身       = %p (数组首地址)\n", (void*)arr);
    printf("&arr[0]        = %p (第一个元素地址)\n", (void*)&arr[0]);
    printf("两者相同 → 数组名就是首地址\n");
    printf("*(arr+2) = %d（指针访问元素，等价于 arr[2]）\n", *(arr + 2));

    printf("\n===== 3. 找最大值 =====\n");
    int data[] = {34, 7, 23, 32, 5, 62, 31};
    int size = sizeof(data) / sizeof(data[0]);
    print_array(data, size);
    find_max(data, size);

    printf("\n===== 4. 冒泡排序 =====\n");
    int unsorted[] = {34, 7, 23, 32, 5, 62, 31};
    int n = sizeof(unsorted) / sizeof(unsorted[0]);
    printf("排序前：");
    print_array(unsorted, n);
    bubble_sort(unsorted, n);
    printf("排序后：");
    print_array(unsorted, n);

    return 0;
}
