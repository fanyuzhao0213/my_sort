#include "shell_sort.h"
#include "common.h"


/**
 * @brief 希尔排序函数
 *
 * @param data  待排序数组指针
 * @param n     数组长度
 * @param order 排序方式，SORT_ASC 升序，SORT_DESC 降序
 */
void shell_sort(int* data, int n, int order)
{
    int gap, i, j, temp;

    // 选择间隔序列，这里采用最简单的希尔原始序列: n/2, n/4, ..., 1
    for(gap = n / 2; gap > 0; gap /= 2)
    {
        // 对每个间隔做插入排序
        for(i = gap; i < n; i++)
        {
            temp = data[i];
            j = i;

            if(order == SORT_ASC)
            {
                // 对间隔序列内元素进行升序排序
                while(j >= gap && data[j - gap] > temp)
                {
                    data[j] = data[j - gap];  // 向右移动元素
                    j -= gap;
                }
            }
            else // SORT_DESC
            {
                // 对间隔序列内元素进行降序排序
                while(j >= gap && data[j - gap] < temp)
                {
                    data[j] = data[j - gap];  // 向右移动元素
                    j -= gap;
                }
            }

            data[j] = temp; // 插入到合适位置
        }
    }
}