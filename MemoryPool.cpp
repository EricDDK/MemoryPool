#include "MemoryPool.h"
#include "iostream"

MEMORY_POOL_NAMESPACE_START

MemoryPool::MemoryPool()
	:_pool(std::vector<std::unordered_set<void*>>(POOL_MAX_SIZE))
{
	size_t i, j;
	for (i = 0; i < POOL_MAX_SIZE; ++i)
	{
		for (j = 0; j < NODE_MAX_SIZE; ++j)
		{
			MP_LOG((i + 1) * MEM_ALIGN_FACTOR);
			void* p = malloc((i + 1) * MEM_ALIGN_FACTOR);
			_pool[i].insert(_pool[i].begin(), p);
		}
	}

}

MemoryPool::~MemoryPool()
{
	size_t i, j;
	for (auto& s : _pool)
	{
		for (auto &v : s)
		{
			delete v;
		}
		s.clear();
	}
	_pool.clear();
}

MEMORY_POOL_NAMESPACE_END