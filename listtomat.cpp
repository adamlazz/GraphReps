// Adam Lazzarato
//
// Convert adjacency list to adjacency matrix
//
// TODO:
// * Make out of order adjacencies parse correctly
// * > 2 digit vertex parsing
//
// Usage:
//		./listtomat <adjlist_file>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define USAGE "Usage:\n\t./listtomat <adjlist_file>"
#define MAX_DIGITS 32 // maximum digits in vertex labels

using namespace std;

int main (int argc, char const *argv[]) {
	FILE *fp;
	int c; // char in file
	int temp; // temp memory
	int lookahead;
	int brk = 0; // break flag
	int col = 0; // column in matrix line
	int n = 0; // number of vertices in graph
	int first = 1; // spacing
	int result;

	if (argc != 2) {
		perror("Incorrect number of arguments.\n");
		perror(USAGE);
		return -1;
	}

	fp = fopen(argv[1], "r"); // open adjacency list file
	if (fp == NULL) {
		perror("File does not exist.");
		perror(USAGE);
		return -1;
	}

	// get number of lines (vertices) in file
	c = fgetc(fp);
	while(c != EOF){
		if (c == '\n') {
			n = n + 1;
		}
		c = fgetc(fp);
	}
	// EOF is an empty line
	rewind(fp);

	while (1) { // for each line in adjacency list
		for (int i = 0; i < MAX_DIGITS; ++i) { // parse over vertex label and colon separator
			c=fgetc(fp);
			if (c == ':'){
				c=fgetc(fp); // space
				break;
			}
		}

		while (1) { // for each adjacency
			c = fgetc(fp); // parse adjacency
			temp = c;
			if (temp == '\n') { // vertex with no adjacencies
				for (int i = col; i < n; ++i) { // fill rest of line with 0
					if (first == 1)	{
						printf("%d", 0);
						first = 0;
					}
					else {
						printf(" %d", 0);
					}
				}
				break;
			}
			c = fgetc(fp); // space or second digit

			if (c=='\n'){
				c = temp;
				brk = 1;
			}
			else if (c==' ') {
				c = temp;
			}
			else if (c==EOF){
				return 0;
			}
			else if (isdigit(c)){ // double digits
				lookahead=fgetc(fp);

				if (lookahead=='\n') {
					ungetc(lookahead,fp);
					brk = 1;
				}
				// else if isdigit(c)
					// > 2 DIGIT VERTEX PARSING
				// else space
				result = (10*(temp-'0'))+c-'0';
				c=result+'0';
			}

			if (c-'0' > n) { 
				perror("Invalid adjacency parsed\n.");
				perror(USAGE);
				return -1;
			}

			while (1) {
				if (c-'0' == col) { // found correct position in matrix for adjacency (1)
					if (first == 1) {
						printf("%d", 1);
						first = 0;
					}
					else {
						printf(" %d", 1);
					}
					col = col + 1;
					break;
				}
				else { // incorrect position in matrix for adjacency
					if (first == 1) {
						printf("%d", 0);
						first = 0;
					}
					else {
						printf(" %d", 0);
					}
					col = col + 1; // increment position in matrix
				}
			}

			if (brk == 1) { // EOL
				if (col != n) { // fill rest of line with 0's
					for (int i = col; i < n; ++i) {
						printf(" %d", 0);
					}
				}
				brk = 0;
				temp = 0;
				break;
			}
		}
		printf("\n");
		col = 0;
		temp = 0;
		first = 1;
	}
	fclose(fp);
    return 0;
}