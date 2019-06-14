#ifndef _MEMORY_POOL_H__
#define _MEMORY_POOL_H__

#ifndef MEMORY_POOL_NAMESPACE_START
#define MEMORY_POOL_NAMESPACE_START namespace memorypool {
#endif // !MEMORY_POOL_NAMESPACE

#ifndef MEMORY_POOL_NAMESPACE_END
#define MEMORY_POOL_NAMESPACE_END }
#endif // !MEMORY_POOL_NAMESPACE_END

#ifndef MEMORY_POOL_NAMESPACE_USE
#define MEMORY_POOL_NAMESPACE_USE using namespace memorypool;
#endif // !MEMORY_POOL_NAMESPACE_USE

#include <assert.h>

// class
MEMORY_POOL_NAMESPACE_START

class MemoryPool
{
public:
	MemoryPool();
	~MemoryPool();

private:

};

MEMORY_POOL_NAMESPACE_END

#endif
