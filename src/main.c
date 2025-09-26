#include <stdio.h>
#include "common.h"

#include "bubble_sort.h"
#include "select_sort.h"
#include "insert_sort.h"
#include "shell_sort.h"
#include "quick_sort.h"

/* =================== 工具函数：打印数组 =================== */
void print_array(int *arr, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// #define TEST_BUBBLE_SORT                 //冒泡排序
// #define TEST_SELECT_SORT                 //选择排序
// #define TEST_INSERT_SORT                 //插入排序
// #define TEST_SHELL_SORT                     //希尔排序 （插入排序的一种改进版本）
#define TEST_QUICK_SORT                     //快速排序
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 112, 23, 12, 1, 34, 11, 23, 12345, 9999,111,222,333,444,555,666,777,888,999,1000};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("before sort arr:");
    print_array(arr, n);

    // 升序排序
    #ifdef TEST_BUBBLE_SORT
    bubble_sort(arr, n, SORT_ASC);
    #endif
    #ifdef TEST_SELECT_SORT
    selection_sort(arr, n, SORT_ASC);
    #endif
    #ifdef TEST_INSERT_SORT
    insert_sort(arr, n, SORT_ASC);
    #endif
    #ifdef TEST_SHELL_SORT
    shell_sort(arr, n, SORT_ASC);
    #endif
    #ifdef TEST_QUICK_SORT
    quick_sort(arr, 0, n - 1, SORT_ASC);
    #endif
    printf("Sorted array (ASC):");
    print_array(arr, n);

    // 升序排序
    #ifdef TEST_BUBBLE_SORT
    bubble_sort(arr, n, SORT_DESC);
    #endif
    #ifdef TEST_SELECT_SORT
    selection_sort(arr, n, SORT_DESC);
    #endif
    #ifdef TEST_INSERT_SORT
    insert_sort(arr, n, SORT_DESC);
    #endif
    #ifdef TEST_SHELL_SORT
    shell_sort(arr, n, SORT_DESC);
    #endif
    #ifdef TEST_QUICK_SORT
    quick_sort(arr, 0, n - 1, SORT_DESC);
    #endif


    printf("Sorted array (DESC):");
    print_array(arr, n);

    return 0;
}