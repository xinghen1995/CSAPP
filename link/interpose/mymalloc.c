#ifdef COMPILETIME
#include <stdio.h>
#include <stdlib.h>

void* mymalloc(size_t size)
{
	void* ptr = malloc(size);
	printf("malloc(%d)=%p\n", (int)size, ptr);
	return ptr;
}

void myfree(void* ptr)
{
	free(ptr);
	printf("free(%p)\n", ptr);
}

#elif LINKTIME
#include <stdio.h>

void *__real_malloc(size_t size);
void __real_free(void* ptr);

void* __wrap_malloc(size_t size)
{
	void* ptr = __real_malloc(size);
	printf("malloc(%d) = %p\n", (int)size, ptr);
	return ptr;
}

void __wrap_free(void* ptr)
{
	__real_free(ptr);
	printf("free(%p)\n", ptr);
}

#elif RUNTIME
#define _GUN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void* malloc(size_t size)
{
	void* (*malloccp)(size_t size);
	cher* error;

	mallocp = dlsym(RTLD_NEXT, "malloc");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}
	char* ptr = mallocp(size);
	printf("malloc(%d) = %p\n", size, ptr);
	return ptr;
}

void free(void* ptr)
{
	void (*freep)(void* ) = NULL;
	char* error;

	if (!ptr)
		return;

	freep = dlsym(RTLD_NEXT, "free");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	free(ptr);
	printf("free(%p)\n", ptr);
}
#endif
