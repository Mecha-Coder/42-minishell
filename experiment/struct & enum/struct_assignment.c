/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 02:23:20 by jpaul             #+#    #+#             */
/*   Updated: 2024/10/03 02:23:20 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
t_date x;
int y;

x is a variable like char & int.
Therefore, we can them just like a number.
 
x = (t_data){40, 50};
y = 50;
*/

typedef struct s_data
{
	int	a;
	int	b;
}	t_data;

t_data	createnode(int a, int b)
{
	return ((t_data){a, b});
}

int	main(void)
{
	t_data	x;

	x = createnode(40, 56);
	printf("%d, %d\n", x.a, x.b);
	return (0);
}
