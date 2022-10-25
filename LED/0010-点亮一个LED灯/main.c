#include <REGX52.h>

void Delayms(unsigned int ms)		//@11.0592MHz
{
    unsigned char i, j;

    while(--ms)
    {
        i = 2;
        j = 199;

        do
        {
            while (--j);
        }
        while (--i);
    }
}


void main()
{
    int base = 0x1FF;

    int start = 7;
    int end = 0;
    int point = start;
    int add = -1;

    while (1)
    {
        P2 = base ^ (1 << point);
        Delayms(200);

        if ((add < 0 && point - 1 >= end) || (point + 1 <= end))
        {
            point += add;

            continue;
        }

        base ^= 1 << point;

        if (base == 0x100)
        {
            base = 0x1FF;
            start = 7;
            end = 0;
            point = start;
            add = -1;
            continue;
        }

        point = start;
        start = end;
        end = point;

        if (add < 0)
        {
            add = 1;
        }
        else
        {
            add = -1;
        }

        start += add;
        point = start;
    }

    return;
}
