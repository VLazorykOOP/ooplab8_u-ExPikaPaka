#include <iostream>
#include <Windows.h>
#include "Array.h"
#include "BinaryTree.h"



template<typename T>
int sequentialSearch(T arr[], int size, T key) {
	int lastIndex = -1;
	for (int i = 0; i < size; i++) {
		if (arr[i] == key) lastIndex = i;
	}
	return lastIndex;
}

template<>
int sequentialSearch<char*>(char* arr[], int size, char* key) {
	int lastIndex = -1;
	for (int i = 0; i < size; i++) {
		if (!strcmp(arr[i], key)) lastIndex = i;
	}
	return lastIndex;
}



void test1() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 2, 2, 3, 1, 3, 5 };

	std::cout << "The array is: \n";
	for (int i : arr) {
		std::cout << arr[i] << " ";
	}

	std::cout << "\n\n";

	for (int i = -2; i < 10; i++) {
		std::cout << "The last index of number [" << i << "] is " << sequentialSearch(arr, sizeof(arr) / sizeof(arr[0]), i) << '\n';
	}
	std::cout << "\n\n\n\n\n";









	char* words[] = { (char*)"Meat", (char*)"banana", (char*)"juice", (char*)"Nighmare", (char*)"one"};
	
	std::cout << "The array of words is:\n";
	for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++) {
		std::cout << "[" << i << "] " << words[i] << '\n';
	}
	std::cout << "\n";
	
	char *keyWord = (char*)"juice";
	std::cout << "The index of word [" << keyWord << "] is " << sequentialSearch(words, (int)(sizeof(words) / sizeof(words[0])), keyWord) << '\n';
	std::cout << "The index of word [" << "WillBe(-1)" << "] is " << sequentialSearch(words, (int)(sizeof(words) / sizeof(words[0])), (char*)"WillBe(-1)") << '\n';
}














template<typename T>
void qsort(T arr[], int size) {
	T lPivot = arr[size - 1];
	int lIndexOfLargestElement = 0;
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] < lPivot) {
			// Swap largest element with this
			std::swap(arr[i], arr[lIndexOfLargestElement]);
			lIndexOfLargestElement++;
		}
	}

	// swap pivot with xArray[lIndexOfLargestElement]
	std::swap(arr[lIndexOfLargestElement], arr[size - 1]);
	if (lIndexOfLargestElement > 1)
		qsort(arr, lIndexOfLargestElement);
	if (size - lIndexOfLargestElement - 1 > 1)
		qsort(arr + lIndexOfLargestElement + 1, size - lIndexOfLargestElement - 1);
}


template<>
void qsort(char* arr[], int size) {
	char* lPivot = arr[size - 1];
	int lIndexOfLargestElement = 0;
	for (int i = 0; i < size - 1; i++) {
		if (strlen(arr[i]) < strlen(lPivot)) {
			// Swap largest element with this
			std::swap(arr[i], arr[lIndexOfLargestElement]);
			lIndexOfLargestElement++;
		}
	}

	// swap pivot with xArray[lIndexOfLargestElement]
	std::swap(arr[lIndexOfLargestElement], arr[size - 1]);
	if (lIndexOfLargestElement > 1)
		qsort(arr, lIndexOfLargestElement);
	if (size - lIndexOfLargestElement - 1 > 1)
		qsort(arr + lIndexOfLargestElement + 1, size - lIndexOfLargestElement - 1);
}


void test2() {
	// Number sort
	std::cout << "Sorting numbers:\n";
	int intArr[] = { 5, 2, 8, 1, 3 };
	int intSize = sizeof(intArr) / sizeof(intArr[0]);

	std::cout << "Before sorting: ";
	for (int i = 0; i < intSize; i++) {
		std::cout << intArr[i] << " ";
	}
	std::cout << "\n";


	std::cout << "After sorting: ";
	qsort(intArr, intSize);
	for (int i = 0; i < intSize; i++) {
		std::cout << intArr[i] << " ";
	}
	std::cout << "\n\n";



	// Strings sort
	std::cout << "Sorting strings (by length):\n";
	char* strArr[] = { (char*)"22", (char*)"1", (char*)"7777777", (char*)"333", (char*)"4444", (char*)"22" };
	int strSize = sizeof(strArr) / sizeof(strArr[0]);

	std::cout << "Before sorting: ";
	for (int i = 0; i < strSize; i++) {
		std::cout << strArr[i] << " ";
	}
	std::cout << "\n";


	std::cout << "After sorting: ";
	qsort(strArr, strSize);
	for (int i = 0; i < strSize; i++) {
		std::cout << strArr[i] << " ";
	}
	std::cout << "\n";
}






void test3() {
	Array<int> ar1(3);

	std::cout << "Array size :" << ar1.getSize() << "\n";
	std::cout << "Array length : " << ar1.getLength() << "\n";

	std::cout << "*Appending values*\n";
	for (int i = 13; i > 0; i--) {
		ar1.append(i);
	}

	std::cout << "Array size :" << ar1.getSize() << "\n";
	std::cout << "Array length : " << ar1.getLength() << "\n\n";

	std::cout << "Array values: \n[" << ar1.get(0);
	for (int i = 1; i < ar1.getLength(); i++) {
		std::cout << ", " << ar1.get(i);
	}
	std::cout << "]\n\n\n";



	std::cout << "Deleting value from index 5, and output via [] overload:\n";
	ar1.remove(5);
	std::cout << "Array values: \n[" << ar1.get(0);
	for (int i = 1; i < ar1.getLength(); i++) {
		std::cout << ", " << ar1[i];
	}
	std::cout << "]\n\n\n";


	std::cout << "Inserting value 256 twice on index 8:\n";
	ar1.insert(256, 8);
	ar1.insert(256, 8);
	std::cout << "Array values: \n[" << ar1.get(0);
	for (int i = 1; i < ar1.getLength(); i++) {
		std::cout << ", " << ar1.get(i);
	}
	std::cout << "]\n\n\n";


	std::cout << "Clearing the array, and output via [] overload:\n";
	ar1.clear();
	std::cout << "Array values: \n[" << ar1.get(0);
	for (int i = 1; i < ar1.getLength(); i++) {
		std::cout << ", " << ar1[i];
	}
	std::cout << "]\n\n\n";
}



void test4() {
	BinaryTree<int> tree;
	tree.insert(5);	//				 5				//
	tree.insert(3);	//             /    \			//
	tree.insert(7);	//            /      \			//
	tree.insert(1); //			 /		  \			//
	tree.insert(4); //		    3		   7		//
	tree.insert(6); //		 /	   \     /    \		//
	tree.insert(8); //		1       4	6       8	//
	
	
	for (BinaryTree<int>::Iterator it = tree.begin(); it != tree.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << '\n';
}


int main() {
	std::string choice;

	while (choice != "5") {
		std::cout << "Input task number (1-4) (5 to exit): ";
		std::cin >> choice;

		if (choice == "1") {
			system("cls");
			test1();
		}
		if (choice == "2") {
			system("cls");
			test2();
		}
		if (choice == "3") {
			system("cls");
			test3();
		}
		if (choice == "4") {
			system("cls");
			test4();
		}
	}
}