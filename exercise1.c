#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 81

int main (void) {
    char strings[LENGTH];
    FILE *pfile = NULL;
    char *filename = "exercise1.txt";

    pfile = fopen(filename, "a");

    setbuf(pfile, NULL);
    printf("Enter strings of up to 80 characters or press Enter to end:\n");
    while (1) {
        fgets(strings, LENGTH, stdin);
        if (strings[0] == '\n')
            break;
        if (EOF == fputs(strings, pfile))
        {
            printf("Error writing file.\n");
            exit(1);
        }
    }
    fclose(pfile);
    return 0;
}