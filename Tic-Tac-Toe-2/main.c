#include <stdio.h>
#include <stdlib.h>
#include "CompMove.c"

int main()
{
    TicTacToe_Head();
    return 0;
}

char TicTacToe_PlayGround[3][3];
char HTP_PvP_InstructionSet[] = "1) The Asterisk will be a Substitute for just Moving the Symbol of the Player . It is created to stop Confusion . \n2) The Asterisk can be Moved by Arrow Keys . \n3) The Asterisk can be Replaced by Insert Key . Remember ! Once Replaced the Symbol can't change its Position . \n4) The Player who completes the chain First is the WINNER . \n";
char HTP_PvC_InstructionSet[] = "1) The Asterisk will be a Substitute for just Moving the Symbol of the Player . It is created to stop Confusion . \n2) The Asterisk can be Moved by Arrow Keys . \n3) The Asterisk can be Replaced by Insert Key . Remember ! Once Replaced the Symbol can't change its Position . \n4) The Player or Computer whoever completes the chain First is the WINNER . \n";
char Instruction_Set_In[] = "\nUP Arrow Key : Move UP \nDOWN Arrow Key : Move DOWN \nLEFT Arrow Key : Move LEFT \nRIGHT Arrow Key : Move RIGHT \nINSERT Key : REPLACE Assterick \nEND Key : RESTART \n";
char PlayerSymbolShower[] = "\nSymbol of Player 1 : X \nSymbol of Player 2 : O \n";
int PlayerCode = 1;

int TicTacToe_Head()
{
    system("cls");

    printf("TIC-TAC-TOE\n\n");

    int User_ModeChoice;
    PlayerCode = 1;

    printf("1. Player Vs Player \n");
    printf("2. Player Vs Computer \n\n");
    printf("Your Choice : ");
    scanf("%d",&User_ModeChoice);

    if(User_ModeChoice == 1)
        PlayVsPlay_Head();
    else if(User_ModeChoice == 2)
        PlayVsComp_Head();

}

int PlayVsPlay_Head()
{
    int i,j;
    char PortalTransferControl;

    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            TicTacToe_PlayGround[i][j] = 0;
        }
    }

    system("cls");

    printf("TIC-TAC-TOE\n\n");
    printf("How To Play : \n\n");
    printf("%s",HTP_PvP_InstructionSet);
    printf("\nARE YOU READY . !!! \n");
    printf("\nPress B to go Back to Home Screen or Press any other Key to continue . \n\n");

    PortalTransferControl = getche();

    if(PortalTransferControl == 'B' || PortalTransferControl == 'b')
        TicTacToe_Head();
    else
        PlayVsPlay_SubHead();

}

int PlayVsPlay_SubHead()
{
    system("cls");
    PlaceAssterick();
    PlayGround_Printer();
    while(1)
    {
        MoveWithKey_Get(1);
    }
}

int PlayVsComp_Head()
{
    int i,j;
    char PortalTransferControl;
    PlayerCode = 1;

    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            TicTacToe_PlayGround[i][j] = 0;
        }
    }

    system("cls");

    printf("TIC-TAC-TOE\n\n");
    printf("How To Play : \n\n");
    printf("%s",HTP_PvC_InstructionSet);
    printf("\nARE YOU READY . !!! \n");
    printf("\nPress B to go Back to Home Screen or Press any other Key to continue . \n\n");

    PortalTransferControl = getche();

    if(PortalTransferControl == 'B' || PortalTransferControl == 'b')
        TicTacToe_Head();
    else
        PlayVsComp_SubHead();
}

int PlayVsComp_SubHead()
{
    system("cls");
    PlaceAssterick();
    PlayGround_Printer();
    while(1)
    {
        if(PlayerCode == 1)
            MoveWithKey_Get(2);
        else if(PlayerCode == 2)
            ComputerSymbolPlacer();
    }
}

void PlayGround_Printer()
{
    int i,j;

    system("cls");

    printf("TIC-TAC-TOE\n\n");
    printf("%s",Instruction_Set_In);
    printf("%s",PlayerSymbolShower);

    printf("\nChance of Player %d \n\n\n",PlayerCode);

    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(j == 1 || j == 2)
            {
                printf("|");
            }
            printf("%c\t",TicTacToe_PlayGround[i][j]);
        }
        printf("\n");
        if(i == 0 || i == 1)
        {
            printf("--------|-------|--------\n");
        }
    }
}

void MoveWithKey_Get(int GameMode)
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
                    MoveWithKey_Post(1,GameMode);
                    break;
                case 80:
                    MoveWithKey_Post(2,GameMode);
                    break;
                case 75:
                    MoveWithKey_Post(3,GameMode);
                    break;
                case 77:
                    MoveWithKey_Post(4,GameMode);
                    break;
                case 82:
                    MoveWithKey_Post(5,GameMode);
                    break;
                case 79:
                    TicTacToe_Head();
            }
        }
    }
}

void MoveWithKey_Post(int KeyMode,int GameMode)
{
    switch(KeyMode)
    {
        case 1:
            MoveUP();
            break;
        case 2:
            MoveDOWN();
            break;
        case 3:
            MoveLEFT();
            break;
        case 4:
            MoveRIGHT();
            break;
        case 5:
            SymbolInserter();
            FinisherTest();
            if(GameMode == 1)
                PlaceAssterick();
    }

    PlayGround_Printer();
}

void MoveUP()
{
    char Extra;
    int TestResult = 0,i,j;

    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(i != 0)
            {
                if(TicTacToe_PlayGround[i][j] == '*')
                {
                    if(i == 1)
                    {
                        if(TicTacToe_PlayGround[i-1][j] == 0)
                        {
                            Extra = TicTacToe_PlayGround[i][j];
                            TicTacToe_PlayGround[i][j] = TicTacToe_PlayGround[i-1][j];
                            TicTacToe_PlayGround[i-1][j] = Extra;
                            TestResult = 1;
                            break;
                        }
                        else
                        {
                            StuckRemover(i,j);
                            TestResult = 1;
                            break;
                        }
                    }
                    else if(i == 2)
                    {
                        if(TicTacToe_PlayGround[i-1][j] == 0)
                        {
                            Extra = TicTacToe_PlayGround[i][j];
                            TicTacToe_PlayGround[i][j] = TicTacToe_PlayGround[i-1][j];
                            TicTacToe_PlayGround[i-1][j] = Extra;
                            TestResult = 1;
                            break;
                        }
                        else if(TicTacToe_PlayGround[i-2][j] == 0)
                        {
                            Extra = TicTacToe_PlayGround[i][j];
                            TicTacToe_PlayGround[i][j] = TicTacToe_PlayGround[i-2][j];
                            TicTacToe_PlayGround[i-2][j] = Extra;
                            TestResult = 1;
                            break;
                        }
                        else
                        {
                            StuckRemover(i,j);
                            TestResult = 1;
                            break;
                        }
                    }
                }
            }
        }
        if(TestResult == 1)
        {
            TestResult = 0;
            break;
        }
    }
}

void MoveDOWN()
{
    char Extra;
    int TestResult = 0,i,j;
    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(i != 2)
            {
                if(TicTacToe_PlayGround[i][j] == '*')
                {
                    if(i == 1)
                    {
                        if(TicTacToe_PlayGround[i+1][j] == 0)
                        {
                            Extra = TicTacToe_PlayGround[i][j];
                            TicTacToe_PlayGround[i][j] = TicTacToe_PlayGround[i+1][j];
                            TicTacToe_PlayGround[i+1][j] = Extra;
                            TestResult = 1;
                            break;
                        }
                        else
                        {
                            StuckRemover(i,j);
                            TestResult = 1;
                            break;
                        }
                    }
                    else if(i == 0)
                    {
                        if(TicTacToe_PlayGround[i+1][j] == 0)
                        {
                            Extra = TicTacToe_PlayGround[i][j];
                            TicTacToe_PlayGround[i][j] = TicTacToe_PlayGround[i+1][j];
                            TicTacToe_PlayGround[i+1][j] = Extra;
                            TestResult = 1;
                            break;
                        }
                        else if(TicTacToe_PlayGround[i+2][j] == 0)
                        {
                            Extra = TicTacToe_PlayGround[i][j];
                            TicTacToe_PlayGround[i][j] = TicTacToe_PlayGround[i+2][j];
                            TicTacToe_PlayGround[i+2][j] = Extra;
                            TestResult = 1;
                            break;
                        }
                        else
                        {
                            StuckRemover(i,j);
                            TestResult = 1;
                            break;
                        }
                    }
                }
            }
        }
        if(TestResult == 1)
        {
            TestResult = 0;
            break;
        }
    }
}

void MoveLEFT()
{
    char Extra;
    int TestResult = 0,i,j;

    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(j != 0)
            {
                if(TicTacToe_PlayGround[i][j] == '*')
                {
                    if(j == 1)
                    {
                        if(TicTacToe_PlayGround[i][j-1] == 0)
                        {
                            Extra = TicTacToe_PlayGround[i][j];
                            TicTacToe_PlayGround[i][j] = TicTacToe_PlayGround[i][j-1];
                            TicTacToe_PlayGround[i][j-1] = Extra;
                            TestResult = 1;
                            break;
                        }
                        else
                        {
                            StuckRemover(i,j);
                            TestResult = 1;
                            break;
                        }
                    }
                    else if(j == 2)
                    {
                        if(TicTacToe_PlayGround[i][j-1] == 0)
                        {
                            Extra = TicTacToe_PlayGround[i][j];
                            TicTacToe_PlayGround[i][j] = TicTacToe_PlayGround[i][j-1];
                            TicTacToe_PlayGround[i][j-1] = Extra;
                            TestResult = 1;
                            break;
                        }
                        else if(TicTacToe_PlayGround[i][j-2] == 0)
                        {
                            Extra = TicTacToe_PlayGround[i][j];
                            TicTacToe_PlayGround[i][j] = TicTacToe_PlayGround[i][j-2];
                            TicTacToe_PlayGround[i][j-2] = Extra;
                            TestResult = 1;
                            break;
                        }
                        else
                        {
                            StuckRemover(i,j);
                            TestResult = 1;
                            break;
                        }
                    }
                }
            }
        }
        if(TestResult == 1)
        {
            TestResult = 0;
            break;
        }
    }
}

void MoveRIGHT()
{
    char Extra;
    int TestResult = 0,i,j;

    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(j != 2)
            {
                if(TicTacToe_PlayGround[i][j] == '*')
                {
                    if(j == 1 && TicTacToe_PlayGround[i][j+1] == 0)
                    {
                        if(TicTacToe_PlayGround[i][j+1] == 0)
                        {
                            Extra = TicTacToe_PlayGround[i][j];
                            TicTacToe_PlayGround[i][j] = TicTacToe_PlayGround[i][j+1];
                            TicTacToe_PlayGround[i][j+1] = Extra;
                            TestResult = 1;
                            break;
                        }
                        else
                        {
                            StuckRemover(i,j);
                            TestResult = 1;
                            break;
                        }
                    }
                    else if(j == 0)
                    {
                        if(TicTacToe_PlayGround[i][j+1] == 0)
                        {
                            Extra = TicTacToe_PlayGround[i][j];
                            TicTacToe_PlayGround[i][j] = TicTacToe_PlayGround[i][j+1];
                            TicTacToe_PlayGround[i][j+1] = Extra;
                            TestResult = 1;
                            break;
                        }
                        else if(TicTacToe_PlayGround[i][j+2] == 0)
                        {
                            Extra = TicTacToe_PlayGround[i][j];
                            TicTacToe_PlayGround[i][j] = TicTacToe_PlayGround[i][j+2];
                            TicTacToe_PlayGround[i][j+2] = Extra;
                            TestResult = 1;
                            break;
                        }
                        else
                        {
                            StuckRemover(i,j);
                            TestResult = 1;
                            break;
                        }
                    }
                }
            }
        }
        if(TestResult == 1)
        {
            TestResult = 0;
            break;
        }
    }
}

void SymbolInserter()
{
    char Extra;
    int TestResult = 0,i,j;

    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(TicTacToe_PlayGround[i][j] == '*')
            {
                if(PlayerCode == 1)
                {
                    TicTacToe_PlayGround[i][j] = 'X';
                    PlayerCode++;
                    TestResult = 1;
                    break;
                }
                else if(PlayerCode == 2)
                {
                    TicTacToe_PlayGround[i][j] = 'O';
                    PlayerCode--;
                    TestResult = 1;
                    break;
                }
            }
        }
        if(TestResult == 1)
        {
            TestResult = 0;
            break;
        }
    }
}

void StuckRemover(s1,s2)
int s1,s2;
{
    int i,j,TestResult = 0;
    char Extra;

    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(TicTacToe_PlayGround[i][j] == 0)
            {
                if(i != s1 && j != s2)
                {
                    Extra = TicTacToe_PlayGround[i][j];
                    TicTacToe_PlayGround[i][j] = TicTacToe_PlayGround[s1][s2];
                    TicTacToe_PlayGround[s1][s2] = Extra;
                    TestResult = 1;
                    break;
                }
            }
        }
        if(TestResult == 1)
        {
            TestResult = 0;
            break;
        }
    }
}

void PlaceAssterick()
{
    int i,j,TestResult = 0;

    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(TicTacToe_PlayGround[i][j] == 0)
            {
                TicTacToe_PlayGround[i][j] = '*';
                TestResult = 1;
                break;
            }
        }
        if(TestResult == 1)
        {
            TestResult = 0;
            break;
        }
    }
}

int FinisherTest()
{
    WinnerDecider(PlayerCode);
    TieDecider();
}

void WinnerDecider(int WinnerDecider_Ex)
{
    int i,j;

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
            if(TicTacToe_PlayGround[i][j] != 0)
            {
                if(i == 0 && j == 0)
                {
                    if(TicTacToe_PlayGround[i][j] == TicTacToe_PlayGround[i][j+1] && TicTacToe_PlayGround[i][j] == TicTacToe_PlayGround[i][j+2])
                    {
                        system("cls");
                        printf("\nCongratulation !!! Player %d Won . \n",WinnerDecider_Ex);
                        Restarter();
                    }
                    else if(TicTacToe_PlayGround[i][j] == TicTacToe_PlayGround[i+1][j] && TicTacToe_PlayGround[i][j] == TicTacToe_PlayGround[i+2][j])
                    {
                        system("cls");
                        printf("\nCongratulation !!! Player %d Won . \n",WinnerDecider_Ex);
                        Restarter();
                    }
                    else if(TicTacToe_PlayGround[i][j] == TicTacToe_PlayGround[i+1][j+1] && TicTacToe_PlayGround[i][j] == TicTacToe_PlayGround[i+2][j+2])
                    {
                        system("cls");
                        printf("\nCongratulation !!! Player %d Won . \n",WinnerDecider_Ex);
                        Restarter();
                    }
                }
                else if(i == 0 && j == 1)
                {
                    if(TicTacToe_PlayGround[i][j] == TicTacToe_PlayGround[i+1][j] && TicTacToe_PlayGround[i][j] == TicTacToe_PlayGround[i+2][j])
                    {
                        system("cls");
                        printf("\nCongratulation !!! Player %d Won . \n",WinnerDecider_Ex);
                        Restarter();
                    }
                }
                else if(i == 0 && j == 2)
                {
                    if(TicTacToe_PlayGround[i][j] == TicTacToe_PlayGround[i+1][j] && TicTacToe_PlayGround[i][j] == TicTacToe_PlayGround[i+2][j])
                    {
                        system("cls");
                        printf("\nCongratulation !!! Player %d Won . \n",WinnerDecider_Ex);
                        Restarter();
                    }
                    else if(TicTacToe_PlayGround[i][j] == TicTacToe_PlayGround[i+1][j-1] && TicTacToe_PlayGround[i][j] == TicTacToe_PlayGround[i+2][j-2])
                    {
                        system("cls");
                        printf("\nCongratulation !!! Player %d Won . \n",WinnerDecider_Ex);
                        Restarter();
                    }
                }
                else if(i == 1 && j == 0)
                {
                    if(TicTacToe_PlayGround[i][j] == TicTacToe_PlayGround[i][j+1] && TicTacToe_PlayGround[i][j] == TicTacToe_PlayGround[i][j+2])
                    {
                        system("cls");
                        printf("\nCongratulation !!! Player %d Won . \n",WinnerDecider_Ex);
                        Restarter();
                    }
                }
                else if(i == 2 && j == 0)
                {
                    if(TicTacToe_PlayGround[i][j] == TicTacToe_PlayGround[i][j+1] && TicTacToe_PlayGround[i][j] == TicTacToe_PlayGround[i][j+2])
                    {
                        system("cls");
                        printf("\nCongratulation !!! Player %d Won . \n",WinnerDecider_Ex);
                        Restarter();
                    }
                }
            }
        }
    }
}

int TieDecider()
{
    int i,j,TestResult = 0;

    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
            if(TicTacToe_PlayGround[i][j] != 0 && TicTacToe_PlayGround[i][j] != 42)
            {
                if(i == 2 && j == 2)
                {
                    system("cls");
                    printf("\nThere is a Tie between Player 1 and Player 2 \n");
                    Restarter();
                }
                else
                    continue;
            }
            else
            {
                TestResult = 1;
                break;
            }
        }
        if(TestResult == 1)
        {
            TestResult = 0;
            break;
        }
    }
}

void Restarter()
{
    printf("\nPress \'R\' to Replay or Press any Key to Exit . \n");

    char PortalTransferControl = getche();

    if(PortalTransferControl == 'R' || PortalTransferControl == 'r')
        PlayVsPlay_SubHead();
    else
        TicTacToe_Head();
}

int ComputerSymbolPlacer()
{
    int TestResult = 0,i,j;

    TestResult = CompMove_Decider();

    if(TestResult == 1)
    {
        i = 0;
        j = 0;
    }
    else  if(TestResult == 2)
    {
        i = 0;
        j = 1;
    }
    else  if(TestResult == 3)
    {
        i = 0;
        j = 2;
    }
    else  if(TestResult == 4)
    {
        i = 1;
        j = 0;
    }
    else  if(TestResult == 5)
    {
        i = 1;
        j = 1;
    }
    else  if(TestResult == 6)
    {
        i = 1;
        j = 2;
    }
    else  if(TestResult == 7)
    {
        i = 2;
        j = 0;
    }
    else  if(TestResult == 8)
    {
        i = 2;
        j = 1;
    }
    else if(TestResult == 9)
    {
        i = 2;
        j = 2;
    }

    TicTacToe_PlayGround[i][j] = '*';

    SymbolInserter();

    FinisherTest();
    PlaceAssterick();
    PlayGround_Printer();
}

int CompMove_Decider()
{
    // Hor Line 1
    if(TicTacToe_PlayGround[0][0] == TicTacToe_PlayGround[0][1] && TicTacToe_PlayGround[0][2] == 0)
        return (3);
    else if(TicTacToe_PlayGround[0][0] == TicTacToe_PlayGround[0][2] && TicTacToe_PlayGround[0][1] == 0)
        return (2);
    else if(TicTacToe_PlayGround[0][1] == TicTacToe_PlayGround[0][2] && TicTacToe_PlayGround[0][0] == 0)
        return (1);
    // Hor Line 2
    else if(TicTacToe_PlayGround[1][0] == TicTacToe_PlayGround[1][1] && TicTacToe_PlayGround[1][2] == 0)
        return (6);
    else if(TicTacToe_PlayGround[1][0] == TicTacToe_PlayGround[1][2] && TicTacToe_PlayGround[1][1] == 0)
        return (5);
    else if(TicTacToe_PlayGround[1][1] == TicTacToe_PlayGround[1][2] && TicTacToe_PlayGround[1][0] == 0)
        return (4);
    // Hor Line 3
    else if(TicTacToe_PlayGround[2][0] == TicTacToe_PlayGround[2][1] && TicTacToe_PlayGround[2][2] == 0)
        return (9);
    else if(TicTacToe_PlayGround[2][0] == TicTacToe_PlayGround[2][2] && TicTacToe_PlayGround[2][1] == 0)
        return (8);
    else if(TicTacToe_PlayGround[2][1] == TicTacToe_PlayGround[2][2] && TicTacToe_PlayGround[2][0] == 0)
        return (7);
    // Ver Line 1
    else if(TicTacToe_PlayGround[0][0] == TicTacToe_PlayGround[1][0] && TicTacToe_PlayGround[2][0] == 0)
        return (7);
    else if(TicTacToe_PlayGround[0][0] == TicTacToe_PlayGround[2][0] && TicTacToe_PlayGround[1][0] == 0)
        return (4);
    else if(TicTacToe_PlayGround[1][0] == TicTacToe_PlayGround[2][0] && TicTacToe_PlayGround[0][0] == 0)
        return (1);
    // Ver Line 2
    else if(TicTacToe_PlayGround[0][1] == TicTacToe_PlayGround[1][1] && TicTacToe_PlayGround[2][1] == 0)
        return (8);
    else if(TicTacToe_PlayGround[0][1] == TicTacToe_PlayGround[2][1] && TicTacToe_PlayGround[1][1] == 0)
        return (5);
    else if(TicTacToe_PlayGround[1][1] == TicTacToe_PlayGround[2][1] && TicTacToe_PlayGround[0][1] == 0)
        return (2);
    // Ver Line 3
    else if(TicTacToe_PlayGround[0][2] == TicTacToe_PlayGround[1][2] && TicTacToe_PlayGround[2][2] == 0)
        return (9);
    else if(TicTacToe_PlayGround[0][2] == TicTacToe_PlayGround[2][2] && TicTacToe_PlayGround[1][2] == 0)
        return (6);
    else if(TicTacToe_PlayGround[1][2] == TicTacToe_PlayGround[2][2] && TicTacToe_PlayGround[0][2] == 0)
        return (3);
    // Slant Line 1
    else if(TicTacToe_PlayGround[0][0] == TicTacToe_PlayGround[1][1] && TicTacToe_PlayGround[2][2] == 0)
        return (9);
    else if(TicTacToe_PlayGround[0][0] == TicTacToe_PlayGround[2][2] && TicTacToe_PlayGround[1][1] == 0)
        return (5);
    else if(TicTacToe_PlayGround[1][1] == TicTacToe_PlayGround[2][2] && TicTacToe_PlayGround[0][0] == 0)
        return (1);
    // Slant Line 2
    else if(TicTacToe_PlayGround[0][2] == TicTacToe_PlayGround[1][1] && TicTacToe_PlayGround[2][1] == 0)
        return (7);
    else if(TicTacToe_PlayGround[0][2] == TicTacToe_PlayGround[2][1] && TicTacToe_PlayGround[1][1] == 0)
        return (5);
    else if(TicTacToe_PlayGround[1][1] == TicTacToe_PlayGround[2][1] && TicTacToe_PlayGround[0][2] == 0)
        return (3);
    // All Corner
    else if(TicTacToe_PlayGround[0][0] == 0)
        return (1);
    else if(TicTacToe_PlayGround[0][2] == 0)
        return (3);
    else if(TicTacToe_PlayGround[2][0] == 0)
        return (7);
    else if(TicTacToe_PlayGround[2][2] == 0)
        return (9);
    // Center
    else if(TicTacToe_PlayGround[1][1] == 0)
        return (5);
    // Other Parts
    else if(TicTacToe_PlayGround[0][1] == 0)
        return (2);
    else if(TicTacToe_PlayGround[1][0] == 0)
        return (4);
    else if(TicTacToe_PlayGround[1][2] == 0)
        return (6);
    else if(TicTacToe_PlayGround[2][1] == 0)
        return (8);
}

/*
int ResultDeclarer(int GameMode,int)
{

}
*/

