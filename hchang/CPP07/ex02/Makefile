# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchang <hchang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 15:09:06 by hchang            #+#    #+#              #
#    Updated: 2022/12/01 16:11:02 by hchang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX				=	c++
NAME			=	Array
RM 				=	rm -rf
CXXFLAGS 		=	-Wall -Wextra -Werror -std=c++98

SRCS 			=	$(wildcard *.cpp)
OBJS 			=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re