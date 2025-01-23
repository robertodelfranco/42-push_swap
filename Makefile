NAME		=	push_swap
NAME_BONUS	=	checker

CC			=	cc
FLAGS		=	-Wall -Werror -Wextra -g
LIBFT		=	./current_lib


LIB			=	$(LIBFT)/libft.a
HEADERS		=	-I $(current_lib)/Includes

SRCS		=	./mandatory/algorithm_utils.c \
				./mandatory/algorithm.c \
				./mandatory/free.c \
				./mandatory/list_manipulation.c \
				./mandatory/main.c \
				./mandatory/node_set_values.c \
				./mandatory/node_utils.c \
				./mandatory/op_push.c \
				./mandatory/op_reverse.c \
				./mandatory/op_rotate.c \
				./mandatory/op_swap.c

SRCS_BONUS	=	./bonus/checker_bonus.c \
				./bonus/create_nodes_bonus.c \
				./bonus/errors_bonus.c \
				./bonus/init_bonus.c \
				./bonus/node_utils_bonus.c \
				./bonus/read_bonus.c \
				./bonus/validate_bonus.c \
				./bonus/moves/op_push_bonus.c \
				./bonus/moves/op_reverse_bonus.c \
				./bonus/moves/op_rotate_bonus.c \
				./bonus/moves/op_swap_bonus.c

OBJS		=	${SRCS:.c=.o}
OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

all: libft ${NAME}


libft:
	@make -C $(LIBFT)

${NAME}: ${OBJS}
	@$(CC) $(OBJS) $(LIB) $(HEADERS) -o $(NAME)

%.o:%.c
	${CC} ${FLAGS} -o $@ -c $< ${HEADERS}

bonus: libft ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS}
	$(CC) $(OBJS_BONUS) $(LIB) $(HEADERS) -o $(NAME_BONUS)

clean:
	@rm -rf ${OBJS} ${OBJS_BONUS}
	@$(MAKE) -C $(LIBFT) clean

fclean:	clean
	@rm -rf ${NAME} ${NAME_BONUS}
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all bonus

.PHONY: all clean fclean re libft bonus