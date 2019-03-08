//
// Created by Administrator on 2019/3/8.
//

#include <stdio.h>

int main() {

    int arr[] = {22, 44};
    int len= sizeof(arr)/sizeof(arr[0]);
    printf("%d\n",len);
    int arr2[len];
    for (int i = 0; i < len; ++i) {
        arr2[i] = arr[len-i-1];
    }
    printf("new arr:\n");
    for (int j = 0; j < len; ++j) {
        printf("%d,", arr2[j]);
    }
}