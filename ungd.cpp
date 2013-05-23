// Adam Lazzarato
//
// Utility to add header lines from adjacency matrix files for GraphDraw.jar
//
// Usage:
//		./ungd <adjmat_file>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define USAGE "Usage:\n\t./ungd <adjmat_file>"

using namespace std;

int main (int argc, char const *argv[]) {
	FILE *adjmat;
	int c;
	int n;

	if (argc != 2) {
		perror("Incorrect number of arguments.\n");
		perror(USAGE);
		return -1;
	}

	adjmat = fopen(argv[1], "r+");
	if (adjmat == NULL) {
		perror("File does not exist.");
		perror(USAGE);
		return -1;
	}
	
	c = fgetc(adjmat);
	if (c != 'U' && c != 'D') { // GraphDraw.jar formatted file
		perror("File is not GraphDraw formatted.");
		return -1;
	}
	else {
		for (int i = 0; i < 3; ++i) { // attempt to scan to the first entry in adjacency matrix
			c = fgetc(adjmat);
		}
		while(c != '\n'){ // > 1 digit in line 2 of GraphDraw adjacency list
			c = fgetc(adjmat);
		}
	}

	c = fgetc(adjmat);
	while(c != EOF){ // print the adjacency matrix
		printf("%c", c);
		c = fgetc(adjmat);
	}

    return 0;
}