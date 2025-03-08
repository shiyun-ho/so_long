#include "libft/libft.h"
#include <stdio.h>

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

char	**make_area(char *zone[], t_point size)
{
	char	**area;
	int		i;
	int		j;

	area = (char**)(malloc((size.y) * sizeof(char*)));
	i = 0;
	while (i < size.y)
	{
		area[i] = (char*)(malloc((size.x + 1) * sizeof(char)));
		j = 0;
		while (j < size.x)
		{
			area[i][j] = zone[i][j * 2]; //To account for space in between
			j++;
		}
		i++;
	}
	return (area);
}

void	print_tab(char **area, t_point size)
{
	int		i;

	i = 0;
	while (i < size.y)
	{
		printf("%s\n", area[i]);
		i++;
	}
}

void	fill(char **tab, t_point size, char target, int row, int col)
{
	if (row < 0 || col < 0 || row > size.y || col > size.x)
		return ;
	if (target == 'F' || tab[row][col] != target)
		return ;

	fill(tab, size, target, row - 1, col);
	fill(tab, size, target, row + 1, col);
	fill(tab, size, target, row, col - 1);
	fill(tab, size, target, row - 1, col + 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target;
	int		row;
	int		col;

	target = tab[begin.y][begin.x];
	row = size.y;
	col = size.x;
	fill(tab, size, target, row, col);
}

int main()
{
	char	**area;
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
		NULL
	};
	area = make_area(zone, size);
	print_tab(area, size);

	flood_fill(area, size, begin);
	print_tab(area, size);

	return (0);
}