#pragma once
class DynamicArrayChar
{

private:
	char* arr;
	int size;

public:
	DynamicArrayChar();
	void InitializeInt(char* arr, int size);
	DynamicArrayChar(char* text, int size); 
	void FileInput();
	void UserInput(int size);
	void ShrinkArr(int index);

	void RemoveVowels();
	void RemoveVowelsNested();
	void Print();
	~DynamicArrayChar();

};

