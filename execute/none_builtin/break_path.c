/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:15:44 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/29 13:34:40 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* >>> all_path
Purpose: 
- Search env key = PATH
Split env_path into individual path
- Put paths into malloc array
=======================================================================
Example: 

/urs/local/bin:/local/sbin:/usr/bin\0
/urs/local/bin\0

-> /usr/local/bin/
-> /loca/sbin/
-> /usr/bin/

Note: Delimited by ':' and '\0' and add '/' slash in the end
=======================================================================
Return
- char ** : 2D array
          : NULL if env PATH is blank
*/

void break_path