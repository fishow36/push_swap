#include "push_swap.h"

void    swap(t_stack **stack, t_stack **instr, char stack_name)
{
    t_stack *temp;

    if (*stack)
    {
        if ((*stack)->next)
        {
            temp = (*stack)->next;
            (*stack)->next = (*stack)->next->next;
            temp->next = *stack;
            *stack = temp;
            stack_push_back(stack_name == 'a' ? 52 : 58, instr);
        }
    }
}

/* stack_name -- куда пушим, то есть to */
void    push(t_stack **from, t_stack **to, t_stack **instr, char stack_name)
{
    t_stack *temp;

    if (*from)
    {
        temp = (*from)->next;
        (*from)->next = *to;
        *to = *from;
        *from = temp;
        stack_push_back(stack_name == 'a' ? 62 : 68, instr);
    }
}

void    rotate(t_stack **stack, t_stack **instr, char stack_name)
{
    int cont;

    if (*stack)
    {
        if ((*stack)->next)
        {
            cont = stack_pop(stack);
            stack_push_back(cont, stack);
            // ft_printf("r%c\n", stack_name);
            // print_stack(*stack);
            stack_push_back(stack_name == 'a' ? 12 : 18, instr);
        }
    }
}

void    reverse_rotate(t_stack **stack, t_stack **instr, char stack_name)
{
    t_stack *temp;
    int cont;

    if (*stack)
    {
        if ((*stack)->next)
        {
            temp = *stack;
            while (temp->next->next)
                temp = temp->next;
            cont = temp->next->num;
            // free(temp->next);
            temp->next = NULL;
            stack_push(cont, stack);
            stack_push_back((stack_name == 'a') ? 112 : 118, instr);
        }
    }
}

int is_sorted(t_stack *stack, int len, char stack_name)
{
    t_stack *temp;
    int prev;

    if (stack == NULL)
        return(1);
    temp = stack;
    prev = temp->num;
    temp = temp->next;
    while (len > 1)
    {
        if ((stack_name == 'a' && prev > temp->num) ||
        stack_name == 'b' && prev < temp->num)
            return(0);
        prev = temp->num;
        temp = temp->next;
        len--;
    }
    return(1);
}