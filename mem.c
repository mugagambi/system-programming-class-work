#include <stdio.h>
#include <stdlib.h>

int uig;
int ig = 5;

int func()
{
    return 0;
}
int main()
{
    int local;
    int *ptr;
    ptr = (int *)malloc(sizeof(int));
    printf("An address from BSS: %p\n", &uig);
    printf("An address from Data segment: %p\n", &ig);
    printf("An address from Code segment: %p\n", &func);
    printf("An address from Stack segment: %p\n", &local);
    printf("An address from Heap: %p\n", ptr);
    printf("Another address from Stack: %p\n", &ptr);
    free(ptr);
    return 0;
}