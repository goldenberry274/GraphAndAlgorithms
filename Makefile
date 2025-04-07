# Eitan.Beriy@msmail.ariel.ac.il

CC = g++
CFLAGS = -std=c++20 -g -I./DataStructures -I./DynamicDataStructures -I./Testing

# Directories and file structure
TARGET_MAIN = main
TARGET_TEST = test_bin
CUR_DIR = $(CURDIR)
SRC_DIR = $(CUR_DIR)
OBJ_DIR = $(CUR_DIR)/Objects
OBJ_SUBDIRS = $(OBJ_DIR)/DataStructures
DS_DIR = $(CUR_DIR)/DataStructures

# Source files
MAIN_SRC := $(SRC_DIR)/main.cpp $(SRC_DIR)/Graph.cpp $(SRC_DIR)/Algorithms.cpp
TEST_SRC := $(SRC_DIR)/Testing.cpp $(SRC_DIR)/Graph.cpp $(SRC_DIR)/Algorithms.cpp

DS_FILES := $(wildcard $(DS_DIR)/*.cpp)

MAIN_OBJS := $(patsubst $(CUR_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(MAIN_SRC) $(DS_FILES))
TEST_OBJS := $(patsubst $(CUR_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(TEST_SRC) $(DS_FILES))

# Ensure object subdirectories exist
$(OBJ_SUBDIRS):
	mkdir -p $@

prepare: $(OBJ_SUBDIRS)

# Default build
main: $(TARGET_MAIN)

# Build main executable
$(TARGET_MAIN): $(MAIN_OBJS) | prepare
	$(CC) $(MAIN_OBJS) -o $(TARGET_MAIN)

# Build test executable
$(TARGET_TEST): $(TEST_OBJS) | prepare
	$(CC) $(TEST_OBJS) -o $(TARGET_TEST)

# Compile .cpp files to .o
$(OBJ_DIR)/%.o: "$(CUR_DIR)/%.cpp" | prepare
	$(CC) $(CFLAGS) -c "$<" -o "$@"

# Unit test target: builds and runs the test binary
test: $(TARGET_TEST)
	./$(TARGET_TEST)

# Valgrind test on main
valgrind: $(TARGET_MAIN)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET_MAIN)

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(TARGET_MAIN) $(TARGET_TEST)
