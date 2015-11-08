#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define TAILLE_MAX 1000
#ifdef WIN32
#include <windows.h>
#elif _POSIX_C_SOURCE >= 199309L
#include <time.h>
#else
#include <unistd.h>
#endif

void sleep_ms(int milliseconds) // cross-platform sleep function
{
#ifdef WIN32
    Sleep(milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#else
    usleep(milliseconds * 1000);
#endif
}


void sleepFor(int seconds){
    fflush(stdout);
    sleep_ms(seconds);
}

void showLoad(){
    printf("|");
    sleepFor(100);
    printf("\b");
    fflush(stdout);
    printf("/");
    sleepFor(100);
    printf("\b");
    fflush(stdout);
    printf("-");
    sleepFor(100);
    printf("\b");
    fflush(stdout);
    printf("|");
    sleepFor(100);
    printf("\b");
    fflush(stdout);
    printf("/");
    sleepFor(100);
    printf("\b");
    fflush(stdout);
    printf("-");
    sleepFor(100);
    printf("\b");
    fflush(stdout);
    printf("|");
    sleepFor(100);
    printf("\b");
    fflush(stdout);
}

int main()
{
    char loading = 0;
    char wrongCommand = 0;
    char win = 0;
    bool inGame = true;
    char AttsServers = 20;
    char VerizonServers = 20;
    int VerizonAttack = 0;
    int DeadServers = 0;
    int ServerLose = 0;
    char password[] = "atts";
    char givenPassword[10];
    char ID[50];
    char IDAdmin[] = "root";
    char Continue[] = "CONTINUE";
    char Manual[] = "MANUAL";
    char Restart[] = "RESTART";
    char Ranking[] = "RANKING";
    char Mitm[] = "MITM";
    char OverCPU[] = "OVERCPU";
    char Fix[] = "FIX";
    char givenCommand[20];
    char Exit[] = "EXIT";
    char Name[50];
    char lineManual[TAILLE_MAX] = "";

    srand(time(NULL));

    FILE* manual = NULL;
    FILE* ranking = NULL;

    printf("Connection to ATTS' servers");
    sleepFor(1000);

    loading = 0;

    while (loading < 10)
    {
        showLoad();
        loading ++;
    }

    printf("\nConnection established\n");
    sleepFor(500);
    printf("Please enter your ID\n");
    printf("ID : ");
    scanf("%s", ID);
    sleepFor(500);

    if (strcmp(ID, IDAdmin) == 0)
    {
        printf("Hi Admin, please enter your password");
    }

    else
    {
        printf("\nWrong ID. You will be rejected by the server in 5 seconds");
        sleepFor(5000);
        return 0;
    }

    printf("\nPassword : ");
    scanf("%s", givenPassword);

    loading = 0;

    while (loading < 5)
    {
        showLoad();
        loading ++;
    }

    printf("\b");

    if (strcmp(givenPassword, password) == 0)
    {
        printf("Access Granted\n");

        loading = 0;

        while (loading < 5)
        {
            showLoad();
            loading ++;
        }

    printf("\b");
    }

    else
    {
        printf("Wrong password. You will be rejected by the server in 5 seconds");
        sleepFor(5000);
        return 0;
    }

    while (wrongCommand != 1)
    {

        printf("You are now connected, to see the manual type MANUAL, to see the ranking type\nRANKING else type CONTINUE\n");
        printf("command : ");
        scanf("%s", givenCommand);

        loading = 0;

        while (loading < 5)
        {
            showLoad();
            loading ++;
        }

        printf("\b");

        if (strcmp(givenCommand, Manual) == 0)
        {
            manual = fopen("manual.txt", "r");

            if (manual != NULL)
            {
                while (fgets(lineManual, TAILLE_MAX, manual) != NULL)
                {
                    printf("%s", lineManual);
                    sleepFor(500);
                }

                printf("\ncommand :");
                scanf("%s", givenCommand);

                if (strcmp(givenCommand, Restart) == 0)
                {
                    wrongCommand = 0;
                }

                else if (strcmp(givenCommand, Exit) == 0)
                {
                    printf("The program will stop in few seconds");
                    sleepFor(5000);
                    return 0;
                }

                else
                {
                    printf("Wrong command");
                }
            }

            else
            {
                printf("Unknown error detected during the manual opening, the program will restart automatically in few seconds\n");
                sleepFor(5000);
            }

        }

        else if (strcmp(givenCommand, Ranking) == 0)
        {
            ranking = fopen("ranking.txt", "r");

            if (ranking != NULL)
            {
                while (fgets(lineManual, TAILLE_MAX, ranking) != NULL)
                {
                    printf("%s", lineManual);
                    sleepFor(500);
                }

                printf("\nWhen you have read everything you can type RESTART or EXIT");
                printf("\ncommand :");
                scanf("%s", givenCommand);

                if (strcmp(givenCommand, Restart) == 0)
                {
                    wrongCommand = 0;
                }

                else if (strcmp(givenCommand, Exit) == 0)
                {
                    printf("The program will stop in few seconds");
                    sleepFor(5000);
                    return 0;
                }

                else
                {
                    printf("Wrong command");
                }
            }

            else
            {
                printf("Unknown error detected during the ranking file opening, the program will restart automatically in few seconds\n");
                sleepFor(5000);
            }
        }

        else if (strcmp(givenCommand, Continue) == 0)
        {
            printf("Welcome in the Servers Administration Center SAC\nComponents are loading");

            loading = 0;

            while (loading < 10)
            {
                showLoad();
                loading ++;
            }

            printf("\b");

            printf("\nComponents are ready to use\nVerizon is trying to hack your servers but you knew that was planned today!\nIt is your turn!");
            while (inGame != false)
            {
                printf("\ncommand : ");
                scanf("%s", givenCommand);

                loading = 0;

                while (loading < 2)
                {
                    showLoad();
                    loading ++;
                }

                printf("\b");

                if (strcmp(givenCommand, Mitm) == 0)
                {
                    printf("\nVerizon's servers hacked, they lost one server!");

                    VerizonServers --;

                    loading = 0;

                    while (loading < 2)
                    {
                        showLoad();
                        loading ++;
                    }

                    printf("\b");

                    VerizonAttack = rand() % 3;

                    if (VerizonAttack == 0)
                    {
                        printf("\nVerizon uses the MITM method, you lose 1 server");
                        AttsServers --;
                    }

                    else if (VerizonAttack == 1)
                    {
                        printf("\nVerizon allocates a server to overheat your CPU");
                        DeadServers = rand() % 5;
                        sleepFor(500);

                        if (DeadServers == 0)
                        {
                            printf("\nVerizon wastes his attack, you keep all of your servers");
                        }

                        else if (DeadServers == 1)
                        {
                            printf("\nVerizon kills 1 of your servers");
                            AttsServers --;
                        }

                        else if (DeadServers == 2)
                        {
                            printf("\nVerizon kills 2 of your servers");
                            AttsServers -= 2;
                        }

                        else if (DeadServers == 3)
                        {
                            printf("\nVerizon kills 3 of your servers");
                            AttsServers -= 3;
                        }

                        else
                        {
                            printf("\nVerizon kills 4 of your servers");
                            AttsServers -= 4;
                        }

                        sleepFor(500);

                        ServerLose = rand() % 2;

                        if (ServerLose == 0)
                        {
                            printf("\nBy using one of his servers, Verizon lose one of his servers");
                            VerizonServers --;
                        }

                        else
                        {
                            printf("\nVerizon hacks you with his server but don't broke it");
                        }
                    }

                    else
                    {
                        printf("\nVerizon fixes a server");
                        VerizonServers ++;
                    }

                    printf("\nYou have %d servers and Verizon has %d servers...", AttsServers, VerizonServers);
                }

                else if (strcmp(givenCommand, OverCPU) == 0)
                {
                        printf("\nYou allocate a server to overheat their CPU");
                        DeadServers = rand() % 5;
                        sleepFor(500);

                        if (DeadServers == 0)
                        {
                            printf("\nYou waste your attack, they keep all of their servers");
                        }

                        else if (DeadServers == 1)
                        {
                            printf("\nYou kill 1 of their servers");
                            VerizonServers --;
                        }

                        else if (DeadServers == 2)
                        {
                            printf("\nYou kill 2 of their servers");
                            VerizonServers -= 2;
                        }

                        else if (DeadServers == 3)
                        {
                            printf("\nYou kill 3 of their servers");
                            VerizonServers -= 3;
                        }

                        else
                        {
                            printf("\nYou kill 4 of their servers");
                            VerizonServers -= 4;
                        }

                        sleepFor(500);

                        ServerLose = rand() % 2;

                        if (ServerLose == 0)
                        {
                            printf("\nBy using one of his servers, you lose one of your servers");
                            AttsServers --;
                        }

                        else
                        {
                            printf("\nYou hack Verizon with your server but don't broke it");
                        }

                        VerizonAttack = rand() % 3;

                    if (VerizonAttack == 0)
                    {
                        printf("\nVerizon uses the MITM method, you lose 1 server");
                        AttsServers --;
                    }

                    else if (VerizonAttack == 1)
                    {
                        printf("\nVerizon allocates a server to overheat your CPU");
                        DeadServers = rand() % 5;
                        sleepFor(500);

                        if (DeadServers == 0)
                        {
                            printf("\nVerizon wastes his attack, you keep all of your servers");
                        }

                        else if (DeadServers == 1)
                        {
                            printf("\nVerizon kills 1 of your servers");
                            AttsServers --;
                        }

                        else if (DeadServers == 2)
                        {
                            printf("\nVerizon kills 2 of your servers");
                            AttsServers -=2;
                        }

                        else if (DeadServers == 3)
                        {
                            printf("\nVerizon kills 3 of your servers");
                            AttsServers -=3;
                        }

                        else
                        {
                            printf("\nVerizon kills 4 of your servers");
                            AttsServers -=4;
                        }

                        sleepFor(500);

                        ServerLose = rand() % 2;

                        if (ServerLose == 0)
                        {
                            printf("\nBy using one of his servers, Verizon lose one of his servers");
                            VerizonServers --;
                        }

                        else
                        {
                            printf("\nVerizon hacks you with his server but don't broke it");
                        }
                    }

                    else
                    {
                        printf("\nVerizon fixes a server");
                        VerizonServers ++;
                    }

                    printf("\nYou have %d servers and Verizon has %d servers...", AttsServers, VerizonServers);
                }

                else if (strcmp(givenCommand, Fix) == 0)
                {
                    printf("\nYou fix 1 of your servers");
                    AttsServers ++;

                    VerizonAttack = rand() % 3;

                    if (VerizonAttack == 0)
                    {
                        printf("\nVerizon uses the MITM method, you lose 1 server");
                        AttsServers --;
                    }

                    else if (VerizonAttack == 1)
                    {
                        printf("\nVerizon allocates a server to overheat your CPU");
                        DeadServers = rand() % 5;
                        sleepFor(500);

                        if (DeadServers == 0)
                        {
                            printf("\nVerizon wastes his attack, you keep all of your servers");
                        }

                        else if (DeadServers == 1)
                        {
                            printf("\nVerizon kills 1 of your servers");
                            AttsServers --;
                        }

                        else if (DeadServers == 2)
                        {
                            printf("\nVerizon kills 2 of your servers");
                            AttsServers --;
                            AttsServers --;
                        }

                        else if (DeadServers == 3)
                        {
                            printf("\nVerizon kills 3 of your servers");
                            AttsServers --;
                            AttsServers --;
                            AttsServers --;
                        }

                        else
                        {
                            printf("\nVerizon kills 4 of your servers");
                            AttsServers --;
                            AttsServers --;
                            AttsServers --;
                            AttsServers --;
                        }

                        sleepFor(500);

                        ServerLose = rand() % 2;

                        if (ServerLose == 0)
                        {
                            printf("\nBy using one of his servers, Verizon lose one of his servers");
                            VerizonServers --;
                        }

                        else
                        {
                            printf("\nVerizon hacks you with his server but don't broke it");
                        }
                    }

                    else
                    {
                        printf("\nVerizon fixes a server");
                        VerizonServers ++;
                    }

                    printf("\nYou have %d servers and Verizon has %d servers...", AttsServers, VerizonServers);
                }

                else
                {
                    printf("Wrong command! Retry");
                }

                if (AttsServers <= 0)
                {
                    printf("\nYou lose");
                    printf("\nVerizon hits you and kept %d servers", VerizonServers);
                    AttsServers = 20;
                    VerizonServers = 20;
                    inGame = false;
                }
                else if (VerizonServers <= 0)
                {
                    printf("\nYou win!");
                    printf("\nYou hit Verizon, you kept %d servers and ATTS became\nthe biggest company because of you!\n", AttsServers);
                    printf("\nPlease enter your name : ");
                    scanf("%s", Name);
                    printf("%s's Bank Account : 2450$", Name);
                    sleepFor(250);
                    printf("\b\b");
                    sleepFor(250);
                    printf("\b");
                    sleepFor(250);
                    printf("\b");
                    sleepFor(250);
                    printf("\b");
                    sleepFor(250);
                    loading = 0;
                    while(loading <= 15){
                        printf("9");
                        sleepFor(250);
                        loading++;
                    }
                    printf("$");
                    sleepFor(500);
                    printf("\nDear %s,\nTo thank you, we send you a bit of money\nand we promote you Security Team CHIEF!\nCongratulations,\nATTS Inc CEO, Hugues KADI", Name);

                    ranking = fopen("ranking.txt", "a");
                    fprintf(ranking, "\n%s hit Verizon and kept %d servers!", Name, AttsServers);

                    AttsServers = 20;
                    VerizonServers = 20;

                    inGame = false;
                }
            }

                printf("\ncommand RESTART or EXIT : ");
                scanf("%s", givenCommand);

                if (strcmp(givenCommand, Restart) == 0)
                {
                    wrongCommand = 0;
                }

                else if (strcmp(givenCommand, Exit) == 0)
                {
                    printf("The program will stop in few seconds");
                    sleepFor(5000);
                    return 0;
                }

                else
                {
                    printf("Wrong command");
                }


        }

        else if (strcmp(givenCommand, Exit) == 0)
        {
            printf("The program will stop in few seconds");
            sleepFor(5000);
            return 0;
        }

        else
        {
            printf("Wrong command\n");
        }

    }
    return 0;
}
