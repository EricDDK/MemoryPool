#ifndef _MEMORY_TOOL_H__
#define _MEMORY_TOOL_H__

#include "MemoryPool.h"

static memorypool::MemoryPool *s_pool = new memorypool::MemoryPool;

class MemoryTool
{
public:
	static memorypool::MemoryPool *getInstance()
	{
		return s_pool;
	}

	template<typename T, typename... Args>
	T* safeMalloc(Args&&... args)
	{
		return pool->safeMalloc(args);
	}

	template<typename T>
	void safeFree(T* &t)
	{
		pool->safeFree(t);
	}
};

#endif