#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file
 * @filename: Name of the file to append to
 * @text_content: Content to append to the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, status, i;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		i = 0;
		while (text_content[i])
			i++;

		status = write(fd, text_content, i);
		if (status == -1)
			return (-1);
	}

	close(fd);
	return (1);
}
