//
// Created by Administrator on 2019/3/7.
//

#include <stdio.h>

int main() {

    char c;
    int nums = 0, letters = 0, spaces = 0, others = 0;
    printf("请输入一些字符串:\n");
    while ((c = getchar()) != '\n') {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            letters++;
        else if (c >= '0' && c <= '9')
            nums++;
        else if (c == ' ')
            spaces++;
        else
            others++;
    }
    printf("您输入的字符串中含有数字:%d,字母:%d,空格:%d,其他:%d", nums, letters, spaces, others);
}