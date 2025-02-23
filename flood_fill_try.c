#include "libft/libft.h"

/**
FLOOD FILL ALGORITHM
- Fills an entire zone by replacing character with 'F'
- To run: 
	```cc flood_fill.c -I./libft -L./libft -lft -o flood_fill```
*/

typedef	struct	s_point
{
	int		x;
	int		y;
}				t_point;

char	**make_area(char *zone[])
{
	char	**area; //2d array
	int		rows;
	int		cols;
	int		i;

	rows = 0;
	cols = 0;
	while (zone[rows])
		rows++;
	if (rows > 0)
		cols = ft_strlen(zone[0]); //get number of cols from length of first input
	
	/**
		ALLOCATE MEMORY FOR INDIVIDUAL ELEMENTS IN *AREA[] 
			AREA[ [], [], [], [], [] ]
			SIZE  1				  ROW
	*/
	area = (char **)malloc(rows * sizeof(char*));
	if (!area)
		return (NULL);

	// Allocate memory for each row itself
	// Copy data from zone
	i = 0;
	while (i < rows)
	{
		area[i] = (char *)malloc((cols + 1) * sizeof(char));
		if (!area[i])
		{
			while(i > 0)
			{
				free(area[i]);
				i--;
			}
			return (NULL);
		}
		ft_strlcpy(area[i], zone[i], cols);
		i++;
	}
	area[rows] = '\0';
	return (area);
}

void	print_tab(char *area[])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(area[i])
	{
		j = 0;
		while(area[i][j])
		{
			ft_printf("%c", area[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	fill(char **tab, t_point size, char target, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;

	if (tab[row][col] != '0')
		return ;

	// Avoid filled cells and cells which are not the seed cells
	if (tab[row][col] == 'F' || tab[row][col] != target)
		return ;

	tab[row][col] == 'F';

	fill(tab, size, target, row - 1, col);
	fill(tab, size, target, row + 1, col);
	fill(tab, size, target, row, col - 1);
	fill(tab, size, target, row, col + 1);
}

/**
	@brief: Fills an entire zone from given 'begin' t_point

	@param: tab - 2d array
	@param: begin - begin coordinates
	@param: size - length of 2d array (column wise)

*/
void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target;

	target = tab[begin.y][begin.x];
	
	fill(tab, size, target, begin.y, begin.x);	
}

int	main(void)
{
	char	**area;
	t_point	size;
	t_point	begin;

	// size = (t_point) {8, 5};
	// begin = (t_point) {2, 2};
	size.x = 8;
	size.y = 5;
	begin.x = 2;
	begin.y = 2;
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
		NULL
	};

	area = make_area(zone);
	ft_printf(">>> Printing original input: \n\n");
	print_tab(area);
	ft_printf("\n");

	flood_fill(area, size, begin);
	// ft_printf(">>> Printing outcome of flood_fill(): \n\n");
	// print_tab(area);

	return (0);
}
