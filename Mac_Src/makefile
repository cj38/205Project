
CCC=g++ 
CXXFLAGS= -std=c++11 

game: class.o game.o title.o
	$(CCC) -o game class.o game.o title.o

class.o: class.h codes.h options.h

game.o: class.h title.h options.h codes.h

title.o: options.h codes.h

clean:
	rm -f *.o

real_clean: clean
	rm -f game
