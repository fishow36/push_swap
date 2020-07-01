#include "push_swap.h"

int		nbr_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int		*char_to_int(int argc, char **argv)
{
	int	*list;
	int	i;

	i = 0;
	list = (int*)malloc(sizeof(int) * (argc - 1));
	if (!list)
		return(NULL);
	while (i < argc - 1)
	{
		list[i] = ft_atoi(argv[i + 1]);
		if (ft_strlen(argv[i + 1]) != nbr_len((long)list[i]) ||
		(list[i] == 0 && argv[i + 1][0] != '0'))
		{
			free(list);
			return(NULL);
		}
		i++;
	}
	return(list);
}

int		has_doubles(int *list, int len)
{
	int	i;
	int	prev;
	
	i = 1;
	prev = list[0];
	while(i < len)
	{
		if (list[i] == prev)
			return(1);
		prev = list[i];
		i++;
	}
	return(0);
}

int		*copy_list(int *list, int len)
{
	int	*res;
	int	i;

	res = (int*)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		res[i] = list[i];
		i++;
	}
	return(res);
}

int		*list_validation (int argc, char **argv)
{
	int		i;
	int		*list;
	int		*for_sort;
	int		prev;

	list = char_to_int(argc, argv);
	if (!list)
		return(NULL);
	for_sort = copy_list(list, argc - 1);
	for_sort = bubble_sort(for_sort, argc - 1);
	if (has_doubles(for_sort, argc - 1) == 1)
	{
		free(list);
		free(for_sort);
		return(NULL);
	}
	free(for_sort);
	return (list);
}
