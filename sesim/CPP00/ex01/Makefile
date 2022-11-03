# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 10:57:40 by sesim             #+#    #+#              #
#    Updated: 2022/11/03 22:12:34 by sesim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compile Macros
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors
RM			=	rm -rf

# Directories
SRCS_DIR	:=	srcs/
INCS_DIR	:=	incs/
OBJS_DIR	:=	objs/
DEPS_DIR	:=	deps/

# Sources
SRCS		:=	$(wildcard $(SRCS_DIR)*.cpp)
OBJS		:=	$(addprefix $(OBJS_DIR), $(notdir $(SRCS:.cpp=.o)))
DEPS		:=	$(addprefix $(DEPS_DIR), $(notdir $(SRCS:.cpp=.d)))
NAME		:=	phoneBook

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -I$(INCS_DIR) -c $< -o $@ -MMD
	@mkdir -p $(DEPS_DIR)
	@mv $(@:.o=.d) $(DEPS_DIR)$(notdir $(@:.o=.d))

clean:
	$(RM) $(OBJS_DIR) $(DEPS_DIR)

fclean: clean
	$(RM) $(NAME)

re: | fclean all

-include $(DEPS)

.PHONY: all clean fclean re
