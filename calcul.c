#include <stdio.h>
#include <stdlib.h>
#define MY_PI 3.1415926535897932384626433832795

double ft_sqrt(double x) // newton-raphson method
{
    if (x < 0)
    {
        return -1.0; // negative number is undefined
    }
    double value = 0.000001;
    double guess = x;

    while ((guess * guess - x) > value)
    {
        guess = 0.5 * (guess + x / guess);
    }
    return guess;
}

int ft_power(int x, int y)
{
    unsigned long long int i;
    unsigned long long int sum;

    i = 1;
    sum = 1;
    for (i = 1; i <= y; i++)
    {
        sum = sum * x;
    }
    return sum;
}

int ft_factorial(int n)
{
    if (n <= 1)
    {
        return 1.0;
    }
    return n * ft_factorial(n - 1);
}

double ft_absolute(double x)
{
    if (x < 0)
    {
        return -x; // change the sign to make it positive
    }
    else
    {
        return x; // if its positive, return the same value
    }
}

double ft_sin(double x, int y)
{
    double result = 0.0;
    double term = x;
    for (int i = 1; i <= y; i += 2)
    {
        result += term;
        term = term * (-x * x) / ((i + 1) * (i + 2));
    }
    return result;
}

double ft_cos(double x, int y)
{
    double result = 1.0;
    double term = 1.0;
    for (int i = 2; i <= y; i += 2)
    {
        term = term * (-x * x) / (i * (i - 1));
        result += term;
    }
    return result;
}

double ft_log(double x, int terms)
{
    if (x <= 0)
    {
        return -1.0;
    }
    double result = 0.0;

    while (x >= 10.0)
    {
        x /= 10.0;
        result += 1.0;
    }

    // Approximate the logarithm using the log(1 + x) Maclaurin series
    double y = (x - 1.0) / (x + 1.0);
    double term = y;
    double sum = term;

    for (int n = 3; n <= terms; n += 2)
    {
        term *= (y * y);
        sum += (term / n);
    }

    result += 2.0 * sum;

    return result;
}

int main()
{
    float num1;
    float num2;
    int op;
    float result = 0;
    do
    {
        printf("***************************************************\n");
        printf("* Select an operation to perform the calculation: *\n");
        printf("*\t\t\t\t\t\t  *");
        printf("\n*  1. Addition \t\t 2. Subtraction\t\t  *\n*  3. Multiplication \t 4. Division\t\t  *\n*  5. Power \t\t 6. Square root\t\t  *\n*  7. Reminder \t\t 8. Sin\t\t\t  *\n*  9. Cos \t\t10. Tan\t\t\t  *\n* 11. Cot \t\t12. PI\t\t\t  *\n* 13. Factorial \t14. Log\t\t\t  *\n* 15. EXIT\t\t\t\t\t  *\n");
        printf("*\t\t\t\t\t\t  *\n");
        printf("***************************************************\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1: // addition
            printf("You chose: Addition\n");
            printf("Enter first number: \n");
            scanf("%f", &num1);
            printf("Enter second number: \n");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("The addition of numbers: %.2f\n", result);
            break;
        case 2: // subtraction
            printf("You chose: Subt raction\n");
            printf("Enter first number: \n");
            scanf("%f", &num1);
            printf("Enter second number: \n");
            scanf("%f", &num2);
            result = num1 - num2;
            printf("The subtraction of numbers: %.2f\n", result);
            break;
        case 3: // multiplication
            printf("You chose: Multiplication\n");
            printf("Enter first number: \n");
            scanf("%f", &num1);
            printf("Enter second number: \n");
            scanf("%f", &num2);
            result = num1 * num2;
            printf("The multiplication of numbers: %.2f\n", result);
            break;
        case 4: // division
            printf("You chose: Division\n");
            printf("Enter first number: \n");
            scanf("%f", &num1);
            printf("Enter second number: \n");
            scanf("%f", &num2);
            if (num2 == 0)
            {
                printf("Error\n");
                scanf("%f\n", &num2);
            }
            else
            {
                result = num1 / num2;
                printf("The division of numbers: %.2f\n", result);
            }
            break;
        case 5: // power of the number
            printf("You chose: Power\n");
            printf("Enter the number: \n");
            scanf("%f", &num1);
            printf("Enter the exponent: \n");
            scanf("%f", &num2);
            result = ft_power(num1, num2);
            printf("The power of the number:%.2f\n", result);
            break;
        case 6: // square root of the number
            printf("You chose: Square root\n");
            printf("Enter the number: \n");
            scanf("%f", &num1);
            result = ft_sqrt(num1);
            if (result == -1)
            {
                printf("Error\n"); // negative number is undefined
            }
            else
            {
                printf("The square root of the number: %.2f\n", result);
            }
            break;
        case 7: // reminder aka modulus
            printf("You chose: Reminder\n");
            printf("Enter the first number: \n");
            scanf("%f", &num1);
            printf("Enter the second number: \n");
            scanf("%f", &num2);
            result = (int)num1 % (int)num2;
            printf("The reminder of numbers: %.2f\n", result);
            break;
        case 8: // sine of degree
            printf("You chose: Sin\n");
            printf("Enter the degree: \n");
            scanf("%f", &num1);
            num2 = num1 * (MY_PI / 180.0);
            int terms = 40;
            result = ft_sin(num2, terms);
            if (ft_absolute(result) < 1e-6)
            {
                result = 0.0;
            }
            printf("The sine of %.2f degrees is approximately: %.6f\n", num1, result);
            break;
        case 9: // cosine of degree
            printf("You chose: Cos\n");
            printf("Enter the degree: \n");
            scanf("%f", &num1);
            num2 = num1 * (MY_PI / 180.0); // 90 degrees converted to radians
            terms = 40;                    // increase the number of terms for better accuracy
            result = ft_cos(num2, terms);  // check if the result is close to 0 and round it to 0
            if (ft_absolute(result) < 1e-6)
            {
                result = 0.0;
            }
            printf("The cosine of %.2f degrees is approximately: %.6f\n", num1, result);
            break;
        case 10: // tangent of degree
            printf("You chose: Tan\n");
            printf("Enter the degree: \n");
            scanf("%f", &num1);
            if (num1 == 90.000000 || num1 == 270.000000)
            {
                printf("Error\n");
                break;
            }
            num2 = num1 * (3.14159265358979323846 / 180.0);
            terms = 40;
            float result_sin = ft_sin(num2, 40);
            float result_cos = ft_cos(num2, 40);
            result = result_sin / result_cos;
            printf("The tangent of %.2f degrees is approximately: %.6f\n", num1, result);
            break;
        case 11: // cotangent of degree
            printf("You chose: Cot\n");
            printf("Enter the degree: \n");
            scanf("%f", &num1);
            if (num1 == 0.000000 || num1 == 180.000000 || num1 == 360.000000)
            {
                printf("Error\n");
                break;
            }
            num2 = num1 * (3.14159265358979323846 / 180.0);
            terms = 40;
            result_sin = ft_sin(num2, 10);
            result_cos = ft_cos(num2, 40);
            result = result_cos / result_sin;
            printf("The cotangent of %.2f degrees os approximately: %.6f\n", num1, result);
            break;
        case 13: // factorial
            printf("You chose: Factorial\n");
            printf("Enter the number: \n");
            scanf("%f", &num1);
            result = ft_factorial((int)num1);
            printf("The factorial of the number %f: %.1f\n", num1, result);
            break;
        case 14:
            printf("You chose: Log\n");
            printf("Enter the number: \n");
            scanf("%f", &num1);
            int term = 100;
            result = ft_log(num1, terms);
            printf("The logarithm of number %f: %.6f\n", num1, result);
            break;
        case 15: // exit
            printf("You chose: Exit\n");
            exit(0);
            break;
        default:
            printf("Error\n");
            break;
        }
    } while (op != 15);

    return 0;
}
