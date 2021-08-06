MAKEFLAGS	+=	--quiet

WHT	= \033[0;37m
BLK	= \033[0;30m
RED	= \033[0;31m
YEL	= \033[0;33m
BLU	= \033[0;34m
GRN	= \033[0;32m

NAME	=	philo_tester

LIBFT	=	libft/libft

HEADERS	=	headers

DIR_S	=	srcs

DIR_O	=	obj

# Using wildcards: $(shell find $(DIR_S) -name *.c)
SRCS		:= $(shell find $(DIR_S) -name *.c)

OBJS		:= $(SRCS:%.c=$(DIR_O)/%.o)

SUB_DIR_O := $(shell find $(DIR_S) -type d)
SUB_DIR_O := $(SUB_DIR_O:%=$(DIR_O)/%)

# Using wildcards: $(shell find $(HEADERS) -name *.h)
DEPS	=	$(shell find $(HEADERS) -name *.h)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror
INCLUDES	= -I $(HEADERS) -I $(LIBFT)

LIBS	=	-L./$(LIBFT) -lft

RM		=	rm -f

$(DIR_O)/%.o: %.c
			@mkdir -p $(DIR_O)
			@mkdir -p $(SUB_DIR_O)
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME):	$(DEPS) $(OBJS)
			@make $(FAST)bonus -C $(LIBFT)
			$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS)
			printf "$(WHT)[$(GRN)$(NAME) COMPILED$(WHT)]\n"

all:		$(NAME)

miniclean:
			$(RM) $(OBJS)
			$(RM) $(BONUS_OBJS)
			printf "$(WHT)[$(YEL)$(NAME) OBJS REMOVED$(WHT)]\n"

clean:		miniclean
			@make clean -C $(LIBFT)

fclean:		miniclean
			$(RM) $(NAME)
			@make fclean -C $(LIBFT)
			printf "$(WHT)[$(YEL)$(NAME) BINARIES REMOVED$(WHT)]\n"

re:			fclean all

.PHONY:		all bonus miniclean clean fclean re
