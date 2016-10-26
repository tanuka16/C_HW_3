#Homework 4 Makefile. 

HW: main.o Account.o Bank.o Depositer.o Name.o
	g++ -o HW main.o Account.o Bank.o Depositer.o Name.o

main.o: main.cpp
	g++ -c main.cpp

Account.o: Account.cpp Account.h
	g++ -c Account.cpp

Bank.o: Bank.cpp Bank.h
	g++ -c Bank.cpp

Depositer.o: Depositer.cpp Depositer.h
	g++ -c Depositer.cpp

Name.o: Name.cpp Name.h
	g++ -c Name.cpp

clean: rm ./*.o