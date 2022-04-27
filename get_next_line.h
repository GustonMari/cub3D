#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_gnl_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup_less(char *src, int carac);

#endif