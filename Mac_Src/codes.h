/*macros*/
//codes.h
//
#include "options.h"

//hide the shell cursor
#define CHIDE "\033[?25l"

//show the shell cursor
#define CSHOW "\033[?25h"

//define window size
#define SIZE "\033[8;33;28t"

//ansi code to clear the screen
#define CLEAR "\033[2J\033[1;1H"

#ifdef LINUX //use advanced characters
//pacman character
#define Rpman "\u15e7"
#define Lpman "\u15e4"
#define Upman "\u15e2"
#define Dpman "\u15e3"

#define ghost "\u156c"
#define dot "\u2981"
#define bigdot "\u0e4f"
#define fruit "\u2940"

#define over "\u02CD"
#define under "\u203E"

#else  //use basic characters

#define Rpman "p"
#define Lpman "p"
#define Upman "p"
#define Dpman "p"

#define ghost "M"
#define dot "o"
#define bigdot "O"
#define fruit "@"

#define over "-"
#define under "-"

#endif
typedef int Row;
typedef int Col;
