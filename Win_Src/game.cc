//game.cc

#include "class.h"
#include <iostream>
#include <cstdio>
#include <termios.h>
#include "title.h"

int main()
{	
	 
	char c;	
	map game;
	pacman player(game);
        enemy ghst1(game, 1);
	int begin = 0;
	//title screen
	 
	writeTitle();
	
	 while(!begin) //if p, start the game
	{
	std::cin>>c;
	  if (c == 'p') 
		begin = 1;
	 }
	
	std::cout<<CLEAR;
	int score = 0;
	game.reset();
	int counter = 0;
	printf("\033[37;1m");
	printf("\033[32;2H");
	std::cout<<"Score:"<<score;
	int n = 0;
	int win = 0;
	int lose = 0;

   while(!n)
   {
	 if (n == 0)
	{
        	std::cin>>c;
                ghst1.move(game, player, lose);	
		//spawn FRUIT!!
		if (counter == 100) { game.set(17,12,fruit); }
		if (counter == 200) { game.set(11,18,fruit); }

		if (c == 'q')
		{
			n = 1;
		}
	        else if (c == 'i')
		{
			player.move('i', game, ghst1, score, lose);
			printf("\a");
			n = 0;
		}
		else if (c == 'j')
		{
			player.move('j', game, ghst1, score, lose);
		        printf("\a");
			n = 0;
		}
		else if (c == 'k')
		{
			player.move('k', game, ghst1, score, lose);
		        printf("\a");
			n = 0;
		}
		else if (c == 'l')
		{
			player.move('l', game, ghst1, score, lose);
		        printf("\a");
			n = 0;
		}

			game.update(win);
			printf("\033\[32;2H");
			printf("\033[37;1m");
			std::cout<<"Score:"<<score;
                counter++;
		if (win) 
		{
		  printf("\033\[14;11H");
		  std::cout<<"YOU WIN!";
		  printf("\033\[15;12H");
		  std::cout<<"SCORE";
		  printf("\033\[16;12H");
		  std::cout<<score;
		  printf("\033\[17;8H");
		  std::cout<<"Press Q to quit";
		  while(1) {
                  std::cin>>c;
		   if (c=='q')
		  return 0;
                   }
		}
		if (lose)
		{
		  printf("\033\[14;11H");
		  std::cout<<"YOU LOSE";
		  printf("\033[17;8H");
		  std::cout<<"Press Q to quit";
		  while(1) {
	  	  std::cin>>c;
		  if (c=='q')
	              return 0;
		  } 
		}               
	}
    }
         	return 0;
}



