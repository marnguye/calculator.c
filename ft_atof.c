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