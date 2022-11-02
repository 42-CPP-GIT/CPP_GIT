# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 18:32:08 by minsuki2          #+#    #+#              #
#    Updated: 2022/11/02 16:09:09 by minsuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPPFLAGS	=		-Wall -Wextra -Werror -std=c++98
RM 			=		rm -rvf

# Directory
SRCS_DIR 	:=		./
INCS_DIR 	:=		./
OBJS_DIR 	:=		./
DEPS_DIR 	:=		./

SRCS 		:=		$(wildcard $(SRCS_DIR)*.cpp)
OBJS 		:=		$(addprefix $(OBJS_DIR), $(notdir $(SRCS:.cpp=.o)))
DEPS		:=		$(addprefix $(DEPS_DIR), $(notdir $(SRCS:.cpp=.d)))
NAME		:=		account


all: $(NAME)

$(NAME): $(OBJS)
	@echo [$@] linking...
	$(CXX) $(CPPFLAGS) $^ -o $@
	@echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	@echo ">>>>>>>>>> $@ Compiled! <<<<<<<<<<"
	@echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@echo [$<] compiling...
	@$(CXX) $(CPPFLAGS) -I$(INCS_DIR) -c $< -o $@ -MMD

clean:
	@echo
	@echo ">>>>>>>>>>>>>>>> clean List <<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(OBJS) $(DEPS)
	@echo

fclean: clean
	@echo ">>>>>>>>>>>>>>>> fclean List <<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(NAME)
	@echo

re: | fclean all

-include $(DEPS)

.PHONY: all clean fclean re
