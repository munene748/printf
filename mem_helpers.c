#include "main.h"

unsigned int _memcpy(buffer_t *target_buffer, const char
*source_data, unsigned int num_bytes);
void free_memory(buffer_t *target_buffer);
buffer_t *initialize_buffer(void);

/**
 * _memcpy - Copies a specified number of bytes from a source memory area
 *           to the buffer enclosed in a buffer_t structure.
 * @target_buffer: The buffer_t structure where data is to be copied.
 * @source_data: Pointer to the source memory area.
 * @num_bytes: The number of bytes designated to be copied.
 *
 * Return: The actual number of bytes copied.
 */
unsigned int _memcpy(buffer_t *target_buffer, const char
*source_data, unsigned int num_bytes)
{
	unsigned int byte_index;

	for (byte_index = 0; byte_index < num_bytes; byte_index++)
	{
		*(target_buffer->buffer) = *(source_data + byte_index);
		(target_buffer->len)++;

		if (target_buffer->len == 1024)
		{
			write(1, target_buffer->start, target_buffer->len);
			target_buffer->buffer = target_buffer->start;
			target_buffer->len = 0;
		}

		else
			(target_buffer->buffer)++;
	}

	return (num_bytes);
}

/**
 * free_memory - Frees the memory occupied by a buffer_t structure.
 * @target_buffer: The buffer_t structure whose memory is to be released.
 */
void free_memory(buffer_t *target_buffer)
{
	free(target_buffer->start);
	free(target_buffer);
}

/**
 * initialize_buffer - Creates + initializes a buffer_t structure.
 *
 * Return: pointer to newly initialized buffer_t, / NULL if an error occurs.
 */
buffer_t *initialize_buffer(void)
{
	buffer_t *new_buffer;

	new_buffer = malloc(sizeof(buffer_t));
	if (new_buffer == NULL)
		return (NULL);

	new_buffer->buffer = malloc(sizeof(char) * 1024);
	if (new_buffer->buffer == NULL)
	{
		free(new_buffer);
		return (NULL);
	}

	new_buffer->start = new_buffer->buffer;
	new_buffer->len = 0;

	return (new_buffer);
}
