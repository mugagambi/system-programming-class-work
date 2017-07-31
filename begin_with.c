#include <unistd.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char **argv)
{
    char buf[32];
    sprintf(buf, "find . -type f -name \"%s\"\n", strcat(argv[1], "*"));
    system(buf);
}