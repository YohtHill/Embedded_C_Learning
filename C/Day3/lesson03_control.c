/*
 * D3：流程控制 if / for / while
 * —— 程序如何"做决定"和"重复做事"
 *
 * 嵌入式里无处不在：
 *  - if：判断按键是否按下、温度是否超限、串口是否有数据
 *  - for/while：循环采样、定时轮询、延时
 */

#include <stdio.h>

int main() {
    printf("===== 1. if / else if / else =====\n");
    int temp = 85;   /* 模拟温度 85 度 */

    if (temp > 100) {
        printf("温度过高，报警！\n");
    } else if (temp > 60) {
        printf("温度偏高，注意散热\n");
    } else {
        printf("温度正常\n");
    }

    printf("\n===== 2. for 循环（1~10）=====\n");
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n");
    /* for 的三部分：初始化; 条件; 每次迭代后做啥 */

    printf("\n===== 3. while 循环（1~10）=====\n");
    int j = 1;
    while (j <= 10) {
        printf("%d ", j);
        j++;          /* 别忘了让 j 变大，否则死循环！ */
    }
    printf("\n");

    printf("\n===== 4. do-while（至少执行一次）=====\n");
    int k = 1;
    do {
        printf("%d ", k);
        k++;
    } while (k <= 5);
    printf("\n");

    printf("\n===== 5. break / continue =====\n");
    for (int m = 1; m <= 10; m++) {
        if (m == 3) continue;   /* 跳过 3，不打印 */
        if (m == 8) break;      /* 到 8 就退出循环 */
        printf("%d ", m);
    }
    printf("\n");
    printf("（跳过3，到8停止）\n");

    printf("\n===== 6. 1~100 求和（for 循环法）=====\n");
    int sum = 0;
    for (int n = 1; n <= 100; n++) {
        sum += n;
    }
    printf("1+2+...+100 = %d\n", sum);

    printf("\n===== 7. 1~100 求和（公式法）=====\n");
    int sum2 = 100 * (100 + 1) / 2;   /* 等差数列公式 n(n+1)/2 */
    printf("公式 = %d\n", sum2);

    return 0;
}
