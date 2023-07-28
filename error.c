#include "fdf.h"

void    ft_error(char *error_msg)
{
    ft_putstr_fd(error_msg, STDERR_FILENO);
    exit(errno);
}