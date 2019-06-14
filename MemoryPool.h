#ifndef _MEMORY_POOL_H__
#define _MEMORY_POOL_H__

#if defined(_M_X64) || defined(_WIN64) \
|| defined(__LP64__) || defined(_LP64) \
|| defined(__x86_64) || defined(__arm64__) \
|| defined(__aarch64__)
#define OS_64BIT true
#else
#define OS_64BIT false
#endif // judge is 64 bit

#ifndef MEMORY_POOL_NAMESPACE_START
#define MEMORY_POOL_NAMESPACE_START namespace memorypool {
#endif // !MEMORY_POOL_NAMESPACE

#ifndef MEMORY_POOL_NAMESPACE_END
#define MEMORY_POOL_NAMESPACE_END }
#endif // !MEMORY_POOL_NAMESPACE_END

#ifndef MEMORY_POOL_NAMESPACE_USE
#define MEMORY_POOL_NAMESPACE_USE using namespace memorypool;
#endif // !MEMORY_POOL_NAMESPACE_USE

#ifndef MP_LOG
#define MP_LOG(msg) do {std::cout << msg << std::endl;} while(0)
#endif // log define

#include <assert.h>
#include <vector>
#include <unordered_set>
#include "stdio.h"

#ifndef MEM_ALIGN_FACTOR
#if OS_64BIT
#define MEM_ALIGN_FACTOR 8
#else
#define MEM_ALIGN_FACTOR 4
#endif // OS_64BIT
#endif // !MEM_ALIGN_FACTOR

#ifndef POOL_MAX_BYTES
#define POOL_MAX_BYTES MEM_ALIGN_FACTOR * 32
#endif // !POOL_MAX_BYTES

#ifndef POOL_MAX_SIZE
#define POOL_MAX_SIZE POOL_MAX_BYTES / MEM_ALIGN_FACTOR
#endif // !POOL_MAX_SIZE 32

#ifndef NODE_MAX_SIZE
#define NODE_MAX_SIZE 128
#endif // !NODE_MAX_SIZE

// class
MEMORY_POOL_NAMESPACE_START

class MemoryPool
{
public:
	MemoryPool();
	~MemoryPool();



private:
	std::vector<std::unordered_set<void*>> _pool;
};

MEMORY_POOL_NAMESPACE_END

#endif