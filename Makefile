NAME = so_long
BNAME = .bonus

LIBFT = libft/libft.a

S = srcs/
O = objs/
I = incl/
L = libft/
B = bonus/
BO = bonus_objs/

all: $(NAME)

bonus: $(BNAME)

libft: $(LIBFT)

.PHONY: all clean fclean re bonus

CC = cc
CFLAGS += -g -Wall -Wextra -Werror -I$I -I$L
LDFLAGS += -I $(LIBFT) -L $L \
    -I /usr/local/include -L /usr/local/lib \
    -l mlx -l ft -framework OpenGL -framework Appkit

######################
##		MANDATORY 	##
######################

SRC = \
		$Scheck_path.c \
		$Serrors.c \
		$Sfree_structs.c \
		$Smain.c \
		$Sparse_map.c \
		$Svalidate_map.c
		
OBJ = $(SRC:$S%=$O%.o)

$O:
	@mkdir -p $@
	@echo "Making obj dir and files.."

$(OBJ): | $O

$O%.o: $S% $(LIBFT)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
	@echo "Project ready for use."

######################
##		BONUS		##
######################

SRC_B = \

OBJ_B = $(SRC_B:$B%=$(BO)%.o)

 $(BO):
	@mkdir -p $@
	@echo "Making obj dir and files.."

$(OBJ_B): | $(BO)

$(BO)%.o: $B% $(LIBFT)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BNAME): $(OBJ_B) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@
	@cp -f .bonus so_long 
	@echo "Bonus ready for use."

######################
##		DEBUG		##
######################

DEBUG_NAME = debug.out

debug: $(DEBUG_NAME)

DEBUG_FLAGS = -g -fsanitize=address,undefined,integer

$(DEBUG_NAME): $(OBJ) $(LIBFT)
	@$(CC) $(DEBUG_FLAGS) $(CFLAGS) $^ -o $@
	@echo "Debug ready for use."

cleandebug: fclean
	@rm -f $(DEBUG_NAME)
	@echo "debug.out removed"

#LIBFT

$(LIBFT): $L
	@make -C $L

cleanobj:
	@rm -f $(wildcard $(OBJ))

cleanobjdir: cleanobj
	@rm -rf $O

cleanbonus:
	@rm -f $(wildcard $(OBJ_B))

cleanobjbdir: cleanbonus
	@rm -rf $(BO)

cleanlibft:
	@make fclean -C $L

clean: cleanobjdir cleanlibft cleanobjbdir
	@echo "Cleaning object files and libft"

fclean: clean cleanbonus
	@rm -f $(NAME) $(BNAME)
	@echo "Project file removed"

re: fclean all