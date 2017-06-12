#include <stdio.h>
int main () {
    FILE *fpt;
    fpt = fopen("data.txt", "w");
    fprintf(fpt, "Forty two  42 bytes of data on the wall ...");
    fclose(fpt);
    fpt = NULL;
}