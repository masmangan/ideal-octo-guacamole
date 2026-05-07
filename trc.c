#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("trc: missing operand\n");
        printf("Try 'trc --help' for more information.\n");
    }
    else if (argc == 2)
    {
        if (!strcmp("--help", argv[1]))
        {
            printf("Usage: trc [OPTION] STRING\n");
            printf("Delete characters from standard input,\n");
            printf("writing to standard output.\n");

            printf("OPTION include:\n");
            printf("-d, --delete            delete characters in ARRAY1, do not translate\n");
            printf("Interpreted sequences are:\n");

            printf("    \n              new line\n");
        } else {
            printf("invalid option -- '%c'\n", argv[1][1]);
        }
    }
    return 0;
}