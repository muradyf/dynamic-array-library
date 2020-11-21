#include <iostream>
#include <fstream>
#include "DynamicArray.h"
#include "DynamicArrayChar.h"

using namespace std;

void Task1();
void Bonus();
void Task2();
void Students();
void Task3();
void ElectronicVoting();

int main()
{

	//INPUT

	int ch = 0;

	cout << "\nTasks:\n";
	cout << "\n1. Task 1 (Dynamic Integer Array)";
	cout << "\n2. Task 1 - Bonus Question (Remove Vowels)";
	cout << "\n3. Task 2 (ITC Arrays)";
	cout << "\n4. Task 3";
	cout << "\n5. Electronic Voting";

	cout << "\n\nEnter your option: ";
	cin >> ch;

	while (ch > 5)
	{
		cout << "\nOption does not exist!";
		cout << "\n\nEnter your choice: ";
		cin >> ch;
	}

	switch (ch)
	{

	case 1:
		Task1();
		break;

	case 2:
		Bonus();
		break;

	case 3:
		Task2();
		break;
		
	case 4:
		Task3();
		break;

	case 5:
		ElectronicVoting();

	}	

	return 0;

}

void Task1()
{
	system("CLS");

	int ch = '\0';
	int size = 20;

	cout << "\nInput Options:\n";
	cout << "\n1. User Input";
	cout << "\n2. File Input";
	cout << "\n\nDo you want to input the file from user or file? ";
	cin >> ch;

	while (ch > 2)
	{
		cout << "\nOption does not exist!";
		cout << "\n\nEnter your choice: ";
		cin >> ch;
	}

	DynamicArray D;

	switch (ch)
	{
	case 1:
		D.UserInput(size);
		break;

	case 2:
		D.FileInput();
		break;
	}

	system("CLS");

	cout << "Array: ";
	D.Print();

	//MENU (MAIN FUNCTIONS)

	cout << "\n\nMenu:\n";
	cout << "\n1. Find Leader Elements";
	cout << "\n2. Find Distinct Elements";
	cout << "\n3. Find Unique Elements";
	cout << "\n4. Sort Even Indexes (Descending Order)";
	cout << "\n5. Sort Odd Indexes (Ascending Order)";
	cout << "\n6. Sort Even (Descending Order) and Odd Indexes (Ascending Order)";
	cout << "\n7. Sort Even Elements (Descending Order)";
	cout << "\n8. Sort Odd Elements (Ascending Order)";
	cout << "\n9. Sort Even (Descending Order) and Odd Elements (Ascending Order)";
	cout << "\n10. Find Equilibrium Index";
	cout << "\n11. Find Mean, Median and Mode";
	cout << "\n12. Find Distinct, Unique, Leaders and Sort Even and Odd Indexes and Elements (Half-Half)";
	cout << "\n13. Find Unique Prime Indexes";

	ch = 0;

	cout << "\n\nEnter your choice: ";
	cin >> ch;

	while (ch > 13)
	{
		cout << "\nOption does not exist!";
		cout << "\n\nEnter your choice: ";
		cin >> ch;
	}

	int index, si, ei;
	index = si = ei = 0;
	float mean, median;
	mean = median = 0;

	DynamicArray Array, Array1, Array2, Prime;

	switch (ch)
	{
	case 1:
		Array.Leader(D);

		cout << "\nLeader Array: ";
		Array.Print();
		break;

	case 2:
		Array.FindDistinct(D);

		cout << "\nDistinct Array: ";
		Array.Print();
		cout << "\nDistinct Array (Ascending Order): ";
		Array.Ascend();
		Array.Print();
		break;

	case 3:
		Array.FindUnique(D);

		cout << "\nUnique Array: ";
		Array.Print();
		cout << "\nUnique Array (Descending Order): ";
		Array.Descend();
		Array.Print();
		break;

	case 4:
		Array.SortEvenIndexDsc(D);

		cout << "\nSorted Even Indexes (Descending Order): ";
		Array.Print();
		break;

	case 5:
		Array.SortOddIndexAsc(D);

		cout << "\nSorted Odd Indexes (Ascending Order): ";
		Array.Print();
		break;

	case 6:
		Array.SortEvenOddIndex(D);

		cout << "\nSorted Even and Odd Indexes: ";
		Array.Print();
		break;

	case 7:
		Array.SortEvenElements(D);

		cout << "\nSorted Even Elements (Descending Order): ";
		Array.Print();
		break;

	case 8:
		Array.SortOddElements(D);

		cout << "\nSorted Odd Elements (Ascending Order): ";
		Array.Print();
		break;

	case 9:
		Array.SortEvenOddElements(D);

		cout << "\nSorted Odd Elements (Ascending Order): ";
		Array.Print();
		break;

	case 10:
		index = D.FindEquiIndex();

		if (index != -1)
		{
			cout << "\nEquilibrium Index: " << index;
		}
		else
		{
			cout << "\nEquilibrium Index does not exist!";
		}
		break;

	case 11:
		mean = Array.Mean(D);
		cout << "\nMean: " << mean;

		median = Array.Median(D);
		cout << "\nMedian: " << median;

		Array.Mode(D);

		cout << "\nMode(s): ";
		Array.Print();

		break;

	case 12:
		Array1.Copy(D);
		Array2.Copy(D);

		si = 0;
		ei = Array1.GetSize() / 2;

		Array1.BreakFirstArr(si, ei);
		Array2.BreakSecArr(ei);

		Array.FindDistinct(Array1);
		cout << "\nDistinct Elements from First Half of the Array: ";
		Array.Print();

		Array.FindUnique(Array2);
		cout << "Unique Elements from Second Half of the Array: ";
		Array.Print();

		Array.Leader(Array1);
		cout << "\nLeader from First Half of the Array: ";
		Array.Print();

		Array.Leader(Array2);
		cout << "Leader from Second Half of the Array: ";
		Array.Print();

		Array.SortEvenIndexDsc(Array1);
		cout << "\nSorted First Half Even Indexes (Descending Order): ";
		Array.Print();

		Array.SortOddIndexAsc(Array2);
		cout << "Sorted Second Half Odd Indexes (Ascending Order): ";
		Array.Print();

		Array.SortEvenElements(Array1);
		cout << "\nSorted First Half Even Elements (Ascending Order): ";
		Array.Print();

		Array.SortOddElements(Array2);
		cout << "Sorted Second Half Odd Elements (Descending Order): ";
		Array.Print();

		break;

	case 13:
		Prime = Array.PrimeIndex(D);
		cout << "\nPrime Numbers: ";
		Prime.Print();
		cout << "Their Indexes: ";
		Array.Print();

		Array.FindUnique(Prime);
		cout << "\nUnique Prime Numbers: ";
		Array.Print();

		Array.Ascend();
		cout << "Sorted Unique Elements: ";
		Array.Print();

		break;
	}
}

void Bonus()
{
	system("CLS");

	int ch = '\0';
	int size = 50;

	cout << "\nInput Options:\n";
	cout << "\n1. User Input";
	cout << "\n2. File Input";
	cout << "\n\nDo you want to input the file from user or file? ";
	cin >> ch;

	while (ch > 2)
	{
		cout << "\nOption does not exist!";
		cout << "\n\nEnter your choice: ";
		cin >> ch;
	}

	DynamicArrayChar D;

	switch (ch)
	{
	case 1:
		D.UserInput(size);
		break;

	case 2:
		D.FileInput();
		break;
	}

	system("CLS");

	cout << "Text: ";
	D.Print();

	cout << "\nMenu:\n";
	cout << "\n1. Remove vowels (In One Loop)\n";
	cout << "\n2. Remove vowels (Nested Loop)\n";

	ch = 0;

	cout << "\nEnter your option: ";
	cin >> ch;

	while (ch > 2)
	{
		cout << "\nOption does not exist!";
		cout << "\n\nEnter your choice: ";
		cin >> ch;
	}

	switch (ch)
	{
	case 1:
		D.RemoveVowels();
		cout << "\nText: ";
		D.Print();

	case 2: 
		D.RemoveVowelsNested();
		cout << "\nText: ";
		D.Print();
	}

	
	

}

void Task2()
{

	system("CLS");

	int ch = '\0';
	int size = 20;

	cout << "\nInput Options:\n";
	cout << "\n1. User Input";
	cout << "\n2. File Input";
	cout << "\n\nDo you want to input the file from user or file? ";
	cin >> ch;

	while (ch > 2)
	{
		cout << "\nOption does not exist!";
		cout << "\n\nEnter your choice: ";
		cin >> ch;
	}

	DynamicArray D;

	switch (ch)
	{
	case 1:
		D.UserInput(size);
		break;

	case 2:
		D.FileInput();
		break;
	}

	system("CLS");

	cout << "Array: ";
	D.Print();

	//MENU (MAIN FUNCTIONS)

	cout << "\n\nMenu:\n";
	cout << "\n1. Sort Array (Even and Odd)";
	cout << "\n2. Convert Integers to Array";
	cout << "\n3. Convert Array to Integers";
	cout << "\n4. Store Unique Elements";
	cout << "\n5. Check Frequency of Random Array";
	cout << "\n6. Sort by Left Most Digits";
	cout << "\n7. Merge Sorted Arrays";
	cout << "\n8. Binary Search";
	cout << "\n9. Count Frequency of Elements";
	cout << "\n10. Find Max, Second Max, Min, Second Min and kth Element";
	cout << "\n11. Partition Array";
	cout << "\n12. Student ID - Marks";
	

	ch = 0;

	cout << "\n\nEnter your choice: ";
	cin >> ch;

	while (ch > 12)
	{
		cout << "\nOption does not exist!";
		cout << "\n\nEnter your choice: ";
		cin >> ch;
	}

	int* unique = new int[10];
	int* arr = nullptr;
	long int num = 0;
	long int num1 = 0;
	int index = 0;
	DynamicArray D2;

	switch (ch)
	{
	case 1:
		D.SortEvenOddLeftRight();
		D.Print();
		break;

	case 2:
		num = 0;
		cout << "\nEnter the integer: ";
		cin >> num;

		cout << "\nArray: ";
		D.IntegersToArray(num);
		D.Print();

		D2.Copy(D);

		cout << "\nArray (Reversed): ";
		D2.Reverse();
		D2.Print();

		if (D.Equal(D2))
			cout << "\nThe arrays are Palindrome!";
		else
			cout << "\nThe arrays are not Palindrome!";

		break;

	case 3:
		num = 0;
		num = D.ArrayToIntegers();

		cout << "\nInteger: " << num;

		num1 = D.Reverse(num);
		cout << "\nInteger (Reversed): " << num1;

		if (num == num1)
			cout << "\nThe number is Palindrome!";
		else
			cout << "\nThe number is not Palindrome!";
		break;

	case 4:
		D.UniqueElements();

		cout << "\nUnique Elements: ";
		D.Print();
		break;

	case 5:
		D2 = D.RandomFreq();

		cout << "\nData: ";
		D2.Print();

		cout << "\nData & Frequency: ";
		D.Print();
		break;

	case 6:
		D.SortByLeft();

		cout << "\nSorted Array: ";
		D.Print();

	case 7:
		arr = new int[20];

		cout << "\nEnter the sorted array to merge: ";
		
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
			
			if (arr[i] == -99)
			{
				arr[i] = '\0';
				size = i + 1;
				break;
			}
		}

		D.MergeArr(arr, size);

		D.SortAsc();

		cout << "\nMerged Array: ";
		D.Print();

		break;

	case 8:
		ch = 0;

		cout << "\nEnter the number to search: ";
		cin >> ch;

		index = 0;

		index = D.BinarySearch(ch);

		if (index == -1)
			cout << "\nNumber not Found!";
		else
			cout << "\nThe number " << ch << " was found at index " << index;
		break;

	case 9:
		D.FindFreq();

		cout << "\nArray: ";
		D.Print();
		break;

	case 10:
		D.FindMax();

		ch = 0;

		cout << "\nEnter the smallest kth element: ";
		cin >> ch;

		index = 0;

		index = D.FindKthElement(ch);

		cout << "\nThe smallest " << ch << "th element: " << index;
		break;

	case 11:
		ch = 0;

		cout << "\nWhat element do you want to partition at? ";
		cin >> ch;

		D.Partition();

		cout << "\nPartitioned Array: ";
		D.Print();
		break;

	case 12:
		Students();

	}
}

void Task3()
{

	system("CLS");

	int ch = '\0';
	int size = 20;

	cout << "\nInput Options:\n";
	cout << "\n1. User Input";
	cout << "\n2. File Input";
	cout << "\n\nDo you want to input the file from user or file? ";
	cin >> ch;

	while (ch > 2)
	{
		cout << "\nOption does not exist!";
		cout << "\n\nEnter your choice: ";
		cin >> ch;
	}

	DynamicArray D;

	switch (ch)
	{
	case 1:
		D.UserInput(size);
		break;

	case 2:
		D.FileInput();
		break;
	}

	system("CLS");

	cout << "Array: ";
	D.Print();

	//MENU (MAIN FUNCTIONS)

	cout << "\n\nMenu:\n";
	cout << "\n1. Merge Arrays (Ascending)";
	cout << "\n2. Merge Arrays (Descending)";
	cout << "\n3. Sort Even and Odd Elements (Descending -> Ascending)";
	cout << "\n4. Sort by Frequency (Descending)";
	cout << "\n5. Sort 0's and 1's";
	cout << "\n6. Sort Reversed Sub-Array";
	cout << "\n7. Find if Two Elements have Sum Equal to Given Value";
	cout << "\n8. Find if Three Elements have Sum Equal to Given Value";
	cout << "\n9. Find Leader in Subset";
	cout << "\n10. Find Union and Intersection";
	cout << "\n11. Print Closest Elements to Sum";
	cout << "\n12. Find Closest Elements to X";
	cout << "\n13. Find Greater Half Elements";
	cout << "\n14. Sum of Non-Prime Elements";

	ch = 0;

	cout << "\n\nEnter your choice: ";
	cin >> ch;

	DynamicArray arr1, arr2, arr3;
	int* arr = new int[size];
	int num1, num2, num3;
	num1 = num2 = num3 = 0;

	while (ch > 14)
	{
		cout << "\nOption does not exist!";
		cout << "\n\nEnter your choice: ";
		cin >> ch;
	}

	switch (ch)
	{
	case 1:
		cout << "\nEnter elements of Array 1: ";
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];

			if (arr[i] == -99)
			{
				size = i;
				arr[i] = '\0';
			}
		}

		arr1.Initialize(arr, size);

		for (int i = 0; i < size; i++)
			arr[i] = '\0';

		size = 20;

		cout << "\nEnter elements of Array 2: ";
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];

			if (arr[i] == -99)
			{
				size = i;
				arr[i] = '\0';
			}
		}

		arr2.Initialize(arr, size);

		for (int i = 0; i < size; i++)
			arr[i] = '\0';

		size = 20;

		cout << "\nEnter elements of Array 3: ";
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];

			if (arr[i] == -99)
			{
				size = i;
				arr[i] = '\0';
			}
		}

		arr3.Initialize(arr, size);

		arr1.MergeArr(arr2);
		arr1.MergeArr(arr3);

		arr1.SortAsc();

		cout << "\nMerged Arrays (Ascending): ";
		arr1.Print();

		break;

	case 2:

		cout << "\nEnter elements of Array 1: ";
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];

			if (arr[i] == -99)
			{
				size = i;
				arr[i] = '\0';
			}
		}

		arr1.Initialize(arr, size);

		for (int i = 0; i < size; i++)
			arr[i] = '\0';

		size = 20;

		cout << "\nEnter elements of Array 2: ";
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];

			if (arr[i] == -99)
			{
				size = i;
				arr[i] = '\0';
			}
		}

		arr2.Initialize(arr, size);

		for (int i = 0; i < size; i++)
			arr[i] = '\0';

		size = 20;

		cout << "\nEnter elements of Array 3: ";
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];

			if (arr[i] == -99)
			{
				size = i;
				arr[i] = '\0';
			}
		}

		arr3.Initialize(arr, size);

		arr1.MergeArr(arr2);
		arr1.MergeArr(arr3);

		arr1.SortDsc();

		cout << "\nMerged Arrays (Descending): ";
		arr1.Print();

		break;

	case 3:
		D.SortEvenOddAlt();

		cout << "\nSorted Array: ";
		D.Print();
		break;

	case 4:
		D.SortDscFreq();

		cout << "\nArray: ";
		D.Print();
		break;

	case 5:
		D.Sort0and1();

		cout << "\nSorted Array: ";
		D.Print();
		break;

	case 6:
		D.ReverseSubArray();

		cout << "\nArray: ";
		D.Print();
		break;

	case 7:
		ch = 0;

		cout << "\nEnter the sum: ";
		cin >> ch;

		if(D.FindSumOfTwo(num1, num2, ch))
			cout << "\nThe sum of " << num1 << " and " << num2 << " is: " << ch;
		else
			cout << "\nThere does not exist any two numbers whose sum is " << ch;

	case 8:
		ch = 0;

		cout << "\nEnter the sum: ";
		cin >> ch;

		if (D.FindSumOfThree(num1, num2, num3, ch))
			cout << "\nThe sum of " << num1 << ", " << num2 << " and " << num3 << " is: " << ch;
		else
			cout << "\nThere does not exist any three numbers whose sum is " << ch;

	case 9: 
		ch = 0;

		cout << "\nEnter the parameter: ";
		cin >> ch;

		D.FindLeaderSubset(ch);

		cout << "\nLeaders: ";
		D.Print();
		break;

	case 10:
		cout << "\nEnter elements of Array 2: ";
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];

			if (arr[i] == -99)
			{
				size = i;
				arr[i] = '\0';
			}
		}

		arr1.Initialize(arr, size);

		arr2 = D.FindUnionIntersection(arr1);

		cout << "\nUnion: ";
		arr2.Print();
		cout << "\nIntersection: ";
		D.Print();
		break;

	case 11:
		num1 = num2 = num3 = 0;

		D.FindClosestSum(num1, num2, num3);

		cout << "\nThe sum of " << num1 << " and " << num2 << " is closest to 0: ";
		break;

	case 12:
		ch = 0;

		cout << "\nEnter the number of Elements to find: ";
		cin >> ch;

		num1 = 0;

		cout << "\nEnter the value of X: ";
		cin >> num1;

		cout << "\nElements closest to X: ";
		D.FindClosestElement(ch, num1);

		break;

	case 13:
		cout << "\nArray: ";
		D.FindGreaterHalf();

		break;

	case 14:
		ch = 0;
		ch = D.FindSumOfNonPrime();

		cout << "\nThe sum is: " << ch;
		break;

	}

}

void Students()
{

	system("CLS");

	int size = 0;

	ifstream fin;
	fin.open("students.txt");
	fin >> size;

	int* id = new int[size];
	int* q1 = new int[size];
	int* q2 = new int[size];
	int* q3 = new int[size];
	int* avg = new int[size];

	for (int i = 0; i < size; i++)
	{
		fin >> id[i] >> q1[i] >> q2[i] >> q3[i] >> avg[i];
	}

	DynamicArray ID(id, size);
	DynamicArray Q1(q1, size);
	DynamicArray Q2(q2, size);
	DynamicArray Q3(q3, size);
	DynamicArray AVG(avg, size);
	DynamicArray P;

	system("CLS");

	P.PrintStudents(ID, Q1, Q2, Q3, AVG, size);

	//MENU (MAIN FUNCTIONS)

	cout << "\n\nMenu:\n";
	cout << "\n1. Sort by ID (Ascending)";
	cout << "\n2. Sort by ID (Descending)";
	cout << "\n3. Sort by Average (Ascending)";
	cout << "\n4. Sort by Average (Descending)";
	cout << "\n5. Print Student Data";


	int ch = 0;

	cout << "\n\nEnter your choice: ";
	cin >> ch;

	while (ch > 5)
	{
		cout << "\nOption does not exist!";
		cout << "\n\nEnter your choice: ";
		cin >> ch;
	}

	switch (ch)
	{

	case 1:
		P.SortIdAsc(ID, Q1, Q2, Q3, AVG);
		
		cout << "\nSorted Data by ID (Ascending):\n\n";
		P.PrintStudents(ID, Q1, Q2, Q3, AVG, size);
		break;

	case 2:
		P.SortIdDsc(ID, Q1, Q2, Q3, AVG);

		cout << "\nSorted Data by ID (Descending):\n\n";
		P.PrintStudents(ID, Q1, Q2, Q3, AVG, size);
		break;

	case 3:
		P.SortAvgAsc(ID, Q1, Q2, Q3, AVG);

		cout << "\nSorted Data by Average (Ascending):\n\n";
		P.PrintStudents(ID, Q1, Q2, Q3, AVG, size);
		break;

	case 4:
		P.SortAvgDsc(ID, Q1, Q2, Q3, AVG);

		cout << "\nSorted Data by Average (Descending):\n\n";
		P.PrintStudents(ID, Q1, Q2, Q3, AVG, size);
		break;

	case 5:
		ch = 0;

		cout << "\nWhich Student's data do you want to print? ";
		cin >> ch;

		P.PrintStudent(ID, Q1, Q2, Q3, AVG, size, ch);
		break;
	}

}

void ElectronicVoting()
{

	system("CLS");

	int parties = 0;
	int votes = 0;	

	ifstream fin;
	fin.open("votes.txt");

	fin >> parties;

	int* id = new int[parties];
	char** party = new char*[parties];

	for (int i = 0; i < parties; i++)
		party[i] = new char[10];

	for (int i = 0; i < parties; i++)
	{
		fin >> id[i];
		fin.getline (party[i], 9);
	}

	DynamicArray ID(id, parties);

	fin >> votes;

	int* vote = new int[votes];

	for (int i = 0; i < votes; i++)
	{
		fin >> vote[i];
	}

	DynamicArray Vote(vote, votes);

	Vote.VoteCount(ID, parties);

	ID.PrintVoting(ID, party, Vote);

	ID.PrintChart(ID, party, Vote);

}