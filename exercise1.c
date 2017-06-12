#include <stdio.h>

int main () {
    FILE *fpt;
    fpt = fopen("Fileone.txt", "a");
    if (fpt == NULL) {
        printf("File couldn't be opened\n\a\a");
        fclose(fpt);
        exit(0);
    }
    while(1) {
        switch (menu()) {
            case 1:
                fputs("The higher the fewer.\n", fpt);
            break;
            case 2:
            fclose(fpt);
            fpt = NULL;
            printf("Exiting the program\n");
            exit(0);
        }
    }
}
int menu () {
    char choice[1];
    printf("1.Enter string to write into file\n
    2.quit\n");
    scanf('%s',choice);
    if (choice == '1'){
        return 1
    }
    else {
        return 2
    }

}