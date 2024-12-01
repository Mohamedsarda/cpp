NAME = ScavTrap

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp

OBJ = $(SRC:%.cpp=%.o)

CC = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  -std=c++98 -Wall -Wextra -Werror $(OBJ) -o $@
%.o : %.cpp ClapTrap.hpp ScavTrap.hpp
	$(CC)  -std=c++98 -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
