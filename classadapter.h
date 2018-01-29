#ifndef STACK_H
#define STACK_H
#include "dlist.h"

//the abstract base class Stack, the interface of a Stack.
class Stack{
public:
	Stack();
	virtual void push(const Object& o)=0;
	virtual void pop()=0;
	virtual Object top()=0;
	virtual bool isEmpty()=0;
	virtual ~Stack();
};

#endif
