NAME		=	push_swap
CC			=	cc
FLAGS		=	-Wall -Werror -Wextra -g
LIBFT		=	./current_lib


LIB			=	$(LIBFT)/libft.a
HEADERS		=	-I $(current_lib)/Includes

SRCS		=	./mandatory/main.c \
				./mandatory/algorithm.c \
				./mandatory/free.c \
				./mandatory/list_manipulation.c \
				./mandatory/node_set_values.c \
				./mandatory/node_utils.c \
				./mandatory/op_push.c \
				./mandatory/op_reverse.c \
				./mandatory/op_rotate.c \
				./mandatory/op_swap.c \
				./mandatory/pivot.c \
				./mandatory/sort_six.c

OBJS		=	${SRCS:.c=.o}
OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

all: libft ${NAME}

libft:
	@make -C $(LIBFT)

${NAME}: ${OBJS}
	@$(CC) $(OBJS) $(LIB) $(HEADERS) -o $(NAME)

%.o:%.c
	@${CC} ${FLAGS} -o $@ -c $< ${HEADERS}

clean:
	@rm -rf ${OBJS}
	@$(MAKE) -C $(LIBFT) clean

fclean:	clean
	@rm -rf ${NAME}
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libft