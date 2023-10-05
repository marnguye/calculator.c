#include <stdio.h>
#include <stdlib.h>

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

double ft_sin(double x, int y)
{
    double result = 0.0;
    double term = x;
    int sign = -1;
    for (int i = 1; i <= y; i += 2)
    {
        result += term;
        term = term * (x * x) / ((i + 1) * i + 2);
        sign *= -1;
    }
    return result;
}

double ft_cos(double x, int y)
{
    double result = 1.0;
    double term = 1.0;
    int sign = -1;
    for (int i = 1; i <= y; i += 2)
    {
        term = term * (x * x) / ((i + 1) * i + 2);
        result += sign * term;
        sign *= -1;
    }
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
        printf("Select a operation to perform the calculation: \n");
        printf("\n1. Addition \t\t2. Subtraction \n3. Multiplication \t4..Division \n5. Power \t\t6. Square root \n7. Reminder \t\t8. Sin \n9. Cos \t\t\t10. Tan \n11. Log \t\t12. PI \n13. Factorial \t\t14. EXIT\n");
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
            printf("Addition of two number is: %.2f\n", result);
            break;
        case 2: // subtraction
            printf("You chose: Subt raction\n");
            printf("Enter first number: \n");
            scanf("%f", &num1);
            printf("Enter second number: \n");
            scanf("%f", &num2);
            result = num1 - num2;
            printf("%.2f\n", result);
            break;
        case 3: // multiplication
            printf("You chose: Multiplication\n");
            printf("Enter first number: \n");
            scanf("%f", &num1);
            printf("Enter second number: \n");
            scanf("%f", &num2);
            result = num1 * num2;
            printf("%.2f\n", result);
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
                printf("%.2f\n", result);
            }
            break;
        case 5: // power of the number
            printf("You chose: Power\n");
            printf("Enter the number: \n");
            scanf("%f", &num1);
            printf("Enter the exponent: \n");
            scanf("%f", &num2);
            result = ft_power(num1, num2);
            printf("%.2f\n", result);
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
                printf("%.2f\n", result);
            }
            break;
        case 7: // reminder aka modulus
            printf("You chose: Reminder\n");
            printf("Enter the first number: \n");
            scanf("%f", &num1);
            printf("Enter the second number: \n");
            scanf("%f", &num2);
            result = (int)num1 % (int)num2;
            printf("%.2f\n", result);
            break;
        case 8: // sin
            printf("You chose: Sin\n");
            printf("Enter the degree: \n");
            scanf("%f", &num1);
            num2 = num1 * 3.14159265358979323846 / 180.0;
            int terms = 10;
            result = ft_sin(num2, terms);
            printf("The sine of %.2f degrees is approximately %.6f\n", num1, result);
            break;
        case 9: // cos
            printf("You chose: Cos\n");
            printf("Enter the degree: \n");
            scanf("%f", &num1);
            num2 = num1 * 3.14159265358979323846 / 180.0;
            int term = 10;
            result = ft_cos(num2, term);
            printf("The cos of %.2f degrees is approximately %.6f\n", num1, result);
        case 13: // factorial
            printf("You chose: Factorial\n");
            printf("Enter the number: \n");
            scanf("%f", &num1);
            result = ft_factorial((int)num1);
            printf("%.1f\n", result);
            break;
        case 14: // exit
            printf("You chose: Exit\n");
            exit(0);
            break;
        default:
            printf("Error\n");
            break;
        }
    } while (op != 14);

    return 0;
}
