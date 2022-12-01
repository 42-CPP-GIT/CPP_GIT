# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 17:07:45 by junhjeon          #+#    #+#              #
#    Updated: 2022/11/05 17:56:04 by junhjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC_DIR = .
NAME = a.out
SRCS = ./main.cpp ./Fixed.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDE = .

all : $(NAME)
		
.cpp.o:
	$(CXX) -c $(CPPFLAGS) -I $(INCLUDE) -o $@ $< 

$(NAME) : $(OBJS) 
	$(CXX) $(CPPFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: 
	make fclean;
	make all;

.PHONY: clean all fclean re
