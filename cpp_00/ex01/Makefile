NAME = myPhoneBook
CXX = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98 -pedantic
RM = rm -f 
SRCS = 	./Contact.cpp	\
		./PhoneBook.cpp \
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
