struct s_data
{
	long long		philo_cnt;
	long long		must_eat;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;


}; //	t_data;


struct s_app
{
	struct s_data
	long long		start_time;
	long long		stop;// 1 실행중, 0 멈춤
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	state_mutex;
};
