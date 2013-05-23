// Adam Lazzarato
//
// Utility to add header lines from adjacency matrix files for GraphDraw.jar
//
// Usage:
//		./gd <adjmat_file>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define USAGE "Usage:\n\t./gd <adjmat_file>"

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
	if (c == 'U' || c == 'D') {
		perror("File is already GraphDraw formatted.");
		return -1;
	}

	while(c != EOF){ // count number of vertices in adjacency matrix
		if (c == '\n') {
			n = n + 1;
		}
		c = fgetc(adjmat);
	}

	printf("U\n%d\n", n); // print header: U (undirected) and n

	rewind(adjmat);
	c = fgetc(adjmat);
	while(c != EOF){ // print the adjacency matrix
		printf("%c", c);
		c = fgetc(adjmat);
	}

    return 0;
}