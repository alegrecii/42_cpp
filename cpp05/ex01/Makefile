NAME = bureau

SRCS = main.cpp Bureaucrat.cpp Form.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)✅Compiled✅$(WHITE)"

clean:
	@rm -f $(OBJS)
	@echo "$(BLUE)☑️ Clean☑️ $(WHITE)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)☑️ Clean☑️ $(WHITE)"

re : fclean all

.PHONY: all $(NAME) clean fclean re

WHITE = \033[0m
GREEN = \033[1;92m
BLUE = \033[1;94m
