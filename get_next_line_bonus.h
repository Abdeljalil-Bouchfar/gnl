/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:29:41 by abouchfa          #+#    #+#             */
/*   Updated: 2021/11/17 13:29:47 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2);
int		gnl_strchr(const char *s);
void	ft_free(void *p);
size_t	ft_strlen(const char *s);
void	ft_strncpy(char *dest, char *src, int n);
char	*get_next_line(int fd);

#endif