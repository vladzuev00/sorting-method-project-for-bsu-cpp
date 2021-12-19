#ifndef BUBBLEARRAYSORTINGMETHOD_H
#define BUBBLEARRAYSORTINGMETHOD_H

#include "Array.h"

//*****************************************************************************
template<class ElementType>
class BubbleArraySortingMethod : public ArraySortingMethod<ElementType>
{
public:
	BubbleArraySortingMethod();
public:
	virtual void sortArray(const Array<ElementType> &sortedArray) const override;
public:
	virtual ~BubbleArraySortingMethod() override;
};
//*****************************************************************************

#endif BUBBLEARRAYSORTINGMETHOD_H