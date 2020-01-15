//: ecf/fork.c
// Created by XPL on 2020/1/15.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    int x = 1;
    int y = 1;
    int *ptr = &y;

    pid = fork();
    if (pid == 0) {
        printf("Child: x=%d, y=%d\n", ++x, ++(*ptr));
        exit(0);
    }

    printf("Parent: x=%d, y=%d\n", --x, --(*ptr));
    return 0;

}

///:~