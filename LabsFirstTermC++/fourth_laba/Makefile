CXX = g++
CXXFLAGS = -Wall -Wextra -Iinclude
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/fourth_laba

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJ_DIR) $(TARGET)
