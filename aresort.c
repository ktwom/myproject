//
// Created by Administrator on 2019/3/8.
//

#include <stdio.h>

int main() {

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int t, i;
    printf("原始数组是:\n");
    for (i = 0; i < 10; ++i) {
        printf("%d,", arr[i]);
        if (i == 9)
            printf("\n");
    }
    for (i = 0; i < 10 / 2; ++i) {
        t = arr[i];
        arr[i] = arr[10 - i - 1];
        arr[10 - i - 1] = t;
    }
    printf("倒序之后的数组是:\n");
    for (i = 0; i < 10; ++i) {
        printf("%d,", arr[i]);
        if (i == 9)
            printf("\n");
    }
}