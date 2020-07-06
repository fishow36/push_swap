# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshor <eshor@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/06 15:03:46 by eshor             #+#    #+#              #
#    Updated: 2020/07/06 16:55:59 by eshor            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker
FLAGS = -Wall -Wextra -Werror
INC = -Iincludes
LIB = libft/libftprintf.a
SRCS_PS = bubble_sort.c \
		check_instructions.c \
		create_stack.c \
		instr_shorten.c \
		midsort.c \
		sort_main.c \
		sort_small.c \
		sort_small_nonempty.c \
		stack_basic_funcs.c \
		stack_basic_funcs2.c \
		stack_init.c \
		stack_sorting_funcs.c \
		validation.c \
		verbose_mode.c \
		push_swap.c
		
SRCS_CH = bubble_sort.c \
        check_instructions.c \
        create_stack.c \
        instr_shorten.c \
        midsort.c \
        sort_main.c \
        sort_small.c \
        sort_small_nonempty.c \
        stack_basic_funcs.c \
        stack_basic_funcs2.c \
        stack_init.c \
        stack_sorting_funcs.c \
        validation.c \
        verbose_mode.c \
        ch_main.c

OBJ_PS = $(SRCS_PS:.c=.o)
OBJ_CH = $(SRCS_CH:.c=.o)

%.o: %.c
	@gcc $(FLAGS) $(INC) -o $@ -c $<
	
$(NAME_CH): $(OBJ_CH) $(NAME_PS)
	@make -C libft/
	@gcc $(FLAGS) -o $(NAME_CH) $(OBJ_CH) $(INC) $(LIB)

$(NAME_PS): $(OBJ_PS)
	@make -C libft/
	@gcc $(FLAGS) -o $(NAME_PS) $(OBJ_PS) $(INC) $(LIB)


clean:
	@make -C libft clean
	@rm -f $(OBJ_PS)
	@rm -f $(OBJ_CH)

fclean: clean
	@rm -f $(NAME_PS)
	@rm -f $(NAME_CH)

re: fclean all

all: $(NAME_PS) $(NAME_CH)

.PHONY: all clean fclean re