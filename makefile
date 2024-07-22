# Compiler to use
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall

# Target executable
TARGET = hangman

# Source files
SRCS = main.cpp gameState.cpp gameDisplay.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(TARGET) $(OBJS)
