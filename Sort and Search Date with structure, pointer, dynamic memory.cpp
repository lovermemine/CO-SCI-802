#include <iostream>
#include <conio.h>
using namespace std;
struct Date
{
	int month, day, year;
};
const int MAX = 100;
int getDates(Date* dates[], int size);
void sort(Date* dates[], int size);
int binSearch(Date* dates[], int size, Date searchDate);
void display(Date* date[], int size);
void swapDates(Date& date1, Date& date2);
void delDates(Date* dates[], int size);
int main()
{
	Date* dates[MAX] = { NULL };
	char slash;

	int size = getDates(dates, MAX);
	sort(dates, size);
	display(dates, size);

	Date searchDate;
	cout << "\nEnter search date: ";
	cin >> searchDate.month >> slash >> searchDate.day >> slash >> searchDate.year;
	int index = binSearch(dates, size, searchDate);
	if (index == -1)
		cout << "\nDate was not found.";
	else
		cout << "\nDate was found at index " << index;

	delDates(dates, size);

	cout << "\nPress any key to continue.";
	_getch();
	return 0;
}
int getDates(Date* dates[], int size)
{
	int tmp;
	char slash;

	cout << "Enter dates in month/day/year format and -1 when done.";
	int i;
	for (i = 0; i < size; i++)
	{
		cin >> tmp;
		if (tmp != -1)
		{
			dates[i] = new Date;
			dates[i]->month = tmp;
			cin >> slash >> dates[i]->day >> slash >> dates[i]->year;
		}
		else
			break;
	}
	return i;
}
void sort(Date* dates[], int size)
{
	bool swap;
	do
	{
		swap = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (dates[i]->year > dates[i + 1]->year)
			{
				swapDates(*(dates[i]), *(dates[i + 1]));
				swap = true;
			}
			else if (dates[i]->year == dates[i + 1]->year 
				&& dates[i]->month > dates[i + 1]->month)
			{
				swapDates(*(dates[i]), *(dates[i + 1]));
				swap = true;
			}
			else if (dates[i]->year == dates[i + 1]->year
				&& dates[i]->month == dates[i + 1]->month 
				&& dates[i]->day > dates[i + 1]->day)
			{
				swapDates(*(dates[i]), *(dates[i + 1]));
				swap = true;
			}
		}
	} while (swap);
}
void swapDates(Date& date1, Date& date2)
{
	Date tmp = date1;
	date1 = date2;
	date2 = tmp;
}
void display(Date* dates[], int size)
{
	for (int i = 0; i < size; i++)
		cout << dates[i]->month << '/' << dates[i]->day << '/' << dates[i]->year << endl;
}
int binSearch(Date* dates[], int size, Date searchDate)
{
	int first = 0, last = size - 1, mid;
	bool found = false;

	while (first <= last && !found)
	{
		mid = (first + last) / 2;
		if (searchDate.year == dates[mid]->year
			&& searchDate.month == dates[mid]->month
			&& searchDate.day == dates[mid]->day)
		{
			found = true;
			return mid;
		}
		else if (searchDate.year > dates[mid]->year)
			first = mid + 1;
		else if (searchDate.year == dates[mid]->year
			&& searchDate.month > dates[mid]->month)
			first = mid + 1;
		else if (searchDate.year == dates[mid]->year
			&& searchDate.month == dates[mid]->month
			&& searchDate.day > dates[mid]->day)
			first = mid + 1;
		else
			last = last - 1;
	}
	return -1;
}
void delDates(Date* dates[], int size)
{
	for (int i = 0; i < size; i++)
	{
		delete dates[i];
		dates[i] = NULL;
	}
}