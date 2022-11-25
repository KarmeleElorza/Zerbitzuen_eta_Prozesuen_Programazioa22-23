#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
void menuaErakutsi()
{
    printf("1.Dirua atera\n");
    printf("2.Dirua sartu\n");
    printf("3.Egungo Egoera (Kontuko egungo egoera, sarrera eta irteera guztiak ikusi)\n");
    printf("0.Irten\n");
}
void main()
{
    int aukera = 0;
    float hasierakoDirua = 10000;
    int fd[2], fd1[2], fd2[2];
    pid_t pid, pid2;
    pipe(fd);
    pipe(fd1);
    pipe(fd2);
    pid = fork();
    float ateratotal = 0, sartutotal = 0;
    if (pid == -1)
    {
        printf("Ezin izan da semea1 sortu...\n");
    }
    else
    {
        if (pid == 0) // Semea1
        {
            while (1)
            {
                float erabiltzaileakAteratakoa;
                //SEMEAK JASO
                close(fd[1]);//sarrera itxi
                read(fd[0], erabiltzaileakAteratakoa, sizeof (erabiltzaileakAteratakoa)); //pipea irakurri
                ateratotal = ateratotal + erabiltzaileakAteratakoa;
                printf("ateratotal: %f", ateratotal);
                //SEMEAK BIDALI
                close (fd1[0]);//pipea irakurtzeko aukera itxi
                write(fd1[1], ateratotal);//pipean idatzi
            }
        }
        else // Aita
        {
            pid2 = fork();
            if (pid2 == -1)
            {
                printf("Ezin izan da semea2 sortu...\n");
            }
            else
            {
                if (pid2 == 0) // Semea2
                {
                    while (1)
                    {
                        float erabiltzaileakSartutakoa;
                        //SEMEAK JASO
                        close(fd[1]);//sarrera itxi
                        read(fd[0], erabiltzaileakSartutakoa, sizeof (erabiltzaileakSartutakoa)); //pipea irakurri
                        sartutotal = sartutotal + erabiltzaileakSartutakoa;
                        printf("sartutotal: %f", sartutotal);
                        //SEMEAK BIDALI
                        close (fd2[0]);//pipea irakurtzeko aukera itxi
                        write(fd2[1], sartutotal);//pipean idatzi
                    }
                }
                else // Aita
                {
                    do
                    {
                        menuaErakutsi();
                        printf("Zer nahi duzu egin zure Kontu Korrontean?\n");
                        scanf("%d", &aukera);
                        switch (aukera)
                        {
                        case 1:
                            float diruaMurriztu;
                            printf("Dirua Ateratzeko prozesuan sartu zara. Zenbat diru nahi duzu atera?\n");
                            scanf("%f", &diruaMurriztu);
                            if (hasierakoDirua > diruaMurriztu)
                            {
                                hasierakoDirua = hasierakoDirua - diruaMurriztu;
                                printf("Kontu Korronteko Saldoa: %f\n", hasierakoDirua);
                            }
                            else
                            {
                                printf("Kontu Korrontean ez dago hainbeste dirurik...\n");
                            }
                            close(fd[0]);
                            write(fd[1], diruaMurriztu); // pipean idazten...
                            pid = wait(NULL);
                            break;

                        case 2:
                            float diruaGehitu;
                            printf("Dirua Sartzeko prozesuan sartu zara. Zenbat diru nahi duzu sartu?\n");
                            scanf("%f", &diruaGehitu);
                            hasierakoDirua = hasierakoDirua + diruaGehitu;
                            printf("Kontu Korronteko Saldoa: %f\n", hasierakoDirua);
                            close(fd[0]);
                            write(fd[1], diruaGehitu); // pipean idazten...
                            wait(NULL);
                            break;
                        case 3:

                            printf("Gaur egungo Kontu Korronteko saldoa honako hau da : %f\n", hasierakoDirua);
                            printf("%f ateraldi egin dira guztira\n", ateratotal);
                            printf("%f sarrera egin dira guztira\n", sartutotal);
                            break;
                        case 0:
                            kill(pid, SIGKILL);  // Semea1 kill
                            kill(pid2, SIGKILL); // Semea2 kill
                            sleep(1);
                            break;
                        }
                    } while (aukera != 0);
                }
            }
        }
    }
}