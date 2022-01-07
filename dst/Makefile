NAME	= fractol
SRCDIR	= ./srcs/
SRCNAME	= 	main.c\
			arg_parse.c\
			exit.c\
			fractol.c\
			init.c\
			vector.c\
			color.c\
			draw_to_window.c\
			trgb_to_int.c

SRCS	= $(addprefix $(SRCDIR), $(SRCNAME))
OBJS	= $(SRCS:.c=.o)

INCLUDE = -I./includes
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
LIBDIR	= ./libft/
LIBFT	= libft.a
LIBFTA	= $(LIBDIR)$(LIBFT)

LIBMLXDIR	= ./minilibx-linux/
LIBMLXNAME	= libmlx_Linux.a
LIBMLX		= $(LIBMLXDIR)$(LIBMLXNAME)
LINK		= -L/usr.lib -lXext -lX11 -lm

all		:	$(NAME)

.c.o	:
			if [ ! -d ./minilibx-linux ]; then git clone https://github.com/42Paris/minilibx-linux.git; fi
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME)	:	$(OBJS) $(LIBFTA) $(LIBMLX)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFTA) $(LIBMLX) $(LINK) -o $(NAME)

$(LIBFTA)	:
			make -C $(LIBDIR)

$(LIBMLX):
			if [ ! -d ./minilibx-linux ]; then git clone https://github.com/42Paris/minilibx-linux.git; fi
			make -C $(LIBMLXDIR)

clean	:
			$(RM) $(OBJS)
			$(RM) $(LIBMLXNAME)
			make clean -C $(LIBDIR)

fclean	:	clean
			$(RM) $(NAME)
			$(RM) $(LIBMLXNAME)
			$(RM) capture.bmp
			make fclean -C $(LIBDIR)

re		:	fclean all

.PHONY	:	all clean fclean re $(LIBFTNAME) $(LIBMLXNAME)
