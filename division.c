////////////////////////////////////////////////////////////////////////////////
// Main File:        division.c
// This File:        division.c
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

//Handles int
void handler(int sig);
//Handles fpe
void handler1(int sig);
//Global structs
struct sigaction actInt;
struct sigaction actFPE;
int count;


void handler(int sig){
        printf("Error: a division by 0 operation was attempted. \n");
	printf("Total number of operations completed successfully: ");
        printf("%d", count);
	printf("\n");
        printf("The program will be terminated.\n");
        exit(0);

}
void handler1(int sig){
	printf("\nTotal number of operations completed successfully: ");
        printf("%d", count);
	printf("\n");
        printf("The program will be terminated.\n");
        exit(0);
}  

int main( int argc, const char* argv[] ){
	//Sets up int handler
        memset ( &actInt,  0, sizeof(actInt));
        actInt.sa_handler = handler1;
        sigaction(SIGINT, &actInt, NULL);
        //Sets up fpe handler
        memset ( &actFPE,  0, sizeof(actFPE));
        actFPE.sa_handler = handler;
        sigaction(SIGFPE, &actFPE, NULL);

	//Creates an infinite loop
	while(1){
		int quotient;
		int remainder;
		char num1[100];
		char num2[100];
		int int1;
		int int2;
		int count;
		//Gets first number
		printf("Enter first integer: " );
		fgets(num1, 100, stdin);
		//Gets second number
		printf("Enter second integer: " );
       		fgets(num2, 100, stdin);
		int1 = atoi(num1);
		int2 = atoi(num2);
		quotient = int1/int2;
		remainder = int1%int2;
		printf("%d", int1);
		printf(" / ");
		printf("%d", int2);
		printf(" is ");
		printf("%d", quotient);
		printf(" with a remainder of ");
		printf("%d", remainder);
		printf("\n");
		count++;
	}
	exit(0);
}

