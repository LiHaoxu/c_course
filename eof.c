#include <stdio.h>

int main(void)

{
    int c;
    int nl = 0;
    while ((c = getchar()) != EOF) {
        printf("_%c", c);
        if (c == '\n')
            ++nl;
    }
    printf("%d\n", nl);
    return 0;
}

