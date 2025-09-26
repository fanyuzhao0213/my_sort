#include "quick_sort.h"
#include "common.h"


/* ===================== 交换函数 ===================== */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* ===================== 分区函数 =====================
 * 选择中间元素作为基准值 (pivot)
 * @param data  待排序数组
 * @param low   左边界索引
 * @param high  右边界索引
 * @param order 排序方式
 * @return pivot 位置
 */
int partition(int* data, int low, int high, int order)
{
    int mid = low + (high - low) / 2;  // 取中间元素索引
    int pivot = data[mid];             // 中间值作为基准

    int i = low;
    int j = high;

    while (i <= j) {
        if (order == SORT_ASC) {
            // 升序：左边找 >= pivot 的元素，右边找 <= pivot 的元素
            while (data[i] < pivot) i++;
            while (data[j] > pivot) j--;
        } else {
            // 降序：左边找 <= pivot 的元素，右边找 >= pivot 的元素
            while (data[i] > pivot) i++;
            while (data[j] < pivot) j--;
        }

        if (i <= j) {
            swap(&data[i], &data[j]); // 交换左右不符合条件的值
            i++;
            j--;
        }
    }
    return i; // 返回分割点
}

/* ===================== 快速排序递归函数 ===================== */
void quick_sort(int* data, int low, int high, int order)
{
    if (low < high) {
        int index = partition(data, low, high, order);

        // 递归处理左半部分
        if (low < index - 1)
            quick_sort(data, low, index - 1, order);

        // 递归处理右半部分
        if (index < high)
            quick_sort(data, index, high, order);
    }
}
