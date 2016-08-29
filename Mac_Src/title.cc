//File containing title page

#include "title.h"
#include <iostream>
#include "codes.h"
#include "options.h"

void writeTitle()
{
	  
	   std::cout<<CLEAR;
	#ifdef COLOR
	   std::cout<<"\033[38;5;21m";
	#endif
           std::cout<<"**************************"<<std::endl;
	#ifdef COLOR
	   std::cout<<"\033[38;5;226m";
	#endif
	   std::cout<<"   _____  ______  ______  "<<std::endl; 
	   std::cout<<"  |     ||      ||      |"<<std::endl;
	   std::cout<<"  |  -  ||  --  ||   ___|"<<std::endl;
	   std::cout<<"  |   __||  __  ||  |___ "<<std::endl;
	   std::cout<<"  |  |   |  ||  ||      | "<<std::endl;
	   std::cout<<"  |__|   |__||__||______|"<<std::endl;
	   std::cout<<" _______  ______  __   __"<<std::endl;
	   std::cout<<"|       ||      ||  | |  |"<<std::endl;
	   std::cout<<"|       ||  --  ||   ||  |"<<std::endl;
	   std::cout<<"| |   | ||  __  ||    |  |"<<std::endl;
	   std::cout<<"| ||_|| ||  ||  ||   |   |"<<std::endl;
	   std::cout<<"|_|   |_||__||__||___||__|"<<std::endl;
	#ifdef COLOR
	   std::cout<<"\033[38;5;21m";
	#endif
	   std::cout<<std::endl<<"**************************"<<std::endl;
	#ifdef COLOR
	   std::cout<<"\033[38;5;255m";
	#endif
	   std::cout<<std::endl<<"   ";
	   std::cout<<dot<<' '<<bigdot<<' '<<dot<<' '<<bigdot<<' '<<ghost<<' '<<Rpman<<' '<<
	   ghost<<' '<<bigdot<<' '<<dot<<' '<<bigdot
	   <<' '<<dot<<std::endl;
	#ifdef COLOR
	   std::cout<<"\033[38;5;118m";
	#endif
	   std::cout<<"     Collect Dots and"<<std::endl;
	   std::cout<<"   Avoid Ghosts to Win!"<<std::endl<<std::endl;
	   std::cout<<"         Controls"<<std::endl;
	   std::cout<<"        I = Move up"<<std::endl;
	   std::cout<<"       K = Move down"<<std::endl;
	   std::cout<<"       J = Move left"<<std::endl;
	   std::cout<<"       L = Move right"<<std::endl;
	   std::cout<<"         Q = Quit"<<std::endl;
	   std::cout<<std::endl<<std::endl;
	#ifdef COLOR
	   std::cout<<"\033[38;5;21m";
	#endif
           std::cout<<"      Press p to Begin";
}
	
