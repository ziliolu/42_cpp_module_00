NAME = myAwesomePhoneBook
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
RM = rm -f 
SRCS = 	./contact.cpp	\
		./phoneBook.cpp \
		./main.cpp
OBJ = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean 
	$(RM) $(NAME)

re: clean all