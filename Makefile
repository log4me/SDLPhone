CPPFLAGS = -g -std=c++11 $(shell sdl2-config --cflags) 
SRC = $(shell ls *.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = phone
	
LIBS = $(shell sdl2-config --libs) 
LIBS += -lSDL2_image -lSDL2_mixer -lSDL2_ttf
 

${TARGET} : ${OBJ}
	g++ -o $@ ${OBJ} ${LIBS}
run:
	./${TARGET}

clean:
	rm -fr ${TARGET}
	rm -fr *.o 
