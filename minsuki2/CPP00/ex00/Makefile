# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 18:32:08 by minsuki2          #+#    #+#              #
#    Updated: 2022/11/08 16:06:27 by minsuki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPPFLAGS	=		-Wall -Wextra -Werror -std=c++98
RM 			=		rm -rvf

# Directory
SRCS_DIR 	:=		./
INCS_DIR 	:=		./
OBJS_DIR 	:=		objs/

SRCS 		:=		$(notdir $(wildcard $(SRC_DIR)*.cpp))
OBJS 		:=		$(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))
NAME		:=		megaphone


all: $(NAME)

$(NAME): $(OBJS)
	@echo [$@] linking...
	$(CXX) $(CPPFLAGS) $^ -o $@
	@echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	@echo ">>>>>>>>>> $@ Compiled! <<<<<<<<<<"
	@echo @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	mkdir -p $(dir $@)
	echo [$<] compiling...
	$(CXX) $(CPPFLAGS) -I$(INCS_DIR) -c $< -o $@

clean:
	@echo
	@echo ">>>>>>>>>>>>>>>> clean List <<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(OBJS_DIR)
	@echo

fclean: clean
	@echo ">>>>>>>>>>>>>>>> fclean List <<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(NAME)
	@echo

re: | fclean all

.PHONY: all clean fclean re
