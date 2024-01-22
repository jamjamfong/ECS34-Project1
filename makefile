CXX = g++ #C++ compiler flag 

# Directories
OBJ_DIR = ./obj
BIN_DIR = ./bin
INC_DIR = ./include
SRC_DIR = ./src
TESTSRC_DIR = ./testsrc

CFLAGS = -std=c++17 -Wall -I$(INC_DIR) # Compilation flags 
LIBS = -lgtest -lgtest_main -lpthread # Google Test flags 

#Main target 
all: directories runtests

#Run tests after building executable
runtests: $(BIN_DIR)/teststrutils
	$(BIN_DIR)/teststrutils

#Target for teststrutils executable
$(BIN_DIR)/teststrutils: $(OBJ_DIR)/StringUtils.o $(OBJ_DIR)/StringUtilsTest.o
	$(CXX) -o $(BIN_DIR)/teststrutils $(CFLAGS) $^ $(LIBS)

#Builds StringUtils object file
$(OBJ_DIR)/StringUtils.o: $(SRC_DIR)/StringUtils.cpp $(INC_DIR)/StringUtils.h
	$(CXX) -o $@ -c $(CFLAGS) $<

#Builds StringUtilsTest object file
$(OBJ_DIR)/StringUtilsTest.o: $(TESTSRC_DIR)/StringUtilsTest.cpp $(INC_DIR)/StringUtils.h
	$(CXX) -o $@ -c $(CFLAGS) $<

#Cleans up built directories
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)

#Creates directories if not existing
directories:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)

