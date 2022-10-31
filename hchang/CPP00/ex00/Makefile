# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchang <hchang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 15:09:06 by hchang            #+#    #+#              #
#    Updated: 2022/10/28 11:24:21 by hchang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX				=	c++
NAME			=	megaphone
RM 				=	rm -rf
CPPFLAGS 		=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors

SRCS 	=	megaphone.cpp
OBJS 	=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re