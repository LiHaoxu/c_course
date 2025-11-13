// 假设 $maxn$ 是单词中出现次数最多的字母的出现次数，$minn$ 是单词中出现次数最少的字母的出现次数，如果 $maxn−minn$ 是一个质数，那这个单词就是一个 Lucky Word。
// 输入是多行，每行一个单词，其中只可能出现小写英文字母，并且每个单词长度小于 $200$。
// 输出行数和输入一样。每一行有两部分，由一个空格隔开：
// 第一部分是一个字符串，假设输入的单词是 Lucky Word，那么输出 `Lucky Word`，否则输出 `No Answer`；
// 第二行是一个整数，如果输入的单词是 Lucky Word，输出 $maxn−minn$ 的值，否则不输出。
// 提示：小写英文字母的类别是有限的，可以使用数组存储每个字母的出现次数

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define MAX_LEN 200

bool is_prime(int n) {
//TODO: 判断质数
}

void check_lucky_word(const char *word) {
    int freq[26] = {0}; // frequency array for 'a' to 'z'
    int len = strlen(word);

//TODO: 计算出现次数并记录在freq[26]中


    int maxn = 0, minn = MAX_LEN + 1; // Initialize maxn and minn
    for (int i = 0; i < 26; ++i) {
//TODO: 计算maxn和minn
    }

    int diff = maxn - minn;
    if (FIXME) {
        printf("Lucky Word %d\n", diff);
    } else {
        printf("No Answer\n");
    }
}

int main() {
    char word[MAX_LEN + 1];
    while (scanf("%s", word) != EOF) {
//TODO: 调用函数
    }
    return 0;
}