#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	t_stack *temp;
	int len;

	len = 0;
	temp = stack;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

int *list_from_stack(t_stack *stack, int len)
{
	int i;
	int *list;
	t_stack *temp;

	i = 0;
	list = (int*)malloc(sizeof(int) * len);
	if (!list)
		return(NULL);
	temp = stack;
	while (i < len)
	{
		list[i] = temp->num;
		temp = temp->next;
		i++;
	}
	return(list);
}