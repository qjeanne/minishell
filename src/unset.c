#include "../includes/minishell.h"

static int	check_variable(char *text, char **name)
{
	int		i;

	if (!(ft_isalpha(text[0]) || text[0] == '_'))
		return (0);
	i = 0;
	while (text[i] != '=' && text[i] != '\0')
		i++;
	*name = (char *)malloc(sizeof(char) * (i + 1));
	(*name)[i] = '\0';
	i = 0;
	while (*text != '=' && *text != '\0')
		(*name)[i++] = *text++;
	return (1);
}

static void	without_variable(t_info *info, int i)
{
	char	**copy;
	int		size;
	int		n;

	size = 0;
	while (info->envp[size] != NULL)
		size++;
	copy = (char **)malloc(sizeof(char *) * (size));
	copy[size - 1] = NULL;
	size = 0;
	n = 0;
	while (info->envp[size] != NULL)
	{
		if (size != i)
		{
			copy[n] = (char *) malloc(
					sizeof(char) * (ft_strlen(info->envp[size]) + 1));
			ft_strlcpy(copy[n], info->envp[size], ft_strlen(info->envp[size])
				+ 1);
			n++;
		}
		size++;
	}
	free_2arr(info->envp);
	info->envp = copy;
}

static void	delet_variable(t_info *info, char *name)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	while (info->envp[i] != NULL)
	{
		if (!ft_strncmp(info->envp[i], name, ft_strlen(name))
			&& (info->envp[i][ft_strlen(name)] == '='
			|| info->envp[i][ft_strlen(name)] == '\0'))
		{
			check = 1;
			break ;
		}
		i++;
	}
	if (check)
		without_variable(info, i);
}

void	unset(t_info *info, char **text)
{
	char	*name;

	text++;
	if (!(*text))
		return ;
	else
	{
		while (*text)
		{
			name = NULL;
			check_variable(*text, &name);
			delet_variable(info, name);
			text++;
			free(name);
		}
	}
}
