#include <stdio.h>

// int power(int m, int n);

// int main()
// {
//     int i;

//     for (i = 0; i < 10; i++)
//     {
//         printf("%d %d %d\n", i, power(2, i), power(-3, i));
//     }
//     return 0;
// }

// int power(int base, int n)
// {
//     int i, p;
//     p = 1;
//     for (i = 1; i <= n; ++i)
//         p = p * base;

//     return p;
// }

void fahrCelsiusTable (float low, float up, float stp);

int main()
{
    float lower, upper, step;

    lower = 0;   /* lower limit of temperatuire scale */
    upper = 300; /* upper limit */
    step = 20;   /* step size */
    fahrCelsiusTable(lower, upper, step);
    return 0;
}

void fahrCelsiusTable(float lower, float upper, float step) {
    float fahr, celsius;
    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}