NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -I. -ILibft
RM = rm -f

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c \
	base/cleanup.c \
	base/fork_state.c \
	base/free.c \
	base/init.c \
	base/log.c \
	base/print_mutex.c \
	base/resource.c \
	base/time.c \
	base/wait.c \
	base/utils.c \
	monitor/monitor.c \
	monitor/meal_deadline.c \
	simulation/create_philo.c \
	simulation/forks.c \
	simulation/join_philo.c \
	simulation/meal.c \
	simulation/philo_actions.c \
	simulation/philo_routine.c \
	simulation/philosophers.c \
	simulation/simulation_state.c \
	simulation/thinking_control.c \
	simulation/manager_model.c \
	simulation/manager_plan.c \
	simulation/think.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
