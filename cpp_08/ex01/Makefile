NAME = ex01
CXX = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98
RM = rm -f 
OBJ_DIR = obj
SRC_DIR = ./src
SRCS =  $(SRC_DIR)/main.cpp	\
		$(SRC_DIR)/Span.cpp		


# Generate object file names
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.cpp=.o)))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

# Rule to compile .cpp files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) -r $(OBJ_DIR)

fclean: clean 
	$(RM) $(NAME)

re: clean all
