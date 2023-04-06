TRGDIR=.
OBJ=./obj
SRC=./src
INC=./inc
FLAGS= -Wall -pedantic -std=c++14 -iquote inc

${TRGDIR}/test_arytm_zesp: ${OBJ} ${OBJ}/main.o ${OBJ}/LZespolona.o\
                     ${OBJ}/WyrazenieZesp.o ${OBJ}/BazaTestu.o ${OBJ}/BazaTestu.o ${OBJ}/Statystyka.o
	g++ -o ${TRGDIR}/test_arytm_zesp ${OBJ}/main.o ${OBJ}/LZespolona.o\
                     ${OBJ}/WyrazenieZesp.o ${OBJ}/BazaTestu.o ${OBJ}/Statystyka.o

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: ${SRC}/main.cpp inc/LZespolona.hh inc/BazaTestu.hh
	g++ -c ${FLAGS} -o ${OBJ}/main.o ${SRC}/main.cpp

${OBJ}/LZespolona.o: ${SRC}/LZespolona.cpp inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/LZespolona.o ${SRC}/LZespolona.cpp

${OBJ}/Statystyka.o: ${SRC}/Statystyka.cpp inc/Statystyka.hh
	g++ -c ${FLAGS} -o ${OBJ}/Statystyka.o ${SRC}/Statystyka.cpp

${OBJ}/BazaTestu.o: ${SRC}/BazaTestu.cpp inc/BazaTestu.hh inc/WyrazenieZesp.hh\
                       inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/BazaTestu.o ${SRC}/BazaTestu.cpp

${OBJ}/WyrazenieZesp.o: ${SRC}/WyrazenieZesp.cpp inc/WyrazenieZesp.hh\
                       inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/WyrazenieZesp.o ${SRC}/WyrazenieZesp.cpp
run:
	${TRGDIR}/test_arytm_zesp latwy

clean:
	rm -f ${TRGDIR}/test_arytm_zesp ${OBJ}/*
