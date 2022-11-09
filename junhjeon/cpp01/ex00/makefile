# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 17:07:45 by junhjeon          #+#    #+#              #
#    Updated: 2022/11/05 18:31:34 by junhjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC_DIR = .
NAME = zombie
SRCS = ./Zombie.cpp ./main.cpp ./newZombie.cpp ./randomChump.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
INCLUDE = .

all : $(NAME)
		
.cpp.o:
	$(CXX) -c $(CPPFLAGS) -I $(INCLUDE) -o $@ $< -MMD

$(NAME) : $(OBJS) 
	$(CXX) $(CPPFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean;
	make all;

-include $(DEPS)

.PHONY: clean all fclean re
