#include <iostream>
#include <conio.h>
using namespace std;

struct Date
{
	int month, day, year;
};
void getDates(Date* dates[], int size);
void display(Date* dates[], int size);
void sortDates(Date* dates[], int size);
void swapDates(Date** date1, Date** date2);
void sort(int nums[], int size);
void swapNums(int& num1, int& num2);
int main()
{
	Date dates[5] = { 0 };
	Date* ptrs[5] = { NULL };
	char slash;

/*	int numbers[5] = { 75, 80, 66, 50, 79 };
	sort(numbers, 5);
*/
	for (int i = 0; i < 5; i++)
		ptrs[i] = &dates[i];

	getDates(ptrs, 5);
	display(ptrs, 5);

	sortDates(ptrs, 5);
	display(ptrs, 5);

	cout << "\nPress any key to continue.";
	_getch();
	return 0;
}
/*void sort(int* nums[], int size)
{
	bool swap;
	do
	{
		swap = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				swapNums(&nums[i], &nums[i + 1]);
				swap = true;
			}
		}
	} while (swap);
}*/
void swapNums(int** n1, int** n2)
{
	int* tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}
void getDates(Date* dates[], int size)
{
	char slash;

	cout << "Enter 5 dates: ";
	for (int i = 0; i < size; i++)
		cin >> dates[i]->month >> slash >> dates[i]->day >> slash >> dates[i]->year;
}
void display(Date* ptrs[], int size)
{
	cout << endl;
	for (int i = 0; i < size; i++)
		cout << ptrs[i]->month << '/' << ptrs[i]->day << '/' << ptrs[i]->year << endl;
}
void sortDates(Date* dates[], int size)
{
	bool swap;
	do
	{
		swap = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (dates[i]->year > dates[i + 1]->year)
			{
				swapDates(&dates[i], &dates[i + 1]);
				swap = true;
			}
		}
	} while (swap);
}
void swapDates(Date** date1, Date** date2)
{
	Date* tmp = *date1;
	*date1 = *date2;
	*date2 = tmp;
}