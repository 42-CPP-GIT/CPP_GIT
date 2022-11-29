# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinypark <jinypark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 17:01:08 by jinypark          #+#    #+#              #
#    Updated: 2022/11/29 14:37:03 by jinypark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX 		=	c++
NAME		=	a.out
RM 			=	rm -rvf
CPPFLAGS 	=	-Wall -Wextra -Werror -std=c++98
SRCS		=	main.cpp AMateria.cpp Character.cpp \
				Ice.cpp Cure.cpp MateriaSource.cpp
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

debug:
	make "CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98 -DDEBUG -fsanitize=address" all

.PHONY: all clean fclean re
