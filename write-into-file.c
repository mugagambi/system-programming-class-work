#include <stdio.h>
int main () {
    FILE *fpt;
    fpt = fopen("data.txt", "w");
    fputs("The higher the fewer.\n", fpt);
    fclose(fpt);
    fpt = NULL;
}