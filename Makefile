# Makefile for Raylib C++ project

# Compiler and compiler flags
CXX := g++
CXXFLAGS := -std=c++11 -Wall -I./src -I./raylib-4.5.0/include
LDFLAGS := -L./raylib-4.5.0/lib -lraylib -lm -lpthread

# Source files and output executable
SRC_DIR := src
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_DIR := obj
OBJS := $(addprefix $(OBJ_DIR)/,$(notdir $(SRCS:.cpp=.o)))
EXECUTABLE := main

# Targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -rf $(OBJ_DIR) $(EXECUTABLE)

.PHONY: all run clean
