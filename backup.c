#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <unistd.h>
int main()
{
    DIR *dirptr = opendir(".");
    struct dirent *entry = readdir(dirptr);
    if (mkdir("directory", 0777) != 0)
    {
        printf("could not create new directory");
    }

    while (entry != NULL)
    {
        if (strlen(entry->d_name) == strlen("directory") && (strcmp(entry->d_name, "directory") == 0))
        {
            continue;
        }
        else
        {
            int pid = fork();
            int childExitStatus;
            if (pid == 0)
            { /* child */
                execl("/bin/cp", "/bin/cp", entry->d_name, "directory", NULL);
            }
            else if (pid < 0)
            {
                /* error - couldn't start process - you decide how to handle */
            }
            else
            {
                /* parent - wait for child - this has all error handling, you
                * could just call wait() as long as you are only expecting to
                * have one child process at a time.
                */
                pid_t ws = waitpid(pid, &childExitStatus);
            }
            entry = readdir(dirptr);
        }
    }
}
