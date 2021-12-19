#include "stdafx.h"
#include "BubbleArraySortingMethod.h"

//*****************************************************************************
template class BubbleArraySortingMethod<double>;
//*****************************************************************************
template<class ElementType>
BubbleArraySortingMethod<ElementType>::BubbleArraySortingMethod()
	: ArraySortingMethod<ElementType>::ArraySortingMethod()
{

}
//*****************************************************************************
template<class ElementType>
void BubbleArraySortingMethod<ElementType>::sortArray(const Array<ElementType> &sortedArray) const 
{
	bool isAlreadySorted;
	for (int i = sortedArray.getAmountOfElements() - 1; i > 0; i--) 
	{
		isAlreadySorted = true;
		for (int j = 0; j < i; j++) 
		{
			if (sortedArray[j] > sortedArray[j + 1])
			{
				ElementType tempHolder = sortedArray[j];
				sortedArray[j] = sortedArray[j + 1];
				sortedArray[j + 1] = tempHolder;
				isAlreadySorted = false;
			}
		}
		if (isAlreadySorted) 
		{
			return;
		}
	}
}
//*****************************************************************************
template<class ElementType>
BubbleArraySortingMethod<ElementType>::~BubbleArraySortingMethod()
{

}
//*****************************************************************************