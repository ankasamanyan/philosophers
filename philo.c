#include "philo.h"
void *halp()
{
	printf("Halp ze philosophers\n");
	return 0;
}
void *halp2()
{
	sleep(2);
	printf("Halp ze second philosophers\n");
	return 0;
}

int main(int argc, char const *argv[])
{
	
	(void)argc;
	(void)argv;
	pthread_t philo1;
	pthread_t philo2;

	pthread_create(&philo2, NULL, &halp2, NULL);
	pthread_create(&philo1, NULL, &halp, NULL);


	pthread_join(philo1, NULL);
	pthread_join(philo2, NULL);

	return 0;
}
