////////////////////////////////////////////////////////////////////////////////
// Main File:        intdate.c
// This File:        intdate.c
// Other Files:      
// Semester:         CS 354 Spring 2017
//
// Author:           Amber Johnson
// Email:            ajohnson42@wisc.edu
// CS Login:         amberj
//
/////////// IF PAIR PROGRAMMING IS ALLOWED, COMPLETE THIS SECTION //////////////
//
// Pair Partner:     (name of your pair programming partner)
// Email:            (email address of your programming partner)
// CS Login:         (partner's CS login name)
//
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//
// Persons:          Identify persons by name, relationship to you, and email.
//                   Describe in detail the the ideas and help they provided.
//
// Online sources:   avoid web searches to solve your problems, but if you do
//                   search, be sure to include Web URLs and description of 
//                   of any information you find.
//////////////////////////// 80 columns wide ///////////////////////////////////
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
//Handles alarm
void handler(int sig);
//Handles user
void handler1(int sig);
//Handles int
void handler2(int sig);
//Global structs
struct sigaction act;
struct sigaction actUser;
struct sigaction actInt;
//Global counter
int count = 0;

void handler(int sig){
	//Create time variable
	time_t currentTime;
	//Gets time
	time(&currentTime);
	//{rint time and PID
	printf("PID: %d | Current Time: %s", (int)getpid(), ctime(&currentTime));
	//Re-arm alarm
	alarm(3);
}
void handler1(int sig){
	printf("SIGUSR1 caught!\n");
	count++;
}
void handler2(int sig){
	printf("\nSIGINT received.\n");
	printf("SIGUSR1 was received %d times. Exiting now.\n", count);
	exit(0);
}

int main( int argc, const char* argv[] )
{
        //Sets up alarm handler
        memset ( &act,  0, sizeof(act));
        act.sa_handler = handler;
        sigaction(SIGALRM, &act, NULL);
        //Sets up usr1 handler
        memset ( &actUser,  0, sizeof(actUser));
        actUser.sa_handler = handler1;
        sigaction(SIGUSR1, &actUser, NULL);

        //Sets up usr1 handler
        memset ( &actInt,  0, sizeof(actInt));
        actInt.sa_handler = handler2;
        sigaction(SIGINT, &actInt, NULL);

        //Print instructions
        printf("Pid and time will be printed every 3 seconds.\n");
        printf("Enter ^C to end the program.\n");
        //Sets the alarm
        alarm(3);
        while(1){
        }
}

