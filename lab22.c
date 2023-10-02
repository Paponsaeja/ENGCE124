//
//  main.c
//  coding 22
//
//  Created by Papon Saeja on 2/10/2566 BE.
//

#include <stdio.h> //use printf
#ifdef __APPLE__
#include <stdlib.h>
#define getch() getchar()
#elif __linux__
#include <stdlib.h>
#define getch() getchar()
#else
#include <conio.h>
#endif
#include <time.h> //use time
#include <stdbool.h>

#ifdef _WIN32 // Windows-specific header
#include <conio.h>
#endif

#define MaxData 100 // Define Max Data
#define MaxRow 10 //0..9 in Decimal base
#define MaxCol 20 //0..19
int Data[MaxData];
int Radix[MaxRow][MaxCol]; //Radix is temporary tank. The size is[0..MaxRow,0..MaxCol]
int N,N1;


void ClearStackPT(void) //Clear every block=0 and use Radix[0] for SP
{
    int i;
    for(i=0;i<=MaxRow;i++)
        Radix[i][0]=NULL; //This position keep the SP
}

void PrepareRawData(int N2)
{
    int i;
    srand(time(NULL)); //for difference random number in rand()
    for (i=0;i<N2;i++)
        Data[i]=(rand() % 899)+100; //random difference number 100..999
}

void DispData(int N2) //Show Data in array
{
    int i;
    for(i=0;i<N2;i++)
        printf("%3d ",Data[i]);
    printf("\n");
}

void Push(int Rad, int Dat) //Put data into Parallel Stack by keep SPat (Rad,0)
{
    int SP;
    SP=Radix[Rad][0]+1; //Skip SP
    Radix[Rad][0]=SP; //keep new SP
    Radix[Rad][SP]=Dat; //Push data into that Radix
}

void ReadStack(void) //Read data from each Stack and transfer to Data[]
{
    int i,j,k,SP;
    k=0; //Start of Data[] at subscript 0
    for(i=0;i<=MaxRow;i++)
    {
        SP=Radix[i][0]; //Max Count value of each Radix keep at column 0
        for(j=1;j<=SP;j++)
        {
            Data[k]=Radix[i][j]; //Transfer data from every Stack to Data[]
            k++;
        }
    }
}


void RadixSort(int N2)
{
    int Digit,i,RadixNo;
    char Txt[2];
    for(Digit=2;Digit>=0;Digit--) //Count down
    {
        printf("[Digit : %d]==>\n",3-Digit);
        for(i=0;i<N2;i++) //Data[] counter
        {
            itoa(Data[i],Txt,10); //convert Integer to Text [itoa(input,output,base)]
            RadixNo=Txt[Digit]-48; //covert Text that Digit to Number
            Push(RadixNo,Data[i]); //Pust Data to Stack at that Radix
        }
        ReadStack();
        DispData(N2);
        ClearStackPT();
    }
}

int main(void)
{
    printf("ASCENDING RADIX SORT\n");
    printf("=====================================================================\n");
    N=16; //Change amount of N here
    N1=N; //Keep N to N1 Because N is 0 when finished RadixSort()!! I don't understand
    PrepareRawData(N);
    printf("Raw Data...\n");
    DispData(N);
    printf("---------------------------------------------------------------------\n");
    printf("Processing Data...\n");
    RadixSort(N);
    //printf("N= %d\n",N); //Problem point!!
    printf("--------------------------------------------------------------Finished\n");
    printf("Sorted Data : \n");
    DispData(N1); //Sorted Data
    return(0);
}

