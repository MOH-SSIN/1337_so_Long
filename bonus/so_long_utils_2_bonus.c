#include "so_long_bonus.h"

int aid_verif_elements(char element,int *p, int *e, int *c, int *x)
{
    if (element == 'P')
        (*p)++;
    else if (element == 'E')
        (*e)++;
    else if (element == 'C')
        (*c)++;
    else if (element == 'X')
        (*x)++;
    else if (element != '0' && element != '1')
                return (0);
    return (1);
}

int get_position_player(char **copie, int *i, int *j)
{
    *i = 0;
    while (copie[*i])
    {
        *j = 0;
        while (copie[*i][*j])
        {
            if (copie[*i][*j] == 'P')
                return (1);//hna l9ite player
            (*j)++;
        }
        (*i)++;
    }
    return (0);// hna mal9itoch
}

int ft_presence_elemntes(char **copie)
{
    int i;
    int j;
    int c;
    int e;
    int x;

    i = 0;
    c = 0;
    e = 0;
    x = 0;
    while (copie[i])
    {
        j = 0;
        while (copie[i][j])
        {
            if (copie[i][j] == 'E')
                e++;
            else if (copie[i][j] == 'C')
                c++;
            else if (copie[i][j] == 'X')
                x++;
            j++;
        }
        i++;
    }
    return (c == 0 && e == 0 && x == 0);// 1 ila les elemnet('E' et 'C') makiniche
}
