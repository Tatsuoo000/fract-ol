SRCDIR		= ./srcs/
SRCNAME		= check_closed_map.c control_key.c cub3d.c draw_splite.c \
			  draw_to_image.c read_conf_file.c read_map.c read_size_tex_color.c \
		 		save_bmp.c get_next_line.c utils.c other.c
SRCS		= $(addprefix $(SRCDIR), $(SRCNAME))
OBJS		= $(SRCS:.c=.o)
INCLUDE		= -I./includes/
NAME		= fractol
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
LIBFTDIR	= ./libft
LIBFTNAME 	= libft.a
LIBFT		= $(LIBFTDIR)/$(LIBFTNAME)
UNAME 		= $(shell uname)
ifeq ($(UNAME),Linux)
	LIBMLXDIR	= ./minilibx-linux
	LIBMLXNAME	= libmlx_Linux.a
	LIBMLX		= $(LIBMLXDIR)/$(LIBMLXNAME)
	LINK		= -lXext -lX11 -lm
else
	LIBMLXDIR	= ./minilibx_mms_20200219
	LIBMLXNAME	= libmlx.dylib
	LIBMLX		= $(LIBMLXDIR)/$(LIBMLXNAME)
	LINK		= 
endif

all		:	$(NAME)

.c.o	:
			if [ ! -d ./minilibx-linux ]; then git clone https://github.com/42Paris/minilibx-linux.git; fi
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME)	:	$(LIBFTNAME) $(LIBMLXNAME) $(OBJS)
			cp $(LIBMLX) ./
			$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) $(LIBMLXNAME) $(LINK) -o $(NAME)

$(LIBFTNAME):
			make -C $(LIBFTDIR)

$(LIBMLXNAME):
			if [ ! -d ./minilibx-linux ]; then git clone https://github.com/42Paris/minilibx-linux.git; fi
			make -C $(LIBMLXDIR)

clean	:
			$(RM) $(OBJS)
			make clean -C $(LIBFTDIR)
			make clean -C $(LIBMLXDIR)

fclean	:	clean
			$(RM) $(NAME)
			$(RM) $(LIBMLXNAME)
			$(RM) capture.bmp
			make fclean -C $(LIBFTDIR)

re		:	fclean all

.PHONY	:	all clean fclean re $(LIBFTNAME) $(LIBMLXNAME)
