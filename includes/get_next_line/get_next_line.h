/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:54:02 by bboisset          #+#    #+#             */
/*   Updated: 2019/11/12 18:53:14 by bboisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 64

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

int        	end_of_line(char *temp);
int        	exit_fct(char **temp, char **buffer);
int        	store_rest(char *temp, char **rest);
int        	read_line(int const fd, char **line, char **rest);
int        	get_next_line(int const fd, char **line);

int			ft_strlen_gnl(const char *s);
char		*ft_strdup_gnl(const char *s1);
char		*ft_strcpy_gnl(char *dst, const char *src);
char		*ft_strjoin_gnl(const char *s1,const char *s2);
char		*ft_substr_gnl(char const *s, size_t start, size_t len);
#endif
