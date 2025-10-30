#include <stdio.h>
#include <string.h>

int read_line(char s[]);

int main() 
{
    char line[1000];
    int len;

    while ((len = read_line(line)) > 0) 
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
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}