#include <stdio.h>
#include <string.h>

int read_line(char s[]) 
{
    int c, i = 0;

    while ((c = getchar()) != EOF && c != '\n') 
    {
        FIXME; //再写一次
    }
    s[i] = '\0';
    return FIXME;
}

void reverse(char s[]) //当然也可以直接在main中由索引从后往前打印, 这样就不需要reverse这个函数了
{
    int i = 0, j = (int)strlen(s) - 1; //(int)strlen(s)是一个很有用的东西，刷leetcode什么的时候还挺常用的，以后找实习或许会用（但现在很多似乎也不考算法题了）
    //这里我想的是不创建新的数组，直接在s上进行交换。所以其实也可以用一个新的数组来存储反转后的结果
    while (i < j) 
    {
        char t = s[i];
        FIXME; //类似于交换两数的思想
        i++;
        FIXME; //j怎么更新？
    }
}

int main() {
    char line[1000];
    int len;

    while ((len = read_line(line)) > 0) {
        FIXME; //调用反转函数
        for (FIXME) //遍历字符串直到结束符
        {
            printf("%c", line[i]);
        }
        printf("\n");
    }
    return 0;
}