#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "list.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int        cycle_detector(const t_list *list)
{
	const t_list *tmp;
	const t_list *tmp2;

	tmp = list;
	tmp2 = list;
	if (list == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		tmp2 = tmp2->next->next;
		if (tmp == tmp2)
		{
			return (1);
		}
	}
	return (0);
}

void        create_list(t_list **check, char *data)
{
    t_list  *temp;
    t_list  *p;

    temp = (t_list *)malloc(sizeof(t_list));
    if (temp == NULL)
        return ;
    temp->data = strdup(data);
    temp->next = NULL;
    if (*check == NULL)
    {
        *check = temp;
    }
    else
    {
        p = *check;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void    ft_putnbr(int n)
{
    if (n >= 0 && n <= 9)
    {
        ft_putchar(n + '0');
    }
}

int main(int argc, char **argv)
{
    t_list  *check;
	t_list	*cycle;
	t_list	*temp;
    int     i;

	i = 1;
	cycle = (t_list *)malloc(sizeof(t_list));
	cycle->data = strdup(argv[i]);
    check = NULL;
    if (argc == 1)
    {
        ft_putchar('\n');
    }
	i = 2;
    while (i < argc)
    {
        create_list(&check, argv[i]);
        i++;
    }
	temp = check;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = cycle;
	cycle->next = check;
    ft_putnbr(cycle_detector(check));
    ft_putchar('\n');
    return (0);
}
