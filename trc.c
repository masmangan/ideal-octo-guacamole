#include <stdio.h>
#include <string.h>

int contains(char *s, char c)
{
    while (*s)
    {
        if (*s == c)
        {
            return 1;
        }
        s++;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("trc: missing operand(1)\n");
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
        }
        else
        {
            printf("invalid option '%s'\n(2)", argv[1]);
            printf("Try 'trc --help' for more information.\n");
        }
    }
    else if (argc == 3)
    {
        if (!strcmp("--delete", argv[1]))
        {
            // tr --delete '\n'
            // printf("%s\n", argv[2]);

            int c;

            while ((c = getchar()) != EOF)
            {
                if (!contains(argv[2], c))
                {
                    putchar(c);
                }
            }
            //putchar('\n');
        }
        else
        {
            printf("invalid option '%s'\n(3)", argv[1]);
            printf("Try 'trc --help' for more information.\n");
        }
    }
    else
    {
        printf("trc: missing operand(4)\n");
        printf("Try 'trc --help' for more information.\n");
    }

    return 0;
}