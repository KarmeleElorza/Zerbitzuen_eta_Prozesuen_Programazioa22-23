#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main()
{
    pid_t pid, Hijo__pid, pid2, Hijo2_pid;
    int fd1 [2];
    int fd2 [2];
    char saludoAbuelo[]="Saludos del Abuelo.\0";
    char saludoPadre[]= "Saludos del Padre..\0";
    char saludoHijo[]= "Saludos del Hijo...\0";
    char saludoNieto[]= "Saludos del Nieto..\0";
    char buffer[80];
    pipe(fd1);
    pipe(fd2);
    pid = fork();
    if (pid == -1 ) //Ha ocurrido un error
    {
        printf("No se ha podido crear el proceso hijo...");
        exit(-1);
    }
    if (pid == 0)
    {
        pid2 = fork();//Soy el Hijo, creo a Nieto
        switch(pid2)
    }
}