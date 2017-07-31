#include <string.h>
#include <stdio.h>


int foo(int fd, char* buf, int b_size, int n, int skip){
    FILE* fp = fdopen(fd, "w");
    return fread(buf,b_size,n,fp);
}
int main(){
    //create a use case here
}