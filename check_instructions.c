#include "push_swap.h"

void apply_instr2(t_stack **a,  t_stack **b, t_stack *instr)
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
    else if (instr->num == 18)
        rotate(b, &fill, 'b');
    else
    {
        reverse_rotate(a, &fill, 'a');
        reverse_rotate(b, &fill, 'b');
    }
}

void apply_instr(t_stack **a,  t_stack **b, t_stack *instr)
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
        else if (instr->num == 12)
            rotate(a, &fill, 'a');
        else
            apply_instr2(a, b, instr);    
        instr = instr->next;
        print_stack(*a);
        print_stack(*b);
    }
    stack_free(&fill);
}

void check_instr(int *list, int len)
{
    t_stack *a;
    t_stack *b;
    t_stack *instr;
    int check;

    a = create_stack_a(len, list);
    free(list);
    b = NULL;
    check = 0;
    instr = create_instr(&check);
    if ((instr == NULL && check == 1) || !a)
    {
        ft_printf("Error\n");
        stack_free(&a);
        stack_free(&b);
        return;
    }
    apply_instr(&a, &b, instr);
    if (is_sorted(a, len, 'a') == 1 && b == NULL)
        ft_printf("%s\n", "OK");
    else
        ft_printf("%s\n", "KO");
    // print_stack(a);
    print_instr(instr);
    stack_free(&a);
    stack_free(&b);
    stack_free(&instr);
    return;
}