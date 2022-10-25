#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *realloc_(void *ptr, size_t sizeNew, size_t sizeOld) {
    void *ret = malloc(sizeNew);
    if (ret == NULL)
        return NULL;
    memcpy(ret, ptr, (sizeNew < sizeOld) ? sizeNew : sizeOld);
    free(ptr);
    return ret;
}

int main() {

    return 0;
}
