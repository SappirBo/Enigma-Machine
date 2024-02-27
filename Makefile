# Makefile for compiling a C++ project with main file and additional classes

# Compiler to use
CXX = g++

# Compiler flags, -I adds include directory of header files
CXXFLAGS = -I include

# Name of the executable to produce
TARGET = Enigma

# Object files that the project depends on
OBJ = main.o src/Rotor.o src/RotorData.o src/Reflector.o src/Plugboard.o src/Enigma.o

# Rule for making the final executable
$(TARGET): $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ)

# Rule for compiling the main program file
# Updated to include dependency on Keywords.hpp and Rotor.hpp
main.o: main.cpp include/Rotor.hpp include/Keywords.hpp include/Enigma.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Rule for compiling the Rotor class
src/Rotor.o: src/Rotor.cpp include/Rotor.hpp include/RotorData.hpp
	$(CXX) $(CXXFLAGS) -c src/Rotor.cpp -o src/Rotor.o

# Rule for compiling the RotorData class
src/RotorData.o: src/RotorData.cpp include/RotorData.hpp
	$(CXX) $(CXXFLAGS) -c src/RotorData.cpp -o src/RotorData.o

# Rule for compiling the Reflector class
src/Reflector.o: src/Reflector.cpp include/Reflector.hpp
	$(CXX) $(CXXFLAGS) -c src/Reflector.cpp -o src/Reflector.o

# Rule for compiling the Plugboard class
src/Plugboard.o: src/Plugboard.cpp include/Plugboard.hpp
	$(CXX) $(CXXFLAGS) -c src/Plugboard.cpp -o src/Plugboard.o

# Rule for compiling the Enigma class
src/Enigma.o: src/Enigma.cpp include/Enigma.hpp include/Plugboard.hpp include/RotorData.hpp include/Reflector.hpp
	$(CXX) $(CXXFLAGS) -c src/Enigma.cpp -o src/Enigma.o

# Rule for cleaning up the project (removes object files and the executable)
clean:
	rm -f $(TARGET) $(OBJ)
