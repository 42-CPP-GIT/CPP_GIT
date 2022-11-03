# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 10:57:54 by sesim             #+#    #+#              #
#    Updated: 2022/11/03 21:59:30 by sesim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compile Macros
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors
RM			=	rm -rf

# Directories
CURR_DIR	:=	./
OBJS_DIR	:=	objs/
DEPS_DIR	:=	deps/

# Sources
SRCS		:=	$(wildcard $(CURR_DIR)*.cpp)
OBJS		:=	$(addprefix $(OBJS_DIR), $(notdir $(SRCS:.cpp=.o)))
DEPS		:=	$(addprefix $(DEPS_DIR), $(notdir $(SRCS:.cpp=.d)))
NAME		:=	phoneBook

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(CURR_DIR)%.o: $(CURR_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -I$(INCS_DIR) -c $< -o $@ -MMD
	@mkdir -p $(DEPS_DIR)
	@mv $(@:.o=.d) $(DEPS_DIR)$(notdir $(@:.o=.d))

clean:
	$(RM) $(CURR_DIR) @(DEPS_DIR)

fclean: clean
	$(RM) $(NAME)

re: | fclean all

-include $(DEPS)

.PHONY: all clean fclean re
