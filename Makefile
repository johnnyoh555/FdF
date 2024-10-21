SRCS = main.c parsing.c drawline.c convert.c isometric.c colors.c hooks.c spinning.c spinhooks.c init.c
SRCS_B = main_bonus.c parsing_bonus.c drawline_bonus.c convert_bonus.c isometric_bonus.c colors_bonus.c hooks_bonus.c spinning_bonus.c spinhooks_bonus.c init_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
NAME = fdf
NAME_B = fdf_bonus
CFLAGS = -Wextra -Werror -Wall
CC = gcc
CLIB = -lmlx -framework OpenGl -framework Appkit -Imlx
LIBFT=	make -C ./libft

all : $(NAME)

$(NAME) : $(OBJS)
	$(LIBFT)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -Llibft -lft  -o $(NAME)

bonus: Flag_f

Flag_f: $(OBJS_B)
	$(LIBFT)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS_B) -Llibft -lft  -o $(NAME_B)
	touch $@

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $^

$(OBJS_B): $(SRCS_B)
	$(CC) $(CFLAGS) -c $^
	
clean:
	rm -f $(OBJS)
	rm -f $(OBJS_B)
	rm -f Flag_f
	$(LIBFT) fclean

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_B)

re : fclean all

.PHONY: all clean fclean re bonus