SRCS = ft_printf.c		\
		utils.c		\
		itoa_base.c		\
		parse_type.c	\
		conver_cspct.c		\
		conver_di.c 	\
		width_dir.c		\
		conver_u.c		\
		conver_xXp.c		\

NAME = libftprintf.a

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c ft_printf.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@ar r $(NAME) $(OBJECTS_PREFIXED)
	@echo "Printf Done !"

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	
re: fclean all

bonus: $(OBJECTS_PREFIXED)
	@ar r $(NAME) $(OBJECTS_PREFIXED)
	@echo "Printf Bonus Done !"
