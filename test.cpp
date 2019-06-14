#include "MemoryPool.h"

#include "iostream"
#include <vector>
#include <unordered_map>

#ifdef _MSC_VER
#ifdef _DEBUG
#define New   new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#define CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>
#endif

#define EXPECT(expect, actual) \
do {\
    if (expect != actual)\
        fprintf(stderr, "%s:%d: \n", __FILE__, __LINE__);\
}while(0)

MEMORY_POOL_NAMESPACE_USE

class Test
{
public:
	Test(int a, double b)
	{
		v = a;
		d = b;
	}
	int v;
	double d;
};

void test1()
{
	MemoryPool m;
	auto p = m.safeMalloc<int>();
	*p = 5;
	m.safeFree(p);
	EXPECT(p, NULL);
}

void test2()
{
	MemoryPool m;
	auto p = m.safeMalloc<Test>(1, 2.0);
	EXPECT(p->v, 1);
	EXPECT(p->d, 2.0);
	m.safeFree(p);
}

int main()
{
	test1();
	test2();

#ifdef _MSC_VER
	//_CrtDumpMemoryLeaks();
	system("pause");
#else

#endif
	return 0;
}