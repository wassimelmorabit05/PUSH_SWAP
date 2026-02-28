NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = main.c \
       ft_atoi.c \
       ft_split.c \
	   ft_strdup.c \
	   ft_strjoin.c \
	   ft_strlen.c \
       op_push.c \
       op_rotate.c \
       op_rrotate.c \
       op_swap.c \
       sort1.c \
       sort_big.c \
       stack_utils.c \
       utils.c \
       validate_args.c 


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re