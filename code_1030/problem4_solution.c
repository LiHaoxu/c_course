#include <stdio.h>
#include <string.h>

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

void reverse(char s[])
{
    int i = 0, j = (int)strlen(s) - 1; 
    while (i < j) 
    {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++; 
        j--;
    }
}

int main() 
{
    char line[1000];
    int len;

    while ((len = read_line(line)) > 0) 
    {
        reverse(line);
        for (int i = 0; line[i] != '\0'; i++) 
        {
            printf("%c", line[i]);
        }
        printf("\n");
    }
    return 0;
}