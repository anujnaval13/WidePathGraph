CXX = g++
CXXFLAGS = -std=c++11 -Wall

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

INCLUDES = -I$(INC_DIR)

SOURCES = $(SRC_DIR)/edge.cpp $(SRC_DIR)/graph.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
