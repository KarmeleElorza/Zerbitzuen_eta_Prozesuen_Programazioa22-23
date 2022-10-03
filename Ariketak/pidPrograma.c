#include <stdio.h>
#include <unistd.h>
void main(void)
{
    pid_t id_actual, id_padre;
    id_actual = getpid();
    id_padre = getppid();
    printf("PID de este proceso: %d\n", id_actual);
    printf("PID del proceso padre: %d\n", id_padre);
}