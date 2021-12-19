// lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "ElementsGenerator.h"
#include "Array.h"
#include "BubbleArraySortingMethod.h"
#include <functional>
#include "MeasurerOfTimeOfExecution.h"
#include "SelectionArraySortingMethod.h"

using namespace std;

int main()
{
	const int minimalBorderOfGeneration = -1000;
	const int maximalBorderOfGeneration = 1000;
	const ElementsGenerator<double> * const elementsGenerator        
		= new ElementsGenerator<double>(minimalBorderOfGeneration, maximalBorderOfGeneration);

	//Quick bubble sort for array with 10000 elements:
	int amountOfElementsOfArray = 10000;
	const double *valuesOfElementsOfArray
		= elementsGenerator->generateElements(amountOfElementsOfArray);
	Array<double> *array = new Array<double>(valuesOfElementsOfArray, amountOfElementsOfArray);        
	delete[] valuesOfElementsOfArray;

	ArraySortingMethod<double> *arraySortingMethod = new BubbleArraySortingMethod<double>();
	array->setArraySortingMethod(arraySortingMethod);

	std::function<void()> *executedFunction = new std::function<void()>([array]()            
	{
		array->sortElements();
	});

	const MeasurerOfTimeOfExecution * const measurerOfTimeOfExecution = new MeasurerOfTimeOfExecution();    
	double amountOfSecondOfExecution = measurerOfTimeOfExecution->mesuareExecutionBySeconds(*executedFunction);

	cout << "Time of execution of quick bubble sorting of array with 10000 elements: " << amountOfSecondOfExecution << "\n";

	delete executedFunction;
	delete array;

	//Quick bubble sort for array with 7500 elements:
	amountOfElementsOfArray = 7500;
	valuesOfElementsOfArray = elementsGenerator->generateElements(amountOfElementsOfArray);       
	array = new Array<double>(valuesOfElementsOfArray, amountOfElementsOfArray);       
	delete[] valuesOfElementsOfArray;

	arraySortingMethod = new BubbleArraySortingMethod<double>();
	array->setArraySortingMethod(arraySortingMethod);

	executedFunction = new std::function<void()>([array]()           
	{
		array->sortElements();
	});

	amountOfSecondOfExecution = measurerOfTimeOfExecution->mesuareExecutionBySeconds(*executedFunction);

	cout << "Time of execution of quick bubble sorting of array with 7500 elements: " << amountOfSecondOfExecution << "\n";

	delete executedFunction;
	delete array;

	//Quick bubble sort for array with 5000 elements:
	amountOfElementsOfArray = 5000;
	valuesOfElementsOfArray = elementsGenerator->generateElements(amountOfElementsOfArray);
	array = new Array<double>(valuesOfElementsOfArray, amountOfElementsOfArray);
	delete[] valuesOfElementsOfArray;

	arraySortingMethod = new BubbleArraySortingMethod<double>();
	array->setArraySortingMethod(arraySortingMethod);

	executedFunction = new std::function<void()>([array]()
	{
		array->sortElements();
	});

	amountOfSecondOfExecution = measurerOfTimeOfExecution->mesuareExecutionBySeconds(*executedFunction);

	cout << "Time of execution of quick bubble sorting of array with 5000 elements: " << amountOfSecondOfExecution << "\n";

	delete executedFunction;
	delete array;

	//Quick bubble sort for array with 2500 elements:
	amountOfElementsOfArray = 2500;
	valuesOfElementsOfArray = elementsGenerator->generateElements(amountOfElementsOfArray);
	array = new Array<double>(valuesOfElementsOfArray, amountOfElementsOfArray);
	delete[] valuesOfElementsOfArray;

	arraySortingMethod = new BubbleArraySortingMethod<double>();
	array->setArraySortingMethod(arraySortingMethod);

	executedFunction = new std::function<void()>([array]()
	{
		array->sortElements();
	});

	amountOfSecondOfExecution = measurerOfTimeOfExecution->mesuareExecutionBySeconds(*executedFunction);

	cout << "Time of execution of quick bubble sorting of array with 2500 elements: " << amountOfSecondOfExecution << "\n";

	delete executedFunction;
	delete array;

	//Quick bubble sort for array with 1000 elements:
	amountOfElementsOfArray = 1000;
	valuesOfElementsOfArray = elementsGenerator->generateElements(amountOfElementsOfArray);
	array = new Array<double>(valuesOfElementsOfArray, amountOfElementsOfArray);
	delete[] valuesOfElementsOfArray;

	arraySortingMethod = new BubbleArraySortingMethod<double>();
	array->setArraySortingMethod(arraySortingMethod);

	executedFunction = new std::function<void()>([array]()
	{
		array->sortElements();
	});

	amountOfSecondOfExecution = measurerOfTimeOfExecution->mesuareExecutionBySeconds(*executedFunction);

	cout << "Time of execution of quick bubble sorting of array with 1000 elements: "
		<< amountOfSecondOfExecution << "\n";

	delete executedFunction;
	delete array;

	cout << "\n===========================================================================\n\n";

	//Selection sort for array with 10000 elements:
	amountOfElementsOfArray = 10000;
	valuesOfElementsOfArray = elementsGenerator->generateElements(amountOfElementsOfArray);
	array = new Array<double>(valuesOfElementsOfArray, amountOfElementsOfArray);
	delete[] valuesOfElementsOfArray;

	arraySortingMethod = new SelectionArraySortingMethod<double>();
	array->setArraySortingMethod(arraySortingMethod);

	executedFunction = new std::function<void()>([array]()
	{
		array->sortElements();
	});

	amountOfSecondOfExecution = measurerOfTimeOfExecution->mesuareExecutionBySeconds(*executedFunction);

	cout << "Time of execution of selection sorting of array with 10000 elements: " 
		<< amountOfSecondOfExecution << "\n";

	delete executedFunction;
	delete array;

	//Selection sort for array with 7500 elements:
	amountOfElementsOfArray = 7500;
	valuesOfElementsOfArray = elementsGenerator->generateElements(amountOfElementsOfArray);
	array = new Array<double>(valuesOfElementsOfArray, amountOfElementsOfArray);
	delete[] valuesOfElementsOfArray;

	arraySortingMethod = new SelectionArraySortingMethod<double>();
	array->setArraySortingMethod(arraySortingMethod);

	executedFunction = new std::function<void()>([array]()
	{
		array->sortElements();
	});

	amountOfSecondOfExecution = measurerOfTimeOfExecution->mesuareExecutionBySeconds(*executedFunction);

	cout << "Time of execution of selection sorting of array with 7500 elements: "
		<< amountOfSecondOfExecution << "\n";

	delete executedFunction;
	delete array;

	//Selection sort for array with 5000 elements:
	amountOfElementsOfArray = 5000;
	valuesOfElementsOfArray = elementsGenerator->generateElements(amountOfElementsOfArray);
	array = new Array<double>(valuesOfElementsOfArray, amountOfElementsOfArray);
	delete[] valuesOfElementsOfArray;

	arraySortingMethod = new SelectionArraySortingMethod<double>();
	array->setArraySortingMethod(arraySortingMethod);

	executedFunction = new std::function<void()>([array]()
	{
		array->sortElements();
	});

	amountOfSecondOfExecution = measurerOfTimeOfExecution->mesuareExecutionBySeconds(*executedFunction);

	cout << "Time of execution of selection sorting of array with 5000 elements: "
		<< amountOfSecondOfExecution << "\n";

	delete executedFunction;
	delete array;

	//Selection sort for array with 2500 elements:
	amountOfElementsOfArray = 2500;
	valuesOfElementsOfArray = elementsGenerator->generateElements(amountOfElementsOfArray);
	array = new Array<double>(valuesOfElementsOfArray, amountOfElementsOfArray);
	delete[] valuesOfElementsOfArray;

	arraySortingMethod = new SelectionArraySortingMethod<double>();
	array->setArraySortingMethod(arraySortingMethod);

	executedFunction = new std::function<void()>([array]()
	{
		array->sortElements();
	});

	amountOfSecondOfExecution = measurerOfTimeOfExecution->mesuareExecutionBySeconds(*executedFunction);

	cout << "Time of execution of selection sorting of array with 2500 elements: "
		<< amountOfSecondOfExecution << "\n";

	delete executedFunction;
	delete array;

	//Selection sort for array with 1000 elements:
	amountOfElementsOfArray = 1000;
	valuesOfElementsOfArray = elementsGenerator->generateElements(amountOfElementsOfArray);
	array = new Array<double>(valuesOfElementsOfArray, amountOfElementsOfArray);
	delete[] valuesOfElementsOfArray;

	arraySortingMethod = new SelectionArraySortingMethod<double>();
	array->setArraySortingMethod(arraySortingMethod);

	executedFunction = new std::function<void()>([array]()
	{
		array->sortElements();
	});

	amountOfSecondOfExecution = measurerOfTimeOfExecution->mesuareExecutionBySeconds(*executedFunction);

	cout << "Time of execution of selection sorting of array with 1000 elements: "
		<< amountOfSecondOfExecution << "\n";

	delete executedFunction;
	delete array;


	delete elementsGenerator;
	delete measurerOfTimeOfExecution;

	system("PAUSE");
    return EXIT_SUCCESS;
}

