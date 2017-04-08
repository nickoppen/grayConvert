
CC = g++
DEFS += -DDEBUG
ESDK=${EPIPHANY_HOME}/tools/host

CCFLAGS += -g $(DEFS)
INCS = -I. 
LIBS = -L/usr/lib/arm-linux-gnueabihf -lopencv_core -lopencv_highgui -lopencv_imgproc


TARGET = grey2text.x text2grey.x

all: $(TARGET)
Debug: grey2text.x

.PHONY: clean install uninstall $(SUBDIRS)

.SUFFIXES: .c .o .x

grey2text.x: grey2text.o
	$(CC) -o grey2text.x grey2text.o $(LIBS)

grey2text.o: grey2text.cpp
	$(CC) $(CCFLAGS) $(INCS) -c grey2text.cpp -o grey2text.o

text2grey.x: text2grey.o
	$(CC) -o text2grey.x text2grey.o $(LIBS)

text2grey.o: text2grey.cpp
	$(CC) $(CCFLAGS) $(INCS) -c text2grey.cpp -o text2grey.o

cleanDebug: $(SUBDIRS)
	rm -f *.o
	rm -f *.x


cleanall: cleanDebug 
distclean: clean


