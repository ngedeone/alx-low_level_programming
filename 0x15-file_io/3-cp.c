
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

void print_error(const char *msg)
{
    dprintf(STDERR_FILENO, "Error: %s\n", msg);
}

int main(int argc, char *argv[])
{
    int fd_from, fd_to, bytes_read, bytes_written;
    char buf[BUF_SIZE];

    if (argc != 3)
    {
        print_error("Usage: cp file_from file_to");
        exit(97);
    }

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
    {
        print_error("Can't read from file");
        exit(98);
    }

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        print_error("Can't write to file");
        exit(99);
    }

    while ((bytes_read = read(fd_from, buf, BUF_SIZE)) > 0)
    {
        bytes_written = write(fd_to, buf, bytes_read);
        if (bytes_written == -1)
        {
            print_error("Can't write to file");
            exit(99);
        }
    }

    if (bytes_read == -1)
    {
        print_error("Can't read from file");
        exit(98);
    }

    if (close(fd_from) == -1)
    {
        print_error("Can't close fd");
        exit(100);
    }

    if (close(fd_to) == -1)
    {
        print_error("Can't close fd");
        exit(100);
    }

    return 0;
}

