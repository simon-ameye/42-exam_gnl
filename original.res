#include "get_next_line.h"$
$
char *ft_str_join(char *temp, char c)$
{$
	int i;$
	char *res;$
$
	if (temp == NULL)$
	{$
		res = malloc(sizeof(char) * 2);$
		res[0] = c;$
		res[1] = '\0';$
	}$
	else$
	{$
		i = 0;$
		while (temp[i])$
			i++;$
		res = malloc(sizeof(char) * (i + 2));$
		i = 0;$
		while (temp[i])$
		{$
			res[i] = temp[i];$
			i++;$
		}$
		res[i] = c;$
		res[i + 1] = '\0';$
		free(temp);$
	}$
	return (res);$
}$
$
int get_next_line(char **line)$
{$
	char *tmp;$
	char c;$
$
	tmp = NULL;$
	c = 0;$
	tmp = ft_str_join(tmp, '\0');$
	while (read(0, &c, 1) && c != '\n')$
		tmp = ft_str_join(tmp, c);$
	*line = tmp;$
	return(c == '\n');$
}