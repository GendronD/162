/*****************************************************
* Author: Devin Gendron
* Date: 11/15/17
* Description: Write a void function called repeatArray 
* that takes two parameters - a reference to a pointer to 
* a dynamically allocated array of doubles, and the size 
* of that array.  The pointer is passed by reference 
* because you want to change the value of the pointer.  
* The function should replace the array with one that is 
* twice as large, with the values from the original array 
* appearing twice.  For example, if array that was passed 
* in was {3.1, 4.2, 5.3}, then it should be replaced by 
* {3.1, 4.2, 5.3, 3.1, 4.2, 5.3}.  The function should 
* prevent any memory leaks.  Remember to also prevent 
* memory leaks in the main you use for testing.
*****************************************************/
#include <iostream>

/***********************Personal notes/thoughts**************************
* Write a void function called repeatArray.  Have it take two parameters
* a reference TO A POINTER! and then to a dynamically allocated array of 
* doubles as well as the size.
*
*
* The function (repeatArray) should replace the array with one that is 
* twice as large, with the values from the original array 
* appearing twice. So we must create a double size variable and make it 
* twice as large.  We also need to create a way to read in the array, so
* a for-loop will be setup to do so.  Since we are doubling this array,
* we can nest another for-loop that will initialize a new dynamic array
* (repeatedArr).  To account for the new size in this nested for-loop,
* a counter (repeatArrSizeCounter) will be used to allocate the subscripts.
* This counter will then be incremented for each loop.  While the inner
* loop is running, refArray will input a value to a certain subscript of
* repeatedArr for each pass, thus successfully doubling refArray.
************************************************************************/



/*******************Definition of repeatArray******************/
void repeatArray(double *&refArray, int arraySize)
{

	int doubleSize = arraySize*2;					//Initialize and declare doubleSize for repeatedArr size.
	int repeatArrSizeCounter = 0;					//Sets counter that counts to the size of repeatedArr.
	double* repeatedArr = new double[doubleSize];	//Declares dynamic array for repeated numbers with new size.

	//Nested for-loop allows program to double refArray and initialize it to repeatedArr
	for(int i=0; i < 2; i++)						//Outer loop repeats twice.
	{
		for(int k=0; k < arraySize; k++)			//Inner loop repeats 3 times.
		{
			//Set repeatedArr[] size to constantly updating repeatArrSizeCounter for each subscript.
			//Then set this equal to arrPointer to obtain it's subscript 
			repeatedArr[repeatArrSizeCounter]=refArray[k];	

			repeatArrSizeCounter += 1;				//The repeatArrSizeCounter is incremented to properly
		}											//allocate to repeatedArr.
	}

	delete [] refArray;		//Delete original array from heap.  This prevents a memory leak.

	refArray = NULL;		//Tell program that pointer no longer refers to valid memory location.

	refArray = repeatedArr; //Re-initializes refArray to the doubled version, repeatedArr.

}
/**************************************************************/






/***********************Main Function**************************/
int main()
{
 
	double* myArray = new double[3];

	for (int i=0; i<3; i++)
		myArray[i] = (i+1)*2;

	repeatArray(myArray, 3);

	for (int i=0; i<6; i++)
		std::cout << myArray[i] << std::endl;

	delete [] myArray;

	return 0;
}
/**************************************************************/