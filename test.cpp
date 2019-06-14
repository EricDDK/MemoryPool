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

class TestLarge
{
public:
	TestLarge(int a)
	{
		l1 = a;
	}
	long long l1;  long long l2;  long long l3;  long long l4;
	long long l5;  long long l6;  long long l7;  long long l8;
	long long l9;  long long l10; long long l11; long long l12;
	long long l13; long long l14; long long l15; long long l16;
	long long l17; long long l18; long long l19; long long l20;
	long long l21; long long l22; long long l23; long long l24;
	long long l25; long long l26; long long l27; long long l28;
	long long l29; long long l30; long long l31; long long l32;
	long long l33; long long l34; long long l35; long long l36;
	long long l37; long long l38; long long l39; long long l40;
	long long l41; long long l42; long long l43; long long l44;
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

void testLarge()
{
	MemoryPool m;
	auto p = m.safeMalloc<TestLarge>(5);
	EXPECT(p->l1, 5);
	m.safeFree(p);
}

int main()
{
	test1();
	test2();
	testLarge();

#ifdef _MSC_VER
	_CrtDumpMemoryLeaks();
	system("pause");
#else

#endif
	return 0;
}