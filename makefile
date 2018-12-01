dealer: dealer.o
	g++ -o dealer dealer.o
dealer.o: dealer.cpp
	g++ -c dealer.cpp
