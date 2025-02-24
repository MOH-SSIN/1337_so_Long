#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#include "../so_long.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

char	*get_next_line(int fd);
void	*ft_free(char *ptr1, char *ptr2);

#endif