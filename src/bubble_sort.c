#include "bubble_sort.h"
#include "common.h"


/**
 * @brief 冒泡排序
 * @param data 要排序的数组
 * @param n 数组大小
 * @param order 排序方式：SORT_ASC 升序，SORT_DESC 降序
 */
void bubble_sort(int arr[], int n, int order)
{
    int i, j;
    int temp;
    bool swapped;  // 标志位，用于优化

    /* 外层循环控制排序趟数 */
    for (i = 0; i < n - 1; i++)
    {
        swapped = false; // 每轮开始前置为false

        /* 内层循环控制比较与交换 */
        for (j = 0; j < n - 1 - i; j++)
        {
            bool need_swap = false;

            if (order == SORT_ASC) // 升序
            {
                if (arr[j] > arr[j + 1])
                    need_swap = true;
            }
            else // 降序
            {
                if (arr[j] < arr[j + 1])
                    need_swap = true;
            }

            if (need_swap)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true; // 本轮发生了交换
            }
        }

        // 如果一趟下来没有交换，说明数组已经有序，提前结束
        if (!swapped)
            break;
    }
}
