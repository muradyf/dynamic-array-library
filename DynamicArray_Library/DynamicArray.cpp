#include "DynamicArray.h"
#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include<time.h> 

using namespace std;

//TASK 1

DynamicArray::DynamicArray()
{
	
	this->size = 1;
	this->arr = nullptr;

}

DynamicArray::DynamicArray(int* elements, int size)
{

	this->size = size;
	this->arr = new int[this->size];

	for (int i = 0; i < this->size; i++)
		this->arr[i] = elements[i];

}

void DynamicArray::InitializeInt()
{

	this->arr = new int[this->size];

	for (int i = 0; i < size; i++)
		this->arr[i] = 0;

	this->arr[size] = '\0';

}

void DynamicArray::InitializeIntArr(int* arr, int size)
{

	arr = new int[size];

	for (int i = 0; i < size; i++)
		arr[i] = 0;

	arr[size] = '\0';

}

void DynamicArray::Initialize(int* arr, int size)
{

	this->size = size;
	this->arr = new int[this->size];

	for (int i = 0; i < this->size; i++)
		this->arr[i] = arr[i];

	arr[size] = '\0';

}

void DynamicArray::FileInput()
{

	ifstream fin;
	fin.open("file.txt");

	int size = 0;
	int num = 0;

	if (!fin.is_open())
		cout << "\nFile does not exist!";
	else
		fin >> size;

	this->size = size;
	this->arr = new int[size];
	InitializeInt();

	for (int i = 0; i < size; i++)
	{
		fin >> num;
		this->arr[i] = num;
	}

	fin.close();

}

void DynamicArray::UserInput(int size)
{

	this->size = size;
	InitializeInt();

	int count = 0;

	cout << "\nEnter the elements for the array (max: 20 elements): ";
	for (int i = 0; i < size; i++)
	{
		cin >> this->arr[i];
		count++;

		if (this->arr[i] == -99)
		{
			this->arr[i] = '\0';
			count--;
			this->size = count;
			break;
		}

	}

}

void DynamicArray::RegrowArr(int* arr, int size)
{

	int *temp = nullptr;

	temp = arr;

	arr = new int[size];

	for (int i = 0; i < size - 1; i++)
		arr[i] = temp[i];

}

void DynamicArray::Leader(const DynamicArray D)
{

	this->arr = nullptr;
	this->size = 2;
	InitializeInt();

	int k = 0;
	bool flag = 0;

	for (int i = 0; i < D.size; i++)
	{

		flag = 0;

		for (int j = i + 1; j < D.size; j++)
		{
			if (D.arr[i] < D.arr[j] && i != j)
			{
				flag = 1;
				break;
			}

		}

		if (flag == 0)
		{
			if (k > 2)
			{
				this->size++;
				RegrowArr(this->arr, this->size);
			}
			this->arr[k] = D.arr[i];
			k++;
		}
	}

	this->size = k;

}

void DynamicArray::FindDistinct(const DynamicArray D)
{

	this->size = 1;
	this->arr = new int[this->size];
	InitializeInt();

	int k = 0;
	bool flag = 0;

	for (int i = 0; i < D.size; i++)
	{

		flag = 0;

		for (int j = 0; j < D.size; j++)
		{
			if (D.arr[i] == D.arr[j] && i != j)
			{
				flag = 1;
				break;
			}
		}

		if (flag == 0)
		{
			this->size++;
			RegrowArr(this->arr, this->size);
			this->arr[k] = D.arr[i];
			k++;
		}

	}

	this->size = k;

}

void DynamicArray::FindUnique(const DynamicArray D)
{

	this->size = 1;
	this->arr = new int[this->size];
	InitializeInt();

	int k = 0;
	bool flag = 0;

	for (int i = 0; i < D.size; i++)
	{

		flag = 0;

		for (int j = 0; j < this->size; j++)
		{
			if (D.arr[i] == this->arr[j])
			{
				flag = 1;
				break;
			}
		}

		if (flag == 0)
		{
			this->size++;
			RegrowArr(this->arr, this->size);
			this->arr[k] = D.arr[i];
			k++;
		}

	}

	this->size = k;

}

void DynamicArray::Ascend()
{

	int temp = 0;

	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			if (this->arr[i] < this->arr[j])
			{
				temp = this->arr[i];
				this->arr[i] = this->arr[j];
				this->arr[j] = temp;
			}
		}
	}

}

void DynamicArray::Descend()
{

	int temp = 0;

	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			if (this->arr[i] > this->arr[j])
			{
				temp = this->arr[i];
				this->arr[i] = this->arr[j];
				this->arr[j] = temp;
			}
		}
	}

}

void DynamicArray::Copy(const DynamicArray D)
{

	this->size = D.size;
	InitializeInt();

	for (int i = 0; i < this->size; i++)
		this->arr[i] = D.arr[i];

}

void DynamicArray::SortEvenIndexDsc(const DynamicArray D)
{

	this->size = D.size;
	InitializeInt();

	Copy(D);

	int temp = 0;

	for (int i = 0; i < this->size; i+=2)
	{
		for (int j = 0; j < this->size; j+=2)
		{
			if (this->arr[i] > this->arr[j])
			{
				temp = this->arr[i];
				this->arr[i] = this->arr[j];
				this->arr[j] = temp;
			}
		}
	}

}

void DynamicArray::SortOddIndexAsc(const DynamicArray D)
{

	this->size = D.size;
	InitializeInt();

	Copy(D);

	int temp = 0;

	for (int i = 1; i < this->size; i += 2)
	{
		for (int j = 1; j < this->size; j += 2)
		{
			if (this->arr[i] < this->arr[j])
			{
				temp = this->arr[i];
				this->arr[i] = this->arr[j];
				this->arr[j] = temp;
			}
		}
	}

}

void DynamicArray::SortEvenOddIndex(const DynamicArray D)
{

	this->size = D.size;
	InitializeInt();

	Copy(D);

	int temp = 0;

	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			if (i % 2 == 0 && j % 2 == 0)
			{
				if (this->arr[i] > this->arr[j])
				{
					temp = this->arr[i];
					this->arr[i] = this->arr[j];
					this->arr[j] = temp;
				}
			}
			else if (i % 2 != 0 && j % 2 != 0)
			{
				if (this->arr[i] < this->arr[j])
				{
					temp = this->arr[i];
					this->arr[i] = this->arr[j];
					this->arr[j] = temp;
				}
			}
		}
	}

}

void DynamicArray::SortEvenElements(const DynamicArray D)
{

	this->size = D.size;
	InitializeInt();

	Copy(D);

	int temp = 0;

	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			if (this->arr[i] % 2 == 0 && this->arr[j] % 2 == 0)
			{
				if (this->arr[i] > this->arr[j])
				{
					temp = this->arr[i];
					this->arr[i] = this->arr[j];
					this->arr[j] = temp;
				}
			}
		}
	}

}

void DynamicArray::SortOddElements(const DynamicArray D)
{

	this->size = D.size;
	InitializeInt();

	Copy(D);

	int temp = 0;

	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			if (this->arr[i] % 2 != 0 && this->arr[j] % 2 != 0)
			{
				if (this->arr[i] < this->arr[j])
				{
					temp = this->arr[i];
					this->arr[i] = this->arr[j];
					this->arr[j] = temp;
				}
			}
		}
	}

}

void DynamicArray::SortEvenOddElements(const DynamicArray D)
{

	this->size = D.size;
	InitializeInt();

	Copy(D);

	int temp = 0;

	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			if (this->arr[i] % 2 == 0 && this->arr[j] % 2 == 0)
			{
				if (this->arr[i] > this->arr[j])
				{
					temp = this->arr[i];
					this->arr[i] = this->arr[j];
					this->arr[j] = temp;
				}
			}
			else if (this->arr[i] % 2 != 0 && this->arr[j] % 2 != 0)
			{
				if (this->arr[i] < this->arr[j])
				{
					temp = this->arr[i];
					this->arr[i] = this->arr[j];
					this->arr[j] = temp;
				}
			}
		}
	}

}

int DynamicArray::FindEquiIndex()
{

	int i = 0;
	int j = 0;
	int leftSum = 0;
	int rightSum = 0;

	for (i = 0; i < this->size; ++i)
	{

		leftSum = 0;
		for (j = 0; j < i; j++)
			leftSum += this->arr[j];

		rightSum = 0;
		for (j = i + 1; j < this->size; j++)
			rightSum += this->arr[j];

		if (leftSum == rightSum)
			return i;
	}

	return -1;

}

float DynamicArray::Mean(const DynamicArray D)
{

	this->size = D.size;
	InitializeInt();

	Copy(D);

	float mean = 0;

	for (int i = 0; i < this->size; i++)
		mean += this->arr[i];

	return mean /= this->size;

}

float DynamicArray::Median(const DynamicArray D)
{

	this->size = D.size;
	InitializeInt();

	Copy(D);

	this->Ascend();

	if (this->size % 2 != 0)
		return this->arr[this->size / 2];
	else
		return (this->arr[(this->size - 1) / 2] + this->arr[this->size / 2])/2.0;

}

void DynamicArray::Mode(const DynamicArray D)
{

	DynamicArray temp;

	temp.size = D.size;
	temp.arr = new int[temp.size];
	InitializeIntArr(temp.arr, D.size);

	temp.Copy(D);
	temp.Ascend();

	this->size = 1;
	InitializeInt();

	int count, mostOccured, j;
	count = mostOccured = j = 0;

	for (int i = 0; i < temp.size; i++)
	{
		if (temp.arr[i] == temp.arr[i + 1])
			count++;

		else
		{
			if (count > mostOccured)
			{
				this->size = 1;
				InitializeInt();
				mostOccured = count;
				this->arr[0] = temp.arr[i];
			}
			else if (count == mostOccured)
			{
				j++;
				mostOccured = count;
				this->arr[j] = temp.arr[i];
				RegrowArr(this->arr, this->size);
				size++;
			}
			count = 0;
		}
	}

	this->arr[this->size] = '\0';

}

void DynamicArray::SetSize(int size)
{

	this->size = size;

}

int DynamicArray::GetSize()
{

	return this->size;

}

void DynamicArray::BreakFirstArr(int si, int ei)
{

	this->size /= 2;

}

void DynamicArray::BreakSecArr(int si)
{

	int* temp = new int[this->size / 2];

	int j = 0;

	for (int i = si; i < this->size; i++)
	{
		temp[j] = this->arr[i];
		j++;
	}

	this->size /= 2;

	for (int i = 0; i < this->size; i++)
		this->arr[i] = temp[i];

}

DynamicArray DynamicArray::PrimeIndex(const DynamicArray D)
{

	DynamicArray temp;

	temp.size = D.size;
	temp.arr = new int[temp.size];
	InitializeIntArr(temp.arr, D.size);

	temp.Copy(D);

	DynamicArray Prime;

	Prime.size = 1;
	Prime.arr = new int[Prime.size];
	InitializeIntArr(Prime.arr, Prime.size);


	bool flag = 0;
	int j = 0;

	this->size = 1;
	InitializeInt();

	for (int i = 0; i < temp.size; i++)
	{
		flag = 0;
		for (int j = 2; j < temp.arr[i]; j++)
		{
			if (temp.arr[i] % j == 0)
			{
				flag = 1;
				break;
			}
		}

		if (!flag)
		{
			this->arr[j] = i;
			Prime.arr[j] = temp.arr[i];
			RegrowArr(Prime.arr, Prime.size);
			RegrowArr(this->arr, this->size);
			Prime.size++;
			this->size++;
			j++;
		}

	}

	Prime.size--;
	this->size--;
	this->arr[this->size] = '\0';
	return Prime;

}


//TASK 2

void DynamicArray::SortEvenOddLeftRight()
{

	int k = 0;
	int temp = 0;

	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{

			if (this->arr[i] % 2 == 0 && i != k)
			{
				temp = this->arr[k];
				this->arr[k] = this->arr[i];
				this->arr[i] = temp;
				k++;
			}

		}
	}

}

void DynamicArray::InitializePtr(int* p, int size)
{

	for (int i = 0; i < size; i++)
	{
		p[i] = 0;
	}

	p[size] = '\0';

}

void  DynamicArray::Reverse()
{

	int tempSize = this->size;
	int* temp = new int[tempSize];

	InitializeIntArr(temp, tempSize);

	for (int i = 0; i < this->size; i++)
	{
		temp[i] = this->arr[this->size - i - 1];
	}

	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = temp[i];
	}

}

void  DynamicArray::Reverse(int* arr, int size)
{

	int tempSize = size;
	int* temp = new int[tempSize];

	int j = size - 1;

	InitializeIntArr(temp, tempSize);

	for (int i = 0; i < size; i++)
	{
		temp[j] = arr[i];
		j--;
	}

	for (int i = 0; i < size; i++)
	{
		arr[i] = temp[i];
	}

}

long int DynamicArray::Reverse(long int num)
{

	DynamicArray temp;

	temp.size = 1;
	temp.arr = new int[temp.size];
	InitializeIntArr(temp.arr, temp.size);

	int rem = 0;

	while (num != 0)
	{
		rem = num % 10;
		temp.arr[temp.size - 1] = rem;
		temp.size++;
		RegrowArr(temp.arr, temp.size);
		num = num / 10;
	}

	temp.size--;
	temp.arr[temp.size] = '\0';

	rem = 0;

	rem = temp.ArrayToIntegers();

	return rem;

}

void DynamicArray::growArrayInt(int* arr, int size)
{

	int* temp = NULL;

	temp = arr;
	arr = new int[size];

	for (int i = 0; i < size - 1; i++)
		arr[i] = temp[i];

}

void DynamicArray::IntegersToArray(long int num)
{

	DynamicArray r;

	r.size = 1;
	r.arr = new int[r.size];
	InitializeIntArr(r.arr, r.size);

	while (num != 0)
	{
		r.arr[r.size - 1] = num % 10;
		num /= 10;
		r.size++;
		growArrayInt(r.arr, r.size);
	}

	r.size--;
	r.arr[r.size] = '\0';

	Reverse(r.arr, r.size);

	this->size = r.size;
	this->arr = new int[this->size];
	InitializePtr(this->arr, this->size);

	for (int i = 0; i < r.size; i++)
		this->arr[i] = r.arr[i];

}

long int DynamicArray::ArrayToIntegers()
{
	long int mul = 0;

	for (int i = 0; i < this->size; i++)
	{
		if(i != 0)
			mul *= 10;

		mul = mul + this->arr[i];

	}

	return mul;
}

bool DynamicArray::Equal(const DynamicArray D2)
{

	for (int i = 0; i < this->size; i++)
	{
		if (this->arr[i] != D2.arr[i])
		{
			return 0;
		}
	}

	return 1;

}

void DynamicArray::UniqueElements()
{

	this->size = 1;
	InitializeInt();

	bool flag = 0;
	int num = 0;
	int j = this->size - 1;

	cout << "\nEnter 10 unique numbers: ";
	
	for (int i = 0; i < 10; i++)
	{
		cin >> num;
		flag = 0;

		for (int j = 0; j < this->size; j++)
		{
			if (this->arr[j] == num)
			{
				flag = 1;
				break;
			}
		}
		
		if (!flag)
		{
			this->arr[this->size - 1] = num;
			this->size++;
			RegrowArr(this->arr, this->size);
		}

	}

	this->size--;
	this->arr[this->size] = '\0';

}

void DynamicArray::InitializeRandom(int*& arr, int size)
{

	srand(time(0));

	arr = new int[size];

	for (int i = 0; i < size; i++)
		arr[i] = rand() % 100 + 1;

	arr[size] = '\0';

}

int DynamicArray::CountOcc(int* arr, int size, int num)
{

	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == num)
			count++;
	}

	return count;

}

bool DynamicArray::Exist(int num)
{

	for (int i = 0; i < this->size; i++)
	{
		if (this->arr[i] == num)
			return 1;
	}

	return 0;

}

DynamicArray DynamicArray::RandomFreq()
{

	DynamicArray Data;
	
	int freq = 0;

	Data.size = 6;
	Data.arr = new int[Data.size];
	InitializeRandom(Data.arr, Data.size);

	this->size = 2;
	InitializeInt();

	for (int i = 0; i < Data.size; i++)
	{
		if (!this->Exist(Data.arr[i]))
		{
			this->arr[this->size - 2] = Data.arr[i];

			freq = CountOcc(Data.arr, Data.size, Data.arr[i]);
			this->arr[this->size - 1] = freq;

			this->size+=2;
			RegrowArr(this->arr, this->size);

			freq = 0;
		}

	}

	this->size -= 2;
	this->arr[this->size] = '\0';
	

	return Data;

}

int DynamicArray::LeftMostDigit(int num)
{
	int remainder = 0;
	while (num > 0)
	{
		remainder = num % 10;
		num = num / 10;
	}
	return remainder;
}

void DynamicArray::Swap(int& num1, int& num2)
{

	int temp = 0;
	temp = num1;
	num1 = num2;
	num2 = temp;

}

void DynamicArray::SortByLeft()
{

	int temp = 0;

	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			if (LeftMostDigit(this->arr[i]) < (LeftMostDigit(this->arr[j])) && i != j)
			{
				Swap(this->arr[i], this->arr[j]);
			}
		}
	}

}

void DynamicArray::SortAsc()
{

	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			if (this->arr[i] < this->arr[j])
				Swap(this->arr[i], this->arr[j]);
		}
	}

}

void DynamicArray::SortDsc()
{

	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size; j++)
		{
			if (this->arr[i] > this->arr[j])
				Swap(this->arr[i], this->arr[j]);
		}
	}

}

void DynamicArray::MergeArr(int* arr, int size)
{

	DynamicArray Merge;
	Merge.size = this->size + size - 1;
	Merge.arr = new int[Merge.size];
	InitializeIntArr(Merge.arr, Merge.size);

	for (int i = 0; i < this->size; i++)
		Merge.arr[i] = this->arr[i];

	int j = 0;

	for (int i = this->size; i < Merge.size; i++)
	{
		Merge.arr[i] = arr[j];
		j++;
	}

	this->size = Merge.size;
	InitializeIntArr(this->arr, this->size);

	for (int i = 0; i < this->size; i++)
		this->arr[i] = Merge.arr[i];

}

int DynamicArray::BinarySearch(int num)
{
	
	int index = 0;

	if (this->arr[this->size / 2] == num)
	{
		return this->size / 2;
	}
	else if (this->arr[this->size / 2] > num)
	{
		for (int i = 0; i < this->size / 2; i++)
		{
			if (this->arr[i] == num)
				return i;
		}

	}
	else
	{
		for (int i = this->size / 2 - 1; i < this->size; i++)
		{
			if (this->arr[i] == num)
				return i;
		}

	}

	return -1;

}

void DynamicArray::FindFreq()
{

	DynamicArray Data, Element, Freq;

	int count = 0;

	Data.size = this->size;
	Data.arr = new int[Data.size];
	Data.Copy(*this);

	Element.size = 1;
	Element.arr = new int[Element.size];
	Element.InitializeIntArr(Element.arr, Element.size);

	Freq.size = 1;
	Freq.arr = new int[Freq.size];
	Freq.InitializeIntArr(Freq.arr, Freq.size);

	for (int i = 0; i < Data.size; i++)
	{
		if (!Element.Exist(Data.arr[i]))
		{
			Element.arr[Element.size - 1] = Data.arr[i];

			count = CountOcc(Data.arr, Data.size, Data.arr[i]);
			Freq.arr[Freq.size - 1] = count;

			Freq.size++;
			Element.size++;
			RegrowArr(Element.arr, Element.size);
			RegrowArr(Freq.arr, Freq.size);

			count = 0;
		}

	}

	Freq.size--;
	Element.size--;
	Freq.arr[Freq.size] = '\0';
	Element.arr[Element.size] = '\0';

	for (int i = 0; i < Freq.size; i++)
	{
		for (int j = 0; j < Freq.size; j++)
		{

			if (Freq.arr[i] > Freq.arr[j] && i != j)
			{
				Swap(Freq.arr[i], Freq.arr[j]);
				Swap(Element.arr[i], Element.arr[j]);
			}

		}
	}

	this->size = Element.size + Freq.size;

	int j = 0;

	for (int i = 0; i < this->size; i+=2)
	{
		this->arr[i] = Element.arr[j];
		this->arr[i + 1] = Freq.arr[j];
		j++;
	}

}

void DynamicArray::FindMax()
{

	int max, secMax, min, secMin;
	max = secMax = min = secMin = 0;

	this->SortAsc();

	max = this->arr[this->size - 1];
	secMax = this->arr[this->size - 2];
	min = this->arr[0];
	secMin = this->arr[1];

	cout << "\nMaximum Element: " << max;
	cout << "\nSecond Maximum Element: " << secMax;
	cout << "\nMinimum Element: " << min;
	cout << "\nSecond Minimum Element: " << secMin;

}

int DynamicArray::FindKthElement(int num)
{

	return this->arr[num - 1];

}

void DynamicArray::Partition()
{

	this->SortAsc();

}

//TASK 2 -STUDENT DATA

void DynamicArray::SortIdAsc(DynamicArray ID, DynamicArray Q1, DynamicArray Q2, DynamicArray Q3, DynamicArray AVG)
{

	int size = ID.size;

	int* index = new int[size];
	InitializeIntArr(index, size);

	for (int i = 0; i < size; i++)
		index[i] = i;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{

			if (ID.arr[i] < ID.arr[j] && i != j)
			{
				Swap(ID.arr[i], ID.arr[j]);
				Swap(Q1.arr[i], Q1.arr[j]);
				Swap(Q2.arr[i], Q2.arr[j]);
				Swap(Q3.arr[i], Q3.arr[j]);
				Swap(AVG.arr[i], AVG.arr[j]);
			}

		}
	}

}

void DynamicArray::SortIdDsc(DynamicArray ID, DynamicArray Q1, DynamicArray Q2, DynamicArray Q3, DynamicArray AVG)
{

	int size = ID.size;

	int* index = new int[size];
	InitializeIntArr(index, size);

	for (int i = 0; i < size; i++)
		index[i] = i;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{

			if (ID.arr[i] > ID.arr[j] && i != j)
			{
				Swap(ID.arr[i], ID.arr[j]);
				Swap(Q1.arr[i], Q1.arr[j]);
				Swap(Q2.arr[i], Q2.arr[j]);
				Swap(Q3.arr[i], Q3.arr[j]);
				Swap(AVG.arr[i], AVG.arr[j]);
			}

		}
	}

}

void DynamicArray::SortAvgAsc(DynamicArray ID, DynamicArray Q1, DynamicArray Q2, DynamicArray Q3, DynamicArray AVG)
{

	int size = AVG.size;

	int* index = new int[size];
	InitializeIntArr(index, size);

	for (int i = 0; i < size; i++)
		index[i] = i;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{

			if (AVG.arr[i] < AVG.arr[j] && i != j)
			{
				Swap(ID.arr[i], ID.arr[j]);
				Swap(Q1.arr[i], Q1.arr[j]);
				Swap(Q2.arr[i], Q2.arr[j]);
				Swap(Q3.arr[i], Q3.arr[j]);
				Swap(AVG.arr[i], AVG.arr[j]);
			}

		}
	}

}

void DynamicArray::SortAvgDsc(DynamicArray ID, DynamicArray Q1, DynamicArray Q2, DynamicArray Q3, DynamicArray AVG)
{

	int size = AVG.size;

	int* index = new int[size];
	InitializeIntArr(index, size);

	for (int i = 0; i < size; i++)
		index[i] = i;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{

			if (AVG.arr[i] > AVG.arr[j] && i != j)
			{
				Swap(ID.arr[i], ID.arr[j]);
				Swap(Q1.arr[i], Q1.arr[j]);
				Swap(Q2.arr[i], Q2.arr[j]);
				Swap(Q3.arr[i], Q3.arr[j]);
				Swap(AVG.arr[i], AVG.arr[j]);
			}

		}
	}

}

//TASK 3

void DynamicArray::MergeArr(DynamicArray Arr)
{

	DynamicArray Merge;
	Merge.size = this->size + Arr.size;
	Merge.arr = new int[Merge.size];
	InitializeIntArr(Merge.arr, Merge.size);

	for (int i = 0; i < this->size; i++)
		Merge.arr[i] = this->arr[i];

	int j = 0;

	for (int i = this->size; i < Merge.size; i++)
	{
		Merge.arr[i] = Arr.arr[j];
		j++;
	}

	this->size = Merge.size;
	InitializeInt();

	for (int i = 0; i < this->size; i++)
		this->arr[i] = Merge.arr[i];

}

void DynamicArray::SortEvenOddAlt()
{

	DynamicArray Dup;

	Dup.size = this->size;
	Dup.arr = new int[Dup.size];
	Dup.InitializeInt();
	Dup.Copy(*this);

	Dup.SortAsc();

	this->InitializeInt();

	int j = Dup.size - 1;
	int k = 0;

	for (int i = 0; i < Dup.size; i+=2)
	{
		this->arr[i] = Dup.arr[j];
		this->arr[i + 1] = Dup.arr[k];
		j--;
		k++;
	}

}

void DynamicArray::SortDscFreq()
{

	DynamicArray Data, Element, Freq;

	int count = 0;

	Data.size = this->size;
	Data.arr = new int[Data.size];
	Data.Copy(*this);

	Element.size = 1;
	Element.arr = new int[Element.size];
	Element.InitializeIntArr(Element.arr, Element.size);

	Freq.size = 1;
	Freq.arr = new int[Freq.size];
	Freq.InitializeIntArr(Freq.arr, Freq.size);

	for (int i = 0; i < Data.size; i++)
	{
		if (!Element.Exist(Data.arr[i]))
		{
			Element.arr[Element.size - 1] = Data.arr[i];

			count = CountOcc(Data.arr, Data.size, Data.arr[i]);
			Freq.arr[Freq.size - 1] = count;

			Freq.size++;
			Element.size++;
			RegrowArr(Element.arr, Element.size);
			RegrowArr(Freq.arr, Freq.size);

			count = 0;
		}

	}

	Freq.size--;
	Element.size--;
	Freq.arr[Freq.size] = '\0';
	Element.arr[Element.size] = '\0';

	for (int i = 0; i < Freq.size; i++)
	{
		for (int j = 0; j < Freq.size; j++)
		{

			if (Freq.arr[i] > Freq.arr[j] && i != j)
			{
				Swap(Freq.arr[i], Freq.arr[j]);
				Swap(Element.arr[i], Element.arr[j]);
			}

		}
	}

	int store = 0;
	for (int i = 0; i < Freq.size; i++)
	{
		store += Freq.arr[i];
	}

	this->size = store;

	int k = 0;

	for (int i = 0; i < Freq.size; i++)
	{
		for (int j = 0; j < Freq.arr[i]; j++)
		{
			this->arr[k] = Element.arr[i];
			k++;
		}

	}

}

void DynamicArray::Sort0and1()
{

	int left = 0, right = size - 1;

	while (left < right)
	{
		while (arr[left] == 0 && left < right)
			left++;

		while (arr[right] == 1 && left < right)
			right--;

		if (left < right)
		{
			arr[left] = 0;
			arr[right] = 1;
			left++;
			right--;
		}
	}

}

void DynamicArray::ReverseSubArray()
{

	int front = -1, back = -1;

	for (int i = 1; i < this->size; i++)
	{
		if (this->arr[i] < this->arr[i - 1])
		{
			front = i - 1;
			break;
		}
	}

	for (int i = this->size - 2; i >= 0; i--)
	{
		if (this->arr[i] > this->arr[i + 1])
		{
			back = i + 1;
			break;
		}
	}

	if (front == -1 and back == -1)
		return;

	while (front <= back)
	{
		Swap(this->arr[front], this->arr[back]);

		front++;
		back--;
	}

}

bool DynamicArray::FindSumOfTwo(int& num1, int& num2, int sum)
{

	int left, right;

	this->SortAsc();

	left = 0;
	right = this->size - 1;

	while (left < right)
	{
		
		if (this->arr[left] + this->arr[right] == sum)
		{
			num1 = this->arr[left];
			num2 = this->arr[right];
			return 1;
		}
		
		else if (this->arr[left] + this->arr[right] < sum)
			left++;
		
		else
			right--;

	}
	return 0;

}

bool DynamicArray::FindSumOfThree(int& num1, int& num2, int& num3, int sum)
{

	for (int i = 0; i < this->size - 2; i++)
	{

		for (int j = i + 1; j < this->size - 1; j++)
		{

			for (int k = j + 1; k < this->size; k++)
			{
				if (this->arr[i] + this->arr[j] + this->arr[k] == sum)
				{
					num1 = this->arr[i];
					num2 = this->arr[j];
					num3 = this->arr[k];
					return true;
				}

			}
		}
	}
  
	return false;

}

void DynamicArray::FindLeaderSubset(const int k)
{

	DynamicArray Data;
	Data.size = this->size;
	Data.arr = new int[Data.size];
	Data.Initialize(this->arr, Data.size);

	this->size = 1;
	this->arr = new int[this->size];
	InitializeInt();

	int max = 0;

	for (int i = 0; i <= Data.size - k; i++)
	{
		max = 0;
		for (int j = i; j <= i + k - 1; j++)
		{
			if (Data.arr[j] > max)
			{
				max = Data.arr[j];
			}
		}
		this->size++;
		RegrowArr(this->arr, this->size);
		this->arr[i] = max;
	}

	this->size--;
	this->arr[this->size] = '\0';

}

DynamicArray DynamicArray::FindUnionIntersection(DynamicArray arr)
{

	DynamicArray Data1, Data2, Union;
	Data1.size = this->size;
	Data1.arr = new int[Data1.size];
	Data1.Initialize(this->arr, Data1.size);

	Data2.size = arr.size;
	Data2.arr = new int[Data2.size];
	Data2.Initialize(arr.arr, arr.size);

	Union.size = 1;
	Union.arr = new int[Union.size];
	Union.InitializeIntArr(Union.arr, Union.size);

	this->size = 1;
	this->arr = new int[this->size];
	InitializeInt();

	Data1.SortAsc();
	Data2.SortAsc();


	//UNION

	int i = 0, j = 0, k = 0;
	while (i < Data1.size && j < Data2.size)
	{
		if (Data1.arr[i] < Data2.arr[j])
		{
			Union.size++;
			RegrowArr(Union.arr, Union.size);
			Union.arr[k] = Data1.arr[i++];
			k++;
		}

		else if (Data2.arr[j] < Data1.arr[i])
		{
			Union.size++;
			RegrowArr(Union.arr, Union.size);
			Union.arr[k] = Data2.arr[j++];
			k++;
		}

		else
		{
			Union.size++;
			RegrowArr(Union.arr, Union.size);
			Union.arr[k] = Data2.arr[j++];
			i++;
			k++;
		}
	}

	while (i < Data1.size)
	{
		Union.size++;
		RegrowArr(Union.arr, Union.size);
		Union.arr[k] = Data1.arr[i++];
		k++;
	}

	while (j < Data2.size)
	{
		Union.size++;
		RegrowArr(Union.arr, Union.size);
		Union.arr[k] = Data2.arr[j++];
		k++;
	}

	Union.size--;
	Union.arr[Union.size] = '\0';

	//INTERSECTION

	i = j = k = 0;
	while (i < Data1.size && j < Data2.size)
	{
		if (Data1.arr[i] < Data2.arr[j])
			i++;

		else if (Data2.arr[j] < Data1.arr[i])
			j++;

		else
		{
			this->size++;
			RegrowArr(this->arr, this->size);
			this->arr[k] = Data2.arr[j];
			k++;
			i++;
			j++;
		}
	}

	this->size--;
	this->arr[this->size] = '\0';

	return Union;

}

void DynamicArray::FindClosestSum(int& num1, int& num2, int num3)
{
	
	int left = 0, right = this->size - 1, diff = this->arr[this->size - 1];

	
	while (right > left)
	{
		
		if (abs(arr[left] + arr[right] - num3) < diff)
		{
			num1 = left;
			num2 = right;
			diff = abs(arr[left] + arr[right] - num3);
		}

		
		if (arr[left] + arr[right] > num3)
			right--;
		else 
			left++;
	}

	num1 = this->arr[num1+1];
	num2 = this->arr[num2+1];

}

void DynamicArray::FindClosestElement(int k, int x)
{

	DynamicArray Data;

	int count = 0;
	int index = 0;

	for (int i = 0; i < this->size; i++)
	{
		if (count < k)
		{

			if (this->arr[i] == x)
			{
				index = i + 1;
				break;
			}
			else if (x - this->arr[i] <= 10)
			{
				cout << arr[i] << " ";
				count++;
			}

		}
		else
			break;
	}

	for (int i = index; i < this->size; i++)
	{
		if (count < k)
		{
			if (this->arr[i] == x)
			{
				index = i + 1;
				break;
			}
			else if (this->arr[i] - x <= 10)
			{
				cout << arr[i] << " ";
				count++;
			}
		}
		else
			break;
	}

}

void DynamicArray::FindGreaterHalf()
{

	int index = (this->size / 2) - 1;
	int num = 0;
	int* NewArr = new int[this->size];

	for (int i = 0; i < this->size; i++)
	{
		NewArr[i] = this->arr[i];
	}

	
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < size; j++)
		{

			if (NewArr[i] < NewArr[j])
				Swap(NewArr[i], NewArr[j]);

		}
	}

	num = NewArr[index];
	for (int i = 0; i < this->size; i++)
	{
		if (this->arr[i] > num)
		{
			cout << arr[i] << " ";
		}
	}

}

bool CheckIfPrime(int num)
{

	if (num == 1)
		return false;

	for (int i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

int DynamicArray::FindSumOfNonPrime()
{

	int sum = 0;
	cout << "Non Prime Numbers are: ";
	for (int i = 0; i < this->size; i++)
	{
		if (!CheckIfPrime(this->arr[i]))
		{
			cout << this->arr[i] << " ";
			sum = sum + this->arr[i];
		}
	}
	
	return sum;

}

//ELECTRONIC VOTING

void DynamicArray::VoteCount(DynamicArray ID, int size)
{

	DynamicArray Vote;
	Vote.size = 1;
	Vote.arr = new int[Vote.size];
	Vote.InitializeIntArr(Vote.arr, Vote.size);

	int count = 0;

	this->SortAsc();

	for (int i = 0; i < size; i++)
	{

		count = 0;

		for (int j = 0; j < this->size; j++)
		{
			if (ID.arr[i] == this->arr[j])
				count++;
		}

		Vote.size++;
		RegrowArr(Vote.arr, Vote.size);
		Vote.arr[i] = count;

	}

	Vote.size--;
	Vote.arr[Vote.size] = '\0';

	this->Copy(Vote);

}


void DynamicArray::Print()
{

	for (int i = 0; i < this->size; i++)
		cout << this->arr[i] << " ";

	cout << endl;

}

void DynamicArray::PrintStudent(DynamicArray ID, DynamicArray Q1, DynamicArray Q2, DynamicArray Q3, DynamicArray AVG, int size, int id)
{

	int index = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (ID.arr[i] == id)
			{
				index = i;
				break;
			}
		}
	}

	cout << "\n ID     Q1     Q2     Q3     AVG\n";

	cout << "\n " << ID.arr[index] << "      " << Q1.arr[index] << "      " << Q2.arr[index] << "      " << Q3.arr[index] << "       " << AVG.arr[index] << endl;

	cout << endl;

}

void DynamicArray::PrintStudents(DynamicArray ID, DynamicArray Q1, DynamicArray Q2, DynamicArray Q3, DynamicArray AVG, int size)
{

	cout << " ID     Q1     Q2     Q3     AVG\n";
	for (int i = 0; i < size; i++)
	{
		cout << "\n " << ID.arr[i] << "      " << Q1.arr[i] << "      " << Q2.arr[i] << "      " << Q3.arr[i] << "       " << AVG.arr[i] << endl;
	}

	cout << endl;

}

void DynamicArray::PrintVoting(DynamicArray ID, char** party, DynamicArray Vote)
{

	cout << "\nParty        Party Name     Votes\n";

	for (int i = 0; i < ID.size; i++)
	{
		cout << "  " << ID.arr[i] << "		" << party[i] << "	     " << Vote.arr[i] << endl;
	}

	cout << endl;

}

void DynamicArray::PrintChart(DynamicArray ID, char** party, DynamicArray Vote)
{

	for (int i = 0; i < ID.size; i++)
	{
		cout << party[i] << ":	";
		
		for (int j = 0; j < Vote.arr[i]; j += 75)
			cout << (char)219;

		cout << endl << endl;
	}

	int index = 0;
	int max = 0;

	for (int i = 0; i < Vote.size; i++)
	{
		if (Vote.arr[i] > max)
		{
			max = Vote.arr[i];
			index = i;
		}
	}

	cout << endl << party[index] << " Party won the election!\n";

}

DynamicArray::~DynamicArray()
{
}