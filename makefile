CC	 = g++
FLAGS	 = -g -c -Wall -O3
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


all: $(OBJS)
	$(CC) -g $(OBJS) -o $(BINARYPATH)/$(OUT) $(LFLAGS)

lib: $(OBJECTPATH)/HCS.o
	ar rcs $(LIBRARYPATH)/HCS.lib $(OBJECTPATH)/HCS.o

test: 
	$(CC) ./Tests/HCStests.cpp $(LIBRARYPATH)/HCS.lib -o $(BINARYPATH)/$(OUT)

$(OBJECTPATH)/HCS.o: $(SOURCEPATH)/HCS.cpp $(INCLUDEPATH)/HCS.h
	$(CC) $(FLAGS) -I$(INCLUDEPATH) $(SOURCEPATH)/HCS.cpp -o $(OBJECTPATH)/HCS.o

$(OBJECTPATH)/HCStests.o: ./Tests/HCStests.cpp $(INCLUDEPATH)/HCS.h
	$(CC) $(FLAGS) -I$(INCLUDEPATH) ./Tests/HCStests.cpp -o $(OBJECTPATH)/HCStests.o

cleanLin:
	rm -f $(OBJS) $(BINARYPATH)/$(OUT)

cleanWin:
	del /f $(OBJS) $(BINARYPATH)\$(addsuffix .exe, $(OUT))