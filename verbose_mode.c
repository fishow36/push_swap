#include "push_swap.h"

/* в инте макс. 11 знаков -- поля по 12 */
void	print_stacks(t_stack *a, t_stack *b)
{
	int len_a;
	int len_b;
	int len;
	int i;
	int j;
	t_stack *temp_a;
	t_stack *temp_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	if (len_a > len_b)
		len = len_a;
	else
		len = len_b;
	temp_a = a;
	temp_b = b;
	i = 0;
	ft_printf("******A*************B******\n");
	while (i < len)
	{
		ft_printf("*");
		if (temp_a)
		{
			ft_printf("%11d ", temp_a->num);
			temp_a = temp_a->next;
		}
		else
			ft_printf("            ");
		ft_printf("*");
		if (temp_b)
		{
			ft_printf("%11d ", temp_b->num);
			temp_b = temp_b->next;
		}
		else
			ft_printf("            ");
		ft_printf("*\n");
		i++;
	}	
	ft_printf("***************************\n\n");
}