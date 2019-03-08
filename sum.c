//
// Created by Administrator on 2019/3/8.
//

#include <stdio.h>

int main() {

    float a = 2, b = 1;
    float sum = 0;
    int t;
    for (int i = 0; i < 20; ++i) {
        sum = sum + (a / b);
        t = a;
        printf("======================\n");
        printf("%f\n",sum);
        printf("%d\n",a);
        printf("%d\n",b);
        printf("%d\n",t);
        printf("=======================\n");
        a = a + b;
        b = t;
    }
    printf("得到的结果是:%9.6f\n", sum);
}