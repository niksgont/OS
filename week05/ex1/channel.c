#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    int f[2];
    char message[1024];
    pid_t p;
    if (pipe(f) == -1)
    {
        fprintf(stderr, "ERROR! Pipe failed");
        return 123;
    }
    p = fork();
    if (p < 0)
    {
        fprintf(stderr, "ERROR! Fork failed");
        return 123;
    }
    if (p > 0)
    {
        printf("Enter a message: ");
        fgets(message, 1024, stdin);
        close(f[0]);
        write(f[1], message, strlen(message) + 1);
        close(f[1]);
        return 0;
    }
    close(f[1]);
    read(f[0], message, 1024);
    printf("Received: %s", message);
    close(f[0]);
}
