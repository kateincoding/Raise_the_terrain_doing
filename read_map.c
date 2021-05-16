#include "raise_the_terrain.h"

/**
 * count_numbers - count numbers from a file to set points of maps
 * @line: line that program give to us
 * it is necessary that line is a digit , change logical 
 * Return: number of numbers
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

/**
 * read_map_size - calculate the size of the grid and assign them in sdl_rt
 * @map: structure in the map, where the fuction will assign the width and height
 * @fd: file to read
 * Return: void
 */
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

/* we will create an array of arrays of line and then pass to array of integer */
/**
 * set_grid_value - set the value of number in each square of the grid
 * @grid_line: grid_line (row) of data in int
 * @line: line to read and pass to integer
 * Return: void
 */
void set_grid_value(int *grid_line, char *line)
{
	int i;
	char **list;

	list = ft_strsplit(line, ' ');
	i = 0;
	while (list[i])
	{
		/* check if atoi can pass a negative number */
		grid_line[i] = atoi(list[i]);
		free(list[i]);
		i++;
	}
	free(list);
}

/**
 * read_map - main structure to read the map of file and create a grid
 * @map: structure of values
 * @av: argument of main
 * Return: 1 if it is success
 */
int read_map(sdl_rt map, char *av)
{
	FILE *fd;
	size_t buff_size;
	char **buff;
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
	/* set a value number in each size of grid */
	while(getline(&buff,&buff_size,fd))
	{
		set_grid_value(map->grid[y], buff);
		/*free(buff); */
		j++;
	}
	/* close fd */
	close(fd);
	free(buff);
	/* EOF */

	map->grid[j] = NULL;
	return (1);
}
