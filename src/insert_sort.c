#include "insert_sort.h"
#include "common.h"


/**
 * @brief 插入排序函数
 *
 * @param data  待排序数组指针
 * @param n     数组长度
 * @param order 排序方式，SORT_ASC 升序，SORT_DESC 降序
 */
void insert_sort(int* data, int n, int order)
{
    int i, j = 0;
    int temp = 0;

    // 外层循环，从数组的第二个元素开始
    // 因为第一个元素默认是有序的
    for(i = 1; i < n; i++)
    {
        temp = data[i];  // 保存当前待插入的元素
        j = i - 1;       // j 用于扫描已排序部分，从后向前比较

        if(order == SORT_ASC) // 升序排序
        {
            // 当 j>=0 且已排序元素大于 temp 时，需要向右移动
            while (j >= 0 && data[j] > temp)
            {
                data[j+1] = data[j]; // 将 data[j] 向右移动
                j--;                 // 继续向左比较
            }
        }
        else // 降序排序
        {
            // 当 j>=0 且已排序元素小于 temp 时，需要向右移动
            while (j >= 0 && data[j] < temp)
            {
                data[j+1] = data[j]; // 将 data[j] 向右移动
                j--;                 // 继续向左比较
            }
        }

        // 找到合适位置，将 temp 插入
        // 注意这里 j 已经减了一次，所以位置是 j+1
        data[j + 1] = temp;
    }
}
