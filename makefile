CC	 = g++
FLAGS	 = -g -c -Wall -Wextra -O3 -I$(INCLUDEPATH)
LDFLAGS = -L$(LIBRARYPATH)
LFLAGS	 = 

SOURCEPATH = ./src
INCLUDEPATH = ./includes
OBJECTPATH = ./obj
LIBRARYPATH = ./lib
BINARYPATH = ./bin

OBJS	= $(OBJECTPATH)/HCS.o $(OBJECTPATH)/HCStests.o  
SOURCE	= HCS.cpp HCStests.cpp
HEADER	= HCS.h
OUT	= HCStests


all: lib test1
	$(CC) -g $(OBJS) -o $(BINARYPATH)/$(OUT) $(LFLAGS)

lib: $(OBJECTPATH)/HCS.o
	ar rcs $(LIBRARYPATH)/HCS.lib $(OBJECTPATH)/HCS.o

test1: $(OBJECTPATH)/HCStests.o
	$(CC) $(FLAGS) $(LDFLAGS) ./Tests/HCStests.cpp -l$(LIBRARYPATH)/HCS.lib -o $(BINARYPATH)/$(OUT)

$(OBJECTPATH)/HCS.o: $(SOURCEPATH)/HCS.cpp $(INCLUDEPATH)/HCS.h
	$(CC) $(FLAGS) $(SOURCEPATH)/HCS.cpp -o $(OBJECTPATH)/HCS.o

$(OBJECTPATH)/HCStests.o: ./Tests/HCStests.cpp $(INCLUDEPATH)/HCS.h
	$(CC) $(FLAGS) ./Tests/HCStests.cpp -o $(OBJECTPATH)/HCStests.o

cleanLin:
	rm -f $(OBJS) $(BINARYPATH)/$(OUT)

cleanWin:
	del /f $(OBJS) $(BINARYPATH)\$(addsuffix .exe, $(OUT))