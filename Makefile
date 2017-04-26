
CC = g++
DEFS += -DDEBUG -std=gnu++11
ESDK=${EPIPHANY_HOME}/tools/host

CCFLAGS += -g $(DEFS)
INCS = -I. 
LIBS = -L/usr/lib/arm-linux-gnueabihf -lopencv_core -lopencv_highgui -lopencv_imgproc


TARGET = gray2text.x text2gray.x

all: $(TARGET)
gray2text: gray2text.x
text2gray: text2gray.x

.PHONY: clean install uninstall $(SUBDIRS)

.SUFFIXES: .c .o .x

gray2text.x: gray2text.o
	$(CC) -o gray2text.x gray2text.o $(LIBS)

gray2text.o: gray2text.cpp
	$(CC) $(CCFLAGS) $(INCS) -c gray2text.cpp -o gray2text.o

text2gray.x: text2gray.o
	$(CC) -o text2gray.x text2gray.o $(LIBS)

text2gray.o: text2gray.cpp
	$(CC) $(CCFLAGS) $(INCS) -c text2gray.cpp -o text2gray.o

cleanDebug: $(SUBDIRS)
	rm -f *.o
	rm -f *.x


cleanall: cleanDebug 
distclean: clean


