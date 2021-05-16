#include <fcntl.h>
#include <stdio.h>

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

    if (renameat2(AT_FDCWD, argv[1], AT_FDCWD, argv[2], RENAME_EXCHANGE)) {
        perror(NULL);
        return 1;
    } else {
        return 0;
    }
}
