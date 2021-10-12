#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int ft_hasreturn(char *s);
int ft_printf(const char *fmt, ...);

int main(void)
{
	int fd;
	char *res;

	fd = open("test.txt", O_RDONLY);

	res = get_next_line(fd);
	ft_printf("---%s", res);
	free(res);
	while (ft_hasreturn(res) == 1)
	{
		res = get_next_line(fd);
		ft_printf("---%s", res);
		free(res);
	}
}