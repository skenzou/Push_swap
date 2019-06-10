# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/03 09:24:41 by midrissi          #+#    #+#              #
#    Updated: 2019/06/10 11:46:35 by midrissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

_END			=	\x1b[0m
_BOLD			=	\x1b[1m
_UNDER			=	\x1b[4m
_REV			=	\x1b[7m
_GREY			=	\x1b[30m
_RED			=	\x1b[31m
_GREEN			=	\x1b[32m
_YELLOW			=	\x1b[33m
_BLUE			=	\x1b[34m
_PURPLE			=	\x1b[35m
_CYAN			=	\x1b[36m
_WHITE			=	\x1b[37m
_IGREY			=	\x1b[40m
_IRED			=	\x1b[41m
_IGREEN			=	\x1b[42m
_IYELLOW		=	\x1b[43m
_IBLUE			=	\x1b[44m
_IPURPLE		=	\x1b[45m
_ICYAN			=	\x1b[46m
_IWHITE			=	\x1b[47m
_MAGENTA		=	\x1b[35m

MSG				= $(_BOLD)$(_BLUE)Compiling push_swap and checker$(_END)
PUSH_SWAP		= push_swap
CHECKER			= checker
cc				= gcc
C_FLAGS			= -Wall -Wextra -Werror
OBJ_PATH		= ./obj/
LIBFT_PATH		= libft/
LIBFT_NAME		= libft.a
LIBFT 			= $(addprefix $(LIBFT_PATH),$(LIBFT_NAME))
INC_PATH		= ./includes
INC_NAME		= push_swap.h
INC_FPATH		= $(addprefix $(INC_PATH),$(INC_NAME))
INC				= $(addprefix -I,$(INC_PATH))

#SRCS
SRC_NAME		= parse_args.c read_instructions.c utils.c sorter.c \
					execute_instructions.c sorter_utils.c small_sort.c
SRC_PATH		= ./srcs/
SRC				= $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ_NAME		= $(SRC_NAME:.c=.o)
OBJ				= $(addprefix $(OBJ_PATH),$(OBJ_NAME))

#PUSH_SWAP
PUSH_SWAP_NAME	= push_swap.c
PUSH_SWAP_FPATH	= $(addprefix $(SRC_PATH),$(PUSH_SWAP_NAME))
PSOBJ			= $(addprefix $(OBJ_PATH)/, $(PUSH_SWAP_NAME:.c=.o))

#CHECKER
CHECKER_NAME	= checker.c
CHECKER_FPATH	= $(addprefix $(SRC_PATH),$(CHECKER_NAME))
CHECKEROBJ		= $(addprefix $(OBJ_PATH)/, $(CHECKER_NAME:.c=.o))


LONGEST			?= $(shell echo $(notdir $(SRC)) | tr " " "\n" | awk ' { if (\
				length > x ) { x = length; y = $$0 } }END{ print y }' | wc -c)

all: $(LIBFT) $(PUSH_SWAP)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(PUSH_SWAP): $(OBJ) $(PSOBJ) $(CHECKEROBJ)
		@$(CC) $(C_FLAGS) $(INC) $(OBJ) $(PSOBJ) $(LIBFT) -o $@
		@printf "\r\033[K$(_BOLD)$(_RED)./$(PUSH_SWAP) is ready for use\n$(_END)"
		@$(CC) $(C_FLAGS) $(INC) $(OBJ) $(CHECKEROBJ) $(LIBFT) -o $(CHECKER)
		@printf "$(_BOLD)$(_RED)./$(CHECKER) is ready for use\n$(_END)"

#PUSH_SWAP
$(PSOBJ) : $(PUSH_SWAP_FPATH)
		@$(CC) $(C_FLAGS) $(INC) -o $@ -c $<
		@printf "\r\033[K$(MSG) $(_BOLD)$(_CYAN)%-$(LONGEST)s\$(_END)" $(notdir $<)

#CHECKER
$(CHECKEROBJ) : $(CHECKER_FPATH)
		@$(CC) $(C_FLAGS) $(INC) -o $@ -c $<
		@printf "\r\033[K$(MSG) $(_BOLD)$(_CYAN)%-$(LONGEST)s\$(_END)" $(notdir $<)

#SRCS
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(C_FLAGS) $(INC) -o $@ -c $<
		@printf "\r\033[K$(MSG) $(_BOLD)$(_CYAN)%-$(LONGEST)s\$(_END)" $(notdir $<)

clean: clean_obj
		@make -C $(LIBFT_PATH) clean

clean_obj:
		@rm -rf $(OBJ_PATH)
		@echo "$(_BOLD)$(_RED)Successfully removed all objects from ${PUSH_SWAP}\
		$(_END)"

fclean: clean_obj
		@make -C $(LIBFT_PATH) fclean
		@rm -f $(PUSH_SWAP)
		@rm -f $(CHECKER)
		@echo "$(_BOLD)$(_RED)Successfully removed ${PUSH_SWAP} and ${CHECKER} from ${PUSH_SWAP}$(_END)"

re: fclean all
