NAME = Animal

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
 
OBJ = $(SRC:%.cpp=%.o)

CC = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  -std=c++98 -Wall -Wextra -Werror -Wno-c++11-extensions $(OBJ) -o $@
%.o : %.cpp Animal.hpp Cat.hpp Dog.hpp Brain.hpp
	$(CC)  -std=c++98 -Wall -Wextra -Werror -Wno-c++11-extensions -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all