NAME = phoneBook

SRC = Contact.cpp main.cpp ./Files/ft_add_phonebook.cpp    ./Files/Helper.cpp ./Files/ShowTable.cpp
 
OBJ = $(SRC:%.cpp=%.o)

CPPFALGS =  -std=c++98 -Wall -Wextra -Werror -g

CC = c++

all: $(NAME)

$(NAME): $(OBJ) ./PhoneBook.hpp
	$(CC)  -std=c++98 -Wall -Wextra -Werror $(OBJ) -o $@
%.o : %.cpp
	$(CC)  -std=c++98 -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all