main: main.o employee.o manager.o
	g++ -o main.o employee.o manager.o

main.o: main.cpp
	g++ -c main.cpp

employee.o: employee.cpp employee.h
	g++ -c employee.cpp

manager.o: manager.cpp manager.h
	g++ -c manager.cpp

clean:
	-rm *.o
	-rm main