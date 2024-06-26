# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babischa <babischa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 14:42:15 by babischa          #+#    #+#              #
#    Updated: 2024/06/26 12:05:25 by babischa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		:=	client
SERVER 		:=	server

CC 			:=	cc
FLAGS 		:=	-Werror -Wextra -Wall -g3
LIBPRINTF 	:=	./library/ft_printf

HEADERS 	:=	-I ./include -I $(LIBPRINTF)/include

LIB			:=	$(LIBPRINTF)/ft_printf.a

SRC_CLIENT	:=	client \
				utils

SRC_SERVER	:=	server

OBJ_CLIENT	:=	$(addprefix objects/, $(addsuffix .o, $(SRC_CLIENT)))
OBJ_SERVER	:=	$(addprefix objects/, $(addsuffix .o, $(SRC_SERVER)))

all: make_printf $(CLIENT) $(SERVER)

make_printf:
	$(MAKE) -C $(LIBPRINTF)

objects/%.o: source/%.c | objects
	$(CC) $(FLAGS) -o $@ -c $< $(HEADERS) ; \
	echo "Compiling: $(notdir $<)"

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(OBJ_CLIENT) $(LIB) $(HEADERS) -o $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	$(CC) $(OBJ_SERVER) $(LIB) $(HEADERS) -o $(SERVER)

objects:
	mkdir -p objects

bonus: all

clean:
	$(MAKE) -C $(LIBPRINTF) clean
	rm -rf objects

fclean: clean
	$(MAKE) -C $(LIBPRINTF) fclean
	rm -rf $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re make_printf objects bonus

.SILENT:
