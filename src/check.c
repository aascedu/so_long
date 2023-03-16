#include "so_long.h"

int	map_is_full(char *str)
{
	int	i;
	int	nbr_c;
	int	nbr_e;
	int	nbr_p;

	i = 0;
	nbr_c = 0;
	nbr_e = 0;
	nbr_p = 0;
	while (str && str[i])
	{
		if (str[i] == 'C')
			nbr_c++;
		if (str[i] == 'E')
			nbr_e++;
		if (str[i] == 'P')
			nbr_p++;
		i++;
	}
	if (nbr_c == 0 || nbr_e != 1 || nbr_p != 1)
		return (1);
	return (0);
}

int	check_str(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str && str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != '\n' && str[i] != 'C'
			&& str[i] != 'E' && str[i] != 'P')
			return (1);
		i++;
	}
	if (map_is_full(str))
		return (1);
	return (0);
}

int	check_filename(char *filename)
{
	if (filename[ft_strlen(filename) - 1] != 'r'
		|| filename[ft_strlen(filename) - 2] != 'e'
		|| filename[ft_strlen(filename) - 3] != 'b'
		|| filename[ft_strlen(filename) - 4] != '.')
		return (1);
	else if (!ft_strncmp(filename, "/.ber", ft_strlen(filename)))
		return (1);
	return (0);
}

int	check_directory(char *filename)
{
	int	fd;

	fd = open(filename, __O_DIRECTORY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}
