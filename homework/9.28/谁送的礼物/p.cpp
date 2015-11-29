#include <cstdio>

int main()
{
    for (char i = 'A'; i <= 'D'; ++i)
    {
        int count =
            (i != 'A') +
            (i == 'B') +
            (i != 'B') +
            (i == 'C');
        if (count == 3)
        {
            printf("%c\n", i);
            break;
        }
    }
    return 0;
}