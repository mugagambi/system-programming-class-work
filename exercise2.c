#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 81
int main(void) {
    char strings[LENGTH];
    FILE *readfile = NULL;
    FILE *writefile = NULL;
    char *readfilename = "exercise1.txt";
    char *writefilename = "exercise2.txt";
    readfile = fopen(readfilename, "r");
    writefile = fopen(writefilename, "w");
    setbuf(readfile, NULL);
    printf("reading and writing the strings to another file\n");
    while (fgets(strings, LENGTH, readfile)){
        if (EOF == fputs(strings, writefile)) {
			printf("Error writing file.\n");
			exit(1);
		}
    }
    fclose(writefile);b
    fclose(readfile);
    return 0;
}