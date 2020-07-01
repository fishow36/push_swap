#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "../libft/includes/ft_printf.h"

typedef	struct	s_stack
{
	int			    num;
	struct s_stack	*next;
	struct s_stack *prev;
}				t_stack;

typedef struct s_inf
{
	t_stack *a;
	t_stack *b;
	t_stack *instr;
}			t_inf;

t_stack *stack_new(int cont);
void    stack_push(int cont, t_stack **stack);
void stack_push_back(int cont, t_stack **stack);
int stack_pop(t_stack **stack);
void    stack_free(t_stack **stack);
void    free_main(t_stack **a, t_stack **b, t_stack **instr);
int	stack_len(t_stack *stack);
int *list_from_stack(t_stack *stack, int len);

t_stack *create_stack_a(int argc, int *argv);
int		*char_to_int(int argc, char **argv, int v);
t_stack *create_instr(int *check);
void    print_stack(t_stack *stack);
void	print_stacks(t_stack *a, t_stack *b);

void    print_instr(t_stack *instr);

int		*bubble_sort(int  *arr, int len);
int		nbr_len(long n);

void    swap(t_stack **stack, t_stack **instr, char stack_name);
void    push(t_stack **from, t_stack **to, t_stack **instr, char stack_name);
void    rotate(t_stack **stack, t_stack **instr, char stack_name);
void    reverse_rotate(t_stack **stack, t_stack **instr, char stack_name);
int		is_sorted(t_stack *stack, int len, char stack_name);

void	sort_2(t_stack **stack, char stack_name, t_stack **instr);
void sort_3a(t_stack **stack, t_stack **instr);
void sort_3b(t_stack **stack, t_stack **instr);
void	sort_3a_nonemptystack(t_stack **a, t_stack **b, t_stack **instr);
void	sort_3b_nonemptystack(t_stack **a, t_stack **b, t_stack **instr);

void apply_instr(t_stack **a,  t_stack **b, t_stack *instr, int v);
void check_instr(int *list, int len, int v);

int		*list_validation (int argc, char **argv, int v);

int	midsort(t_stack **from, t_stack **to, t_stack **instr, int *list, int len, char stack_name, int num_chunks_in_from);

int	sort_stack(t_stack **a, t_stack **b, t_stack **instr, t_stack **chunks_a, t_stack **chunks_b);

void	replace_swaps(t_stack **instr);
void	replace_rotates(t_stack **instr);
void	replace_pushes(t_stack **instr);
void	replace_pushswap(t_stack **instr);
void	replace_r_rr(t_stack **instr);

#endif