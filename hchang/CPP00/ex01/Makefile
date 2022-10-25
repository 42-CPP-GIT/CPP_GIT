# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchang <hchang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 15:09:06 by hchang            #+#    #+#              #
#    Updated: 2022/10/25 14:41:22 by hchang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 				=	c++
NAME			=	PhoneBook
RM 				=	rm -rf
CFLAGS 			=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors

SRCS 	=	PhoneBook.cpp main.cpp
OBJS 	=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re:
	@make fclean

.PHONY: all clean fclean re