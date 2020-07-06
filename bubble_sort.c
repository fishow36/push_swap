/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:28:32 by eshor             #+#    #+#             */
/*   Updated: 2020/07/06 13:28:33 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    *bubble_sort(int  *arr, int len)
{
    int i;
    int j;

    i = 0;
    while(i < len - 1)
    {
        j = i + 1;
        while (j < len)
        {
            if (arr[i] >= arr[j])
            {
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
            j++;
        }
        i++;
    }
    return(arr);
}
