SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all:	letras cantidad_letras test_lista_palabras documentacion


letras: $(BIN)/letras

cantidad_letras: $(BIN)/cantidad_letras

test_lista_palabras: $(BIN)/test_lista_palabras
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(OBJ)/lista_palabras.o:	$(SRC)/lista_palabras.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/lista_palabras.o -Iinclude $(SRC)/lista_palabras.cpp

$(OBJ)/letras.o:	$(SRC)/letras.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/letras.o -Iinclude $(SRC)/letras.cpp

$(OBJ)/conjunto_letras.o:	$(SRC)/conjunto_letras.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/conjunto_letras.o -Iinclude $(SRC)/conjunto_letras.cpp

$(OBJ)/bolsa_letras.o:	$(SRC)/bolsa_letras.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/bolsa_letras.o -Iinclude $(SRC)/bolsa_letras.cpp



$(OBJ)/main_letras.o:	$(OBJ)/lista_palabras.o $(OBJ)/letras.o $(OBJ)/conjunto_letras.o $(OBJ)/bolsa_letras.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)/main_letras.o -Iinclude $(SRC)/main_letras.cpp

$(OBJ)/main_cantidad_letras.o:	$(OBJ)/lista_palabras.o $(OBJ)/letras.o $(OBJ)/conjunto_letras.o $(OBJ)/bolsa_letras.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)/main_cantidad_letras.o -Iinclude $(SRC)/main_cantidad_letras.cpp

$(OBJ)/main_test_lista_palabras.o:	$(OBJ)/lista_palabras.o
	$(CXX) $(CPPFLAGS) -o $(OBJ)/main_test_lista_palabras.o -Iinclude $(SRC)/test_lista_palabras.cpp



$(BIN)/letras:	$(OBJ)/main_letras.o
	$(CXX) -o bin/letras -Iinclude $(OBJ)/lista_palabras.o $(OBJ)/letras.o $(OBJ)/conjunto_letras.o $(OBJ)/bolsa_letras.o $(OBJ)/main_letras.o

$(BIN)/cantidad_letras:	$(OBJ)/main_cantidad_letras.o
	$(CXX) -o bin/cantidad_letras -Iinclude $(OBJ)/lista_palabras.o $(OBJ)/letras.o $(OBJ)/conjunto_letras.o $(OBJ)/bolsa_letras.o $(OBJ)/main_cantidad_letras.o

$(BIN)/test_lista_palabras:	$(OBJ)/main_test_lista_palabras.o
	$(CXX) -o bin/test_lista_palabras -Iinclude $(OBJ)/lista_palabras.o $(OBJ)/main_test_lista_palabras.o 



# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ 

mrproper : clean
	-rm $(BIN)/* doc/html/*
