#include <stdio.h>
#include <string.h>

int read_line(char s[]); //函数要在main前声明

int main() 
{
    char line[1000];
    int len;

    while (FIXME) //当输入只有EOF或者回车时结束
    {
        printf("%d\n", len);
    }
    return 0;
}

int read_line(char s[]) 
{
    int c, i = 0;

    while ((c = getchar()) != EOF && c != '\n') 
    {
        FIXME; //将字符存入数组并更新索引
    }
    s[i] = '\0'; //表示字符串结束符
    return FIXME; //返回字符串长度
}