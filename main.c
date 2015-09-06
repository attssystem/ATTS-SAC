#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX 1000

int main()
{
    char loading = 0;
    char wrongCommand = 0;
    char win = 0;
    char inGame = 0;
    char AttsServers = 20;
    char VerizonServers = 20;
    int VerizonAttack = 0;
    int DeadServers = 0;
    int ServerLose = 0;
    char password[] = "Play";
    char givenPassword[10];
    char ID[50];
    char IDAdmin[] = "Root";
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
    _sleep(1000);

    loading = 0;

    while (loading < 10)
    {
        printf("|");
        _sleep(100);
        printf("\b");
        printf("/");
        _sleep(100);
        printf("\b");
        printf("-");
        _sleep(100);
        printf("\b");
        printf("|");
        _sleep(100);
        printf("\b");
        printf("/");
        _sleep(100);
        printf("\b");
        printf("-");
        _sleep(100);
        printf("\b");
        printf("|");
        _sleep(100);
        printf("\b");
        loading ++;
    }

    printf("\nConnection established\n");
    _sleep(500);
    printf("Please enter your ID\n");
    printf("ID : ");
    scanf("%s", ID);
    _sleep(500);

    if (strcmp(ID, IDAdmin) == 0)
    {
        printf("Hi Admin, please enter your password");
    }

    else
    {
        printf("\nWrong ID. You will be rejected by the server in 5 seconds");
        _sleep(5000);
        return 0;
    }

    printf("\nPassword : ");
    scanf("%s", givenPassword);

    loading = 0;

    while (loading < 5)
    {
        printf("|");
        _sleep(100);
        printf("\b");
        printf("/");
        _sleep(100);
        printf("\b");
        printf("-");
        _sleep(100);
        printf("\b");
        printf("|");
        _sleep(100);
        printf("\b");
        printf("/");
        _sleep(100);
        printf("\b");
        printf("-");
        _sleep(100);
        printf("\b");
        printf("|");
        _sleep(100);
        printf("\b");
        loading ++;
    }

    printf("\b");

    if (strcmp(givenPassword, password) == 0)
    {
        printf("Access Granted\n");

        loading = 0;

        while (loading < 5)
        {
            printf("|");
            _sleep(100);
            printf("\b");
            printf("/");
            _sleep(100);
            printf("\b");
            printf("-");
            _sleep(100);
            printf("\b");
            printf("|");
            _sleep(100);
            printf("\b");
            printf("/");
            _sleep(100);
            printf("\b");
            printf("-");
            _sleep(100);
            printf("\b");
            printf("|");
            _sleep(100);
            printf("\b");
            loading ++;
        }

    printf("\b");
    }

    else
    {
        printf("Wrong password. You will be rejected by the server in 5 seconds");
        _sleep(5000);
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
            printf("|");
            _sleep(100);
            printf("\b");
            printf("/");
            _sleep(100);
            printf("\b");
            printf("-");
            _sleep(100);
            printf("\b");
            printf("|");
            _sleep(100);
            printf("\b");
            printf("/");
            _sleep(100);
            printf("\b");
            printf("-");
            _sleep(100);
            printf("\b");
            printf("|");
            _sleep(100);
            printf("\b");
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
                    _sleep(500);
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
                    _sleep(5000);
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
                _sleep(5000);
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
                    _sleep(500);
                }

                printf("\nWhen you red everything you can type RESTART or EXIT");
                printf("\ncommand :");
                scanf("%s", givenCommand);

                if (strcmp(givenCommand, Restart) == 0)
                {
                    wrongCommand = 0;
                }

                else if (strcmp(givenCommand, Exit) == 0)
                {
                    printf("The program will stop in few seconds");
                    _sleep(5000);
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
                _sleep(5000);
            }
        }

        else if (strcmp(givenCommand, Continue) == 0)
        {
            printf("Welcome in the Servers Administration Center SAC\nComponents are loading");

            loading = 0;

            while (loading < 10)
            {
                printf("|");
                _sleep(100);
                printf("\b");
                printf("/");
                _sleep(100);
                printf("\b");
                printf("-");
                _sleep(100);
                printf("\b");
                printf("|");
                _sleep(100);
                printf("\b");
                printf("/");
                _sleep(100);
                printf("\b");
                printf("-");
                _sleep(100);
                printf("\b");
                printf("|");
                _sleep(100);
                printf("\b");
                loading ++;
            }

            printf("\b");

            printf("\nComponents are ready to use\nVerizon is trying to hack your servers but you knew that was planned today!\nIt is your turn!");
            while (inGame != 1)
            {
                printf("\ncommand : ");
                scanf("%s", givenCommand);

                loading = 0;

                while (loading < 2)
                {
                    printf("|");
                    _sleep(100);
                    printf("\b");
                    printf("/");
                    _sleep(100);
                    printf("\b");
                    printf("-");
                    _sleep(100);
                    printf("\b");
                    printf("|");
                    _sleep(100);
                    printf("\b");
                    printf("/");
                    _sleep(100);
                    printf("\b");
                    printf("-");
                    _sleep(100);
                    printf("\b");
                    printf("|");
                    _sleep(100);
                    printf("\b");
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
                        printf("|");
                        _sleep(100);
                        printf("\b");
                        printf("/");
                        _sleep(100);
                        printf("\b");
                        printf("-");
                        _sleep(100);
                        printf("\b");
                        printf("|");
                        _sleep(100);
                        printf("\b");
                        printf("/");
                        _sleep(100);
                        printf("\b");
                        printf("-");
                        _sleep(100);
                        printf("\b");
                        printf("|");
                        _sleep(100);
                        printf("\b");
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
                        _sleep(500);

                        if (DeadServers == 0)
                        {
                            printf("\nVerizon wastes his attack, you keep all of your servers");
                        }

                        else if (DeadServers == 1)
                        {
                            printf("\nVerizon kill 1 of your servers");
                            AttsServers --;
                        }

                        else if (DeadServers == 2)
                        {
                            printf("\nVerizon kill 2 of your servers");
                            AttsServers --;
                            AttsServers --;
                        }

                        else if (DeadServers == 3)
                        {
                            printf("\nVerizon kill 3 of your servers");
                            AttsServers --;
                            AttsServers --;
                            AttsServers --;
                        }

                        else
                        {
                            printf("\nVerizon kill 4 of your servers");
                            AttsServers --;
                            AttsServers --;
                            AttsServers --;
                            AttsServers --;
                        }

                        _sleep(500);

                        ServerLose = rand() % 2;

                        if (ServerLose == 0)
                        {
                            printf("\nBy using one of his servers, Verizon lose one of his servers");
                            VerizonServers --;
                        }

                        else
                        {
                            printf("\nVerizon hack you with his server but don't broke it");
                        }
                    }

                    else
                    {
                        printf("\nVerizon fix a server");
                        VerizonServers ++;
                    }

                    printf("\nYou have %d servers and Verizon has %d servers...", AttsServers, VerizonServers);
                }

                else if (strcmp(givenCommand, OverCPU) == 0)
                {
                        printf("\nYou allocate a server to overheat their CPU");
                        DeadServers = rand() % 5;
                        _sleep(500);

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
                            VerizonServers --;
                            VerizonServers --;
                        }

                        else if (DeadServers == 3)
                        {
                            printf("\nYou kill 3 of their servers");
                            VerizonServers --;
                            VerizonServers --;
                            VerizonServers --;
                        }

                        else
                        {
                            printf("\nYou kill 4 of their servers");
                            VerizonServers --;
                            VerizonServers --;
                            VerizonServers --;
                            VerizonServers --;
                        }

                        _sleep(500);

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
                        _sleep(500);

                        if (DeadServers == 0)
                        {
                            printf("\nVerizon wastes his attack, you keep all of your servers");
                        }

                        else if (DeadServers == 1)
                        {
                            printf("\nVerizon kill 1 of your servers");
                            AttsServers --;
                        }

                        else if (DeadServers == 2)
                        {
                            printf("\nVerizon kill 2 of your servers");
                            AttsServers --;
                            AttsServers --;
                        }

                        else if (DeadServers == 3)
                        {
                            printf("\nVerizon kill 3 of your servers");
                            AttsServers --;
                            AttsServers --;
                            AttsServers --;
                        }

                        else
                        {
                            printf("\nVerizon kill 4 of your servers");
                            AttsServers --;
                            AttsServers --;
                            AttsServers --;
                            AttsServers --;
                        }

                        _sleep(500);

                        ServerLose = rand() % 2;

                        if (ServerLose == 0)
                        {
                            printf("\nBy using one of his servers, Verizon lose one of his servers");
                            VerizonServers --;
                        }

                        else
                        {
                            printf("\nVerizon hack you with his server but don't broke it");
                        }
                    }

                    else
                    {
                        printf("\nVerizon fix a server");
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
                        _sleep(500);

                        if (DeadServers == 0)
                        {
                            printf("\nVerizon wastes his attack, you keep all of your servers");
                        }

                        else if (DeadServers == 1)
                        {
                            printf("\nVerizon kill 1 of your servers");
                            AttsServers --;
                        }

                        else if (DeadServers == 2)
                        {
                            printf("\nVerizon kill 2 of your servers");
                            AttsServers --;
                            AttsServers --;
                        }

                        else if (DeadServers == 3)
                        {
                            printf("\nVerizon kill 3 of your servers");
                            AttsServers --;
                            AttsServers --;
                            AttsServers --;
                        }

                        else
                        {
                            printf("\nVerizon kill 4 of your servers");
                            AttsServers --;
                            AttsServers --;
                            AttsServers --;
                            AttsServers --;
                        }

                        _sleep(500);

                        ServerLose = rand() % 2;

                        if (ServerLose == 0)
                        {
                            printf("\nBy using one of his servers, Verizon lose one of his servers");
                            VerizonServers --;
                        }

                        else
                        {
                            printf("\nVerizon hack you with his server but don't broke it");
                        }
                    }

                    else
                    {
                        printf("\nVerizon fix a server");
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
                    printf("\You lose");
                    printf("\nVerizon hits you and kept %d servers", VerizonServers);
                    AttsServers = 20;
                    VerizonServers = 20;
                    inGame = 1;
                }
                else if (VerizonServers <= 0)
                {
                    printf("\nYou win!");
                    printf("\nYou hit Verizon, you kept %d servers and ATTS became\nthe biggest company because of you!\n", AttsServers);
                    printf("\nPlease enter your name : ");
                    scanf("%s", Name);
                    printf("%s's Bank Account : 2450$", Name);
                    _sleep(250);
                    printf("\b\b");
                    _sleep(250);
                    printf("\b");
                    _sleep(250);
                    printf("\b");
                    _sleep(250);
                    printf("\b");
                    _sleep(250);
                    printf("9");
                    _sleep(250);
                    printf("9");
                    _sleep(250);
                    printf("9");
                    _sleep(250);
                    printf("9");
                    _sleep(250);
                    printf("9");
                    _sleep(250);
                    printf("9");
                    _sleep(250);
                    printf("9");
                    _sleep(250);
                    printf("9");
                    _sleep(250);
                    printf("9");
                    _sleep(250);
                    printf("9");
                    _sleep(250);
                    printf("9");
                    _sleep(250);
                    printf("9");
                    _sleep(250);
                    printf("9");
                    _sleep(250);
                    printf("9");
                    _sleep(250);
                    printf("9");
                    _sleep(250);
                    printf("$");
                    _sleep(500);
                    printf("\nDear %s,\nto thanks you we send you a bit of money\nand we promote you Security Team CHIEF!\nCongratulations,\nATTS Inc CEO, Hugues KADI");

                    ranking = fopen("ranking.txt", "a");
                    fprintf(ranking, "\n%s hit Verizon and kept %d servers!", Name, AttsServers);

                    AttsServers = 20;
                    VerizonServers = 20;

                    inGame = 1;
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
                    _sleep(5000);
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
            _sleep(5000);
            return 0;
        }

        else
        {
            printf("Wrong command\n");
        }

    }
    return 0;
}
