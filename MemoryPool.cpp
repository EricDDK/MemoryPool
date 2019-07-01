#include "MemoryPool.h"
#include "iostream"

MEMORY_POOL_NAMESPACE_START

MemoryPool::MemoryPool()
	:_pool(std::vector<std::stack<void*>>(POOL_MAX_SIZE))
{
	size_t i, j;
	for (i = 0; i < POOL_MAX_SIZE; ++i)
	{
		for (j = 0; j < NODE_MAX_SIZE; ++j)
		{
			//MP_LOG((i + 1) * MEM_ALIGN_FACTOR);
			void* p = malloc((i + 1) * MEM_ALIGN_FACTOR);
			_pool[i].push(p);
		}
	}

}

MemoryPool::~MemoryPool()
{
	_mtx.lock();
	for (auto& s : _pool)
	{
		while (!s.empty())
		{
			auto v = s.top();
			s.pop();
			delete v;
		}
	}
	_mtx.unlock();
}

void MemoryPool::gc()
{
	_mtx.lock();
	for (auto& s : _pool)
	{
		size_t size = s.size();
		while (size-- > NODE_MAX_SIZE)
		{
			void *p = s.top();
			s.pop();
			delete(p);
		}
	}
	_mtx.unlock();
}

MEMORY_POOL_NAMESPACE_END
