# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 19:43:14 by junoh             #+#    #+#              #
#    Updated: 2022/11/10 14:53:10 by junoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./PhoneBook.cpp\
		./Contact.cpp\
		./main.cpp\
		./PhoneBookUtil.cpp

CXX = c++
NAME = phonebook

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean : 
		rm -rf $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
