# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinypark <jinypark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 17:01:08 by jinypark          #+#    #+#              #
#    Updated: 2022/12/06 22:40:15 by jinypark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX 		=	c++
NAME		=	convert
RM 			=	rm -rvf
CPPFLAGS 	=	-Wall -Wextra -Werror -std=c++98
SRCS		=	main.cpp serialize.cpp
OBJS		=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CPPFLAGS) -o $@ $(OBJS)

%.o : %.cpp
	@echo [$<] compiling ...
	@$(CXX) $(CPPFLAGS) -c -o $@ $<

clean:
	@echo ">>>>>>deleted list<<<<<<<"
	@$(RM) $(OBJS)

fclean: clean
	@echo ">>>>>>deleted list<<<<<<<"
	@$(RM) $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re
