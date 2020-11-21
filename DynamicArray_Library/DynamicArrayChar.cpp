#include "DynamicArrayChar.h"
#include <iostream>
#include <fstream>

using namespace std;

DynamicArrayChar::DynamicArrayChar()
{

	this->size = 1;
	this->arr = nullptr;

}

void DynamicArrayChar::InitializeInt(char* arr, int size)
{

	this->size = size;
	this->arr = new char[size];

	for (int i = 0; i < size; i++)
		this->arr[i] = 0;

	this->arr[size] = '\0';

}

void DynamicArrayChar::FileInput()
{

	ifstream fin;
	fin.open("file1.txt");

	int size = 0;
	char num = '\0';

	if (!fin.is_open())
		cout << "\nFile does not exist!";
	else
		fin >> size;

	this->size = size;
	this->arr = new char[size];
	InitializeInt(this->arr, this->size);

	for (int i = 0; i < size; i++)
	{
		fin >> num;
		this->arr[i] = num;
	}

	fin.close();

}

void DynamicArrayChar::UserInput(int size)
{

	this->size = size;
	InitializeInt(this->arr, this->size);

	int count = 0;

	cout << "\nEnter the elements for the array (max: 50 elements): ";
	for (int i = 0; i < size; i++)
	{
		cin >> this->arr[i];
		count++;

		if (this->arr[i] == '~')
		{
			this->arr[i] = '\0';
			count--;
			this->size = count;
			break;
		}

	}

}

DynamicArrayChar::DynamicArrayChar(char* text, int size)
{

	this->size = size;
	this->arr = new char[this->size];

	for (int i = 0; i < this->size; i++)
		this->arr[i] = text[i];

}

void DynamicArrayChar::ShrinkArr(int index)
{

	int temp = 0;

	for (int i = index; i < this->size; i++)
	{
		this->arr[i] = this->arr[i + 1];

	}

}

void DynamicArrayChar::RemoveVowels()
{

	for (int i = 0; i < this->size; i++)
	{
		if (this->arr[i] == 'a' || this->arr[i] == 'e' || this->arr[i] == 'i' || this->arr[i] == 'o' || this->arr[i] == 'u' || this->arr[i] == 'A' || this->arr[i] == 'E' || this->arr[i] == 'I' || this->arr[i] == 'O' || this->arr[i] == 'U')
		{
			ShrinkArr(i);
		}
	}

}

void DynamicArrayChar::RemoveVowelsNested()
{

	char temp = '\0';

	for (int i = 0; i < this->size; i++)
	{
		for (int j = this->size - 1; j != i; j--)
		{
			if ((this->arr[i] == 'a' || this->arr[i] == 'e' || this->arr[i] == 'i' || this->arr[i] == 'o' || this->arr[i] == 'u' || this->arr[i] == 'A' || this->arr[i] == 'E' || this->arr[i] == 'I' || this->arr[i] == 'O' || this->arr[i] == 'U') && i != j)
			{
				if (this->arr[j] != 'a' || this->arr[j] != 'e' || this->arr[j] != 'i' || this->arr[j] != 'o' || this->arr[j] != 'u' || this->arr[j] != 'A' || this->arr[j] != 'E' || this->arr[j] != 'I' || this->arr[j] != 'O' || this->arr[j] != 'U')
				{
					temp = this->arr[i];
					this->arr[i] = this->arr[j];
					this->arr[j] = temp;
					ShrinkArr(this->size);
					this->size--;
				}
				else
					j--;

			}
		}
	}

}


void DynamicArrayChar::Print()
{

	for (int i = 0; i < this->size; i++)
		cout << this->arr[i];

	cout << endl;

}

DynamicArrayChar::~DynamicArrayChar()
{

}