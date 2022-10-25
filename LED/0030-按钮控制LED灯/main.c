#include <REGX52.h>

void Delay20ms()		//@11.0592MHz
{
    unsigned char i, j;

    i = 36;
    j = 217;

    do
    {
        while (--j);
    }
    while (--i);
}

int point = 0;
int num = 1;

void light(int p)
{
    point += p;

    if(point < 0)
    {
        point = 7;
    }
    else if(point > 7)
    {
        point = 0;
    }

    P2 = 0xFF ^ (num << point);
}

void addNum(unsigned n)
{
    if(n)
    {
        num = num << 1 | 1;
    }
    else
    {
        num >>= 1;
    }
}

void main()
{
    P2 = 0xFF;

    light(0);

    while(1)
    {
        if(P3_1 == 0)
        {
            Delay20ms();

            while(P3_1 == 0);

            Delay20ms();

            light(-1);
        }
        else if(P3_0 == 0)
        {
            Delay20ms();

            while(P3_0 == 0);

            Delay20ms();

            light(1);
        }
        else if(P3_2 == 0)
        {
            Delay20ms();

            while(P3_2 == 0);

            Delay20ms();

            addNum(1);
            light(0);
        }
        else if(P3_3 == 0)
        {
            Delay20ms();

            while(P3_3 == 0);

            Delay20ms();

            addNum(0);
            light(0);
        }
    }
}