# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchang <hchang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 15:09:06 by hchang            #+#    #+#              #
#    Updated: 2022/11/25 15:25:01 by hchang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX				=	c++
NAME			=	Form
RM 				=	rm -rf
CPPFLAGS 		=	-Wall -Wextra -Werror -std=c++98

SRCS 			=	$(wildcard *.cpp)
OBJS 			=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	@$(CXX) $(CPPFLAGS) -c $< -o $@ 

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(wildcard *_shrubbery)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re