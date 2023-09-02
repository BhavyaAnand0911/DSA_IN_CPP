#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum = 0; // shared variable

void *runner(void *param); // thread function

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: %s <num>\n", argv[0]);
        return -1;
    }

    int upper = atoi(argv[1]);
    if (upper < 0)
    {
        fprintf(stderr, "num must be >= 0\n");
        return -1;
    }

    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, runner, &upper);
    pthread_join(tid, NULL);

    printf("Sum = %d\n", sum);

    return 0;
}

void *runner(void *param)
{
    int upper = *(int *)param;
    for (int i = 1; i <= upper; i++)
        sum += i;

    pthread_exit(NULL);
}
