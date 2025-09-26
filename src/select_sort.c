#include "select_sort.h"
#include "common.h"

/**
 * @brief 选择排序实现
 * @param arr   数组指针
 * @param n     数组长度
 * @param order 排序顺序 (SORT_ASC升序, SORT_DESC降序)
 */
void selection_sort(int arr[], int n, int order)
{
    int i,j = 0;
    int target_index = 0;
    int temp = 0;

    // 外层循环控制已排序和未排序区域
    for (i = 0; i < n - 1; i++) {
        int target_index = i; // 假设第一个元素为最小或最大

        // 在未排序区域中寻找最小值或最大值的位置
        for (j = i + 1; j < n; j++) {
            int condition = (order == SORT_ASC) ? (arr[j] < arr[target_index]) : (arr[j] > arr[target_index]);
            if (condition) {
                target_index = j;
            }
        }

        // 如果找到的目标值位置不是当前位置，则交换
        if (target_index != i) {
            int temp = arr[i];
            arr[i] = arr[target_index];
            arr[target_index] = temp;
        }
    }
}

