all: dealer hand
dealer: dealer.o
	g++ -o dealer dealer.o
dealer.o: dealer.cpp
	g++ -c dealer.cpp
hand: hand.o
	g++ -o hand hand.o
hand.o: hand.cpp
	g++ -c hand.cpp
