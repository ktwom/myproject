//
// Created by Administrator on 2019/3/8.
//

#include <stdio.h>
#include <math.h>

int main() {
    int i, j, k;
    int th;
    for (int i = 1; i < 101; ++i) {
        th = 0;
        k = (int) sqrt(i);
        for (int j = 2; j <= k; ++j) {
            if (i % j == 0) {
                th = 1;
                break;
            }
        }
        if (th == 0)
            printf("%d\n", i);
    }
}
