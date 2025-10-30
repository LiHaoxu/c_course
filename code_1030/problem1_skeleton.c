#include <stdio.h>

double celsius_to_fahrenheit(double celsius) 
{
    FIXME; //返回摄氏度转换为华氏度的结果
}

int main() 
{
    double celsius;
    printf("摄氏度\t华氏度\n");
    printf("-----------------\n");
    for (celsius = 0; celsius <= 300; celsius += 20) 
    {
        printf("%.1f\t%.1f\n", celsius, FIXME); //调用转换函数
    }
    return 0;
}