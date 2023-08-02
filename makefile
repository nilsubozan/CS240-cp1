COURSE = cs240
SEMESTER = spring2022

# Update the CP_NUMBER if you adapt this makefile for future assignments
CP_NUMBER = 1

# Change the following to your own information
LASTNAME = Bozan
GITUSERID = nilsubozan
USER = zbozan1
# The name of the executable
EXE = play

# Name files according to CS240 naming conventions
REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)$(LASTNAME)$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj

# Store executables in a subdirectory
all: $(BIN)/$(EXE)
			$(BIN)/$(EXE)

$(BIN)/$(EXE): $(OBJ)/Play.o $(OBJ)/Player.o $(OBJ)/Team.o
	$(CC) $(FLAGS) $(OBJ)/Play.o $(OBJ)/Player.o $(OBJ)/Team.o -o $@

$(OBJ)/Play.o: Play.cpp
	$(CC) $(FLAGS) -c Play.cpp -o $@

$(OBJ)/Player.o: Player.h
	$(CC) $(FLAGS) -c Player.cpp -o $@

$(OBJ)/Team.o: Team.h
	$(CC) $(FLAGS) -c Team.cpp -o $@

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz

tar: clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)