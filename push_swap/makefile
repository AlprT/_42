NAME = push_swap

SRCS =	./src/free_utils.c \
		./src/ft_err.c \
		./src/index.c \
		./src/put_utils.c \
		./src/check/check_valid.c \
		./src/lst_utils/ft_lstadd_back.c \
		./src/lst_utils/ft_lstadd_front.c \
		./src/lst_utils/ft_lstlast.c \
		./src/lst_utils/ft_lstnew.c \
		./src/lst_utils/ft_lstsize.c \
		./src/operations/opt_p.c \
		./src/operations/opt_r.c \
		./src/operations/opt_rr.c \
		./src/operations/opt_s.c \
		./src/Push_swap/Radix_sort.c \
		./src/Push_swap/Simple_sort.c \
		./src/Simple_sort/Sort_3.c \
		./src/Simple_sort/Sort_4.c \
		./src/Simple_sort/Sort_5.c \
		./src/libft/ft_atoi.c \
		./src/libft/ft_bzero.c \
		./src/libft/ft_calloc.c \
		./src/libft/ft_isdigit.c \
		./src/libft/ft_memset.c \
		./src/libft/ft_split.c \
		./src/libft/ft_strlen.c \
		./src/libft/ft_substr.c

OBJS =	free_utils.o \
		ft_err.o \
		index.o \
		put_utils.o \
		check_valid.o \
		ft_lstadd_back.o \
		ft_lstadd_front.o \
		ft_lstlast.o \
		ft_lstnew.o \
		ft_lstsize.o \
		opt_p.o \
		opt_r.o \
		opt_rr.o \
		opt_s.o \
		Radix_sort.o \
		Simple_sort.o \
		Sort_3.o \
		Sort_4.o \
		Sort_5.o \
		ft_atoi.o \
		ft_bzero.o \
		ft_calloc.o \
		ft_isdigit.o \
		ft_memset.o \
		ft_split.o \
		ft_strlen.o \
		ft_substr.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME}

${NAME}:
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) $(CFLAGS) $(OBJS) ./src/Push_swap/main.c -o $(NAME)

clean: 
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re