#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

int read_line(char s[]) 
{
    int c, i = 0;

    while ((c = getchar()) != EOF && c != '\n') 
    {
        FIXME;
    }
    s[i] = '\0';
    return FIXME;
}

int main() 
{
    char line[MAXLEN];
    char longest[MAXLEN];
    int len, maxlen = FIXME;

    while ((len = read_line(line)) > 0) 
    {
        if (len > maxlen) 
        {
            FIXME; 
            strcpy(FIXME);//上次实验课讲过的字符串复制函数的用法
        }
    }

    printf("%s\n", FIXME);
    return 0;
}