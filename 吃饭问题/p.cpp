#include<cstdio>
int main()
{
    for(int a=1;a<=3;++a)
    {
        for(int b=1;b<=3;++b)
        {
            for(int c=1;c<=3;++c)
            {
                int aCount=(b>a) + (a==c),
                    bCount=(a>b) + (a>c),
                    cCount=(c>b) + (b>a);
                if ( ((a<b)==(aCount>bCount)) &&
                     ((a<c)==(aCount>cCount)) &&
                     ((b<c)==(bCount>cCount))) //饭量越小, count越大
                {
                    for(int i=1;i<=3;++i)
                    {
                        if(a==i) printf("A");
                        if(b==i) printf("B");
                        if(c==i) printf("C");
                        if(i<3) printf(" ");
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
