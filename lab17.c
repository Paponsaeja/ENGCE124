//
//  main.c
//  coding 17
//
//  Created by Papon Saeja on 26/9/2566 BE.
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
#define MaxData 100 // Define Max Data
int Data[MaxData];
int N;

void PrepareRawData(int N)
{
    int i;
    srand(time(NULL)); //for difference random number in rand()
    for (i=1;i<=N;i++)
        Data[i]=1+rand() % 99; //random difference number 1..99
}

void DispData(int N)
{
    int i;
    for(i=1;i<=N;i++)
        printf("%2d   ",Data[i]);
    printf("\n");
}

void InsertionSort(int N)
{
    int i,j,temp;
    printf("---------------------------------------------------------------------\n");
    printf(" i ");
    for(i=1;i<=N;i++)
        printf(" (%2d)",i);
    printf("\n");
    printf("---------------------------------------------------------------------\n");
    printf("%2d.  ",0);
    DispData(N); //Show every step sorting
    for (i=1;i<N;i++) //Count i forward
    {
        if(Data[i+1]<Data[i]) //If next data < previous data
        {
            temp=Data[i+1]; //Keep insert data into temp
            Data[i+1]=NULL;
            j=i; //let counter j loop backward
            while(temp<Data[j]) //loop if temp remain < data[j]
            {
                Data[j+1]=Data[j]; //Skip data forward to next block of array
                Data[j]=NULL;
                printf("%2d.  ",i+1);
                DispData(N); //Show every time sorting
                j=j-1; //count backward of j
                
            } //End whil
            Data[j+1]=temp; //Put temp into Data[j+1] finally
            printf("%2d.  ",i+1);
            DispData(N); //Show every time sorting
        }
    }
}

int main() {
  printf("ASCENDING INSERTION SORT\n");
  printf("==============================\n");
  N=12;
  PrepareRawData(N);
  printf("Raw Data...");
  DispData(N);
  printf("Processing Data...\n");
  InsertionSort(N);
  printf("----------------------------------------------------------------\n");
  printf("Sorted Data : ");
  DispData(N); //Sorted Data
  return(0);
} //End Main
       
        
