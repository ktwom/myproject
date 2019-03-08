
#include <stdio.h>
#include <string.h>

char *get_two_jz(int a) {

    char *str;
    int str_len;
    while (a) {
        if (a % 2 == 1)
            strcat(str, "1");
        else
            strcat(str, "0");
        a = a / 2;
    };
    return str;
}

int main() {
    int num;
    printf("Content-Type: text/html\n\n");
    printf("请输入一个数字:");
    scanf("%d", &num);
    printf("%c\n", get_two_jz(num));
    return 0;
}
