NAME		=	push_swap

NAME_BONUS	=	checker

# Colors
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
RED			=	\033[0;31m
RESET		=	\033[0m
BOLD		=	\033[1m

# Directories
OBJ_DIR		=	obj/
LIBFT_DIR	=	libft/

SRC			=	push_swap.c utils.c instrcution_push_swap.c \
				instruction_rotate.c instruction_rev_rotate.c \
				instruction_maxnmin.c instruction_calculate_n_copy.c \
				instruction_postion_n_combination.c instrction_LIS.c \
				instruction_sort.c instruction_free.c check_strlen.c\

SRC_BONUS	=	checker.c check_utils.c check_instruction_one.c\
				check_instruction_two.c check_instruction_three.c\
				check_free.c check_strlen.c\

LIBFT		=	$(LIBFT_DIR)libft.a

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

OBJ_BONUS	=	$(addprefix $(OBJ_DIR), $(SRC_BONUS:.c=.o))

CC			=	cc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

# Default target
all:		$(NAME)

# Create obj directory
$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)
			@echo "$(BLUE)Created $(OBJ_DIR) directory$(RESET)"

# Compile object files
$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
			@echo "$(YELLOW)Compiling: $(BOLD)$<$(RESET)"
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			@echo "$(BLUE)Building libft...$(RESET)"
			@make -C $(LIBFT_DIR)
			@echo "$(GREEN)Linking $(BOLD)$(NAME)$(RESET)"
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
			@echo "$(GREEN)$(BOLD)✓ $(NAME) successfully built!$(RESET)"

clean:
			@echo "$(RED)Cleaning object files...$(RESET)"
			@make clean -C $(LIBFT_DIR)
			@$(RM) -r $(OBJ_DIR)
			@echo "$(RED)Object files cleaned$(RESET)"

fclean: 	clean
			@echo "$(RED)Full clean...$(RESET)"
			@make fclean -C $(LIBFT_DIR)
			@$(RM) $(NAME) $(NAME_BONUS)
			@echo "$(RED)$(BOLD)✓ Everything cleaned!$(RESET)"

re:			fclean bonus

bonus:		all $(OBJ_BONUS)
			@echo "$(GREEN)Linking $(BOLD)$(NAME_BONUS)$(RESET)"
			@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT)
			@echo "$(GREEN)$(BOLD)✓ $(NAME_BONUS) successfully built!$(RESET)"

.PHONY:		all clean fclean re bonus
