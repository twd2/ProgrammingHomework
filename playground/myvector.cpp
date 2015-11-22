#include <iostream>
#include <memory>
#include <cstdlib>
using namespace std;

struct MyVector
{
	void **data;
	size_t cap;
	size_t size;
};

MyVector *vector_new(size_t cap)
{
    if (cap <= 0) return NULL;
    MyVector *vec = (MyVector *)malloc(sizeof(MyVector));
    vec->cap = cap;
    vec->size = 0;
    vec->data = (void **)malloc(vec->cap * sizeof(void *));
    return vec;
}

/*
MyVector *vector_new()
{
    return vector_new(8);
}
*/

void vector_add(MyVector *vec, void *x)
{
	if (vec->size == vec->cap)
	{
		vec->cap *= 2;
		vec->data = (void **)realloc(vec->data, vec->cap * sizeof(void *));
	}
	vec->data[vec->size] = x;
	++vec->size;
}
	
void **vector_get(MyVector *vec, size_t i)
{
	return vec->data + i;
}

size_t vector_size(MyVector *vec)
{
    return vec->size;
}

size_t vector_capacity(MyVector *vec)
{
    return vec->cap;
}

void **vector_begin(MyVector *vec)
{
    return vec->data;
}

void **vector_end(MyVector *vec)
{
    return vec->data + vec->size;
}

void vector_free(MyVector *vec)
{
    delete [] vec->data;
    vec->data = NULL;
    delete vec;
    vec = NULL;
}

int main()
{
    for (;;)
    {
        MyVector *a = vector_new(8);
        int n = 100000000;
        //cin >> n;
        for (int i = 0; i < n; ++i)
        {
            //int x;
            //cin >> x;
            vector_add(a, (void *)(n - i));
        }
        for (int i = 0; i < n; ++i)
        {
            int b = (int)(*(vector_get(a, i)));
            //cout << (int)(*(vector_get(a, i))) << " ";
        }
        cout << "." << endl;
        vector_free(a);
        a = NULL;
	}
	return 0;
}