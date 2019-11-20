#include "queue.h"


Queue::Queue(int s)
{
	if ((s < 1) || (s > MaxSize)) throw (s);
	size = s;
	hi = 0;
	li = 0;
	count = 0;
	pMem = new int[size + 1];
	pMemTmp = new int[1];
}

Queue::Queue(const Queue &obj)
{
	size = obj.size;
	hi = obj.hi;
	li = obj.li;
	count = obj.count;
	pMem = new int[size + 1];
	for (int i = 0; i < size; i++)
		pMem[i] = obj.pMem[i];
}

Queue::~Queue()
{
	delete[] pMem;
	delete[] pMemTmp;
	pMem = NULL;
	pMemTmp = NULL;
}

bool Queue::IsEmpty()
{
	return(count == 0);
}

bool Queue::IsFull()
{
	return (count == size);
}

void Queue::put(const int &newElem)
{
	if (IsFull())  throw (count);
	pMem[li] = newElem;
	li++;
	count++;
	if (li > size)
		li = li - size + 1;
}

int Queue::get()
{
	if (IsEmpty()) throw (count);
	pMem[0] = pMem[hi];
	hi++;
	count--;
	if (hi > size)
		hi = hi - size + 1;
	return pMemTmp[0];
}

int Queue::top()
{
	if (IsEmpty()) throw (count);
	return pMem[hi];;
}