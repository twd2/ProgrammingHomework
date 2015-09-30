#include<cstdio>
int main()
{
    for(char i='A';i<='D';++i)
    {
        int count=
            (i!='A')+
            (i=='D')+
            (i=='B')+
            (i!='D');
        if(count==1)
        {
            printf("%c\n", i);
            break;
        }
    }
    return 0;
}