# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babischa <babischa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 13:50:13 by babischa          #+#    #+#              #
#    Updated: 2024/06/25 14:05:41 by babischa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	ft_printf.a

CC		:=	cc

CFLAGS	:=	-Wall -Werror -Wextra -g

FILE	:= 	ft_printf		\
			ft_printf_utils	\

SRC		:=	$(addprefix source/, $(addsuffix .c, $(FILE)))
OBJ		:=	$(addprefix objects/, $(addsuffix .o, $(FILE)))

HEADERS :=	-I ./include -I /include

all: $(NAME)

objects/%.o: source/%.c | objects
	$(CC) $(FLAGS) -o $@ -c $< $(HEADERS) ; \
	echo "Compiling: $(notdir $<)"
	
$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

objects:
	@mkdir -p objects

clean:
	@rm -rf objects

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all objects clean fclean re objects

.SILENT:
