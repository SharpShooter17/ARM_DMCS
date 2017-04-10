#===================================================================================
CXX        	= gcc
BIN_PATH  	= .
CODE_PATH 	= .
PROG_NAME 	= registers
LIB_PATH  	= 
INCLUDE_PATH 	=
LIB       	= 
CXXFLAGS    	= -static -g -Wall --pedantic $(INCLUDE_PATH:%=-I%) 

OBJ_LIB 	= libreg.o
#===================================================================================

All:	registers.o lib libreg.o registers.h 
	$(CXX)  $(CXXFLAGS) registers.o -L. -lreg -o $(BIN_PATH)/registers


registers.o : registers.c binarymacro.h registers.h
	$(CXX) -g -c registers.c -o $(BIN_PATH)/registers.o

libreg.o : libreg.c libreg.h
	$(CXX) -g -c libreg.c -o $(BIN_PATH)/libreg.o
	


.PHONY :  clean ALl

lib:	$(OBJ_LIB)
	ar  rcs   libreg.a $(OBJ_LIB)




clean:
	-rm -f $(PROG_NAME)
	-rm -f $(BIN_PATH)/*.o

libc:
	-rm -r libreg.a