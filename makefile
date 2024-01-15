CXX = g++
CXXFLAGS = -std=c++17

# Target executable name
TARGET = Library
TEST_TARGET = test_app

# Source files
SOURCES := $(wildcard *.cpp)
HEADERS	 := $(wildcard *.h)
TEST_SOURCES := $(wildcard test/*.cpp)
EXCLUDED_SRC := library.cpp
INCLUDED_SRC := $(filter-out $(EXCLUDED_SRC), $(SOURCES))


# Object files
OBJECTS = $(SOURCES:.cpp=.o)
REGULAR_OBJECTS_FOR_TEST = $(INCLUDED_SRC:%.cpp=test/%.o)
TEST_OBJECTS := $(TEST_SOURCES:test/%.cpp=test/%.o)
ALL_OBJECTS := $(REGULAR_OBJECTS_FOR_TEST) $(TEST_OBJECTS)

# Default target
all: clean $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Compile source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target for removing compiled files
clean:
	rm -f $(TARGET)  $(TEST_TARGET) $(OBJECTS)
	rm -f test/*.o

# Run the program
run: $(TARGET)
	./$(TARGET)

# Target for running tests
test: $(TEST_TARGET)

# Compile source files in the 'test' directory into object files
test/%.o: test/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile source files into object files
test/%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build the test executable
$(TEST_TARGET): $(ALL_OBJECTS)
	$(CXX) $(CXXFLAGS) $(ALL_OBJECTS) -o $(TEST_TARGET)






# Phony targets
.PHONY: all run clean
