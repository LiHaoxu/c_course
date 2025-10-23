#include <stdio.h>

/* 宏：上下界与步长 */
#define LOWER  0
#define UPPER  300
#define STEP   20

int main(void) {
    /* 表1：华氏->摄氏，按 300 -> 0 逆序 */
    printf("Fahrenheit to Celsius (descending)\n");
    printf("  F      C\n");
    for (int f = UPPER; f >= LOWER; f -= STEP) {
        double c = (f - 32) * 5.0 / 9.0;   // °C = (°F - 32) * 5/9
        printf("%4d  %6.1f\n", f, c);
    }

    putchar('\n');

    /* 表2：摄氏->华氏，同样逆序（300 -> 0） */
    printf("Celsius to Fahrenheit (descending)\n");
    printf("  C      F\n");
    for (int c = UPPER; c >= LOWER; c -= STEP) {
        double f = c * 9.0 / 5.0 + 32.0;   // °F = °C * 9/5 + 32
        printf("%4d  %6.1f\n", c, f);
    }

    return 0;
}
