#pragma once
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>  
#include <locale>    
using namespace std;
const unsigned int MaxSize = 100;

class Queue
{
private:
	int *pMem;
	int *pMemTmp;
	int size;
	int hi;
	int li;
	int count;
public:
	Queue(int s);
	Queue(const Queue &obj);
	~Queue();
	bool IsEmpty();
	bool IsFull();
	void put(const int &newElem);
	int get();
	int top();
	int get_size() { return count; };
};

#endif 

