# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yichinos <yichinos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 10:39:13 by yichinos          #+#    #+#              #
#    Updated: 2023/09/18 10:52:20 by yichinos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= 	cc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	pipex
OBJDIR	=	objs/
SRCS	=	main.c \
			pipe_file_init.c \
			chiled.c \
			make_path.c \
			error.c
HEAD_FILE	=	include/pipex.h
OBJS	=	$(addprefix $(OBJDIR),$(SRCS:.c=.o))
LIBFT_DIR	=	libft
LIBFT	=	$(LIBFT_DIR)/libft.a
RM		= 	rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(OBJDIR)%.o : %.c $(HEAD_FILE)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJDIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
