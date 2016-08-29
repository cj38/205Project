
CCC=g++ 
CXXFLAGS= -std=c++11 

game: class.o game.o title.o
	$(CCC) -o game class.o game.o title.o

class.o: class.h codes.h

game.: class.h title.h

clean:
	rm -f *.o

real_clean: clean
	rm -f game
