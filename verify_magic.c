///////////////////////////////////////////////////////////////////////////////
// Main File:        p2
// This File:        verify_magic.c
// Other Files:      generate_magic.c
// Semester:         CS 354 Spring 2017
//
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
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure representing Square
// size: dimension(number of rows/columns) of the square
// array: 2D array of integers
typedef struct _Square {
	int size;
	int **array;
} Square;

Square * construct_square(char *filename);
int verify_magic(Square * square);

int main(int argc, char *argv[])
{
	// Check input arguments to get filename
  	char* fileName;

	if(argc == 2){
		fileName = argv[1];
	}
	else{
		printf("Use: ./verify_magic <filename>\n");
		exit(1);
	}
	// Construct square
	Square *square = construct_square(fileName);

	// Verify if it's a magic square and print true or false
	if(verify_magic(square)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	//Free up memory
	for (int i = square->size - 1; i >= 0; i--){
		free(*(square->array+i));
	}
	free(square);
	return 0;

}

/* construct_square reads the input file to initialize a square struct
 * from the contents of the file and returns the square.
 * The format of the file is defined in the assignment specifications
 */
Square * construct_square(char *filename)
{
	// Open and read the file
	FILE* file;
	file = fopen (filename, "r");
	if (file == NULL) {
		printf("Cannot open file for reading.");
		exit(1);
	}
	// Read the first line to get the square size
 	char line[256];//Line buffer
	fgets(line, sizeof(line), file);
	int sizeSquare = atoi(line);

	//Create array
	int **n = (int**)malloc(sizeSquare * sizeof(int *));
	if(n) {
		for(int i = 0; i < sizeSquare; i++){
			*(n + i) = (int*)malloc(sizeSquare * sizeof(int));
		}
	}
	else{
		printf("Could not allocate memory");
		exit(1);
	}


	// Initialize a new Square struct of that size
	Square *square = malloc(sizeof(Square));
	if(square){
		square->array = n;
		square->size = sizeSquare;
	}
	else{
		printf("Could not allocate memory");
                exit(1);
        }
	n = NULL;
	// Read the rest of the file to fill up the square
	int row;
	int col;
	char* token;
	//Parse file into square
	for (row = 0; row < square->size; row++){
		col = 0;
		fgets(line, sizeof(line), file);
		token = strtok(line, ",");
		*(*(square->array+row)+col) = atoi(token);
		while(token != NULL){
			token = strtok(NULL, ",");
			if (token != NULL) {
				col++;*(*(square->array+row)+col) = atoi(token);
			}
		}
	}
	fclose(file);// Closes the file

	return square;
}

/* verify_magic verifies if the square is a magic square
 * 
 * returns 1(true) or 0(false)
 */
int verify_magic(Square * square)
{ 
	//Initalize variables
	int row;
	int column;
	int sum;
	int test;
	// Check all rows sum to same number
	sum = 0;	
	for (row = 0; row < square->size; row++) {
	sum = 0;
		for (column = 0; column < square->size; column++) {
			sum = sum + *(*(square->array+row)+column);
		}
		test = sum;
		if (sum == test){
		}
		else {
			printf("false\n");
			exit(1);
		}
	}

	// Check all cols sum to same number
 	sum = 0;
        for (row = 0; row < square->size; row++) {
        sum = 0;
                for (column = 0; column < square->size; column++) {
                        sum = sum + *(*(square->array+row)+column);
                }
                test = sum;
                if (sum == test){
                }
                else {
                        printf("false\n");
                        exit(1);
                }
        }
	// Check main diagonal
 	sum = 0;
	for (row = 0; row < square->size; row++) {
		for (column = 0; column < square->size; column++) {
			if (row == column){
				sum = sum + *(*(square->array+row)+column);
			}
		}		
	}
	if (sum == test){
	}
	else {
		printf("false\n");exit(1);
	}
	// Check secondary diagonal
	sum = 0;
	for (row = square->size - 1; row >= 0; row--) {
		for (column = square->size - 1; column >= 0; column--) {
			if (row == column){
				sum = sum + *(*(square->array+row)+column);
			}
		}
	}
	//Returns 1 if all sums are equal
	if (sum == test){
		return 1;
	}
	else{
		return 0;
	}
}
