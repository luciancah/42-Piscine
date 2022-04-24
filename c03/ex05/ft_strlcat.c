/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:07:05 by jinhlee           #+#    #+#             */
/*   Updated: 2022/02/16 10:08:18 by jinhlee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	_strlen(char *c)
{
	int	len;

	len = 0;
	while (c[len])
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	i = 0;
	dest_len = _strlen(dest);
	src_len = _strlen(src);
	while (i < size && *dest != '\0')
	{
		dest++;
		i++;
	}
	if (i == size)
		return (src_len + size);
	while (i + 1 < size && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (dest_len + src_len);
}
