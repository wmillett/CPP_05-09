# Colours
RED = '\033[0;31m'
GREEN = '\033[0;32m'
RESET_COLOR = '\033[0;0m'

# Compiler
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Executable
NAME = Array

# Source files
SRC = $(wildcard *.cpp)


# Object files
OBJS = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(GREEN)"Compiling $(NAME)"$(RESET_COLOR)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	@echo $(RED)"Removing object files."$(RESET_COLOR)
	@rm -f $(OBJS)

fclean: clean
	@echo $(RED)"Removing $(NAME)"$(RESET_COLOR)
	@rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re
