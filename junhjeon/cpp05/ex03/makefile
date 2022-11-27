# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhjeon <junhjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 17:07:45 by junhjeon          #+#    #+#              #
#    Updated: 2022/11/11 19:20:27 by junhjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC_DIR = .
NAME = a.out
SRCS = ./Bureaucrat.cpp ./main.cpp ./Form.cpp ./PresidentialPardonForm.cpp \
	   ./RobotomyRequestForm.cpp ./ShrubberyCreationForm.cpp ./Intern.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDE = .

all : $(NAME)
		
.cpp.o:
	$(CXX) -c $(CPPFLAGS) -I $(INCLUDE) -o $@ $< 

$(NAME) : $(OBJS) 
	$(CXX) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: 
	make fclean;
	make all;

.PHONY: clean all fclean re
