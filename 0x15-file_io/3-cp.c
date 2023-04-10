#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFSIZE 1024

void print_error(int errnum, char *filename, int fd);
void close_files(int fd_from, int fd_to);

int main(int argc, char *argv[])
{
	int fd_from, fd_to, rd_count, wr_count;
	char buf[BUFSIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		print_error(errno, argv[1], fd_from);
		exit(98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		print_error(errno, argv[2], fd_to);
		exit(99);
	}

	while ((rd_count = read(fd_from, buf, BUFSIZE)) > 0)
	{
		wr_count = write(fd_to, buf, rd_count);
		if (wr_count != rd_count)
		{
			print_error(errno, argv[2], fd_to);
			close_files(fd_from, fd_to);
			exit(99);
		}
	}

	if (rd_count == -1)
	{
		print_error(errno, argv[1], fd_from);
		close_files(fd_from, fd_to);
		exit(98);
	}

	if (close(fd_from) == -1)
	{
		print_error(errno, argv[1], fd_from);
		close_files(fd_from, fd_to);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		print_error(errno, argv[2], fd_to);
		exit(100);
	}

	return 0;
}

void print_error(int errnum, char *filename, int fd)
{
	dprintf(STDERR_FILENO, "Error: %s %s", strerror(errnum), filename);
	if (fd != -1)
		dprintf(STDERR_FILENO, " %d", fd);
			dprintf(STDERR_FILENO, "\n");
}

void close_files(int fd_from, int fd_to)
{
	if (close(fd_from) == -1)
		print_error(errno, "fd_from", fd_from);
	if (close(fd_to) == -1)
		print_error(errno, "fd_to", fd_to);
}
