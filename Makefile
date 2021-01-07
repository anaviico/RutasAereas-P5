###############################################################################
##
##		Práctica 5 Estructura de Datos
##
##
##
##	Alumnos: Ana Lucía Vico Martínez y Carlos Salas Eiroa
##
##
###############################################################################


### variables de entorno


HOME = .
BIN = $(HOME)/bin
INCLUDE = $(HOME)/include
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib


### Compilación

all : presentar $(BIN)/rutas_aereas clean final


### presentación

presentar : 
	@echo "______      _                  "
	@echo "| ___ \    | |                 "
	@echo "| |_/ /   _| |_ __ _ ___       "
	@echo "|    / | | | __/ _\` / __|      "
	@echo "| |\ \ |_| | || (_| \__ \      "
	@echo "\_| \_\__,_|\__\__,_|___/      "
	@echo 
	@echo "  ___                          "
	@echo " / _ \                         "
	@echo "/ /_\ \ ___ _ __ ___  __ _ ___ "
	@echo "|  _  |/ _ \ '__/ _ \/ _\` / __|"
	@echo "| | | |  __/ | |  __/ (_| \\__ \\"
	@echo "\_| |_/\___|_|  \___|\__,_|___/"
	@echo
	@echo "[+] Compilando Pila_max..."
	@echo


### final

final :
	@echo "[+] Compilado"
	@echo


### Ejecutable

$(BIN)/rutas_aereas : $(OBJ)/rutas_aereas.o $(OBJ)/imagen.o
	g++ -o $(BIN)/rutas_aereas $(OBJ)/rutas_aereas.o $(OBJ)/imagen.o


### Objetos

$(OBJ)/rutas_aereas.o : $(SRC)/rutas_aereas.cpp $(SRC)/imagen.cpp $(INCLUDE)/Paises.h $(INCLUDE)/almacen_rutas.h $(INCLUDE)/imagen.h
	g++ -c -o $(OBJ)/rutas_aereas.o $(SRC)/rutas_aereas.cpp -I$(INCLUDE)

$(OBJ)/imagen.o : $(SRC)/imagen.cpp $(INCLUDE)/imagen.h
	g++ -o $(OBJ)/imagen.o $(SRC)/imagen.cpp -I$(INLCUDE)


### Limpieza de archivos

clean :
	-rm $(OBJ)/*.o

mr.proper : clean
	-rm $(BIN)/*