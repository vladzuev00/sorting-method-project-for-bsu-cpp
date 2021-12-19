#ifndef SELECTIONARRAYSORTINGMETHOD_H
#define SELECTIONARRAYSORTINGMETHOD_H

#include "Array.h"

//*****************************************************************************
template<class ElementType>
class SelectionArraySortingMethod : public ArraySortingMethod<ElementType>
{
public:
	SelectionArraySortingMethod();
public:
	virtual void sortArray(const Array<ElementType> &sortedArray) const override;
public:
	virtual ~SelectionArraySortingMethod() override;
};
//*****************************************************************************

#endif SELECTIONARRAYSORTINGMETHOD_H

