/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinsekan <jinsekan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 04:09:58 by jinsekan          #+#    #+#             */
/*   Updated: 2026/11/05 17:47:26 by jinsekan         ###   ########.fr       */
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

/* Caller holds state.print; start_time is immutable after startup. */
void	log_locked(t_philo *p, const char *action, long long now)
{
	t_state	*s;
	size_t	len;
	char	buf[64];

	s = p->state;
	len = append_number(buf, 0, now - s->start_time);
	buf[len++] = ' ';
	len = append_number(buf, len, p->id);
	buf[len++] = ' ';
	len = append_text(buf, len, action);
	buf[len++] = '\n';
	write(1, buf, len);
}

void	log_action(t_philo *p, const char *action)
{
	t_state		*s;
	long long	now;
	int			running;

	s = p->state;
	pthread_mutex_lock(&s->print);
	pthread_mutex_lock(&s->mx);
	now = now_ms();
	running = (s->stop == 1);
	pthread_mutex_unlock(&s->mx);
	if (running)
		log_locked(p, action, now);
	pthread_mutex_unlock(&s->print);
}
