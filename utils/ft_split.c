#include "../function.h"

int    ft_is_sep(char c, char *charset)
{
    int    i;

    i = 0;
    while (charset[i])
    {
        if (c == charset[i])
            return (1);
        i++;
    }
    return (0);
}

int    ft_wordlen(char *str, char *charset)
{
    int    i;

    i = 0;
    while (str[i] && !ft_is_sep(str[i], charset))
        i++;
    return (i);
}

int    ft_count_words(char *str, char *charset)
{
    int    count;
    int    len;

    count = 0;
    while (*str)
    {
        while (ft_is_sep(*str, charset) && *str)
            str++;
        len = ft_wordlen(str, charset);
        str += len;
        if (len != 0)
            count++;
    }
    return (count);
}

char    *w_copy(char *str, int len)
{
    char    *ret;

    ret = malloc(sizeof(char) * len + 1);
    if (!ret)
        return (NULL);
    ret[len] = '\0';
    while (len-- >= 0)
        ret[len] = str[len];
    return (ret);
}

char    **ft_split(char *str, char *charset)
{
    char    **tab;
    int        words;
    int        w_len;
    int        i;

    i = 0;
    words = ft_count_words(str, charset);
    tab = malloc(sizeof(char *) * (words + 1));
    if (!tab)
        return (NULL);
    while (i < words)
    {
        while (ft_is_sep(*str, charset) && *str)
            str++;
        w_len = ft_wordlen(str, charset);
        tab[i] = w_copy(str, w_len);
        if (!tab[i])
            return (0);
        str += w_len;
        i++;
    }
    tab[words] = 0;
    return (tab);
}