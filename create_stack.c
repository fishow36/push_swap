#include "push_swap.h"

t_stack		*create_stack_a(int argc, int *argv)
{
	t_stack *stack;

	stack = stack_new(argv[argc - 1]);
	argc = argc - 2;
	while (argc >= 0)
	{
		stack_push(argv[argc], &stack);
		argc--;
	}
	return(stack);
}

int			instr_to_int(char *str)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'r')
			res = res * 10 + 1;
		else if (str[i] == 'a')
			res = res * 10 + 2;
		else if (str[i] == 's')
			res = res * 10 + 5;
		else if (str[i] == 'p')
			res = res * 10 + 6;
		else if (str[i] == 'b')
			res = res * 10 + 8;
		else
			return(-1);
		i++;
	}
	if (res == 52 || res == 58 || res == 55 || res == 62 || res == 68 || res ==
	12 || res == 18 || res == 11 || res == 112 || res == 118 || res == 111)
		return(res);
	else
		return(-1);  
}

t_stack		*free_str_return(char *str)
{
	free(str);
	return(NULL);
}

t_stack		*create_instr(int *check)
{
	t_stack	*stack;
	char	*str;
	int		cont;

	stack = NULL;
	while (get_next_line(1, &str))
	{
		*check = 1;
		cont = instr_to_int(str);
		if (cont == -1)
			return(free_str_return(str));
		if (!stack)
		{
			stack = stack_new(cont);
			if (!stack)
				return(free_str_return(str));
		}
		else
			stack_push_back(cont, &stack);
		free(str);
	}
	return (stack);
}

void		print_stack(t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	while (temp)
	{
		ft_printf("%d\n", temp->num);
		temp = temp->next;
	}
	ft_printf("\n\n\n");
}

void		print_instr(t_stack *instr)
{
	t_stack *temp;

	temp = instr;
	while (temp)
	{
		if (temp->num / 100 == 1)
			ft_printf("rr");
		if (temp->num / 10 == 5)
			ft_printf("s");
		else if (temp->num / 10 == 6)
			ft_printf("p");
		else if (temp->num / 10 == 1)
			ft_printf("r");
		if (temp->num % 10 == 2)
			ft_printf("a");
		else if (temp->num % 10 == 8)
			ft_printf("b");
		else if (temp->num % 10 == 1)
			ft_printf("r");
		else if (temp->num % 10 == 5)
			ft_printf("s");
		ft_printf("\n");
		temp = temp->next;
	}
}