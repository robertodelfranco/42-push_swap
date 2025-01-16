NAME		=	push_swap
CC			=	cc
FLAGS		=	-Wall -Werror -Wextra -g
LIBFT		=	./current_lib


LIB			=	$(LIBFT)/libft.a
HEADERS		=	-I $(current_lib)/Includes

SRCS		=	./mandatory/main.c \
				./mandatory/algorithms.c \
				./mandatory/free.c \
				./mandatory/list.c \
				./mandatory/movements.c \
				./mandatory/op_push.c \
				./mandatory/op_reverse.c \
				./mandatory/op_rotate.c \
				./mandatory/op_swap.c \
				./mandatory/pivot.c \
				./mandatory/validation.c

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