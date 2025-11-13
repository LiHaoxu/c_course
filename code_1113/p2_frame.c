// 本题要求实现一个判断质数的简单函数，并利用该函数验证哥德巴赫猜想。
// 输入每行一个不小于6的偶数 $n < 200000$
// 输出每行两个奇素数 $a, b$，两者之和为 $n$ 且是所有满足这种可能的奇素数对中 $a$ 最小的一对，中间用空格分开。
// 若找不到这种奇素数对，输出 `No Answer` 代替。

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX_N 200000

bool is_prime(int n) {
//TODO: 判断是否是质数（可以欧几里得除法，也可以用最笨的试除法）
}

void check_goldbach(int n) {
    if (n < 6 || n % 2 != 0 || n >= MAX_N) {
        printf("No Answer\n");
        return;
    }

//TODO: 寻找两个奇素数 a 和 b，使得 a + b = n，并输出它们
    printf("No Answer\n");

    return;
}

int main(void) {
    int n;
    while (scanf("%d", &n) == 1) {
//TODO: 调用函数
    }
    return 0;
}