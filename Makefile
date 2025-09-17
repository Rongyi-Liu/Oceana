CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = test_runner
SRCS = main.cpp Invoice.cpp

.PHONY: all clean

all:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)
	./$(TARGET)

clean:
	rm -f $(TARGET)
