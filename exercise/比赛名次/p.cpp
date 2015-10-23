#include <cstdio>

void reverse(char *f, char *l)
{
    if (f == NULL || l == NULL) return;
    if (f == l) return;
    
    int len = l - f;
    int s = len / 2;
    char t;
    
    for (int i = 0; i < s; ++i)
    {
        t = f[i];
        f[i] = f[len - i - 1];
        f[len - i - 1] = t;
    }
}
bool next(char *f, char *l)
{
    if (f == NULL || l == NULL) return 0;
    if (f == l) return false;
    if (l - f == 1) return false;
    
    char t;
    char *i = NULL, *j = NULL, *k = NULL;
    k = i = l - 1;
    while (true)
    {
        j = i;
        --i;
        if (*i < *j)
        {
            while (!(*i < *k)) --k;
            t = *i;
            *i = *k;
            *k = t;
            reverse(j, l);
            return true;
        }
        if(i == f) return false;
    }
    return false;
}
void print(char *f, char *l)
{
    for (char *i = f; i < l; ++i)
    {
        printf("%c", *i);
    }
    printf("\n");
}
int main()
{
    int A, B, C, D, E;
    char a[] = "ABCDE";
    do
    {
        //do something
        A = (a[1] == 'B') + (a[2] == 'A');
        B = (a[1] == 'B') + (a[3] == 'E');
        C = (a[0] == 'C') + (a[1] == 'D');
        D = (a[4] == 'C') + (a[2] == 'D');
        E = (a[3] == 'E') + (a[0] == 'A');

        if (A == 1 && B == 1 && C == 1 && D == 1 && E == 1)
            printf("%c %c %c %c %c\n", a[0], a[1], a[2], a[3], a[4]);
    } while(next(a, a + 5));
    return 0;
}
