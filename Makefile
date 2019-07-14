NAME_INT = interpr
NAME_CHECK = checker
NAME_SOL = push_swap
SRCS1 = stack_gen.c check_stack.c instructions_swap.c instructions_push.c instructions_rotate.c \
		instructions_rrotate.c actions.c read_inst.c error.c exe.c track.c execute.c help.c descent.c \
		descent_action.c climb.c print_module.c print_module2.c startfinish_rotate.c 
SRCS = $(addprefix src/, $(SRCS1))
OBJ = $(SRCS1:.c=.o)
FLAGS =  -Wall -Wextra -Werror
LIB = libftprintf

all: $(NAME_INT) $(NAME_CHECK) $(NAME_SOL)

$(NAME_INT):
	@make -C $(LIB)/ re
	@gcc $(FLAGS) -I $(LIB)/includes -c src/interpr.c $(SRCS) -g
	@gcc -o $(NAME_INT) interpr.o $(OBJ) -I libft/includes -L $(LIB)/ -lftprintf -g

$(NAME_CHECK):
	@make -C $(LIB)/ re
	@gcc $(FLAGS) -I $(LIB)/includes -c src/main.c $(SRCS) -g
	@gcc -o $(NAME_CHECK) main.o $(OBJ) -I $(LIB)/includes -L $(LIB)/ -lftprintf -g

$(NAME_SOL):
	@make -C $(LIB)/ re
	@gcc $(FLAGS) -I $(LIB)/includes -c src/push_swap.c $(SRCS) -g
	@gcc -o $(NAME_SOL) push_swap.o $(OBJ) -I $(LIB)/includes -L $(LIB)/ -lftprintf -g

clean:
	@/bin/rm -f push_swap.o main.o interpr.o $(OBJ)
	@make -C $(LIB)/ clean

fclean: clean
	@/bin/rm -f $(NAME_INT) $(NAME_SOL) $(NAME_CHECK)
	@make -C $(LIB)/ fclean

re: fclean all