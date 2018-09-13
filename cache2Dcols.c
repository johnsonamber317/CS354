////////////////////////////////////////////////////////////////////////////////
// Main File:        cache2Dcols.c
// This File:        cache2Dcols.c
// Other Files:      None
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

//Initialize 2D array
int arr2D[3000][500];

int main(int argc, const char* argv[]){
//Loop that iterates through columns
for (int j = 0; j< 3000; j++){
     	//Loop that iterates through rows
	for (int i = 0; i< 500; i++){
        	arr2D[i][j] = i + j;
     }
}
return 0;
}
