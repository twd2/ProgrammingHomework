#include <iostream>
#include <cstdlib>

using namespace std;

struct MapNode
{
    void *value;
    MapNode *subNodes[256];
};

MapNode *map_node_new()
{
    MapNode *node = (MapNode *)malloc(sizeof(MapNode));
    node->value = NULL;
    for (int i = 0; i < 256; ++i)
    {
        node->subNodes[i] = NULL;
    }
    return node;
}

MapNode *map_new()
{
    return map_node_new();
}

void map_newSubNode(MapNode* node, char key)
{
    if (node->subNodes[key]) return;
    node->subNodes[key] = map_node_new();
}

void map_add(MapNode* node, const char *str, void *value)
{
    if (*str == '\0')
    {
        node->value = value;
        return;
    }
    if (!node->subNodes[*str])
    {
        map_newSubNode(node, *str);
    }
    map_add(node->subNodes[*str], str + 1, value);
}

void** map_get(MapNode* node, const char *str)
{
    if (*str == '\0')
    {
        return &(node->value);
    }
    if (node->subNodes[*str])
        return map_get(node->subNodes[*str], str + 1);
    else
        return NULL;
}

void map_free(MapNode *node)
{
    if (!node) return;
    node->value = NULL;
    for (int i = 0; i < 256; ++i)
    {
        if (node->subNodes[i])
            map_free(node->subNodes[i]);
        node->subNodes[i] = NULL;
    }
    free(node);
    node = NULL;
}

int main()
{
    for (;;)
    {
        MapNode *root = map_new();
        map_add(root, "test1", (void *)1);
        map_add(root, "tess1", (void *)2);
        map_add(root, "tfst1", (void *)3);
        map_add(root, "abcdef", (void *)4);

        cout << *map_get(root, "test1") << endl;
        *map_get(root, "test1") = (void *)0x233;
        cout << *map_get(root, "test1") << endl;
        map_free(root);
        root = NULL;
    }
    return 0;
}