#include<iostream>
using namespace std;

struct numst
{
    int num;
    numst *next;
};

void del(numst *phead, int num)
{
    numst *p = NULL, *q = NULL;
    if(phead == NULL)
        return;
    p = phead;
    if(p->num == num)
    {
        phead = p->next;
        delete p;
        return;
    }
    q = p->next;
    while(q != NULL)
    {
        if(q->num == num)
        {
            p->next = q->next;
            delete q;
            return; 
        }
        if(q->num > num)
            return;
        p = q;
        q = q->next; 
    }
}
 
 
int main()
{
    numst *pmhead = NULL;
    pmhead = new numst;
    pmhead->next = new numst;
    pmhead->next->next = new numst;
    
    pmhead->num = 5;
    pmhead->next->num = 10;
    pmhead->next->next->num = 15;
    pmhead->next->next->next = NULL;
    del(pmhead,10); 
    return 0;
}

