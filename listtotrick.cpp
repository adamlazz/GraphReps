// Adam Lazzarato
//
// Convert adjacency list to trick
//
// TODO:
// * Make out of order adjacencies parse correctly
// * > 2 digit vertex parsing
//
// Usage:
//      ./listtotrick <adjlist_file>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define USAGE "Usage:\n\t./listtotrick <adjlist_file>"

using namespace std;

int main (int argc, char const *argv[]) {
    FILE *fp;
    int c;
    int n = 0;
    int adjacencies;

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

    c = fgetc(fp);
    while(c != EOF){
        if (c == '\n') {
            n = n + 1;
        }
        c = fgetc(fp);
    }
    // EOF is an empty line
    rewind(fp);
    
    // begin transfer to trick form
    c = fgetc(fp);
    for (int h = 0; h < n; ++h) {
        while (1) {
            if (c == ':') {
                break;
            }
            c = fgetc(fp);
        }
        c = fgetc(fp); // space
        while (1) {
            if (c != '\n' && c != ' ') {
                adjacencies = adjacencies + 1;
            }
            if (c == '\n') {
                break;
            }
            c = fgetc(fp);
        }
    }
    adjacencies = adjacencies / 2;
    printf("%d %d\n", n+1, adjacencies); // vertices and edges (top)

    rewind(fp);
    for (int g = 0; g < n; ++g) {
        while (1) {
            if (c == ':') {
                break;
            }
            c = fgetc(fp);
        }
        c = fgetc(fp); // space
        while (1) {
            if (c != '\n' && c != ' ') {
                if (c-'0' > g) {
                    printf("%d %d\n", g+1, (c-'0')+1);
                }
            }
            if (c == '\n') {
                break;
            }
            c = fgetc(fp);
        }
    }
    return 0;
}