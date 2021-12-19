#include "stdafx.h"
#include "SelectionArraySortingMethod.h"
#include "ArrayCreatingException.h"
#include "ArrayModificationException.h"
#include "ArraySearchingException.h"

//***********************************Array******************************************
template class Array<double>;
//*****************************************************************************
template<class ElementType>
Array<ElementType>::Array()
{
	this->amountOfElements = 0;
	this->capacity = Array<ElementType>::DEFAULT_INITIAL_CAPACITY;
	this->elements = new ElementType[this->capacity];
	this->arraySortingMethod = new SelectionArraySortingMethod<ElementType>();
}
//*****************************************************************************
template<class ElementType>
const int Array<ElementType>::DEFAULT_INITIAL_CAPACITY = 16;
//*****************************************************************************
template<class ElementType>
Array<ElementType>::Array(const int initialCapacity) 
{
	if (!Array<ElementType>::ARRAY_VALIDATOR.isValidInitialCapacity(initialCapacity)) 
	{
		throw new ArrayCreatingException("Impossible to create array with given"
			" initial capacity: " + std::to_string(initialCapacity) + ".");
	}
	this->amountOfElements = 0;
	this->capacity = initialCapacity;
	this->elements = new ElementType[this->capacity];
	this->arraySortingMethod = new SelectionArraySortingMethod<ElementType>();
}
//*****************************************************************************
template<class ElementType>
const ArrayValidator Array<ElementType>::ARRAY_VALIDATOR = ArrayValidator();
//*****************************************************************************
template<class ElementType>
Array<ElementType>::Array(const ElementType * const valuesOfElements, const int amountOfElements)
{
	if ( !(Array<ElementType>::ARRAY_VALIDATOR.areValidValuesOfElements<ElementType>(valuesOfElements)
		&& Array<ElementType>::ARRAY_VALIDATOR.isValidAmountOfElements(amountOfElements)))
	{
		throw new ArrayCreatingException("Impossible to create array with given values of elements"
			" and amount of elements: " + std::to_string(amountOfElements) + ".");
	}
	this->amountOfElements = amountOfElements;
	this->capacity = amountOfElements;
	this->elements = new ElementType[this->capacity];
	this->initializeElements(valuesOfElements);
	this->arraySortingMethod = new SelectionArraySortingMethod<ElementType>();
}
//*****************************************************************************
template<class ElementType>
void Array<ElementType>::initializeElements(const ElementType * const valuesOfElements)
{
	for (int i = 0; i < this->amountOfElements; i++) 
	{
		*(this->elements + i) = *(valuesOfElements + i);
	}
}
//*****************************************************************************
template<class ElementType>
Array<ElementType>::Array(const ElementType * const valuesOfElements, const int amountOfElements,
	                      ArraySortingMethod<ElementType> * const arraySortingMethod)
	: Array<ElementType>::Array(valuesOfElements, amountOfElements)
{
	if (!Array<ElementType>::ARRAY_VALIDATOR
		.isValidMethodOfSortingArray<ElementType>(arraySortingMethod))
	{
		throw new ArrayCreatingException("Impossible to create array"
			" with given method of searching element.");
	}
	this->arraySortingMethod = arraySortingMethod;
}
//*****************************************************************************
template<class ElementType>
Array<ElementType>::Array(const Array<ElementType> &other)
	: amountOfElements(other.amountOfElements),
	  capacity(other.capacity)
{
	this->elements = new ElementType[this->capacity];
	this->initializeElements(other.elements);
	this->arraySortingMethod = new SelectionArraySortingMethod<ElementType>();
}
//*****************************************************************************
template<class ElementType>
int Array<ElementType>::getAmountOfElements() const
{
	return this->amountOfElements;
}
//*****************************************************************************
template<class ElementType>
int Array<ElementType>::getCapacity() const
{
	return this->capacity;
}
//*****************************************************************************
template<class ElementType>
void Array<ElementType>::setArraySortingMethod(
	ArraySortingMethod<ElementType> * const arraySortingMethod)
{
	if (!Array<ElementType>::ARRAY_VALIDATOR
		.isValidMethodOfSortingArray<ElementType>(arraySortingMethod))
	{
		throw new ArrayModificationException("Impossible to set new given"
			" method of searching element.");
	}
	delete this->arraySortingMethod;
	this->arraySortingMethod = arraySortingMethod;
}
//*****************************************************************************
template<class ElementType>
ArraySortingMethod<ElementType>* Array<ElementType>::getArraySortingMethod() const
{
	return this->arraySortingMethod;
}
//*****************************************************************************
template<class ElementType>
void Array<ElementType>::updateValueOfElement(
	const ElementType &newValueOfElement, const int indexOfElement)
{
	if (!Array<ElementType>::ARRAY_VALIDATOR
		.isValidIndex<ElementType>(indexOfElement, *this))
	{
		throw new ArrayModificationException("Impossible to update value"
			" of element with given index: " + std::to_string(indexOfElement)
			+ ".");
	}
	*(this->elements + indexOfElement) = newValueOfElement;
}
//*****************************************************************************
template<class ElementType>
ElementType& Array<ElementType>::findElement(const int indexOfElement) const
{
	if (!Array<ElementType>::ARRAY_VALIDATOR
		.isValidIndex<ElementType>(indexOfElement, *this))
	{
		throw new ArraySearchingException("Impossible to find element"
			" with given index: " + std::to_string(indexOfElement));
	}
	return *(this->elements + indexOfElement);
}
//*****************************************************************************
template<class ElementType>
void Array<ElementType>::addElement(const ElementType &valueOfAddedElement)
{
	if (this->amountOfElements == this->capacity)
	{
		this->increaseCapacity();
	}
	const int indexOfAddedElement = this->amountOfElements;
	*(this->elements + indexOfAddedElement) = valueOfAddedElement;
	this->amountOfElements++;
}
//*****************************************************************************
template<class ElementType>
void Array<ElementType>::increaseCapacity()
{
	const int newCapacity = (int)(this->capacity *
		(1 + Array<ElementType>::COEFFICIENT_OF_INCREASING_CAPACITY));
	this->changeCapacity(newCapacity);
}
//*****************************************************************************
template<class ElementType>
const double Array<ElementType>::COEFFICIENT_OF_INCREASING_CAPACITY = 0.75;
//*****************************************************************************
template<class ElementType>
void Array<ElementType>::changeCapacity(const int newCapacity)
{
	if (newCapacity < this->amountOfElements)
	{
		throw new ArrayModificationException("Impossible to change capacity."
			" Given new capacity: " + std::to_string(newCapacity) + ".");
	}
	ElementType *tempHolder = this->elements;
	this->elements = new ElementType[newCapacity];
	for (int i = 0; i < this->amountOfElements; i++)
	{
		*(this->elements + i) = *(tempHolder + i);
	}
	delete[] tempHolder;
}
//*****************************************************************************
template<class ElementType>
void Array<ElementType>::addElement(const ElementType &valueOfAddedElement,
	                                const int indexOfAddedElement)
{
	if (!Array<ElementType>::ARRAY_VALIDATOR
		.isValidIndexToAddElement<ElementType>(indexOfAddedElement, *this))
	{
		throw new ArrayModificationException("Impossible to add element"
			" with given index: " + std::to_string(indexOfAddedElement) + ".");
	}
	if (this->amountOfElements == this->capacity)
	{
		this->increaseCapacity();
	}
	for (int i = this->amountOfElements - 1; i >= indexOfAddedElement; i--)
	{
		*(this->elements + i + 1) = *(this->elements + i);
	}
	*(this->elements + indexOfAddedElement) = valueOfAddedElement;
	this->amountOfElements++;
}
//*****************************************************************************
template<class ElementType>
void Array<ElementType>::removeElement(const int indexOfRemovedElement)
{
	if (!Array<ElementType>::ARRAY_VALIDATOR
		.isValidIndex<ElementType>(indexOfRemovedElement, *this))
	{
		throw new ArrayModificationException("Impossible to remove element"
			" with given index: " + std::to_string(indexOfRemovedElement) + ".");
	}
	for (int i = indexOfRemovedElement; i < this->amountOfElements - 1; i++)
	{
		*(this->elements + i) = *(this->elements + i + 1);
	}
	this->amountOfElements--;
}
//*****************************************************************************
template<class ElementType>
void Array<ElementType>::sortElements()
{
	this->arraySortingMethod->sortArray(*this);
}
//*****************************************************************************
template<class ElementType>
std::string Array<ElementType>::toString() const
{
	std::string descriptionOfArray(typeid(*this).name());
	descriptionOfArray.append("[amountOfElements = ");
	descriptionOfArray.append(std::to_string(this->amountOfElements));
	descriptionOfArray.append(", capacity = ");
	descriptionOfArray.append(std::to_string(this->capacity));
	descriptionOfArray.append(", elements = ");
	descriptionOfArray.append(this->findDescriptionOfElements());
	descriptionOfArray.append("]");
	return descriptionOfArray;
}
//*****************************************************************************
template<class ElementType>
std::string Array<ElementType>::findDescriptionOfElements() const
{
	std::string descriptionOfElements("[");
	const std::string delimiterOfDescriptionOfElements = ", ";
	int i;
	for (i = 0; i < this->amountOfElements - 1; i++)
	{
		descriptionOfElements.append(std::to_string(*(this->elements + i)));
		descriptionOfElements.append(delimiterOfDescriptionOfElements);
	}
	descriptionOfElements.append(std::to_string(*(this->elements + i)));
	return descriptionOfElements;
}
//*****************************************************************************
template<class ElementType>
ElementType& Array<ElementType>::operator[](const int indexOfElement) const
{
	return this->findElement(indexOfElement);
}
//*****************************************************************************
template<class ElementType>
bool Array<ElementType>::operator==(const Array<ElementType> &other) const
{
	if (this == &other)
	{
		return true;
	}
	if (this->amountOfElements != other.amountOfElements)
	{
		return false;
	}
	for (int i = 0; i < this->amountOfElements; i++)
	{
		if (*(this->elements + i) != *(other.elements + i))
		{
			return false;
		}
	}
	return true;
}
//*****************************************************************************
template<class ElementType>
bool Array<ElementType>::operator!=(const Array<ElementType> &other) const
{
	return !(*this == other);
}
//*****************************************************************************
template<class ElementType>
Array<ElementType>& Array<ElementType>::operator=(const Array<ElementType> &other)
{
	if (this == &other)
	{
		return *this;
	}
	delete[] this->elements;
	this->amountOfElements = other.amountOfElements;
	this->capacity = other.amountOfElements;
	this->elements = new ElementType[this->capacity];
	this->initializeElements(other.elements);
	delete this->arraySortingMethod;
	this->arraySortingMethod = new SelectionArraySortingMethod<ElementType>();
	return *this;
}
//*****************************************************************************
template<class ElementType>
Array<ElementType>::~Array()
{
	delete[] this->elements;
	delete this->arraySortingMethod;
}
//**************************************ArraySortingMethod***************************************
template class ArraySortingMethod<double>;
//*****************************************************************************
template<class ElementType>
ArraySortingMethod<ElementType>::ArraySortingMethod() 
{

}
//*****************************************************************************
template<class ElementType>
ArraySortingMethod<ElementType>::~ArraySortingMethod() 
{

}
//*****************************************************************************
bool ArrayValidator::isValidInitialCapacity(const int researchInitialCapacity) const
{
	return ArrayValidator::MINIMAL_ALLOWABLE_INITIAL_CAPACITY <= researchInitialCapacity
		&& researchInitialCapacity <= ArrayValidator::MAXIMAL_ALLOWABLE_INITIAL_CAPACITY;
}
//*****************************************************************************
const int ArrayValidator::MINIMAL_ALLOWABLE_INITIAL_CAPACITY = 1;
//*****************************************************************************
const int ArrayValidator::MAXIMAL_ALLOWABLE_INITIAL_CAPACITY = INT_MAX;
//*****************************************************************************
template<class ElementType>
bool ArrayValidator::areValidValuesOfElements(
	const ElementType * const researchValuesOfElements) const
{
	return researchValuesOfElements;
}
//*****************************************************************************
bool ArrayValidator::isValidAmountOfElements(const int researchAmountOfElements) const
{
	return ArrayValidator::MINIMAL_ALLOWABLE_AMOUNT_OF_ELEMENTS <= researchAmountOfElements
		&& researchAmountOfElements <= ArrayValidator::MAXIMAL_ALLOWABLE_AMOUNT_OF_ELEMENTS;
}
//*****************************************************************************
const int ArrayValidator::MINIMAL_ALLOWABLE_AMOUNT_OF_ELEMENTS = 0;
//*****************************************************************************
const int ArrayValidator::MAXIMAL_ALLOWABLE_AMOUNT_OF_ELEMENTS
		= ArrayValidator::MAXIMAL_ALLOWABLE_INITIAL_CAPACITY;
//*****************************************************************************
template<class ElementType>
bool ArrayValidator::isValidMethodOfSortingArray(
	ArraySortingMethod<ElementType> * const researchMethod) const
{
	return researchMethod;
}
//*****************************************************************************
template<class ElementType>
bool ArrayValidator::isValidIndex(const int researchIndex,
	const Array<ElementType> &array) const
{
	return ArrayValidator::MINIMAL_ALLOWABLE_VALUE_OF_INDEX <= researchIndex
		&& researchIndex < array.getAmountOfElements();
}
//*****************************************************************************
const int ArrayValidator::MINIMAL_ALLOWABLE_VALUE_OF_INDEX = 0;
//*****************************************************************************
template<class ElementType>
bool ArrayValidator::isValidIndexToAddElement(const int researchIndex,
	const Array<ElementType> &array) const
{
	return ArrayValidator::MINIMAL_ALLOWABLE_VALUE_OF_INDEX <= researchIndex
		&& researchIndex <= array.getAmountOfElements();
}
//*****************************************************************************

