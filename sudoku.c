#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int savedNums[9][9];
int i, m, j, k, row, column, blockNum;
int zeroFlag;
int zeroCounter = 0;
int rowSetter, columnSetter;
int dupCounter = 0;
int flag = 0;
int okFlag=0;
int counter;
int x;

void printSud()
{
    for(row = 0; row < 9; row++)
    {
        for(column = 0; column < 9; column++)
        {
            printf(" %d", savedNums[row][column]);
        }
        printf( "\n");
    }
}
int checkF(int printEnable)
{
/*----------------------- Row Check ----------------------- */
    counter = 0;
    zeroCounter = 0;

    for(row = 0; row < 9; row++)
    {
        for(k = 1; k < 10; k++)
        {
            for(column = 0; column < 9; column++)
            {
                if(savedNums[row][column] == k)
                {
                    counter++;
                    break;
                }
            }
        }

        for(m = 0; m < 9; m++)
        {
            if(savedNums[row][m]== 0)
                zeroCounter++;
        }
        if(zeroCounter != 9-counter)
        {
            if(printEnable == 1)
                printf("Invalid row %d\n", row + 1);
            okFlag = 1;
        }
        counter = 0;
        zeroCounter = 0;
    }
/*-------------------- Column Check ----------------------- */
    counter = 0;
    zeroCounter = 0;

    for(column = 0; column < 9; column++)
    {
        for (k = 1; k < 10; k++)
        {
            for(row = 0; row < 9; row++)
            {
                if(savedNums[row][column] == k)
                {
                    counter++;
                    break;
                }
            }
        }

        for(m = 0; m < 9; m++)
        {
            if(savedNums[m][column] == 0)
                zeroCounter++;
        }

        if(zeroCounter != 9-counter)
        {
            if(printEnable == 1)
                printf("Invalid column %d\n", column + 1);
            okFlag = 1;
        }
        counter = 0;
        zeroCounter = 0;
    }
/*------------------- Block Check --------------------- */
    counter = 0;
    zeroCounter = 0;
    rowSetter = 0;
    columnSetter = 0;

    for(blockNum = 1; blockNum < 10; blockNum++)
    {
        for(k = 1; k < 10; k++)
        {
            for(row = rowSetter; row < rowSetter + 3; row++)
            {
                for(column = columnSetter; column < columnSetter + 3; column++)
                {
                    if(savedNums[row][column] == k)
                    {
                        if(flag == 0)
                        {
                            counter++;
                            flag = 1;
                        }
                    }
                }
            }
            flag = 0;
        }
        for(m = rowSetter; m < rowSetter + 3 ; m++)
        {
            for(i = columnSetter; i < columnSetter + 3; i++)
            {
                if(savedNums[m][i] == 0)
                    zeroCounter++;
            }
        }

        if(zeroCounter != 9-counter)
        {
            if(printEnable == 1)
                printf("Invalid block %d\n", blockNum);
            okFlag = 1;
        }
        counter = 0;
        zeroCounter = 0;

        if(blockNum == 3 || blockNum == 6)
            rowSetter += 3;

        if (blockNum == 3 || blockNum == 6)
            columnSetter = 0;
        else
            columnSetter += 3;

    }

/*------------------- Return Algorithm ------------------ */

    if(okFlag == 0 && printEnable == 1)
    {
        printf("OK\n");
        return 1;
    }
    if(okFlag == 0 && printEnable == 0)
    {
        return 1;
    }

    okFlag = 0;
    return 0;
}

int solveSud()
{
    int row2;
    int column2;
    int x;
    zeroFlag = 0;
    for(row2 = 0; row2 < 9; row2++)
    {
        for(column2 = 0; column2 < 9; column2++)
        {
            if(savedNums[row2][column2] == 0)
            {
                zeroFlag = 1;
                break;
            }
        }
        if(zeroFlag == 1)
            break;
    }
    if(zeroFlag == 0)
        {
            return 1;
        }

    for(x = 1; x < 10; x++)
    {
        savedNums[row2][column2] = x;
        if(checkF(0))
        {

            if(solveSud() == 1)
             {
                return 1;
             }
        }
    }
    savedNums[row2][column2] = 0;
    return 0;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
     return 1;

    for(row = 0; row < 9; row++)
    {
        for(column = 0; column < 9; column++)
            scanf("%d", &savedNums[row][column]);
    }
    printf("\n");

/* ---------------- Prwti Leitourgia -check ------------------- */
    if(strcmp(argv[1], "-check") == 0)
    {
        checkF(1);
    }

/* ---------------- Deuteri Leitourgia -solve ----------------- */
    else if(strcmp(argv[1], "-solve") == 0)
    {
        if(checkF(0) == 1)
        {
            if(solveSud() == 1)
            {
                printSud();
            }
            else
                printf("No solution.\n");

        }
        else
            printf("No solution.\n");

        return 0;
    }
    else
        return 1;
}
