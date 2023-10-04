#include <stdio.h>

double ft_atof(char *c) // convertion ascii to float
{
    double result;
    double fraction;
    int sign;
    int hasFraction;

    result = 0.0;
    fraction = 0.0;
    sign = 1;
    hasFraction = 0;
    while (*c == ' ' || *c == '\t')
    {
        c++;
    }
    if (*c == '-')
    {
        sign = -1;
        c++;
    }
    else if (*c == '+')
    {
        c++;
    }

    while (*c >= '0' && *c <= '9')
    {
        result = result * 10.0 + (*c - '0');
        c++;
    }

    if (*c == '.')
    {
        c++;
        double decimal = 10.0;
        while (*c >= '0' && *c <= '9')
        {
            fraction += (*c - '0') / decimal;
            decimal *= 10.0;
            hasFraction = 1;
            c++;
        }
    }
    result = sign * (result + fraction);

    return result;
}

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

double ft_power(double base, int exponent)
{
    if (exponent == 0)
    {
        return 1.0;
    }
    double result = 1.0;
    int i;

    if (exponent > 0)
    {
        for (i = 0; i < exponent; i++)
        {
            result *= base;
        }
    }
    else
    {
        for (i = 0; i > exponent; i--)
        {
            result /= base;
        }
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
        case 8:
            printf("You chose: Sin\n");
            scanf("%f", &num1);
            break;
        default:
            printf("Error\n");
            break;
        }
    } while (op != 8);

    return 0;
}
