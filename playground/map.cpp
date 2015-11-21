#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
    void *value;
    node *subNodes[256];
};

node *node_new()
{
    node *n = (node *)malloc(sizeof(node));
    n->value = NULL;
    for (int i = 0; i < 256; ++i)
    {
        n->subNodes[i] = NULL;
    }
    return n;
}

void node_newsub(node* n, char key)
{
    if (n->subNodes[key]) return;
    n->subNodes[key] = node_new();
}

void node_add(node* n, char *str, void *value)
{
    if (*str == '\0')
    {
        n->value = value;
        return;
    }
    if (!n->subNodes[*str])
    {
        node_newsub(n, *str);
    }
    node_add(n->subNodes[*str], str + 1, value);
}

void** node_get(node* n, char *str)
{
    if (*str == '\0')
    {
        return &(n->value);
    }
    if (n->subNodes[*str])
        return node_get(n->subNodes[*str], str + 1);
    else
        return NULL;
}

int main()
{
    node *root = node_new();
    node_add(root, "test1", (void *)1);
    node_add(root, "tess1", (void *)2);
    node_add(root, "tfst1", (void *)3);
    node_add(root, "abcdef", (void *)4);
    
    if (!node_get(root, "abcdeg"))
        cout << "ok" << endl;
    return 0;
}