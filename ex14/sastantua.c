#include <unistd.h>
#include <stdlib.h>

int	g_size = 0;
int	g_sum;
int	g_extra_width;
int	g_step;
int	g_done_lines;
int g_width;
int g_height;
int g_i;
int g_r;
int g_space;
int g_t;

void	ft_error(char *str, int fd)
{
    while (*str)
        write(fd, str++, 1);
    exit(EXIT_FAILURE);
}

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

int		lines(void)
{
	int height_pyramid;
	int size;

	size = g_size;
	height_pyramid = g_size;
	while (size-- > 0)
	{
		height_pyramid += size + 2;
	}
	return (height_pyramid);
}

int		offset(void)
{
	int max;
	int sum;
	int real;
	int i;

	max = 2;
	sum = !(g_size % 2);
	real = 0;
	i = 1;
	while (i++ < g_size / 2)
		++max;
	i = g_step;
	while (i++ < g_size)
	{
		real += max;
		if (sum)
		{
			max -= 1;
			sum = 0;
		}
		else
			sum = 1;
	}
	return (real);
}

int		segment(int w, int h, int o, int l)
{
	g_r = 1;
	while (g_r <= h)
	{
		g_space = 0;
		while (g_space++ < l + o - g_r)
			ft_putchar(' ');
		ft_putchar('/');
		g_t = 0;
		while (g_t++ < (w + 2 * (g_r - 1)))
		{
			if (o == 0 && (l - g_r < h - 3 + g_size % 2) && (g_t > w / 2 + g_r
		- (g_size + g_size % 2) / 2) && g_t < w / 2 + g_r + (g_size + g_size % 2) / 2)
			{
				(l - g_r == (h - 3 + g_size % 2) / 2 &&
		g_size > 4 && g_t == w / 2 + g_r + (g_size + g_size % 2) / 2 - 2) ?
				ft_putchar('$') : ft_putchar('|');
			}
			else
				ft_putchar('*');
		}
		ft_putchar('\\');
		ft_putchar('\n');
		++g_r;
	}
	return (w + 2 * (h - 1));
}

void	sastantua(int size)
{
	g_width = 1;
	g_height = 3;
	g_step = 1;
	g_done_lines = 0;
	g_size = size;
	if (g_step > 0)
	{
		while (g_step <= g_size)
		{
			g_extra_width = 2;
			g_sum = 1;
			g_width = segment(g_width, g_height, offset(), lines() - g_done_lines);
			g_i = 1;
			while (g_i++ <= g_step)
			{
				if (g_sum)
					g_extra_width++;
				g_sum = !g_sum;
			}
			g_width += g_extra_width * 2;
			g_done_lines += g_height;
			++g_height;
			++g_step;
		}
	}
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int res = atoi(av[1]);
        sastantua(res);
    }
    else
    {
        ft_error("usage: ./sastantua [size]", 2);
    }
    return 0;
}