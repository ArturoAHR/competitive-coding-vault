# Compiler settings
CXX = g++
CXXFLAGS = -Wall -g -std=c++17

# Template file
TEMPLATE = template.cpp

# Find the most recently modified CPP file in subdirectories
SRC := $(shell find . -name '*.cpp' -type f -printf '%T@ %p\n' | sort -k 1nr | cut -d' ' -f2- | head -1)

# Directory of the source file
DIR := $(dir $(SRC))

# Target file will be in the same directory as the source but with .out extension
TARGET := $(SRC:.cpp=.out)

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<

# Builds the executable if there isn't one already
build: $(TARGET)

# Build and run the executable
run: $(TARGET)
	./$(TARGET)

# Create a new problem file from the template
new:
ifndef PROBLEM
	$(error PROBLEM is not set. Usage: make new PROBLEM=problem_name)
endif
	@mkdir -p "$(PROBLEM)"
	@cp "$(TEMPLATE)" "$(PROBLEM)/$(PROBLEM).cpp"
	@echo "Created new problem: $(PROBLEM)/$(PROBLEM).cpp"

# Clean up
clean:
	find . -type f -name '*.out' -exec rm {} +
	clear

# Prevent make from doing something with a file named all, run, or new
.PHONY: all run new clean build