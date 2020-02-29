#include "push_swap.h"

int     check_arg(char *arg)
{
    int i;

    i = 1;
    if (arg[0] != '-' && arg[0] != '+' && !(arg[0] >= '0' && arg[0] <= '9'))
        return(-1);
    while (arg[i])
    {
        if (!(arg[i] >= '0' && arg[i] != '9'))
            return(0);
        i++;
    }
    return(0);
}

int     ft_numlen(int num)
{
    int len;

    len = 0;
    if (num == 0)
        return(1);
    else if (num < 0)
    {
        len++;
        num = num * -1;
    }
    while (num > 0)
    {
        len++;
        num = num / 10;
    }
    return(len);
}

int    validate(int argc, char **argv)
{
    int i;
    int j;
    int arr[argc - 1];

    i = 1;
    while (i < argc)
    {
        if (check_arg(argv[i]) == -1)
            return (-1);
        arr[i - 1] = ft_atoi(argv[i]);
        if (ft_strlen(argv[i]) != ft_numlen(arr[i - 1]))
            return(-1);
        j = 0;
        while (j < i - 1)
        {
            if (arr[j] == arr[i - 1])
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}
