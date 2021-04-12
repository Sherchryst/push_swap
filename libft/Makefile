# DIRECTORIES
BUILD	= .build

# FILES
NAME	= libft.a
SRC		= ft_isalnum.c ft_isdigit.c ft_memccpy.c ft_memset.c ft_putchar.c \
		ft_atoi.c ft_isalpha.c ft_isprint.c ft_memcpy.c ft_bzero.c \
		ft_isascii.c ft_isspace.c ft_memmove.c ft_strlen.c ft_memcmp.c \
		ft_putstr.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		ft_strncat.c ft_strlcat.c ft_putnbr.c ft_strchr.c ft_strrchr.c \
		ft_strstr.c ft_strnstr.c ft_strnchr.c ft_strncmp.c ft_strcmp.c \
		ft_strnlen.c ft_isupper.c ft_tolower.c ft_islower.c ft_toupper.c \
		ft_memdel.c ft_calloc.c ft_strnew.c ft_strdel.c ft_strclr.c \
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		ft_strnequ.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_putendl.c ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c \
		ft_putnbr_fd.c ft_isblank.c ft_iscntrl.c ft_isgraph.c ft_isxdigit.c \
		ft_strndup.c ft_strlcpy.c ft_memchr.c get_next_line.c ft_strreplace.c \
		ft_freeint.c ft_tabmap.c
BONUS	= ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstnew_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
		ft_lstmap_bonus.c ft_lstadd_back_bonus.c ft_lstiter_bonus.c \
		ft_free_tab.c
DEP		:= $(SRC:%.c=$(BUILD)/%.d)
OBJ		:= $(SRC:%.c=$(BUILD)/%.o)
OBJ_B	:= $(BONUS:%.c=$(BUILD)/%.o)

# COMPILATION
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
DFLAGS	= -MP -MMD

$(NAME): $(OBJ)
		@ar -rcs $@ $^
	@echo "\n\033[03mThe library archive of \033[00m\033[0;32m"
	@echo "██╗     ██╗██████╗ ███████╗████████╗"
	@echo "██║     ██║██╔══██╗██╔════╝╚══██╔══╝"
	@echo "██║     ██║██████╔╝█████╗     ██║   "
	@echo "██║     ██║██╔══██╗██╔══╝     ██║   "
	@echo "███████╗██║██████╔╝██║        ██║   "
	@echo "╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝   "
	@echo "\033[00m"
	@echo "			 \033[03mHas been created!\n\033[00m"

all: $(NAME)

bonus: $(OBJ_B) $(NAME)
	@ar -rcs $(NAME) $^
	@echo "			\033[03mBONUS Has been added!\n\033[00m"

clean:
	@rm -rf $(BUILD)
	@echo "\033[1;34mExecute:\t\033[1;33mCleaning build\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;34mExecute:\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"
re: fclean all


$(BUILD):
	@echo "\033[1;32m\nCreation of .build\033[0m \n"
	@mkdir $@ $(DIRS)

$(BUILD)/%.o: %.c | $(BUILD)
	@printf "\033[1;34mExecute: \t\033[1;33mCompilation of \033[1;36m$(notdir $<)\033[0m \
	 %-33.33s\r"
	@$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ -I../include

-include $(DEP)

.PHONY: all clean fclean re
