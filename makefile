main:main.o operation.o Input.o Judge.o Output.o operation.h handle.h
	g++ main.o operation.o Input.o Judge.o Output.o operation.h handle.h -o main
main.o:main.cpp
	g++ -c main.cpp -o main.o
operation.o:operation.cpp
	g++ -c operation.cpp -o operation.o
Input.o:Input.cpp
	g++ -c Input.cpp -o Input.o
Judge.o:Judge.cpp
	g++ -c Judge.cpp -o Judge.o
Output.o:Output.cpp
	g++ -c Output.cpp -o Output.o
clean:
	rm *.o
	rm main
	rm *.out
	rm *.txt
