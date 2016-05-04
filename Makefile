#=================================================
# NEEDED PROPERTIES
#=================================================
OBJECTS = body.o star.o space.o universe.o main.o
CFLAGS = -c -Wall
FLAGS = -Wall -Werror -pedantic
LIB = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
TEST_LIB = -lboost_unit_test_framework
LINK = -L /usr/local/lib
INCLUDE = -I /usr/local/include
EXECUTABLE = NBody
CC = g++

# ===========================================
# Make the final program
all: $(EXECUTABLE)

# ===========================================
# Creating Executables
NBody: main.o universe.o star.o space.o spaceship.o body.o
	@echo '' # New line
	@echo ' ------ 	 target: $@'
	$(CC) $(FLAGS) main.o universe.o body.o star.o space.o spaceship.o -o NBody $(LINK) $(LIB)

# ===========================================
# Creating Executables
test: test.o universe.o body.o space.o
	@echo '' # New line
	@echo ' ------ 	 target: $@'
	$(CC) $(FLAGS) test.o universe.o space.o body.o -o test $(LINK) $(TEST_LIB)

# ===========================================
# Creating objects
test.o: test.cpp SpaceObject.hpp body.hpp Universe.hpp
	@echo '' # New line
	@echo ' ------ Building target: $@'
	$(CC) $(CFLAGS) $(INCLUDE) test.cpp -o test.o

# ===========================================
# Creating objects
body.o: body.cpp body.hpp SpaceObject.hpp
	@echo '' # New line
	@echo ' ------ Building target: $@'
	$(CC) $(CFLAGS) $(INCLUDE) body.cpp -o body.o

# ===========================================
# Creating objects
star.o: Star.cpp Star.hpp SpaceObject.hpp
	@echo '' # New line
	@echo ' ------ Building target: $@'
	$(CC) $(CFLAGS) $(INCLUDE) Star.cpp -o star.o

# ===========================================
# Creating objects
universe.o: Universe.cpp
	@echo '' # New line
	@echo ' ------ Building target: $@'
	$(CC) $(CFLAGS) $(INCLUDE) Universe.cpp -o universe.o

# ===========================================
# Creating objects
space.o: SpaceObject.cpp SpaceObject.hpp
	@echo '' # New line
	@echo ' ------ Building target: $@'
	$(CC) $(CFLAGS) $(INCLUDE) SpaceObject.cpp -o space.o

# ===========================================
# Creating objects
spaceship.o: SpaceShip.cpp SpaceShip.hpp
	@echo '' # New line
	@echo ' ------ Building target: $@'
	$(CC) $(CFLAGS) $(INCLUDE) SpaceShip.cpp -o spaceship.o

# ===========================================
# Creating objects
main.o: main.cpp Universe.hpp
	@echo '' # New line
	@echo ' ------ Building target: $@'
	$(CC) $(CFLAGS) $(INCLUDE) main.cpp -o main.o


clean:
	rm -rf *~ *.o test $(EXECUTABLE)
