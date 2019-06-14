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

MEMORY_POOL_NAMESPACE_USE

int main()
{
	MemoryPool m;


#ifdef _MSC_VER
	_CrtDumpMemoryLeaks();
	system("pause");
#else

#endif
	return 0;
}