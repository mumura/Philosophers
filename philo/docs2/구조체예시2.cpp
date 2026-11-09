struct s_data
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
};


struct s_share
{
	long long		philo_cnt;
	long long		must_eat;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
};

t_share cli_parse(int argc, char **argv);

struct s_state // 상태관리
{
	// long long		must_eat;
	long long		eat_count;
	bool			is_end;
	pthread_mutex_t	mx; // 상태 관리 + 출력
};


struct s_philo
{
	long long		id;
	pthread_t		thread;
	long long		last_meal;
	long long		meal_cnt;
	t_share			share;
	t_state			*state;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	// t_data			*data;
}; //t_philo

void philo_routine(void *p);



data_init(t_data *data_ptr);
data_drop(t_data *data_ptr);

int main()
{
	t_data	data;

	// ...
	// data_init();
	// 열심히 data 접근
	// data_free();
	//
}
