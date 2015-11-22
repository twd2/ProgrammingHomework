#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _MyVector
{
	void **data;
	size_t cap;
	size_t size;
} MyVector;

// Create a new vector
MyVector *vector_new(size_t cap)
{
    if (cap <= 0) return NULL;
    MyVector *vec = (MyVector *)malloc(sizeof(MyVector));
    vec->cap = cap;
    vec->size = 0;
    vec->data = (void **)malloc(vec->cap * sizeof(void *));
    return vec;
}

// Add x to the vector
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

// Get the pointer of the value indexed i from the vector
void **vector_get(MyVector *vec, size_t i)
{
	return vec->data + i;
}

// Get the size of the vector
size_t vector_size(MyVector *vec)
{
    return vec->size;
}

// Get the capacity of the vector
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

// Delete the vector preserving the values
void vector_free(MyVector *vec)
{
    free(vec->data);
    vec->data = NULL;
    free(vec);
    vec = NULL;
}

// Delete the vector and its values
void vector_deepfree(MyVector *vec)
{
    for (size_t i = 0; i < vec->size; ++i)
    {
        free(vec->data[i]);
        vec->data[i] = NULL;
    }
    free(vec->data);
    vec->data = NULL;
    free(vec);
    vec = NULL;
}

int main()
{
    for (;;)
    {
        MyVector *a = vector_new(8);
        int n = 10000;
        for (int i = 0; i < n; ++i)
        {
            int *x = (int *)malloc(sizeof(int));
            *x = n - i;
            vector_add(a, (void *)x);
        }
        for (int i = 0; i < n; ++i)
        {
            int *x = (int *)(*(vector_get(a, i)));
            //printf("%d ", *x);
        }
        //printf(".\n");
        vector_deepfree(a);
        a = NULL;
	}
	return 0;
}