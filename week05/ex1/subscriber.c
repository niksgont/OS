#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


int main(void)
{
    char message[1024];
    int f;
    char *myfifo = "/tmp/ex1";
    mkfifo(myfifo, 0666);

    while(1)
    {
        f = open(myfifo, O_RDONLY);
        read(f, message, 1024);
        printf("Received: %s", message);
        close(f);
    }
}
