# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchang <hchang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 15:09:06 by hchang            #+#    #+#              #
#    Updated: 2022/11/01 11:20:50 by hchang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX				=	c++
NAME			=	Zombie
RM 				=	rm -rf
CPPFLAGS 		=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors

SRCS_DIR 		=	srcs/
INCS_DIR		=	incs/
OBJS_DIR		=	objs/
DEPS_DIR		=	deps/

SRCS 			=	$(wildcard $(SRCS_DIR)*.cpp)
OBJS 			=	$(addprefix $(OBJS_DIR), $(notdir $(SRCS:.cpp=.o)))
DEPS			=	$(addprefix $(DEPS_DIR), $(notdir $(SRCS:.cpp=.d)))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CPPFLAGS) -I$(INCS_DIR) -c $< -o $@ -MMD
	@mkdir -p $(DEPS_DIR)
	@mv $(@:.o=.d) $(DEPS_DIR)$(notdir $(@:.o=.d))

clean:
	@$(RM) $(OBJS_DIR) $(DEPS_DIR)

fclean: clean
	@$(RM) $(NAME)

re:
	@make fclean
	@make all

-include $(DEPS)

.PHONY: all clean fclean re