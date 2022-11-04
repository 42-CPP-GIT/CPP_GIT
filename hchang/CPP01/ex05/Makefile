# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchang <hchang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 15:09:06 by hchang            #+#    #+#              #
#    Updated: 2022/11/04 17:19:23 by hchang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX				=	c++
NAME			=	Harl
RM 				=	rm -rf
CPPFLAGS 		=	-Wall -Wextra -Werror -std=c++98

OBJS 			=	$(SRCS:.cpp=.o)
SRCS 			=	$(wildcard *.cpp)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJS)

%.o: $(SRCS)
	@$(CXX) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) 

fclean: clean
	@$(RM) $(NAME)

re:
	@make fclean
	@make all

-include $(DEPS)

.PHONY: all clean fclean re