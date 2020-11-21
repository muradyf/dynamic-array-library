#pragma once

#include <iostream>

using namespace std;

class DynamicArray
{

private:
	int* arr;
	int size;

public:
	DynamicArray();
	DynamicArray(int* elements, int size);
	void InitializeInt();
	void InitializeRandom(int*& arr, int size);
	void InitializeIntArr(int* arr, int size);
	void Initialize(int* arr, int size);
	void FileInput();
	void UserInput(int size);
	void RegrowArr(int* arr, int size);
	void Ascend();
	void Descend();
	void Copy(const DynamicArray D);
	void SetSize(int size);
	int GetSize();
	void BreakFirstArr(int si, int ei);
	void BreakSecArr(int si);
	void growArrayInt(int* arr, int size);
	void  Reverse();
	void  Reverse(int* arr, int size);
	long int  Reverse(long int num);
	void InitializePtr(int* p, int size);
	bool Equal(const DynamicArray D2);
	int CountOcc(int* arr, int size, int num);
	bool Exist(int num);
	int LeftMostDigit(int num);
	void Swap(int& num1, int& num2);
	void SortAsc();
	void SortDsc();

	//Task 1
	void Leader(const DynamicArray D);
	void FindDistinct(const DynamicArray D);
	void FindUnique(const DynamicArray D);
	void SortEvenIndexDsc(const DynamicArray D);
	void SortOddIndexAsc(const DynamicArray D);
	void SortEvenOddIndex(const DynamicArray D);
	void SortEvenElements(const DynamicArray D);
	void SortOddElements(const DynamicArray D);
	void SortEvenOddElements(const DynamicArray D);
	int FindEquiIndex();
	float Mean(const DynamicArray D);
	float Median(const DynamicArray D);
	void Mode(const DynamicArray D);
	DynamicArray PrimeIndex(const DynamicArray D);

	//Task 2
	void SortEvenOddLeftRight();
	void IntegersToArray(long int num);
	long int ArrayToIntegers();
	void UniqueElements();
	DynamicArray RandomFreq();
	void SortByLeft();
	void MergeArr(int* arr, int size);
	int BinarySearch(int num);
	void FindFreq();
	void FindMax();
	int FindKthElement(int num);
	void Partition();

	//TASK 2 - STUDENT DATA
	void SortIdAsc(DynamicArray ID, DynamicArray Q1, DynamicArray Q2, DynamicArray Q3, DynamicArray AVG);
	void SortIdDsc(DynamicArray ID, DynamicArray Q1, DynamicArray Q2, DynamicArray Q3, DynamicArray AVG);
	void SortAvgAsc(DynamicArray ID, DynamicArray Q1, DynamicArray Q2, DynamicArray Q3, DynamicArray AVG);
	void SortAvgDsc(DynamicArray ID, DynamicArray Q1, DynamicArray Q2, DynamicArray Q3, DynamicArray AVG);

	//TASK 3
	void MergeArr(DynamicArray Arr);
	void SortEvenOddAlt();
	void SortDscFreq();
	void Sort0and1();
	void ReverseSubArray();
	bool FindSumOfTwo(int& num1, int& num2, int sum);
	bool FindSumOfThree(int& num1, int& num2, int& num3,  int sum);
	void FindLeaderSubset(const int ch);
	DynamicArray FindUnionIntersection(DynamicArray arr);
	void FindClosestSum(int& num1, int& num2, int num3);
	void FindClosestElement(int k, int x);
	void FindGreaterHalf();
	int FindSumOfNonPrime();
	void VoteCount(DynamicArray ID, int size);

	void Print();
	void PrintStudent(DynamicArray ID, DynamicArray Q1, DynamicArray Q2, DynamicArray Q3, DynamicArray AVG, int size, int id);
	void PrintStudents(DynamicArray ID, DynamicArray Q1, DynamicArray Q2, DynamicArray Q3, DynamicArray AVG, int size);
	void PrintVoting(DynamicArray ID, char** party, DynamicArray Vote);
	void PrintChart(DynamicArray ID, char** party, DynamicArray Vote);
	~DynamicArray();

};

