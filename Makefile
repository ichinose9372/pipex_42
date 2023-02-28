CC		=	CC
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	pipex
SRCS	=	main.c\
			pipe_init.c\
			chiled.c\
			make_path.c\
			error.c
HEAD_FILE	=	include/pipex.h
OBJS	=	$(SRCS:.c=.o)
LIBFT_DIR	=	libft
LIBFT	=	$(LIBFT_DIR)/libft.a
RM		=	rm -rf

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(HEAD_FILE)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(OBJS) : %.o: %.c $(HEAD_FILE)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
		$(MAKE) -C $(LIBFT_DIR)

clean :
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean : clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY:	all clean fclean re
