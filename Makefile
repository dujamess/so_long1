CFLAGS	= -Wall -Werror -Wextra -fsanitize=address -g3
CC      = cc
NFLAGS = -lmlx -lXext -lX11
SRCS_C    = bonus/so_long_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c bonus/appel_fonction_mouv_player_bonus.c\
	 		bonus/fonction_aid_bonus.c bonus/valid_map_bonus.c bonus/stock_map_bonus.c bonus/desin_map_bonus.c bonus/enms_bonus.c bonus/player_bonus.c\
			bonus/number_enms_bonus.c bonus/flood_fil_bonus.c bonus/mouv_player_bonus.c
SRC	= appel_fonction_mouv_player.c\
		  desin_map.c\
		  flood_fil.c\
		  fonction_aid.c\
		  get_next_line.c\
		  get_next_line_utils.c\
		  player.c\
		  so_long.c\
		  stock_map.c\
		  valid_map.c\

NAME = so_long
NAME_C = so_long_bonus
OBJT = $(SRC:.c=.o)
OBJS_C 	= $(SRCS_C:.c=.o)
all : $(NAME)

$(NAME): $(OBJT)
	$(CC) $(CFLAGS) $(OBJT) $(NFLAGS) -o $(NAME) 

bonus: $(NAME_C)

$(NAME_C): $(OBJS_C)
		   $(CC) $(CFLAGS) $(OBJS_C) $(NFLAGS) -o $(NAME_C)
%.o: %.c
	$(CC) $(CFLAGS) -I -Imlx_linux -O3 -c $< -o $@
clean : 
		rm -f $(OBJT) $(OBJS_C)
fclean : clean
		rm -f $(NAME) $(NAME_C)
re : fclean all
