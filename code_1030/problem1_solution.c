#include <stdio.h>

double celsius_to_fahrenheit(double celsius) 
{
    return (9.0 / 5.0) * celsius + 32.0;
}

int main() 
{
    double celsius;
    printf("摄氏度\t华氏度\n");
    printf("-----------------\n");
    for (celsius = 0; celsius <= 300; celsius += 20) 
    {
        printf("%.1f\t%.1f\n", celsius, celsius_to_fahrenheit(celsius));
    }
    return 0;
}