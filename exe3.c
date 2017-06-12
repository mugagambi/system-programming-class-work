// Exercise 3: Write a program that will read names consisting of a first name and a
// second name, and associated telephone numbers from the keyboard and write them
// to a new file if a file doesn’t already exist and add them if the file does exist. The
// program should optionally list all the entries.
# include <stdio.h>
int main(){
    //open file for append
    FILE *pfile = NULL;
    char *filename = "file3.text";
    if(!fopen_s(&pfile, filename, "a")) // Openmyfile.txt to write it
    printf_s("Failed to open %s.\n", filename);
    fclose(pfile);
    //write reading fromm stdin  1,2,phoneno
    fopen_s(&pfile, "myfile.txt", "a");
    fprintf(pfile, “Forty two 42 bytes ofdata on the wall...”);
    fclose(pfile);
    //read from file and list to stdout
    char text[80];
    fopen_s(&pfile, "myfile.txt", "r");
    fscanf(pfile, “%s”,text);
    fclose(pfile);

}
