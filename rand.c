#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t wrt;
pthread_mutex_t mutex;
int count;
int numreader;
void *writer(void *wno)
{
    sem_wait(&wrt);
    count = count * 2;
    printf("the writer changed the value %d to %d\n", (*((int *)wno)), count);
    sem_post(&wrt);
}
void *reader(void *rno)
{
    pthread_mutex_lock(&mutex);
    numreader++;
    if (numreader == 1)
    {
        sem_wait(&wrt);
    }
    pthreads_mutex_unlock(&mutex);
    printf("the reader changed %d to %d\n", ((*((int *)rno)), count));
    pthread_mutex_lock(&mutex);
    numreader--;
    if (numreader == 0)
    {
        sem_post(&wrt);
    }
    pthread_mutex_unlock(&mutex);
}
int main()
{
    pthread_t write[10], read[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt, 0, 1);
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++)
    {
        pthread_create(&write[i], NULL, (void *)writer, (void *)&a[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        pthread_join(&write[i], NULL);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(read[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}
