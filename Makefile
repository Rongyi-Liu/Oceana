CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

SRC := main.cpp Player.cpp BattleGame.cpp GameInterface.cpp
OBJ := $(SRC:.cpp=.o)
BIN := battle_game

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(BIN)
