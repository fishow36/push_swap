#include "push_swap.h"

void    apply_instr2(t_stack **a,  t_stack **b, t_stack *instr)
{
    t_stack *fill;

    fill = NULL;
    if (instr->num == 11)
    {
        rotate(a, &fill, 'a');
        rotate(b, &fill, 'b');
    }
    else if (instr->num == 112)
        reverse_rotate(a, &fill, 'a');
    else if (instr->num == 118)
        reverse_rotate(b, &fill, 'b');
    else if (instr->num == 12)
            rotate(a, &fill, 'a');
    else if (instr->num == 18)
        rotate(b, &fill, 'b');
    else
    {
        reverse_rotate(a, &fill, 'a');
        reverse_rotate(b, &fill, 'b');
    }
    stack_free(&fill);
}

void    apply_instr(t_stack **a,  t_stack **b, t_stack *instr, int v)
{
    t_stack *fill;

    fill = NULL;
    while (instr)
    {
        if (instr->num == 52)
            swap(a, &fill, 'a');
        else if (instr->num == 58)
            swap(b, &fill, 'b');
        else if (instr->num == 55)
        {
            swap(a, &fill, 'a');
            swap(b, &fill, 'b');
        }
        else if (instr->num == 62)
            push(b, a, &fill, 'a');
        else if (instr->num == 68)
            push(a, b, &fill, 'b');
        else
            apply_instr2(a, b, instr);    
        if (v == 1)
            print_stacks(*a, *b);
        instr = instr->next;
    }
    stack_free(&fill);
}

void    free_main(t_stack **a, t_stack **b, t_stack **instr)
{
    stack_free(a);
    stack_free(b);
    stack_free(instr);
}

void    check_instr(int *list, int len, int v)
{
    t_stack     *a;
    t_stack     *b;
    t_stack     *instr;
    int         check;

    a = create_stack_a(len, list);
    print_stack(a);
    free(list);
    b = NULL;
    check = 0;
    instr = create_instr(&check);
    if ((instr == NULL && check == 1) || !a)
    {
        ft_printf("Error\n");
        free_main(&a, &b, &instr);
        return;
    }
    apply_instr(&a, &b, instr, v);
    if (is_sorted(a, stack_len(a), 'a') == 1 && b == NULL)
        ft_printf("%s\n", "OK");
    else
        ft_printf("%s\n", "KO");
    free_main(&a, &b, &instr);
}