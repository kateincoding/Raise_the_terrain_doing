#include "raise_the_terrain.h"
#include <ctype.h>

int ft_isnumber(char *number)
{
	if (!number)
		return (0);
	if (*number == '-')
		number++;
	while (*number)
	{
		if (!isdigit(*number))
			return (0);
		number++;
	}
	return(1);
}

/**
 * count_numbers - count numbers from a file to set points of maps
 * @line: line that program give to us
 * it is necessary that line is a digit , change logical 
 * Return: number of numbers or 0 if is error
 */
int count_numbers (char *line)
{
	char *tokn = NULL;
	unsigned int numbers = 0;

	if (line)
	{
		tokn = strtok(line, " \t\n");
		while (tokn != NULL)
		{
			if (!ft_isnumber(tokn))
				return (0);
			numbers++;
			printf("tokn = '%s'.\n", tokn);
			tokn = strtok(NULL, " \t\n");
		}
		tokn = NULL;
	}
	return (numbers);
}

/**
 * read_map_size - calculate the size of the grid and assign them in sdl_rt
 * @map: structure in the map, where the fuction will assign the width and height
 * @fd: file to read
 * Return: void
 */
int read_map_size(sdl_rt *map, char *av)
{
	FILE *fd = NULL;
	size_t buff_size = 0;
	char *buff = NULL;

	fd = fopen(av, "r");
	if (!fd)
	{
		dprintf(2, "Can not open file\n");
		fclose(fd);
		exit(EXIT_FAILURE);
	}

	while (getline(&buff, &buff_size, fd) != -1)
	{
		if (map->width == 0)
		{
			map->width = count_numbers(buff);
			if (!(map->width))
			{
				dprintf(2, "aqui error\n");
				free(buff);
				fclose(fd);
				return(0);
			}
		}
		map->height++;
	}
	free(buff);
	fclose(fd);
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
	int i = 0;
	char *tokn;

	if (line)
	{
		tokn = strtok(line, " \t\n");
		while (tokn != NULL)
		{
			grid_line[i] = atoi(tokn);
			tokn = strtok(NULL, " \t\n");
		}
		tokn = NULL;
	}
}

/**
 * read_map - main structure to read the map of file and create a grid
 * @map: structure of values
 * @av: argument of main
 * Return: 1 if it is success
 */
int read_map(sdl_rt *map, char *av)
{
	unsigned int j = 0;
	size_t buff_size = 0;
	char *buff = NULL;
	FILE *fd = NULL;

	/* calculate width and height with getline, strtok, isnumber */
	if (!read_map_size(map, av))
	{
		dprintf(2, "Please only numbers\n");
		exit(EXIT_FAILURE);
	}
	printf("width = %u\n", map->width);
	printf("height = %u\n", map->height);

	/* create the grid size with width and height */
	map->grid = malloc(sizeof(unsigned int *) * (map->height + 1));
	while(j <= map->height)
		map->grid[j++] = malloc (sizeof(unsigned int) * (map->width + 1));
	j = 0;
	printf("here");
	/* set a value number in each size of grid */
	fd = fopen(av, "r");
	if (!fd)
	{
		dprintf(2, "Can not open file\n");
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	/* pass each line and asign to a grid of integers*/
	while(getline(&buff,&buff_size,fd) != -1)
	{
		set_grid_value(map->grid[j], buff);
		buff = NULL;
		j++;
	}
	/* release fd and buff */
	free(buff);
	fclose(fd);
	/* EOF */
	map->grid[j] = NULL;
	return (1);
}
