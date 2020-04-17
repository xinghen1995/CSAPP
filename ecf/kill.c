#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid;

    if ((pid = fork()) == 0) {
        pause();
        printf("control should never be here!\n");
        exit(0);
    }

    kill(pid, SIGKILL);
    exit(0);
}
