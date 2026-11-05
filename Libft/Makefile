NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -f

SRCS1			=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
				ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
				ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
				ft_calloc.c ft_strdup.c

SRCS2			=	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c

BONUS			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				ft_lstmap.c ft_lstnew.c ft_lstsize.c
					
OBJS			= 	$(SRCS1:.c=.o) $(SRCS2:.c=.o)
BONUS_OBJS		= 	$(BONUS:.c=.o)

# -------------------------------- 기본 라이브러리 --------------------------------
all:				$(NAME)

$(NAME):			$(OBJS)
				$(AR) $(ARFLAGS)  $(NAME) $(OBJS)

# -------------------------------- bonus 빌드 --------------------------------

bonus:			$(OBJS) $(BONUS_OBJS)
				$(RM) $(NAME)
				$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(BONUS_OBJS)

# -------------------------------- 컴파일 규직 --------------------------------

%.o:				%.c libft.h
				$(CC) $(CFLAGS) -c $< -o $@

# -------------------------------- 청소 --------------------------------

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

# -------------------------------- PHONY --------------------------------

.PHONY:			all clean fclean re bonus
