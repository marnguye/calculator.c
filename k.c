#define LN10 2.3025850929940456840179914546844

double ln(double x)
{
    if (x <= 0.0)
    {
        // Logarithm is undefined for non-positive numbers
        return -1.0 / 0.0; // Return negative infinity
    }

    double result = 0.0;
    double term = (x - 1) / (x + 1);
    double term_squared = term * term;
    double numerator = term;
    int n = 1;

    while (1)
    {
        result += numerator / n;

        numerator *= term_squared;
        n += 2;

        if (numerator < 1e-15)
        {
            break;
        }
    }

    return 2.0 * result;
}

double log10(double x)
{
    return ln(x) / LN10;
}
#include <stdio.h>

int main()
{
    double x, a;
    printf("This program calculates the logarithm base 10.\n");

    printf("Enter a positive value: ");
    while (1 == scanf("%lf", &x) && x > 0.0)
    {
        double a = log10(x);
        printf("log10(%lf) = %.12lf\n", x, a);
        printf("Enter a positive value: ");
    }
    return 0;
}