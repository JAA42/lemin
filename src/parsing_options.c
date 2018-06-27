#include "../inc/lem_in.h"

int		isoption(char *options, char c)
{
	int i;

	i = 0;
	while (options[i])
	{
		if (options[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	isvalid_option(char c, char *options_available, char *executable)
{
	int i;

	i = 0;
	while (options_available[i])
	{
		if (options_available[i] == c)
			return ;
		i++;
	}
	ft_putstr(executable);
	ft_putstr(": illegal options -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putstr("usage: ");
	ft_putstr(executable);
	ft_putstr(" [-");
	ft_putstr(options_available);
	ft_putstr("]");
	exit(0);
}

void	ft_unused_entry_error(char *str)
{
	printf("Nothing to do with: %s\n", str);
	ft_putstr("Nothing to do with: ");
	ft_putstr(str);
	ft_putchar('\n');
	exit(0);
}

char	*get_options(char *argv[], char *options_available)
{
	int i;
	int p;
	char *options;

	options = ft_strdup("\0");
	i = 1;
	p = 0;
	while(argv[i])
	{
		p = 0;
		if (argv[i][0] == '-')
		{
			p++;
			while (argv[i][p])
			{
				isvalid_option(argv[i][p], options_available, argv[0]);
				options = ft_strjoin_f(options, ft_chardup(argv[i][p]), 3);
				p++;
			}
		}
		else
			ft_unused_entry_error(argv[i]);
		i++;
	}
	return (options);
}
