////////////////////////////////////////////////////////////////////////////////
// Main File:        sendsig.c
// This File:        sendsig.c
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
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int main (int argc, const char* argv[]){
	pid_t pid = atoi(argv[2]);
	// Terminate if argc is less than 3
	if(argc < 3){
		printf("Usage: <signal type> <pid>\n");
		exit(1);
	}
	int intTrue = strcmp(argv[1], "-i");
	int usr1True = strcmp(argv[1], "-u");
	//Sends SIGUSR1 if command 2 is -u
	if(usr1True == 0){
		kill(pid, SIGUSR1);
	}
	//Sends SIGINt if command 2 is -i
	if(intTrue == 0){
		kill(pid, SIGINT);
	}
	return 0;
}

