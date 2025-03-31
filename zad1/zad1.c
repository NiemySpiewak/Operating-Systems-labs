#include <stdio.h>
#include <stdlib.h> //atoi() - char -> intiger
#include <sys/types.h> //pid_t - typ danych do identyfikatorów procesów
#include <sys/wait.h>
#include <unistd.h> //fork,getpid,wait - zarządzanie procesami

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Błąd: Podaj jeden argument (liczbę procesów).\n");
        return 1;
    }

    int n = atoi(argv[1]);

    for (int i = 0; i < n; i++) 
    {
        pid_t pid = fork();
        if (pid == 0) 
        {
            printf("PID macierzysty:%d PID dziecka:%d\n", getppid(), getpid());
            return 0;
        }
    }

    //proces macierzysty czeka na zakończenie wszystkich procesów potomnych
    for (int i = 0; i < n; i++) 
    {
        wait(NULL);
    }

    printf("%d\n", n);
    return 0;
}
