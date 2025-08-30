NAME = pipex

SRCS = src/pipex.c \
			 src/utils.c \
			 libft/libft.a\

BONUS_SRCS = bonus_src/pipex_bonus.c \
						bonus_src/pipex_bonus.h \
						bonus_src/utils_bonus.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: ${OBJS} ${BONUS_OBJS}
	ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

.PHONY: all clean fclean re bonus

