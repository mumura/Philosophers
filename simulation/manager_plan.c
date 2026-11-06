#include "philo.h"

static int available(long long t, long long eat, long long blocked[4][2], int count)
{
 if (t > MAX_LLONG - eat)
  return (0);
 for (int i = 0; i < count; i++)
  if (t < blocked[i][1] && t + eat > blocked[i][0])
   return (0);
 return (1);
}

static long long select_start(t_philo *p, long long period, long long now)
{
 long long blocked[4][2], candidates[11];
 long long target, latest, selected, distance = MAX_LLONG, d;
 int count, len = 3;
 if (p->last_meal > MAX_LLONG - p->share->time_to_die
  || p->last_meal > MAX_LLONG - period)
  return (-1);
 latest = p->last_meal + p->share->time_to_die - 2;
 if (latest < now)
  latest = now;
 target = p->last_meal + period;
 if (target < now) target = now;
 if (target > latest) target = latest;
 count = manager_intervals(p, period, now, blocked);
 candidates[0] = target; candidates[1] = now; candidates[2] = latest;
 for (int i = 0; i < count; i++)
 {
  candidates[len++] = blocked[i][0] - p->share->time_to_eat;
  candidates[len++] = blocked[i][1];
 }
 selected = target;
 for (int i = 0; i < len; i++)
 {
  if (candidates[i] < now || candidates[i] > latest
   || !available(candidates[i], p->share->time_to_eat, blocked, count))
   continue ;
  d = candidates[i] >= target ? candidates[i] - target : target - candidates[i];
  if (d < distance || (d == distance && candidates[i] < selected))
  { selected = candidates[i]; distance = d; }
 }
 return (selected);
}

static int check_forks_again(t_philo *p)
{
 long long delay;
 int busy;
 while (1)
 {
  pthread_mutex_lock(&p->state->mx);
  busy = p->state->fork_state[p->id - 1].owner != 0
   || p->state->fork_state[p->id % p->share->philo_cnt].owner != 0;
  pthread_mutex_unlock(&p->state->mx);
  if (!busy) return (0);
  delay = get_think_delay(p);
  if (delay < 0) { stop_simulation(p->state); return (1); }
  if (delay == 0) delay = 1;
  if (wait_think(p, delay)) return (1);
 }
}

int manager_thinking(t_philo *p, int initial)
{
 long long period, target, now;
 int result;
 period = manager_period(p);
 if (period == 0)
 {
  if (initial) return (0);
  target = get_think_delay(p);
  if (target < 0) { stop_simulation(p->state); return (1); }
  if (wait_think(p, target)) return (1);
  return (yield_think(p));
 }
 pthread_mutex_lock(&p->state->mx);
 now = now_ms();
 if (initial) target = manager_seed(p, period);
 else target = select_start(p, period, now);
 result = p->state->stop == 0 || target < 0 || now < 0;
 if (!result) { p->action = ACTION_THINKING; p->think_end = target; }
 pthread_mutex_unlock(&p->state->mx);
 if (result) { stop_simulation(p->state); return (1); }
 if (initial && target > now) log_action(p, "is thinking");
 if (wait_until(p->state, target)) return (1);
 return (check_forks_again(p));
}
