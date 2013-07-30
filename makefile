clean :
	rm *.o

singlemain : singlemain.cpp 
	gcc -Wall singlemain.cpp libsingleton.a -o singlemain

libsingleton.a : singleton.o
	ar cr libsingleton.a singleton.o
	
singeleton.o : singleton.cpp
	gcc -Wall -c singleton.cpp 



hellomake : hw.cpp
	 gcc -o hellomake hw.cpp -lstdc++ -lasound
	

hp : hw.cpp
	g++ hw.cpp
main : canonsoft.cpp
	gcc -Wall canonsoft.cpp	libhellobye.a -o main
		
libhellobye.a : hello.o bye.o
	ar cr libhellobye.a hello.o bye.o
	
hellobye : hello.cpp bye.cpp
	gcc -Wall -c hello.cpp
	gcc -Wall -c bye.cpp
	
