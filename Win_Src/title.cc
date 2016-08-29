//File containing title page

#include "title.h"
#include <iostream>
#include "codes.h"

void writeTitle()
{
	  
	   std::cout<<CLEAR;
	   std::cout<<"\033[40m";
	   std::cout<<"\033[34;1m";
           std::cout<<"**************************"<<std::endl;
	   std::cout<<"\033[33;1m";
	   std::cout<<"   _____  ______  ______  "<<std::endl; 
	   std::cout<<"  |     ||      ||      | "<<std::endl;
	   std::cout<<"  |  -  ||  --  ||   ___| "<<std::endl;
	   std::cout<<"  |   __||  __  ||  |___  "<<std::endl;
	   std::cout<<"  |  |   |  ||  ||      | "<<std::endl;
	   std::cout<<"  |__|   |__||__||______| "<<std::endl;
	   std::cout<<" _______  ______  __   __ "<<std::endl;
	   std::cout<<"|       ||      ||  | |  |"<<std::endl;
	   std::cout<<"|       ||  --  ||   ||  |"<<std::endl;
	   std::cout<<"| |   | ||  __  ||    |  |"<<std::endl;
	   std::cout<<"| ||_|| ||  ||  ||   |   |"<<std::endl;
	   std::cout<<"|_|   |_||__||__||___||__|"<<std::endl;
	   std::cout<<"\033[34;1m";
	   std::cout<<"                          "<<std::endl;
           std::cout<<"**************************"<<std::endl;
	   std::cout<<"\033[31;1m";
	   std::cout<<"                          "<<std::endl<<"  ";
	   std::cout<<dot<<' '<<bigdot<<' '<<dot<<' '<<bigdot<<' '<<ghost<<' '<<Rpman<<' '<<
	   ghost<<' '<<bigdot<<' '<<dot<<' '<<bigdot
	   <<' '<<dot<<"   "<<std::endl;
	   std::cout<<"\033[37;1m";
	   std::cout<<"     Collect Dots and     "<<std::endl;
	   std::cout<<"   Avoid Ghosts to Win!   "<<std::endl;
	   std::cout<<"                          "<<std::endl;
	   std::cout<<"         Controls         "<<std::endl;
	   std::cout<<"        I = Move up       "<<std::endl;
	   std::cout<<"       K = Move down      "<<std::endl;
	   std::cout<<"       J = Move left      "<<std::endl;
	   std::cout<<"       L = Move right     "<<std::endl;
	   std::cout<<"         Q = Quit         "<<std::endl;
	   std::cout<<"                          "<<std::endl;
	   std::cout<<"                          "<<std::endl;
	   std::cout<<"\033[36;1m";
           std::cout<<"      Press p to Begin    ";
}
	
