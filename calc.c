#include <stdio.h>
#include <math.h>

int ft_atoi(char *c)
{
    int i;
    int sign;
    int result;

    i = 0;
    sign = 1;
    result = 0;
    while (c[i] == 32 || (c[i] >= 9 && c[i] <= 13))
    {
        i++;
    }
    if (c[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (c[i] == '+')
    {
        i++;
    }
    while (c[i] != '\0' && c[i] >= '0' && c[i] <= '9')
    {
        result *= 10;
        result += c[i] - '0';
        i++;
    }
    return (result * sign);
}

int main(int ac, char *av[])
{
    int num1 = ft_atoi(av[1]);
    char op = av[2][0];
    int num2 = ft_atoi(av[3]);
    int result;

    result = 0;

    if (ac == 4)
    {
        switch (op)
        {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0)
            {
                result = (double)num1 / (double)num2;
            }
            break;
        default:
            printf("Error\n");
            return 1;
        }
    }
    else
    {
        return (printf("Error\n"));
    }
    printf("%d\n", result);

    return 0;
}