#include "philo.h"

long long manager_period(t_philo *p)
{
 const t_share *sh = p->share;
 long long k = sh->philo_cnt / 2;
 long long base, work, slack;
 if (!k || sh->philo_cnt > MAX_LLONG / sh->time_to_eat
  || sh->time_to_sleep > MAX_LLONG - sh->time_to_eat)
  return (0);
 work = sh->philo_cnt * sh->time_to_eat;
 base = work / k + (work % k != 0);
 if (base < sh->time_to_eat + sh->time_to_sleep)
  base = sh->time_to_eat + sh->time_to_sleep;
 if (base >= sh->time_to_die)
  return (0);
 slack = (sh->time_to_die - base) / 2;
 if (slack > 25)
  slack = 25;
 return (base + slack);
}

long long manager_seed(t_philo *p, long long period)
{
 long long n = p->share->philo_cnt;
 long long rank;
 if (p->id - 1 > MAX_LLONG / ((n + 1) / 2))
  return (-1);
 rank = ((p->id - 1) * ((n + 1) / 2)) % n;
 if (rank && period > MAX_LLONG / rank)
  return (-1);
 if (p->state->start_time > MAX_LLONG - rank * period / n)
  return (-1);
 return (p->state->start_time + rank * period / n);
}

static long long neighbor_start(t_philo *q, long long period, long long now)
{
 long long target;
 if (q->action == ACTION_THINKING && q->think_end != MAX_LLONG
  && q->think_end >= now)
  return (q->think_end);
 if (q->meal_cnt || q->action == ACTION_EATING || q->action == ACTION_SLEEPING)
 {
  if (q->last_meal > MAX_LLONG - period)
   return (-1);
  target = q->last_meal + period;
 }
 else
  target = manager_seed(q, period);
 if (target < now)
  target = now;
 return (target);
}

int manager_intervals(t_philo *p, long long period, long long now,
 long long blocked[4][2])
{
 t_philo *all = p - (p->id - 1);
 t_philo *q;
 long long n = p->share->philo_cnt;
 long long t;
 int count = 0;
 for (int i = 0; i < 2; i++)
 {
  q = &all[(p->id + n - 2 + 2 * i) % n];
  if (i == 1 && n == 2)
   break ;
  if (q->action == ACTION_EATING && q->last_meal <= MAX_LLONG - p->share->time_to_eat
   && q->last_meal + p->share->time_to_eat > now)
  {
   blocked[count][0] = q->last_meal;
   blocked[count++][1] = q->last_meal + p->share->time_to_eat;
  }
  t = neighbor_start(q, period, now);
  if (t < 0 || t > MAX_LLONG - p->share->time_to_eat)
   continue ;
  blocked[count][0] = t;
  blocked[count++][1] = t + p->share->time_to_eat;
 }
 return (count);
}
