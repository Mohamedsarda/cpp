NAME = main

SRC = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp
 
OBJ = $(SRC:%.cpp=%.o)



CC = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  -std=c++98 -Wall -Wextra -Werror $(OBJ) -o $@
%.o : %.cpp AMateria.hpp Cure.hpp IMateriaSource.hpp MateriaSource.hpp Character.hpp ICharacter.hpp Ice.hpp
	$(CC)  -std=c++98 -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all