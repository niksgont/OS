#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
    void *ptr[10];
    struct rusage res;
    for (int i = 0; i < 10; i++) {
        ptr[i] = malloc(10 * 1024 * 1024);
        if (ptr[i] != NULL)
            memset(ptr[i], 0, 10 * 1024 * 1024);
        printf("%ld\n", res.ru_maxrss);
        getrusage(RUSAGE_SELF, &res);
        sleep(1);
    }      
    return 0;
}
