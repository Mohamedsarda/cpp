NAME = main

SRC = main.cpp 
 
OBJ = $(SRC:%.cpp=%.o)



CC = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC)  -std=c++98 -Wall -Wextra -Werror $(OBJ) -o $@
%.o : %.cpp
	$(CC)  -std=c++98 -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -rf $(OBJ) ./*.replace

fclean: clean
	@rm -rf $(NAME)

re: fclean all