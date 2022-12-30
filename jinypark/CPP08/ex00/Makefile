# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 17:01:08 by jinypark          #+#    #+#              #
#    Updated: 2022/12/29 22:00:07 by jinypark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX 		=	c++
NAME		=	a.out
RM 			=	rm -rvf
CPPFLAGS 	=	-Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address
SRCS		=	main.cpp
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
