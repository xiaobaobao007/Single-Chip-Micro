#include <REGX52.H>

void Delay(unsigned int xms)
{
    unsigned char i, j;
    while (xms)
    {
        i = 2;
        j = 239;
        do
        {
            while (--j)
                ;
        } while (--i);
        xms--;
    }
}

void writeNum(unsigned int n)
{
    unsigned int p;

    for (p = 0; p < 8; p++)
    {
        P3_4 = n & 1;
        P3_6 = 1;
        P3_6 = 0;
        n >>= 1;
    }

    P3_5 = 1;
    P3_5 = 0;
}

void main()
{
    int i, j;

    P0 = 0xFF;
    P3_4 = 0;
    P3_6 = 0;
    P3_5 = 0;

    while (1)
    {
        for (i = 0; i < 8; i++)
        {
            writeNum(1 << i);
            for (j = 6; 0xFFF >= j && j >= 1; j--)
            {
                P0 = 0xFF ^ (1 << j);
                //Delay(100);
            }
        }
    }
}
