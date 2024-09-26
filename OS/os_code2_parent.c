#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Expecting odd/even\n");
        exit(1);
    }

    int pid = fork();
    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("From child process:\nPID = %d, PPID = %d\n\n", getpid(), getppid());
        char* child_argv[] = {"./os_code2_child.out", argv[1], "1", "20", NULL}; // Added NULL to terminate args
        execvp(child_argv[0], child_argv);

        // On failure, only the control comes here
        perror("Exec failed");
        return 1;

    } else {
        // Parent process
        sleep(5);
        printf("From parent process:\nPID = %d, childPID = %d\n\n", getpid(), pid);

        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Child exited with status = %d\n", WEXITSTATUS(status));
        } else {
            printf("Child did not terminate normally\n");
        }
    }

    return 0;
}
