// Adam Lazzarato
//
// Generate adjacency list from adjacency matrix
// Uses [GraphDraw.jar](http://multires.caltech.edu/~keenan/GraphDraw/index.html)
// but not required, given properly formatted adjacency list.
//
// Usage:
//		./graphtolist <adjmat_file>

#include <stdio.h>
#include <stdlib.h>

#define USAGE "Usage:\n\t./graphtolist <adjmat_file>"

using namespace std;

int main (int argc, char const *argv[]) {
	FILE *fp;
	char file[32];
	int c; // char in file
	int n = 0; // number of vertices in graph
	int j; // current vertex in adjacency matrix

	if (argc != 2) {
		perror("Incorrect number of arguments.\n");
		perror(USAGE);
		return -1;
	}

	system("java -jar GraphDraw.jar");

	fp = fopen(argv[1], "r"); // open adjacency matrix saved by GraphDraw.jar
	if (fp == NULL) {
		perror("File does not exist.");
		perror(USAGE);
		return -1;
	}
	
	c = fgetc(fp);
	if (c == 'U' || c == 'D') { // GraphDraw.jar formatted file
		for (int i = 0; i < 3; ++i) { // attempt to scan to the first entry in adjacency matrix
			c = fgetc(fp);
		}
		while(c != '\n'){ // > 1 digit in line 2 of GraphDraw adjacency list
			c = fgetc(fp);
		}
	}
	else if (c == '0' || c == '1') { // adjacency list (not GraphDraw.jar formatted)
		rewind (fp);
	}
	else {
		perror("Invalid file.\n");
		perror(USAGE);
		return -1;
	}

	while (1) { // parse entire adjacency matrix
		c = fgetc(fp);
		if (c != EOF) { // empty line at EOF
			printf("%d :", n); // print current vertex with colon separator
			n = n + 1; // increment number of vertices in graph
		}
		j = 0;
		while (c != '\n') {
			if (c == '0') {
				j = j + 1; // increment vertex in adjacency matrix
			}
			else if (c == '1') {
				printf(" %d", j);
				j = j + 1;
			}
			else if (c == ' ') {
				printf("");
			}
			else if (c == EOF) {
				fclose(fp);
				return 0;
			}
			else {
				perror("Invalid character in file.\n");
				perror(USAGE);
				fclose(fp);
				return -1;
			}
			c = fgetc(fp); // get next adjacency in adjacency matrix
		}
		printf("\n");
	}
    return 0;
}