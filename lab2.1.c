#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void DecToBin(unsigned int data2, int byt)
{
    int count, chk, bits;
    bits = (byt * 8) - 1;
    for (count = bits; count >= 0; count--)
    {
        chk = data2 >> count;   // data right shift count
        if (chk & 1)
            printf("1");
        else
            printf("0");
        
        if (count % 4 == 0 && count > 3)
            printf(" ");
    }
    printf("B\n");
}

void UnsignedShortInt(void)
{
    unsigned short int data;
    printf("\nUNSIGNED SHORT INTEGER MODE [0 to 65,535]\n");
    printf("===========================================\n");
    printf("Enter Raw Data : ");
    scanf("%hu", &data);
    printf("Data in Decimal = %huD\n", data);      // %hu for unsigned short int
    printf("Data in Hexadecimal = %xH\n", data);
    printf("Data in Binary = ");
    DecToBin(data, sizeof(data));
    printf("Size = %zu Bytes\n", sizeof(data));
}

void UnsignedInt(void)
{
    unsigned int data;
    printf("\nUNSIGNED INTEGER MODE [0 to 4,294,967,295]\n");
    printf("============================================\n");
    printf("Enter Raw Data :");
    scanf("%u", &data);
    printf("Data in Decimal = %uD\n", data);
    printf("Data in Hexadecimal = %xH\n", data);
    printf("Data in Binary = ");
    DecToBin(data, sizeof(data));
    printf("Size = %zu Bytes\n", sizeof(data));
}

void Boolean(void)
{
    char data; // Change the data type to 1 byte (unsigned char)
    printf("\nBOOLEAN MODE [0 to 255]\n");
    printf("==========================\n");
    printf("Enter Raw Data :");
    scanf(" %hhu", &data); // Use %hhu for  char input
    printf("Data Meaning = ");
    if (data)
        printf("TRUE\n");
    else
        printf("FALSE\n");
    printf("Data in Decimal = %hhuD\n", data); // Use %hhu for unsigned char output
    printf("Data in Hexadecimal = %xH\n", data);
    printf("Character = %c\n", data);
    printf("Data in Binary = ");
    DecToBin(data, sizeof(data));
    printf("Size = %zu Bytes\n", sizeof(data));
    
}


void Character(void)
{
    char data;
    printf("\nCHARACTER MODE [0 to 255]\n");
    printf("==========================\n");
    printf("Enter Raw Data :");
    scanf(" %c", &data);
    printf("Data in Decimal = %hhuD\n", data); // Use %hhu for unsigned char output
    printf("Data in Hexadecimal = %xH\n", data);
    printf("Character = %c\n", data);
    printf("Data in Binary = ");
    DecToBin(data, sizeof(data));
    printf("Size = %zu Bytes\n", sizeof(data));
}

void SFloat(void)
{
    float data;
    printf("\nSingle Precision Float MODE [1.2E-38 to 3.4E+38]\n");
    printf("===================================================\n");
    printf("Enter Raw Data :");
    scanf("%f", &data);
    printf("Data in Decimal = %fD\n", data);

    unsigned int binaryData;
    memcpy(&binaryData, &data, sizeof(binaryData));
    
    printf("Data in Hexadecimal = %08xH\n", binaryData);
    printf("Data in Binary = ");
    DecToBin(binaryData, sizeof(binaryData));
    printf("Size = %zu Bytes\n", sizeof(data));
}

int main(void)
{
    char ch = ' ';
    printf("\nDATA REPRESENTATION PROGRAM...\n");
    printf("================================\n");
    while (ch != '0')
    {
        printf("\n[1]:Unsigned Short Int [2]:Boolean [3]:Unsigned Int [4]:Character [5]:Single Prec Float [0]:Exit\n");
        printf("\n");
        scanf(" %c", &ch);
        switch (ch)
        {
            case '1':
                UnsignedShortInt();
                break;
            case '2':
                Boolean();
                break;
            case '3':
                UnsignedInt();
                break;
            case '4':
                Character();
                break;
            case '5':
                SFloat();
                break;
            case '0':
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    printf("\n");
    return 0;
}
