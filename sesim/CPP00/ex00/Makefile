# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 08:01:54 by sesim             #+#    #+#              #
#    Updated: 2022/11/03 21:50:15 by sesim            ###   ########.fr        #
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

re:
	make fclean
	make all

.PHONY: all clean fclean re