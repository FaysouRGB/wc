#include "input.h"

int input_read_from_stdin(char **buffer)
{
    // Create the buffer to store the input
    size_t size = 0;
    size_t capacity = BUFFER_SIZE;
    *buffer = malloc(capacity);
    if (!*buffer)
    {
        return 1;
    }

    // Read the input from stdin and store in the buffer
    while (1)
    {
        // Check if the buffer is full
        if (size == capacity)
        {
            capacity *= 2;
            *buffer = realloc(*buffer, capacity);
            if (!*buffer)
            {
                return 1;
            }
        }

        // Read from stdin
        size_t read = fread(*buffer + size, 1, capacity - size, stdin);
        if (read == 0)
        {
            break;
        }

        size += read;
    }

    return 0;
}
