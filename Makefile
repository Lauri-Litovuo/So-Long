
NAME = so_long
BNAME = so_long_bonus


S = srcs/
O = objs/
I = incl/
B = bonus/
BO = bonus_objs/

all: $(MLX_LIB) $(NAME)

bonus: $(BNAME)

.PHONY: all clean fclean re bonus

CC = cc
CFLAGS += -Wall -Wextra -Werror -I$I
LDFLAGS += 

### MLX ###

ifeq ($(shell uname), Linux)
	INCL_MLX = -I/usr/include -Imlx
else
	INCL_MLX = -I/opt/X11/include -Imlx
endif
 
M = mlx
MLX_LIB = $M/libmlx_$(UNAME).a


ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

##		MANDATORY 	##

SRC = \
		$S
		
OBJ = $(SRC:$S%=$O%.o)

$O:
	@mkdir -p $@
	@echo "Making obj dir and files.."

$(OBJ): | $O

$O%.o: $S% $(MLX_LIB)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCL_MLX)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $^ -o $@  
	@echo "Project ready for use."
 

##		BONUS		##

SRC_B = \
		$Bp

OBJ_B = $(SRC_B:$B%=$(BO)%.o)

$(BO):
	@mkdir -p $@
	@echo "Making obj dir and files.."

$(OBJ_B): | $(BO)

$(BO)%.o: $B% $(MLX_LIB)
	@$(CC) $(CFLAGS)  -c $< -o $@ $(INCL_MLX)

$(BNAME): $(OBJ_B) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $^ -o $@
	@echo "Bonus ready for use."

#DEBUG

DEBUG_NAME = debug.out

debug: $(DEBUG_NAME)

DEBUG_FLAGS = -g -fsanitize=address,undefined,integer

$(DEBUG_NAME): $(LIBFT) $(OBJ)
	@$(CC) $(DEBUG_FLAGS) $^ -o $@
	@echo "Debug ready for use."

cleandebug: fclean
	@rm -f $(DEBUG_NAME)
	@echo "debug.out removed"

#MLX LIB

$(MLX_LIB):
	@make -C $M

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

fclean: clean
	@rm -f $(NAME) $(BNAME)
	@echo "Project file removed"

re: fclean all