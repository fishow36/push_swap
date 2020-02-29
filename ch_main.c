#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *stack;

    if (argc == 1)
        ft_printf("\n");
    else
    {
        if (validate(argc, argv) == -1)
            ft_printf("Error\n");
    }
    return(0);
}