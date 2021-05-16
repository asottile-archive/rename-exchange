#include <fcntl.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

/* musl libc does not define RENAME_EXCHANGE */
#ifndef RENAME_EXCHANGE
#define RENAME_EXCHANGE 2
#endif

int main(int argc, char** argv) {
    for (int i = 1; i < argc; i += 1) {
        if (argv[i][0] == '-') {
            printf("usage: %s PATH1 PATH2\n", argv[0]);
            return 0;
        }
    }
    if (argc != 3) {
        printf("usage: %s PATH1 PATH2\n", argv[0]);
        return 1;
    }

    /* musl libc does not have renameat2(...) */
    if (syscall(SYS_renameat2, AT_FDCWD, argv[1], AT_FDCWD, argv[2], RENAME_EXCHANGE)) {
        perror(NULL);
        return 1;
    } else {
        return 0;
    }
}
