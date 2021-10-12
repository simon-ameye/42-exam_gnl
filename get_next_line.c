#include "get_next_line.h"

int ft_strlen(char *s)
{
	int i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_cat(char **res, char *buff)
{
	int i;
	int j;
	char *res2;

	i = ft_strlen(*res);
	j = ft_strlen(buff);
	res2 = malloc(sizeof(char) * (i + j + 1));
	i = 0;
	j = 0;
	if (*res)
	{
		while ((*res)[i])
		{
			res2[i] = (*res)[i];
			i++;
		}
	}
	if (buff)
	{
		while (buff[j])
		{
			res2[i + j] = buff[j];
			j++;
		}
	}
	res2[i + j] = '\0';
	if (*res)
		free(*res);
	*res = res2;
}

int ft_hasreturn(char *s)
{
	int i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void ft_tozero(char *s, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		s[i] = 0;
		i++;
	}
}

char *get_next_line(int fd)
{
	char *res;
	static char buff[BUFF_SIZE + 1];
	int i;
	int j;
	int error;

	res = NULL;
	ft_cat(&res, buff);
	ft_tozero(buff, BUFF_SIZE + 1);
	error = 1;
	while (ft_hasreturn(res) == 0 && error > 0)
	{
		error = read(fd, buff, BUFF_SIZE);
		ft_cat(&res, buff);
		ft_tozero(buff, BUFF_SIZE + 1);
	}
	i = 0;
	while (res[i] && res[i] != '\n')
	{
		i++;
	}
	if (res[i] == '\n')
	{
		i++;
		j = 0;
		while (res[i])
		{
			buff[j] = res[i];
			res[i] = '\0';
			j++;
			i++;
		}
		buff[j] = '\0';
	}
	return (res);
}
