#include "../includes/minishell.h"

void	sig_slash(int code)
{
	(void)code;
	g_sig.sigint = 0;
	ft_putstr_fd("\b \b", 2);
	ft_putstr_fd("BulochkaBao%   ", 2);
	ft_putstr_fd("\b\b", 2);
}

void	sig_init(int code)
{
	(void)code;
	ft_putstr_fd("\b \b", 2);
	ft_putstr_fd("BulochkaBao%   ", 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("BulochkaBao% ", 2);
}
