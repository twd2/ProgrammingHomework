#include <cstdio>

int main()
{
    for (int aEat = 1; aEat <= 3; ++aEat)
    {
        for (int bEat = 1; bEat <= 3; ++bEat)
        {
            for (int cEat = 1; cEat <= 3; ++cEat)
            {
                int aCount = (bEat > aEat) + (aEat == cEat),
                    bCount = (aEat > bEat) + (aEat >  cEat),
                    cCount = (cEat > bEat) + (bEat >  aEat);
                    
                if ( ((aEat < bEat) == (aCount > bCount)) &&
                     ((aEat < cEat) == (aCount > cCount)) &&
                     ((bEat < cEat) == (bCount > cCount)) ) //饭量越小, count越大
                {
                    for (int i = 1; i <= 3; ++i)
                    {
                        if (aEat == i) printf("A");
                        if (bEat == i) printf("B");
                        if (cEat == i) printf("C");
                        if (i < 3) printf(" ");
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
