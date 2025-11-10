#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

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

int main() 
{
    char line[MAXLEN];
    char longest[MAXLEN];
    int len, maxlen = 0;

    while ((len = read_line(line)) > 0) 
    {
        if (len > maxlen) 
        {
            maxlen = len;
            strcpy(longest, line);
        }
    }

    printf("%s\n", longest);
    return 0;
}