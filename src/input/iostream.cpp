#include "input/iostream.hpp"

char *IOStream::read_line(void)
{
    int c;
    int position = 0;
    int bufsize = BUFF_SIZE;
    char *buffer = (char *)malloc(sizeof(char) * bufsize);

    if (!buffer)
    {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }
    while (1)
    {
        c = getchar();
        if (c == EOF || c == '\n')
        {
            buffer[position] = '\0';
            return (buffer);
        }
        else
        {
            buffer[position] = c;
        }
        position++;
        if (position >= bufsize)
        {
            bufsize += BUFF_SIZE;
            buffer = (char *)realloc(buffer, bufsize);
            if (!buffer)
            {
                fprintf(stderr, "lsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}