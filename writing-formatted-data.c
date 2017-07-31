#include <stdio.h>

int main () {
    FILE *pfile = NULL;
    int num1 = 1234, num2 = 5678;
    float pi = 3.1416f;
    if(fopen_s(&pfile, "myfile.txt", "w"))
    {
        printf_s("Error opening file for writing.Program terminated.\n");
        exit(1);

    }
    if(0 > fprintf(pfile, "%12d%12d%14f", num1,num2, pi))
    printf_s("Failed to write the file.\n");

}