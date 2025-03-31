#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int global = 0;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Błąd: Należy podać jeden argument (ścieżkę katalogu).\n");
        return 1;
    }
    printf("Program name: %s\n", argv[0]);

    int local = 0;
    pid_t pid = fork();

    if (pid == 0) 
    {
        printf("child process\n");

        global++;
        local++;

        printf("child pid = %d, parent pid = %d\n", getpid(), getppid());
        printf("child's local = %d, child's global = %d\n", local, global);

        int exec_status = execl("/bin/ls", "ls", argv[1], (char *)NULL);
        if (exec_status == -1) 
        {
            perror("execl failed");
            return 1;
        }

    } else 
    {
        int status;

        //czekamy na zakończenie procesu potomnego
        wait(&status);

        printf("parent process\n");
        printf("parent pid = %d, child pid = %d\n", getpid(), pid);
        printf("Child exit code: %d\n", WEXITSTATUS(status));
        printf("Parent's local = %d, parent's global = %d\n", local, global);
    }

    return 0;
}
