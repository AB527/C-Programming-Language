#include <stdio.h>
#include <stdlib.h>

#define MainCalender_Limit_Row 5
#define MainCalender_Limit_Col 7

int MainCalender[MainCalender_Limit_Row][MainCalender_Limit_Col];
int i,j,k;
int Head_Date,Head_Month,Head_Year;
char *Days_of_Week[] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
char *Months_of_Year[] = {"Months_of_Year","January","February","March","April","May",
                          "June","July","August","September","October","November","December"};
int Begin_Date,Begin_Month,Begin_Year;

int main()
{
    Calender_Main(0);
}

int Calender_Main(int ErrorCode_Ex)
{
    int ErrorCode_In = 0;
    char ClickedButton;

    system("cls");

    system("COLOR 1E");

    printf("\n>>> MY CALENDER <<<\n");

    if(ErrorCode_Ex == 1)
        printf("\n(!) As the Input was Invalid , You have have been redirected to the Home Page .\n");

    printf("\nWelcome !!!\n");
    printf("\nNote : \n\n1] This Calender has a range between 1st January 1962 to 31st December 2099 ONLY .\n2] If the Date is Unknown then \'0\' should be Entered as Input when Asked . \n");


     printf("\nEnter the Year <yyyy> : ");
    scanf("%d",&Head_Year);
    printf("Enter the Month <mm> : ");
    scanf("%d",&Head_Month);
    printf("Enter the Date <dd> : ");
    scanf("%d",&Head_Date);

    if(Head_Date == 0)
        Head_Date = 1;

    ErrorCode_In = Validater(Head_Date,Head_Month,Head_Year);

    if(ErrorCode_In == 1)
    {
        Calender_Main(1);
    }
    Begin_Date = Head_Date,Begin_Month = Head_Month,Begin_Year = Head_Year;
    CalenMaker(Head_Date,Head_Month,Head_Year);

    while (1)
    {
        Forward_with_Key();
    }

    return 0;
}

int CalenMaker(int CalenMaker_Date,int CalenMaker_Month,int CalenMaker_Year)
{
    long int No_of_Day_Returned = 0,No_of_Day_Returned_Ex;

    system("cls");

    printf("\n>>> MY CALENDER <<<\n");

    printf("\nNote : This Calender has a range between 1st January 1962 to 31st December 2099 ONLY .\n");

    printf("\nUp Arrow Key : Next Year , Same Month\n");
    printf("Down Arrow Key : Previous Year , Same Month\n");
    printf("Left Arrow Key : Same Year , Next Month\n");
    printf("Right Arrow Key : Same Year , Previous Month\n");
    printf("Home Key : Home Page\n");

    printf("\nBegan : %s %d , %d [%d/%d/%d]\n",Months_of_Year[Begin_Month],Begin_Date,Begin_Year,Begin_Date,Begin_Month,Begin_Year);
    printf("Current : %s %d , %d [%d/%d/%d]]\n",Months_of_Year[Head_Month],Head_Date,Head_Year,Head_Date,Head_Month,Head_Year);

    for(i = 0;i < MainCalender_Limit_Row;i++)
    {
        for(j = 0;j < MainCalender_Limit_Col;j++)
            MainCalender[i][j] = 0;
    }

    for(i = 1962;i < CalenMaker_Year;i++)
    {
        for(j = 1;j <= 12;j++)
        {
            No_of_Day_Returned_Ex = No_of_Day_Returner(i,j);
            No_of_Day_Returned += No_of_Day_Returned_Ex;
        }
    }

    for(i = 1;i < CalenMaker_Month;i++)
    {
        No_of_Day_Returned_Ex = No_of_Day_Returner(CalenMaker_Year,i);
        No_of_Day_Returned += No_of_Day_Returned_Ex;
    }

    DataInserter(No_of_Day_Returned,No_of_Day_Returner(CalenMaker_Year,CalenMaker_Month));

    Designer_1(CalenMaker_Month,CalenMaker_Year);

    for(i = 0;i < 7;i++)
    {
        if(i == 0)
            printf("| |");
        printf("%s\t",Days_of_Week[i]);
        if(i == 0)
                printf("  ");
        if(i == 6)
            printf("| |");
    }

    printf("\n");

    for(i = 0;i < MainCalender_Limit_Row;i++)
    {
        printf("| | ");

        for(j = 0;j < MainCalender_Limit_Col;j++)
        {
            if(MainCalender[i][j] == 0)
            {
                printf("%c\t",MainCalender[i][j]);
            }
            else
            {
                if(MainCalender[i][j] == Head_Date)
                    printf("*");
                printf("%d\t",MainCalender[i][j]);
            }
            if(j == 0)
                printf("  ");
        }

        printf("| |");

        printf("\n");
    }

    Designer_2();
}

int No_of_Day_Returner(int No_of_DayReturner_Year,int No_of_DayReturner_Month)
{
    int No_of_Day = 0;

    if(No_of_DayReturner_Month == 1)
        No_of_Day = 31;
    if(No_of_DayReturner_Month == 2)
            if(No_of_DayReturner_Year % 4 == 0)
                No_of_Day = 29;
            else
                No_of_Day = 28;
    else if(No_of_DayReturner_Month == 3)
        No_of_Day = 31;
    else if(No_of_DayReturner_Month == 4)
        No_of_Day = 30;
    else if(No_of_DayReturner_Month == 5)
        No_of_Day = 31;
    else if(No_of_DayReturner_Month == 6)
        No_of_Day = 30;
    else if(No_of_DayReturner_Month == 7)
        No_of_Day = 31;
    else if(No_of_DayReturner_Month == 8)
        No_of_Day = 31;
    else if(No_of_DayReturner_Month == 9)
        No_of_Day = 30;
    else if(No_of_DayReturner_Month == 10)
        No_of_Day = 31;
    else if(No_of_DayReturner_Month == 11)
        No_of_Day = 30;
    else if(No_of_DayReturner_Month == 12)
        No_of_Day = 31;

    return (No_of_Day);
}

int DataInserter(int DayNum,int NumLimit)
{
    int DaySelector = DayNum % 7;
    int Counter = 1,Checker = 0;

    for(i = 0;i < MainCalender_Limit_Row;i++)
    {
        for(j = DaySelector;j < MainCalender_Limit_Col;j++)
        {
            if(Counter == NumLimit + 1)
            {
                Checker = 1;
                break;
            }
            MainCalender[i][j] = Counter;
            Counter++;
        }
        if(Checker == 1)
        {
            break;
        }
        DaySelector = 0;
    }
}

void Designer_1(int Working_Month,int Working_Year)
{
    for(i = 0;i < 4;i++)
    {
        if(i == 0)
        {
            for(j = 0;j < 59;j++)
            {
                printf("_");
            }
        }
        else if(i == 1)
        {
            for(j = 0;j < 59;j++)
            {
                if(j == 0 || j == 58)
                    printf("|");
                else if(j == 1 || j == 57)
                    printf(" ");
                else
                    printf("_");
            }
        }
        else if(i == 2)
        {
            printf("| |\t\t\t%s %d\t\t\t| |",Months_of_Year[Working_Month],Working_Year);
        }
        else if(i == 3)
        {
            for(j = 0;j < 55;j++)
            {
                if(j == 0 || j == 54)
                    printf("| |");
                else
                    printf(" ");
            }

        }

        printf("\n");
    }
}

void Designer_2()
{
    for(i = 0;i < 4;i++)
    {
        if(i == 0)
        {
            for(j = 0;j < 55;j++)
            {
                if(j == 0 || j == 54)
                    printf("| |");
                else
                    printf("_");
            }

        }
        else if(i == 1)
        {
            for(j = 0;j < 59;j++)
            {
                if(j == 0 || j == 58)
                    printf("|");
                else
                    printf("_");
            }
        }

        printf("\n");
    }
}

int Forward_with_Key()
{
    int key;
    int Ex_Help_1;
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
                case 71:
                    Calender_Main(0);
                    break;
                case 72:
                    if(Head_Year < 2099)
                        Head_Year += 1;
                    CalenMaker(Head_Date,Head_Month,Head_Year);
                    break;
                case 80:
                    if(Head_Year > 1962)
                        Head_Year -= 1;
                    CalenMaker(Head_Date,Head_Month,Head_Year);
                    break;
                case 75:
                    if(Head_Year > 1962)
                    {
                        if(Head_Month == 1)
                        {
                            Head_Month = 12;
                            Head_Year -= 1;
                        }
                        else
                        {
                            Head_Month -= 1;
                        }
                    }
                    else if(Head_Year == 1962)
                    {
                        if(Head_Month < 1)
                        {
                            Head_Month -= 1;
                        }
                    }
                    CalenMaker(Head_Date,Head_Month,Head_Year);
                    break;
                case 77:
                    if(Head_Year < 2099)
                    {
                        if(Head_Month == 12)
                        {
                            Head_Month = 1;
                            Head_Year += 1;
                        }
                        else
                        {
                            Head_Month += 1;
                        }
                    }
                    else if(Head_Year == 2099)
                    {
                        if(Head_Month > 12)
                        {
                            Head_Month += 1;
                        }
                    }
                    CalenMaker(Head_Date,Head_Month,Head_Year);

            }
        }
    }

}

int Validater(int Validate_Date,int Validate_Month,int Validate_Year)
{
    int returner = 1;

    if(Validate_Year > 1961 && Validate_Year < 3000)
    {
        if(Validate_Month > 0 && Validate_Month < 13)
        {
            int returned = No_of_Day_Returner(Validate_Year,Validate_Month);
            if(returned >= Validate_Date && 0 < Validate_Date)
            {
                returner = 0;
                return (returner);
            }
        }
    }

    return (returner);
}
