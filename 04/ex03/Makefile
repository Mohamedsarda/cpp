NAME = main

SRC = main.cpp AMateria.cpp ICharacter.cpp IMateriaSource.cpp
 
OBJ = $(SRC:%.cpp=%.o)



CC = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  -std=c++98 -Wall -Wextra -Werror $(OBJ) -o $@
%.o : %.cpp AMateria.hpp ICharacter.hpp IMateriaSource.hpp
	$(CC)  -std=c++98 -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all