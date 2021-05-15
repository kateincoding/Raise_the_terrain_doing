#include "raise_the_terrain.h"

/**
 * count_numbers - count numbers from a file to set points of maps
 * @line: line that program give to us
 * it is necessary that line is a digit , change logical 
 */
int count_numbers (char *line)
{
	char *tokn;
	unsigned int numbers = 0;

	if (line)
	{
		tokn = strtok(line, " ");
		while (tkn != NULL)
		{
			numbers++;
			tokn = strtok(NULL, " ")
		}
	}
	return (numbers);
}

int read_map_size(sdl_rt map, FILE *fd)
{
	size_t buff_size;
	char **buff;

	while (getline(&buff, &buff_size, fd) != -1)
	{
		if (map->width = 0)
			map->width = count_numbers(&buff);
		map->height++;
	}
	return (1);
}

int read_map(sdl_rt map, char *av)
{
	FILE *fd;
	unsigned int j;

	fd = fopen(av[1], "r")
	if (!fd)
	{
		dprintf(2, "Can not open file")
		exit(EXIT_FAILURE);
	}
	/* calculate width and height with getline, strtok, isnumber */
	read_map_size(map, fd);
	/* create the grid size with width and height */
	map->grid = (unsigned int**)malloc(sizeof(unsigned int *) * (map->height + 1));
	j = 0;
	while(j <= map->height)
		map->grid[j++] = (unsigned int *)malloc (sizeof(unsigned int *) * (map->width + 1));
	j = 0;
	/* asign a value in each size of grid */

	/* close fd */
	close(fd);
}
