/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 04:09:58 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 05:31:10 by jinsekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	append_number(char *buf, size_t pos, long long value)
{
	if (value >= 10)
		pos = append_number(buf, pos, value / 10);
	buf[pos] = '0' + value % 10;
	return (pos + 1);
}

static size_t	append_text(char *buf, size_t pos, const char *text)
{
	while (*text)
	{
		buf[pos++] = *text;
		text++;
	}
	return (pos);
}

void	log_action(t_philo *p, const char *action)
{
	t_state		*s;
	size_t		len;
	long long	n_ms;
	char		buf[64];

	n_ms = 0;
	s = p->state;
	pthread_mutex_lock(&s->mx);
	if (s->stop == 1)
	{
		n_ms = now_ms();
		len = append_number(buf, 0, n_ms - s->start_time);
		buf[len++] = ' ';
		len = append_number(buf, len, p->id);
		buf[len++] = ' ';
		len = append_text(buf, len, action);
		buf[len++] = '\n';
		write(1, buf, len);
	}
	pthread_mutex_unlock(&s->mx);
}
