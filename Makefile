NAME = pipex

CC = cc
CFLAGS = -Werror -Wall -Wextra -fsanitize=address
RM = rm -rf

SRCS = src/pipex.c src/utils.c
SRCS_BONUS = bonus_src/pipex_bonus.c bonus_src/utils_bonus.c

$(NAME): libft/libft.a $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME)


all: $(NAME)

bonus: libft/libft.a $(SRCS_BONUS)
	$(CC) $(CFLAGS) $(SRCS_BONUS) libft/libft.a -o $(NAME)

libft/libft.a:
	make -C libft

clean:
	$(RM) *.o
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus
