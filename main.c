#include "thread.h"

void    *Increment(t_list *vars)
{
    int i;
    i = 0;
    while (i < 100)
    {
        vars->global++;
        i++;
    }
    return NULL;
}

int main()
{
    t_list vars;
    vars.global = 0;
    pthread_t t1, t2;
    pthread_create(&t1, NULL, (void *)Increment, &vars);
    pthread_create(&t2, NULL, (void *)Increment, &vars);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("%d", vars.global);
}