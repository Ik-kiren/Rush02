#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_putnbr(int nb)
{
	int	r;
	int i;
	static char strnb[500];

	i = 0;
	while (nb != 0)
	{
		r = nb % 10;
		nb /= 10;
		strnb[i] = r + '0';
		i++;
	}
	strnb[i] = '\0';
	return (strnb);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void ft_revstr(char *str)
{
	int i;
	int s;
	int j;
	char t;

	i = 0;
	s = 0;
	j = 0;
	while (str[i])
	{
		i++;
	}
	i--;
	s = i / 2;
	while (j < s)
	{
		t = str[j];
		str[j] = str[i];
		str[i] = t;
		i--;
		j++;
	}
}

void writenbr(char *file, char *str)
{
	int i;
	int j;
	int b;
	char cnb;

	i = 0;
	j = 0;
	b = 0;
	while (str[i])
	{
		j = 0;
		b = 0;
		while (file[j])
		{
			//ft_putchar(file[j]);
			if (str[i] == file[j])
			{
				//ft_putchar(str[i]);
				//ft_putchar(file[j]);
				while(file[j])
				{
					if (file[j] > 96 && file[j] < 123)
					{
						ft_putchar(file[j]);
						if (file[j + 1] <= 96 || file[j + 1] >= 123)
						{	
							b = 1;
							break;
						}
					}
					j++;
				}
			}
			if(b == 1)
			{
				break;
			}
			j++;
		}
		i++;
	}
}

int main()
{
	int fd;
	int ret;
	char buff[5000];
	char tab[500];

	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open error");
		return (1);
	}
	ret = read(fd, buff, 4580);
	if (ret == -1)
	{
		ft_putstr("read error");
		return (1);
	}
	buff[ret] = '\0';
	close(fd);

	ft_strcpy(tab, "210016");
	//ft_revstr(tab);
	//ft_putstr(tab);
	writenbr(buff, tab);
}
