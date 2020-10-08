#include <stdio.h>
#include <stdlib.h>

int i,j,k;
int f1,f2;
int v1,v2;
int contract = 0,contact = 0;
char MainArea[3][3];
char Extra,continuer;
int PlayerCode = 1;

void Restarter()
{
    printf("\nPress End to Replay or Press Cancel to Exit . \n");
    CheckKey();
}

void StuckRemover(s1,s2)
int s1,s2;
{
    for(f1 = 0;f1 < 3;f1++)
    {
        for(f2 = 0;f2 < 3;f2++)
        {
            if(MainArea[f1][f2] == 0)
            {
                if(f1 != s1 && f2 != s2)
                {
                    Extra = MainArea[f1][f2];
                    MainArea[f1][f2] = MainArea[s1][s2];
                    MainArea[s1][s2] = Extra;
                    contract = 1;
                    break;
                }
            }
        }
        if(contract == 1)
        {
            contract = 0;
            break;
        }
    }
}
int TieDecider()
{
    for(v1 = 0;v1 < 3;v1++)
    {
        for(v2 = 0;v2 < 3;v2++)
        {
            if(MainArea[v1][v2] != 0 && MainArea[v1][v2] != 42)
            {
                if(v1 == 2 && v2 == 2)
                {
                    if(contact == 0)
                    {
                        system("cls");
                        printf("\nThere is a Tie between Player 1 and Player 2 \n");
                        contact = 0;
                        Restarter();
                    }
                }
                else
                {
                    continue;
                }
            }
            else
            {
                contract = 1;
                break;
            }
        }
        if(contract == 1)
        {
            contract = 0;
            break;
        }
    }
}
void WinnerDecider(WinnerDecider_Ex)
int WinnerDecider_Ex;
{
    if(WinnerDecider_Ex == 1)
    {
        WinnerDecider_Ex++;
    }
    else if(WinnerDecider_Ex == 2)
    {
        WinnerDecider_Ex--;
    }

    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(MainArea[i][j] != 0)
            {
                if(i == 0 && j == 0)
                {
                    if(MainArea[i][j] == MainArea[i][j+1] && MainArea[i][j] == MainArea[i][j+2])
                    {
                        system("cls");
                        printf("\nCongratulation !!! Player %d Won . \n",WinnerDecider_Ex);
                        contact = 1;
                        Restarter();
                    }
                    else if(MainArea[i][j] == MainArea[i+1][j] && MainArea[i][j] == MainArea[i+2][j])
                    {
                        system("cls");
                        printf("\nCongratulation !!! Player %d Won . \n",WinnerDecider_Ex);
                        contact = 1;
                        Restarter();
                    }
                    else if(MainArea[i][j] == MainArea[i+1][j+1] && MainArea[i][j] == MainArea[i+2][j+2])
                    {
                        system("cls");
                        printf("\nCongratulation !!! Player %d Won . \n",WinnerDecider_Ex);
                        contact = 1;
                        Restarter();
                    }
                }
                else if(i == 0 && j == 1)
                {
                    if(MainArea[i][j] == MainArea[i+1][j] && MainArea[i][j] == MainArea[i+2][j])
                    {
                        system("cls");
                        printf("\nCongratulation !!! Player %d Won . \n",WinnerDecider_Ex);
                        contact = 1;
                        Restarter();
                    }
                }
                else if(i == 0 && j == 2)
                {
                    if(MainArea[i][j] == MainArea[i+1][j] && MainArea[i][j] == MainArea[i+2][j])
                    {
                        system("cls");
                        printf("\nCongratulation !!! Player %d Won . \n",WinnerDecider_Ex);
                        contact = 1;
                        Restarter();
                    }
                    else if(MainArea[i][j] == MainArea[i+1][j-1] && MainArea[i][j] == MainArea[i+2][j-2])
                    {
                        system("cls");
                        printf("\nCongratulation !!! Player %d Won . \n",WinnerDecider_Ex);
                        contact = 1;
                        Restarter();
                    }
                }
                else if(i == 1 && j == 0)
                {
                    if(MainArea[i][j] == MainArea[i][j+1] && MainArea[i][j] == MainArea[i][j+2])
                    {
                        system("cls");
                        printf("\nCongratulation !!! Player %d Won . \n",WinnerDecider_Ex);
                        contact = 1;
                        Restarter();
                    }
                }
                else if(i == 2 && j == 0)
                {
                    if(MainArea[i][j] == MainArea[i][j+1] && MainArea[i][j] == MainArea[i][j+2])
                    {
                        system("cls");
                        printf("\nCongratulation !!! Player %d Won . \n",WinnerDecider_Ex);
                        contact = 1;
                        Restarter();
                    }
                }
            }
        }
    }
    TieDecider(contact);
}

void PlaceAssterick()
{
    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(MainArea[i][j] == 0)
            {
                MainArea[i][j] = '*';
                contract = 1;
                break;
            }
        }
        if(contract == 1)
        {
            contract = 0;
            break;
        }
    }
}
void Inserter()
{
    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(MainArea[i][j] == '*')
            {
                if(PlayerCode == 1)
                {
                    MainArea[i][j] = 'X';
                    PlayerCode++;
                    contract = 1;
                    break;
                }
                else if(PlayerCode == 2)
                {
                    MainArea[i][j] = 'O';
                    PlayerCode--;
                    contract = 1;
                    break;
                }
            }
        }
        if(contract == 1)
        {
            contract = 0;
            break;
        }
    }
    TieDecider();
}
void ChangeUP()
{
    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(i != 0)
            {
                if(MainArea[i][j] == '*')
                {
                    if(i == 1)
                    {
                        if(MainArea[i-1][j] == 0)
                        {
                            Extra = MainArea[i][j];
                            MainArea[i][j] = MainArea[i-1][j];
                            MainArea[i-1][j] = Extra;
                            contract = 1;
                            break;
                        }
                        else
                        {
                            StuckRemover(i,j);
                            contract = 1;
                            break;
                        }
                    }
                    else if(i == 2)
                    {
                        if(MainArea[i-1][j] == 0)
                        {
                            Extra = MainArea[i][j];
                            MainArea[i][j] = MainArea[i-1][j];
                            MainArea[i-1][j] = Extra;
                            contract = 1;
                            break;
                        }
                        else if(MainArea[i-2][j] == 0)
                        {
                            Extra = MainArea[i][j];
                            MainArea[i][j] = MainArea[i-2][j];
                            MainArea[i-2][j] = Extra;
                            contract = 1;
                            break;
                        }
                        else
                        {
                            StuckRemover(i,j);
                            contract = 1;
                            break;
                        }
                    }
                }
            }
        }
        if(contract == 1)
        {
            contract = 0;
            break;
        }
    }
}

void ChangeDOWN()
{
    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(i != 2)
            {
                if(MainArea[i][j] == '*')
                {
                    if(i == 1)
                    {
                        if(MainArea[i+1][j] == 0)
                        {
                            Extra = MainArea[i][j];
                            MainArea[i][j] = MainArea[i+1][j];
                            MainArea[i+1][j] = Extra;
                            contract = 1;
                            break;
                        }
                        else
                        {
                            StuckRemover(i,j);
                            contract = 1;
                            break;
                        }
                    }
                    else if(i == 0)
                    {
                        if(MainArea[i+1][j] == 0)
                        {
                            Extra = MainArea[i][j];
                            MainArea[i][j] = MainArea[i+1][j];
                            MainArea[i+1][j] = Extra;
                            contract = 1;
                            break;
                        }
                        else if(MainArea[i+2][j] == 0)
                        {
                            Extra = MainArea[i][j];
                            MainArea[i][j] = MainArea[i+2][j];
                            MainArea[i+2][j] = Extra;
                            contract = 1;
                            break;
                        }
                        else
                        {
                            StuckRemover(i,j);
                            contract = 1;
                            break;
                        }
                    }
                }
            }
        }
        if(contract == 1)
        {
            contract = 0;
            break;
        }
    }
}

void ChangeLEFT()
{
    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(j != 0)
            {
                if(MainArea[i][j] == '*')
                {
                    if(j == 1)
                    {
                        if(MainArea[i][j-1] == 0)
                        {
                            Extra = MainArea[i][j];
                            MainArea[i][j] = MainArea[i][j-1];
                            MainArea[i][j-1] = Extra;
                            contract = 1;
                            break;
                        }
                        else
                        {
                            StuckRemover(i,j);
                            contract = 1;
                            break;
                        }
                    }
                    else if(j == 2)
                    {
                        if(MainArea[i][j-1] == 0)
                        {
                            Extra = MainArea[i][j];
                            MainArea[i][j] = MainArea[i][j-1];
                            MainArea[i][j-1] = Extra;
                            contract = 1;
                            break;
                        }
                        else if(MainArea[i][j-2] == 0)
                        {
                            Extra = MainArea[i][j];
                            MainArea[i][j] = MainArea[i][j-2];
                            MainArea[i][j-2] = Extra;
                            contract = 1;
                            break;
                        }
                        else
                        {
                            StuckRemover(i,j);
                            contract = 1;
                            break;
                        }
                    }
                }
            }
        }
        if(contract == 1)
        {
            contract = 0;
            break;
        }
    }
}

void ChangeRIGHT()
{
    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(j != 2)
            {
                if(MainArea[i][j] == '*')
                {
                    if(j == 1 && MainArea[i][j+1] == 0)
                    {
                        if(MainArea[i][j+1] == 0)
                        {
                            Extra = MainArea[i][j];
                            MainArea[i][j] = MainArea[i][j+1];
                            MainArea[i][j+1] = Extra;
                            contract = 1;
                            break;
                        }
                        else
                        {
                            StuckRemover(i,j);
                            contract = 1;
                            break;
                        }
                    }
                    else if(j == 0)
                    {
                        if(MainArea[i][j+1] == 0)
                        {
                            Extra = MainArea[i][j];
                            MainArea[i][j] = MainArea[i][j+1];
                            MainArea[i][j+1] = Extra;
                            contract = 1;
                            break;
                        }
                        else if(MainArea[i][j+2] == 0)
                        {
                            Extra = MainArea[i][j];
                            MainArea[i][j] = MainArea[i][j+2];
                            MainArea[i][j+2] = Extra;
                            contract = 1;
                            break;
                        }
                        else
                        {
                            StuckRemover(i,j);
                            contract = 1;
                            break;
                        }
                    }
                }
            }
        }
        if(contract == 1)
        {
            contract = 0;
            break;
        }
    }
}


int Maker(m)
int m;
{
    switch (m)
    {
        case 1:
            ChangeUP();
            break;
        case 2:
            ChangeDOWN();
            break;
        case 3:
            ChangeLEFT();
            break;
        case 4:
            ChangeRIGHT();
            break;
        case 5:
            Inserter(PlayerCode);
            PlaceAssterick();
    }

    system("cls");

    printf("\nUP Arrow Key : Move UP \n");
    printf("DOWN Arrow Key : Move DOWN \n");
    printf("LEFT Arrow Key : Move LEFT \n");
    printf("RIGHT Arrow Key : Move RIGHT \n");
    printf("INSERT Key : REPLACE Assterick \n");
    printf("END Key : RESTART \n");

    printf("\nSymbol of Player 1 : X \n");
    printf("Symbol of Player 2 : O \n");

    printf("\nChance of Player %d \n\n\n",PlayerCode);

    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(j == 1 || j == 2)
            {
                printf("|");
            }
            printf("%c\t",MainArea[i][j]);
        }
        printf("\n");
        if(i == 0 || i == 1)
        {
            printf("--------|-------|--------\n");
        }
    }

    WinnerDecider(PlayerCode);
}

void CheckKey(void)
{
    int key;
    if (kbhit())
    {
        key = getch();
        if (key == 224)
        {
            do
            {
                key = getch();
            }
            while(key == 224);
            switch (key)
            {
                case 72:
                    Maker(1);
                    break;
                case 80:
                    Maker(2);
                    break;
                case 75:
                    Maker(3);
                    break;
                case 77:
                    Maker(4);
                    break;
                case 82:
                    Maker(5);
                    break;
                case 79:
                    main();
            }
        }
    }
}

int main()
{
    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            MainArea[i][j] = 0;
        }
    }
    system("cls");

    printf("TIC-TAC-TOE\n\n");
    printf("How To Play : \n\n");
    printf("1) The Asterisk will be a Substitute for just Moving the Symbol of the Player . It is created to stop Confusion . \n");
    printf("2) The Asterisk can be Moved by Arrow Keys . \n");
    printf("3) The Asterisk can be Replaced by Insert Key . Remember ! Once Replaced the Symbol can't change its Position . \n");
    printf("4) The Player who completes the chain First is the WINNER . \n");

   printf("\nARE YOU READY . !!! \n");
   printf("Press ENTER to continue . \n");
   scanf("%c",&continuer);

   if(continuer == 10)
   {
        system("cls");
        PlaceAssterick();

        printf("\nUP Arrow Key : Move UP \n");
        printf("DOWN Arrow Key : Move DOWN \n");
        printf("LEFT Arrow Key : Move LEFT \n");
        printf("RIGHT Arrow Key : Move RIGHT \n");
        printf("INSERT Key : REPLACE Assterick \n");
        printf("END Key : RESTART \n");

        printf("\nSymbol of Player 1 : X \n");
        printf("Symbol of Player 2 : O \n");

        printf("\nChance of Player %d \n\n\n",PlayerCode);

        for(i = 0;i < 3;i++)
        {
            for(j = 0;j < 3;j++)
            {
                if(j == 1 || j == 2)
                {
                    printf("|");
                }
                printf("%c\t",MainArea[i][j]);
            }
            printf("\n");
            if(i == 0 || i == 1)
            {
                printf("--------|-------|--------\n");
            }
        }

        while (1)
        {
            CheckKey();
        }
    }
    return 0;

}
