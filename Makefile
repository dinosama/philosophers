NAME    =    philo

SRCS    =    sources/actions.c       \
            sources/clean.c            \
            sources/display.c     \
			sources/init.c    \
			sources/parsing.c       \
			sources/philo.c           \
			sources/utils.c           \
			sources/utils2.c           \

INCS    =    /includes/philo.h

OBJS    =    $(SRCS:.c=.o)

CC        =    gcc
CFLAGS    =    -Wall -Wextra -Werror

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

$(NAME):    $(OBJS)
			@echo "\033[1;93mphilo compilation\033[0;m"
			@ar -rcs $(NAME) $(OBJS)
			@$(CC) $(OBJS) -o $(NAME) -lpthread
			@echo "\033[1;92mphilo compiled\033[0;m"

all:        $(NAME)

clean:
			@rm -rf $(OBJS)
			@echo "\033[1;91mobject files removed\033[0;m"

fclean:		clean
			@rm -rf $(NAME)
			@echo "\033[1;91mexecutables removed\033[0;m"

re:			fclean all

.PHONY:		all clean fclean re