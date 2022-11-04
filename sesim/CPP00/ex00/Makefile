# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 08:01:54 by sesim             #+#    #+#              #
#    Updated: 2022/11/04 14:26:08 by sesim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			=	c++
NAME		=	megaphone
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors
RM			=	rm -f

SRCS	=	megaphone.cpp
OBJS	=	$(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: | fclean all

.PHONY: all clean fclean re