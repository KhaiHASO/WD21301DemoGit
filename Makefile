CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
BIN_DIR = bin
DEMO_DIR = demos

TARGETS = $(BIN_DIR)/main \
          $(BIN_DIR)/demo01 \
          $(BIN_DIR)/demo02 \
          $(BIN_DIR)/demo03 \
          $(BIN_DIR)/demo04 \
          $(BIN_DIR)/demo05

all: $(BIN_DIR) $(TARGETS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/main: main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(BIN_DIR)/demo01: $(DEMO_DIR)/01_basic_calculator.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(BIN_DIR)/demo02: $(DEMO_DIR)/02_array_and_sorting.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(BIN_DIR)/demo03: $(DEMO_DIR)/03_string_processing.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(BIN_DIR)/demo04: $(DEMO_DIR)/04_oop_student_management.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

$(BIN_DIR)/demo05: $(DEMO_DIR)/05_file_handling.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -rf $(BIN_DIR) *.csv

run: all
	./$(BIN_DIR)/main

.PHONY: all clean run
