#include <stdio.h>
#include <string.h>

/*
* Example:
* Using tr and trc gives the same result:
*
*  $ echo xyz | ./trc --delete abc
*  $ echo xaz | ./trc --delete abc
*
* echo "Phone: " | tr -d '0-9'
*
* cat file.txt | tr -d '\n'
*/
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
            printf("-d, --delete            delete characters in ARRAY, do not translate\n");
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
            int c;
            char template[200];
            strcpy(template, argv[2]);
            if (!strcmp("\\n", template)) {
                strcpy(template, "\n");
            }
            if (contains(template, '-')) {
                char temp[200];
                char *t = temp;
                for (int v=template[0]; v<=template[2]; v++) {
                    *t++ = v;
                }
                *t = '\0';
                strcpy(template, temp);
            }
            printf("%s\n", template);
            while ((c = getchar()) != EOF)
            {
                if (!contains(template, c))
                {
                    putchar(c);
                }
            }
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