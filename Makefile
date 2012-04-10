NAME_EXE = using

SRC_EXE = using.cpp
OBJ_EXE = $(SRC_EXE:.cpp=.o)

LDFLAGS += -lpthread
CXXFLAGS += -W -Wall -Wextra

CXX = g++


all: $(NAME_EXE)


$(NAME_EXE): $(OBJ_EXE)
	$(CXX) -o $(NAME_EXE) $(OBJ_EXE) $(LDFLAGS)


clean:
	rm -f $(OBJ_LIB) $(OBJ_EXE)


fclean: clean
	rm -f $(NAME_EXE) $(NAME_LIB)


re: fclean all