SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c






# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************


$(BIN)/pruebadiccionario:	obj/pruebadiccionario.o obj/Termino.o obj/Diccionario.o
	g++ -o bin/pruebadiccionario -Iinclude obj/pruebadiccionario.o obj/Termino.o obj/Diccionario.o

obj/Termino.o:	src/Termino.cpp include/Termino.h 
	g++ -c -o obj/Termino.o -Iinclude src/Termino.cpp

obj/Diccionario.o:	src/Diccionario.cpp include/Diccionario.h src/Termino.cpp include/Termino.h 
	g++ -c -o obj/Diccionario.o -Iinclude src/Diccionario.cpp

obj/pruebadiccionario.o:	include/Termino.h src/Termino.cpp include/Diccionario.h src/Diccionario.cpp src/pruebadiccionario.cpp
	g++ -c -o obj/pruebadiccionario.o -Iinclude src/pruebadiccionario.cpp




# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
