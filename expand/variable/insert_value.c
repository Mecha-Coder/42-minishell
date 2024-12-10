/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_identifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:58:08 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/17 14:29:15 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*insert_value(char *s, int *i, int len, t_env *env)
{
	char	*key;
	char	*value;
	char	*result;

	s[*i] = '\0';
	key = (char *)malloc(len + 1);
	if (!key)
		err_exit("malloc", errno);
	ft_strlcpy(key, &s[*i + 1], len + 1);
	value = env_val(key, env);
	result = join3(s, value, &s[*i + len + 1]);
	free(key);
	*i += ft_strlen(value);
	return (result);
}

/* Test
int main()
{
	int i = 0;
	
	t_env n1;
	t_env n2;

	n1.key = "USER";
	n1.val = "jc";
	n1.next = &n2;

	n2.key = "abc";
	n2.val = "$NEW_VAR";
	n2.next = NULL;

	char str[] = "$USER$!lo$SWAP_VAR:User$abc";
	char *s;
	char *temp;
	int len;

	s = (char *)malloc(ft_strlen(str) + 1);
	ft_strcpy(s, str);
	printf("\n\n%s\n", s);

	while(s[i])
	{
		if (s[i] == '$' && is_identifier(&s[i + 1], &len))
		{
			temp = insert_identifier(s, &i, len, &n1);
			free(s);
			s = temp;
			printf("%s\n",s);
		}
		else
			i++;
	}
	free(s);   
}
*/