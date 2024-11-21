/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:36:54 by jpaul             #+#    #+#             */
/*   Updated: 2024/11/16 09:10:35 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANT_H
#define CONSTANT_H

//===========================================================================
// State for Meta character detection

#define ON 0
#define SQ_OFF 1
#define DQ_OFF 2

#define S_QUOTE 1
#define D_QUOTE 2

#define O_BRACKET 0
#define C_BRACKET 1

//===========================================================================
//Type classification

#define AND 1    // &&
#define OR 2     // ||
#define PIPE 3   // |
#define HERE 4   // <<
#define RD 5     // <
#define APPD 6   // >>
#define WR 7     // >
#define OB 8     // (
#define CB 9     // )
#define STR 10   // Word

#define EXE 11   // Execution node
#define SUB 12   // Subshell 

#endif