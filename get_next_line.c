/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:16:11 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/01 08:14:03 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** line must be joined with the buff str first when a newline is detected
** as str contains everything that was in the string preceding the newline
** when the newline char occurs in the buffer then line is copied to
** we use buff and len to copy up to the newline and put that in line
** then we replace he contents of str with whatevers after the newline
** we use len + 1 because at buff[len] is the newline where line should stop
** we use ret - len to get how many characters are leftover in buff
*/

char	*ft_addtostr(char *str, char *buff)
{
	char	*temp;

	temp = ft_strjoin(str, buff);
	free(str);
	return (temp);
}

char	*ft_putline(char **line, char *str)
{
	int		len;
	char	*temp;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	*line = ft_strsub(str, 0, len);
	if (ft_strcmp(*line, str) == 0)
		return (NULL);
	else
	{
		temp = ft_strsub(str, len + 1, (ft_strlen(str + len + 1)));
		free(str);
	}
	return (temp);
}

/*
** get_next_line reads line by line returns 1 if the file isn't
** finished being read,-1 if there is an error ,and 0 when it
** reaches end of file.checks if there is a newline in the str
** which stores the leftovers of read if there is that means
** there is no need to call read again as it has the contents
** of the next line
*/

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static char	*str[1024];

	ret = 0;
	if (!(line) || (read(fd, buff, 0) == -1) || fd < 0)
		return (-1);
	if (!(str[fd]))
		str[fd] = ft_strnew(0);
	if (!(ft_strchr(str[fd], '\n')))
	{
		while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			str[fd] = ft_addtostr(str[fd], buff);
			if (ft_strchr(str[fd], '\n'))
				break ;
		}
	}
	if (ret == 0 && !(ft_strlen(str[fd])))
		return (0);
	str[fd] = ft_putline(line, str[fd]);
	return (1);
}
