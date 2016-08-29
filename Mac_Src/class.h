 //class definitions
 //class.h
#include <iostream> 
#include <cstring>
#include "codes.h"

class map
{
  public:
	//constructor, destructor
	map();
     	~map();
	
	//map print
	void reset();
	void update(int&);
        void points(int row, int col, int& score);
	//accessor
       std::string getscreen(int row, int col);
     void set(int y, int x, std::string s);
	int isValidPosition(int row, int col);
	
   //set underscore, overscore, or wall
   void Lrow(int y, int x, int amount);
   void Hrow(int y, int x, int amount);
   void Vcol(int y, int x, int amount);

   //set dots on screen
   
   void dotrow(int y, int x, int amount);  
   void dotcol(int y, int x, int amount);  
   
    private:
	std::string screen[31][28];
	std::string store[31][28];
	Row r;
	Col c;
};
class enemy;

class pacman
{
  public:
	pacman(map&);
	
	Row position1();
	Col position2();
	void move(char c, map&, enemy&, int& score, int& lose);
  private:
	Row r;
	Col c;

};

class enemy
{
  public:
	enemy(map&, int start);
	
	Row enemyy();
	Col enemyx();
	void initial();
	void move(map&, pacman&, int&);
  
   private:
	Row gy;
        Col gx;

}; 
        

