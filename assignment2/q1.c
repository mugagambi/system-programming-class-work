#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    DIR *dirp = NULL;
    struct dirent *dp = NULL;
    mkdir("./backup", 0777);
    dirp = opendir(".");
    while ((dp = readdir(dirp)) != NULL)
    {
        if (strcmp(dp->d_name, "backup") != 0)
        {
            pid_t fk = fork();
            if(!fk) 
            {
                execl("/bin/cp", "cp", dp->d_name, "backup", NULL);
            }
            else if (fk == -1)
            {
                perror("fork");
            }
        }
    }
    return closedir(dirp);
}