#include<stdio.h>
void Average_Temperature(int arr[], int size);
void Bubble_Sort_Downward(int arr[], int size);

int main()
{
    int arr[7] = {25, 28, 26, 30, 27, 29, 31};
    int Arr[8] = {3, 1, 4, 1, 5, 9, 2, 6};
    Average_Temperature(arr, 7);
    Bubble_Sort_Downward(Arr, 8);

    return 0;
}

void Average_Temperature(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    int average = sum / size;
    printf("一周的平均温度为：%d\n", average);
}

void Bubble_Sort_Downward(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-1-i; j++)
        {
            if(arr[j] < arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("降序排序后的数组为：");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}