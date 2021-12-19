#include "stdafx.h"
#include "SelectionArraySortingMethod.h"

//*****************************************************************************
template class SelectionArraySortingMethod<double>;
//*****************************************************************************
template<class ElementType>
SelectionArraySortingMethod<ElementType>::SelectionArraySortingMethod() 
	: ArraySortingMethod<ElementType>::ArraySortingMethod()
{

}
//*****************************************************************************
template<class ElementType>
void SelectionArraySortingMethod<ElementType>::sortArray(const Array<ElementType> &sortedArray) const
{
	int indexOfMaxElement;
	for (int i = sortedArray.getAmountOfElements() - 1; i > 0; i--)
	{
		indexOfMaxElement = i;
		for (int j = 0; j < i; j++)
		{
			if (sortedArray[j] >= sortedArray[indexOfMaxElement])
			{
				indexOfMaxElement = j;
			}
		}

		if (indexOfMaxElement != i)
		{
			ElementType tempHolder = sortedArray[indexOfMaxElement];
			sortedArray[indexOfMaxElement] = sortedArray[i];
			sortedArray[i] = tempHolder;
		}
	}
}
//*****************************************************************************
template<class ElementType>
SelectionArraySortingMethod<ElementType>::~SelectionArraySortingMethod()
{

}
//*****************************************************************************