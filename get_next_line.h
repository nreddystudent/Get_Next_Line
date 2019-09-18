/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreddy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:33:51 by nreddy            #+#    #+#             */
/*   Updated: 2019/07/01 08:14:19 by nreddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 40000
# include <sys/types.h>
# include <sys/uio.h>
# include "./libft/libft.h"

int		get_next_line(const int fd, char **line);
#endif
