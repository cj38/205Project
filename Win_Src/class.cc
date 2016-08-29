// class functions 
//class.cc

#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include "class.h"
#include <cstdio>
#include "codes.h"
#include <math.h>
#include <stdlib.h>

map::map()
{
        
	/* set border - */
	for (int i(0); i < 1; i++)
	    {
		for (int j(0); j < 28; j++)
		{
		  screen[i][j] = Lborder;
		  store[i][j] = Lborder;
		}
	    }
	for (int i(30); i < 31; i++)
	  {
             for (int j(0); j < 28; j++)
               {
                  screen[i][j] = Oborder;
		  store[i][j] = Oborder;
	       }
	   }

	/*set border | */
 
	for (int i(1); i<30; i++)
	    {
		for (int j(0); j < 28; j++)
		{
		  screen[i][j] = '|';
		store[i][j] = '|';
		  j = j + 26;
		}
	    }
	/* populate */
	for (int i(1); i<30; i++)
	{
		for (int j(1); j < 27; j++)
		{
		  screen[i][j] = ' ';
		  store[i][j] = ' ';
		   }
	}
	/* pacman position */
	screen[23][14] = Rpman;
	store[23][14] = Rpman;
       
        /*  ghost insert */
	screen[14][14] = ghost;
	store[14][14] = ghost;

       		//special case border cut
		screen[9][0] = ' ';
		screen[10][0] = ' ';
		screen[11][0] = ' ';
		screen[12][0] = ' ';
		screen[13][0] = ' ';
		screen[9][27] = ' ';
		screen[10][27] = ' ';
		screen[11][27] = ' ';
		screen[12][27] = ' ';
		screen[13][27] = ' ';
		
		screen[14][0] = ' ';
		screen[14][27] = ' ';

		screen[15][0] = ' ';
		screen[16][0] = ' ';
		screen[17][0] = ' ';
		screen[18][0] = ' ';
		screen[19][0] = ' ';
		screen[15][27] = ' ';
		screen[16][27] = ' ';
		screen[17][27] = ' ';	
		screen[18][27] = ' ';
		screen[19][27] = ' ';	

	/* draw walls */
	Hrow(2,2,4); Lrow(4,2,4); Vcol(2,2,3); Vcol(2,5,3);
	Hrow(2,7,5); Lrow(4,7,5); Vcol(2,7,3); Vcol(2,11,3);
	Vcol(1,13,4); Vcol(1,14,4);
	Hrow(2,16,5); Lrow(4,16,5); Vcol(2,16,3); Vcol(2,20,3);
	Hrow(2,22,4); Lrow(4,22,4); Vcol(2,22,3); Vcol(2,25,3);
		
	Hrow(6,2,4); Lrow(7,2,4); Vcol(6,2,2); Vcol(6,5,2);
	Hrow(6,23,2); Lrow(7,23,2); Vcol(6,22,2); Vcol(6,25,2);
	
	Hrow(9,1,4); Lrow(13,1,4); Vcol(9,5,5);	
	Hrow(9,23,4); Lrow(13,23,4); Vcol(9,22,5);
	Hrow(15,1,4); Lrow(19,1,4); Vcol(15,5,5);
	Hrow(15,23,4); Lrow(19,23,4); Vcol(15,22,5);

	Hrow(21,3,2); Lrow(22,3,2); Vcol(21,2,2); Vcol(23,4,3); 
	Vcol(21,5,5);
	Hrow(21,8,3); Lrow(22,8,3); Vcol(21,7,2); Vcol(21,11,2);
	Hrow(21,17,3); Lrow(22,17,3); Vcol(21,16,2); Vcol(21,20,2);
	Hrow(21,23,2); Lrow(22,23,2); Vcol(21,22,5); Vcol(23,23,3);
	Vcol(21,25,2);

	Hrow(24,1,1); Lrow(25,1,1); Vcol(24,2,2);
	Hrow(24,26,1); Lrow(25,26,1); Vcol(24,25,2);
	
	
	//ultimate center pieces
	Vcol(6,7,8); Vcol(6,8,8); Hrow(9,9,2); Lrow(10,9,2); Vcol(9,11,2);
	Hrow(6,10,8); Lrow(7,10,8); Vcol(6,10,2); Vcol(6,17,2);
	Vcol(8,13,3); Vcol(8,14,3); 	
	Hrow(9,17,2); Lrow(10,17,2); Vcol(9,16,2); Vcol(6,19,8);
	Vcol(6,20,8); 
 	
	Hrow(12,11,6); Lrow(16,11,6); Vcol(12,10,5); Vcol(12,17,5);

	Vcol(15,7,5); Vcol(15,8,5);
	Vcol(15,19,5); Vcol(15,20,5);
	
	Hrow(18,11,6); Lrow(19,11,6); Vcol(18,10,2); Vcol(18,17,2);
	Vcol(20,13,3); Vcol(20,14,3);
	
	Hrow(24,11,6); Lrow(25,11,6); Vcol(24,10,2); Vcol(24,17,2);
	Vcol(26,13,3); Vcol(26,14,3);

	Hrow(27,3,8); Lrow(28,3,8); Vcol(27,2,2); Vcol(27,11,2);
	Vcol(24,7,3); Vcol(24,8,3);
	
	Hrow(27,17,8); Lrow(28,17,8); Vcol(27,16,2); Vcol(27,25,2);
	Vcol(24,19,3); Vcol(24,20,3);	

	//draw dots
	dotrow(1,1,12); dotrow(1,15,12);
	dotrow(5,1,26);
	dotrow(8,1,6); dotrow(8,9,4); dotrow(8,15,4); dotrow(8,21,6); 
	dotrow(20,1,12); dotrow(20,15,12);
	dotrow(23,1,3); dotrow(23,6,7); dotrow(23,15,7); dotrow(23,24,3);
	dotrow(26,1,6); dotrow(26,9,4); dotrow(26,15,4); dotrow(26,21,6);
	dotrow(29,1,26);

	dotcol(1,1,8); dotcol(20,1,4); dotcol(26,1,4);
	dotcol(23,3,4);
	dotcol(1,6,26);
	dotcol(5,9,4); dotcol(23,9,4);
	dotcol(1,12,5); dotcol(20,12,4); dotcol(26,12,4);
	
	dotcol(1,26,8); dotcol(20,26,4); dotcol(26,26,4);
	dotcol(23,24,4);
	dotcol(1,21,26);
	dotcol(5,18,4); dotcol(23,18,4);
	dotcol(1,15,5); dotcol(20,15,4); dotcol(26,15,4);

	//draw big dots
	set(3,1,bigdot);
	set(3,26,bigdot);
	set(23,1,bigdot);
	set(23,26,bigdot);

       /*setup environment, noncanonical */
	struct termios input;
	tcgetattr(STDIN_FILENO, &input);
	input.c_lflag &= ~ICANON;
	input.c_lflag &= ~ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &input);

	struct winsize scr;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &scr);
	r = scr.ws_row;
	c = scr.ws_col;	
	std::cout<<CLEAR<<CHIDE<<SIZE;
        
}

/* Destructor */
map::~map()
{
	printf("\033[8;%d;%dt", r, c);
	printf("\033[%d;%dH", r, 1);

	struct termios input;
	tcgetattr(STDIN_FILENO, &input);
	input.c_lflag |= ICANON;
	input.c_lflag |= ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &input);

	std::cout<<CLEAR<<CSHOW;
}

/* Map Functions */
void map::set(int y, int x, std::string s)
{
      screen[y][x] = s;
}

void map::Lrow(int y, int x, int amount)
{
	for (int i = 0; i < amount; i++)
	  {
	    set(y,x,Lborder);
	      x++;
	  }
}
 
void map::Hrow(int y, int x, int amount)
{
	for (int i = 0; i< amount; i++)
	 {
	     set(y,x,Oborder);
	     x++;
	 }
}

void map::Vcol(int y, int x, int amount)
{
	for (int i = 0; i < amount; i++)
	{
	    set(y,x,"|");
	    y++;
	}
}
//dot functions
void map::dotrow(int y, int x, int amount)
{
	for (int i = 0; i< amount; i++)
	 {
	     set(y,x,dot);
	     x++;
	 }
}

void map::dotcol(int y, int x, int amount)
{
	for (int i = 0; i < amount; i++)
	{
	    set(y,x,dot);
	    y++;
	}
}



//accessor
std::string map::getscreen(int row, int col)
{
	return screen[row][col];
}

int map::isValidPosition(int row, int col)
{
	std::string a = getscreen(row, col);
	if (a == "_" || a == Lborder || a == "|" || a ==Oborder)
	return 0;

	else if ((row==15 && col==27) || (row==13 && col==27)
               || (row==15 && col==0) || (row==13 && col==0))
		return 0;

	else return 1;
} 

void map::points(int row, int col, int& score)
{
	std::string a = getscreen(row, col);
	if (a == dot)
	{
	  score = score + 10;
	}
	if (a == bigdot)
	{
	  score = score + 50;
	}
	if (a == fruit)
	{
	  score = score + 200;
	}
	
}
	
/* print map*/
void map::reset()
{
	for (int i(0); i < 31; i++)
	  {
		for (int j(0); j < 28; j++)
          	{
		 if ((screen[i][j] == "|") || (screen[i][j] == Lborder)
			|| (screen[i][j] == Oborder) || (screen[i][j] == "_"))
			{
			   printf("\033[34;1m");
			}

		     std::cout<< screen[i][j];
                 }
		       std::cout<<std::endl;
	   }
}	
	
/* print updated map*/			
void map::update(int& win)
{
	Row correctiony = 0;
	Col correctionx = 0;
	win = 1;
	for (int i(0); i < 31; i++)
	  {
		for (int j(0); j < 28; j++)
		{

		/* Do dots exist? if not, game over */
                  if (screen[i][j] ==  dot) win = 0;

		/* only update the changes */
		   if (screen[i][j] != store[i][j])
		    {
			store[i][j] = screen[i][j];

		//cursor shift
			correctiony = i + 1;
			correctionx = j + 1;
		printf("\033[%d;%dH", correctiony, correctionx);
                  //print
                  if ((screen[i][j] == Rpman) || (screen[i][j] == Lpman)
			|| (screen[i][j] == Upman) || (screen[i][j] == Dpman))
			{
			   printf("\033[33;1m");
			}
		else if ((screen[i][j] == "|") || (screen[i][j] == Lborder)
			|| (screen[i][j] == Oborder) || (screen[i][j] == "_"))
			{
			   printf("\033[34;1m");
			}
               else if ((screen[i][j] == dot) || (screen[i][j] == bigdot))
			{
			   printf("\033[37;1m");
			}
		else if ((screen[i][j] == fruit))
			{
			   printf("\033[31;1m");
			}
		else if (screen[i][j] == ghost)
			{
			   printf("\033[35;1m");
			}

		else 
		{
		  printf("\033[34;1m");
		}

			std::cout<<screen[i][j];
	
		    }
		}
	   }
}
//new class

pacman::pacman(map& m)
{
	 r = 23;
	 c = 14;
}

Row pacman::position1(map& m)
{
	return r;
}

Col pacman::position2(map& m)
{
	return c;
}

void pacman::move(char n, map& m, enemy& g, int& score, int& lose)
{
	if(m.getscreen(position1(m), position2(m)) == ghost)
	{
		lose = 1;
		return;
	}

	if (n == 'i')  //move up
	{ 

          if ( m.isValidPosition(position1(m)-1,position2(m)) )	
	   { 
	      m.points(position1(m)-1,position2(m), score);
	      m.set(position1(m), position2(m)," ");
	      m.set(position1(m)-1,position2(m), Upman);
	      r--;	
   	   } 		
	}

	else if (n == 'k') //move down
	{
	
	  if ( m.isValidPosition(position1(m)+1,position2(m)) )	
            {
	       m.points(position1(m)+1,position2(m), score);
               m.set(position1(m), position2(m)," ");
	       m.set(position1(m)+1, position2(m), Dpman);
	       r++;
            }
	}

	else if (n == 'j')  //move left
	{
	 
	  if ( m.isValidPosition(position1(m),position2(m)-1) )
	    {
	       m.points(position1(m), position2(m)-1, score);
	       m.set(position1(m), position2(m), " ");
	       m.set(position1(m), position2(m)-1, Lpman);
	       c--;
            }
	}

	else if (n == 'l')   //move right
	{
	
	  if ( m.isValidPosition(position1(m),position2(m)+1) )
	  {
	       m.points(position1(m), position2(m)+1, score);
	       m.set(position1(m), position2(m), " ");
	       m.set(position1(m), position2(m)+1, Rpman);
	       c++;
	  }
	}
	
	//Tunnel Fix
        if (position1(m) == 14 && position2(m) == 28)
	{
	  m.set(position1(m), position2(m), " ");
	  m.set(position1(m)-1, position2(m), Rpman); 
	  c=0;
	}
	if (position1(m) == 14  && position2(m) == -1)
	{
	   m.set(position1(m), position2(m), " ");
           m.set(position1(m)+1, position2(m), Lpman);
           r=14; c=27;
	}

	if  ((r == g.enemyy()) && (c == g.enemyx()))
	{
	   lose = 1;
	}


}
              
enemy::enemy(map& m, int start)
{
        if(start == 1)
        {
                gy = 14;
                gx = 14;
        }
}



Row enemy::enemyy()
{
	return gy;
}

Col enemy::enemyx()
{
	return gx;
}


void enemy::move(map& m, pacman& p, int& lose)
{
   // Move out of ghost box 
     if (m.getscreen(14,14) == ghost) 
	{  
	m.set(enemyy(), enemyx(), " ");
	m.set(enemyy()-1, enemyx(), ghost);
	gy = 13;
        }
     else if (m.getscreen(13,14) == ghost)
	{
	m.set(enemyy(), enemyx(), " ");
	m.set(enemyy()-1, enemyx(), ghost);
        gy = 12;
	}
    else if (m.getscreen(12,14) == ghost)
	{
	m.set(enemyy(), enemyx(), Lborder);
        m.set(enemyy()-1, enemyx(), ghost);
        gy = 11;
        }
    // outside of box 
    else
   {
   //clear current ghost position
    m.set(enemyy(), enemyx(), " ");

   int special = 0;
   float dist1=1000, dist2=1000, dist3=1000, dist4=1000;
   float currentdist = sqrt(pow(abs(enemyy() - p.position1(m)), 2) + pow(abs(enemyx() - p.position2(m)),2)); 
   // If it is possible to move up
   if(m.isValidPosition(enemyy()-1, enemyx()))
   {
	   //Find distance to pacman
	   dist1 = sqrt(pow(abs(enemyy()-1 - p.position1(m)), 2) + pow(abs(enemyx() - p.position2(m)), 2));
   }
   
   // If it is possible to move down
   if(m.isValidPosition(enemyy()+1, enemyx()))
   {
	   //Find distance to pacman
	   dist2 = sqrt(pow(abs(enemyy()+1 - p.position1(m)), 2) + pow(abs(enemyx() - p.position2(m)), 2));
   } 

   // If it is possible to move left
   if(m.isValidPosition(enemyy(), enemyx()-1))
   {
	   //Find distance to pacman
	   dist3 = sqrt(pow(abs(enemyy() - p.position1(m)), 2) + pow(abs(enemyx()-1 - p.position2(m)), 2));
   }

   // If it is possible to move right
   if(m.isValidPosition(enemyy(), enemyx()+1))
   {
	   //Find distance to pacman
	   dist4 = sqrt(pow(abs(enemyy() - p.position1(m)), 2) + pow(abs(enemyx()+1 - p.position2(m)), 2));
   }
   
	   //Determine which direction to move
	   if(dist1<dist2 && dist1<dist3 && dist1<dist4)
	   {
		   m.set(enemyy()-1, enemyx(), ghost);
		   gy = gy - 1;
		   return;
	   }	 

	   if(dist2<dist1 && dist2<dist3 && dist3<dist4)
	   {
		   m.set(enemyy()+1, enemyx(), ghost);
		   gy = gy + 1;
		   return;
	   }

	   if(dist3<dist1 && dist3<dist2 && dist3<dist4)
	   {
		   m.set(enemyy(), enemyx()-1, ghost);
		   gx = gx - 1;
		   return;
	   }

	   if(dist4<dist1 && dist4<dist2 && dist4<dist2)
	   {
		   m.set(enemyy(), enemyx()+1, ghost);
		   gx = gx + 1;
		   return;
	   }
	   // If no clear option just pick one that lessens distance
	   else
	   {
			   if(dist1<currentdist)
			   {
				   m.set(enemyy()-1, enemyx(), ghost);
				   gy = gy - 1;
				   return;
			   }	 

			   if(dist2<currentdist)
			   {
				   m.set(enemyy()+1, enemyx(), ghost);
				   gy = gy + 1;
				   return;
			   }

			   if(dist3<currentdist)
			   {
				   m.set(enemyy(), enemyx()-1, ghost);
				   gx = gx - 1;
				   return;
			   }

			   if(dist4<currentdist)
			   {
				   m.set(enemyy(), enemyx()+1, ghost);
				   gx = gx + 1;
				   return;
			   }
	   }
	if  (p.position1(m) == gy && (p.position2(m) == gx))
	{
	   lose = 1;
	}

    }
}	


