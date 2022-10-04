#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int f;
    char message[1024];
    char *myfifo = "/tmp/ex1";
    mkfifo(myfifo, 0666);

    while(1)
    {
        fgets(message, 1024, stdin);
        f = open(myfifo, O_WRONLY);
        for(int i = 0; i < atoi(argv[1]); i++)
            write(f, message, 1024);
        close(f);
        sleep(1);
    }
}
