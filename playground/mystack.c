#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _MyStack
{
	void **data;
	size_t cap;
	size_t size;
} MyStack;

// Create a new stack
MyStack *stack_new(size_t cap)
{
    if (cap <= 0) return NULL;
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->cap = cap;
    s->size = 0;
    s->data = (void **)malloc(s->cap * sizeof(void *));
    return s;
}

// Push x into the stack
void stack_push(MyStack *s, void *x)
{
	if (s->size == s->cap)
	{
		s->cap *= 2;
		s->data = (void **)realloc(s->data, s->cap * sizeof(void *));
	}
	s->data[s->size] = x;
	++s->size;
}

// Get the pointer of the value indexed i from the stack
void **stack_get(MyStack *s, size_t i)
{
	return s->data + i;
}

// Remove the top element
void stack_pop(MyStack *s)
{
	--s->size;
}

// Remove the top element and free it
void stack_pop_and_free(MyStack *s)
{
	--s->size;
	free(s->data[s->size]);
}

// Get the pointer of the value in the stack top
void **stack_top(MyStack *s)
{
	return s->data + s->size - 1;
}

// Get the size of the stack
size_t stack_size(MyStack *s)
{
    return s->size;
}

// Get the capacity of the stack
size_t stack_capacity(MyStack *s)
{
    return s->cap;
}

void **stack_begin(MyStack *s)
{
    return s->data;
}

void **stack_end(MyStack *s)
{
    return s->data + s->size;
}

// Delete the stack preserving the values
void stack_free(MyStack *s)
{
    free(s->data);
    s->data = NULL;
    free(s);
    s = NULL;
}

// Delete the stack and its values
void stack_deepfree(MyStack *s)
{
    for (size_t i = 0; i < s->size; ++i)
    {
        free(s->data[i]);
        s->data[i] = NULL;
    }
    free(s->data);
    s->data = NULL;
    free(s);
    s = NULL;
}

int main()
{
    for (;;)
    {
        MyStack *a = stack_new(8);
        int n = 10000;
        for (int i = 0; i < n; ++i)
        {
            int *x = (int *)malloc(sizeof(int));
            *x = i;
            stack_push(a, (void *)x);
        }
        while (stack_size(a) > 0)
        {
            int *x = (int *)(*(stack_top(a)));
            stack_pop_and_free(a);
            //printf("%d ", *x);
        }
        //printf(".\n");

        stack_deepfree(a);
        a = NULL;
	}
	return 0;
}