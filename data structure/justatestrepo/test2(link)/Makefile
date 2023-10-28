//makefile 컴파일 파일
link.o  : link.cpp link.h
    gcc -c link.cpp
main.o  : main.cpp link.h
    gcc -c main.o
main.out    :   main.o link.o
    gcc -o main.out main.o link.o

    
