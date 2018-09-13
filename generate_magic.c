////////////////////////////////////////////////////////////////////////////////
// Main File:        generate_magic.c
// This File:        generate_magic.c
// Other Files:      verify_magic.c
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
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

// Structure representing Square
// size: dimension(number of rows/columns) of the square
// array: 2D array of integers
typedef struct _Square {
	int size;
	int **array;
} Square;

int get_square_size();
Square * generate_magic(int size);
void write_to_file(Square * square, char *filename);
//This is where most of the execution takes place
int main(int argc, char *argv[])
{
	// Check input arguments to get filename
 	char* fileName;
 	if (argc == 2){
 		fileName = argv[1];
 	}	
	 else{
	 	printf("Use: ./generate_magic <fileName>\n");
		exit(1);
 	}
	// Get size from user
	 int size =  get_square_size(); // Gets the size from the user
	// Generate the magic square
	 Square *square = generate_magic(size);
	// Write the square to the output file
	 write_to_file(square, fileName);
 	//Free heap memory
	for(int i = square->size - 1; i >= 0; i--){
		free(*(square->array + i));
	}
	free(square);	
	return 0;
}

/* get_square_size prompts the user for the magic square size
 * checks if it is an odd number >= 3 and returns the number
 */ 
 int get_square_size(){
	int n;
 	char line[256]; // Line buffer
  	printf("Enter the size of magic square, must be odd\n");
 	fgets(line, sizeof(line), stdin);
	n = atoi(line);
	//Prevents errors from trying to make an impossible magic square
 	if (!(n % 2) || n < 3){
		printf("Size must be an odd number greater than or equal to 3.\n");
	}
	return n;
}

/* generate_magic constructs a magic square of size n
 * using the Siamese algorithm and returns the Square struct
 */
Square * generate_magic(int n){
	//Construct the square
	Square* output = malloc(sizeof(Square));
	if(output){
		output->size = n;
		output->array = (int **)malloc(output->size * sizeof(int *));
	}
	else{
		printf("Could not allocate memory\n");
	}
	//Initialize the square
	if(output->array){
		for(int i = 0; i <output->size; i++){
			*(output->array + i) = (int*)malloc(output->size * sizeof(int));
		}
	}
	else {
		printf("Could not allocate memory\n");
		exit(1);
	}
	//Populate the array
	//Initialize values
	int row = output->size / 2;
	int column = output->size - 1;
	//Fill in array
	for(int j = 1; 1 <= output->size * output->size;){
		if(row == -1 && column == output->size){
			column = output->size - 2;
			row = 0;
		}
		else{
			//Handles right edge of the array
			if(column == output->size){
				column = 0;
			}
			//Handles top of the array
			if(row < 0){
				row = output->size - 1;
			}
		}
		//Handles if location is occupied
		if(*(*(output->array + row) + column)){
			column -= 2;
			row++;
			continue;
		}
		//Set Value
 		else{
			*(*(output->array + row) + column) = j++;
		}
		//Increment both indicez
		row++;
		column++;
	}

	return output;
}
/* write_to_file opens up a new file(or overwrites the existing file)
 * and writes out the square in the format expected by verify_magic.c
 */
void write_to_file(Square * square, char *filename)
{
	//Opens file
	FILE *file = fopen(filename, "w");
	//Eliminates error of an empty file
	if(file == NULL){
		printf("Cannot open file\n");
	exit(1);
	}

	//Write to file
 	fprintf(file, "%i\n", square->size);
	for(int row = 0; row < square->size; row++){
		for(int column = 0; column < square->size; column++){
			if(column != square->size - 1){
				fprintf(file, "%i,", square->array[row][column]);
			}
			else {
				fprintf(file, "%i", square->array[row][column]);}
			}
		}
		fputs("\n", file);
}
