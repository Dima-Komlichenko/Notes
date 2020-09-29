#pragma once
#include<iostream>

using namespace std;

class Date
{
	string date = "";
public:
	Date() {}
	Date(int i)
	{
		setDate();
	}

	void setDate()
	{
		cout << "¬ведите дату(0 - ќтмена):\n";
		cout << "¬ведите день \n";
		cin.ignore();
		cin.clear();
		int d;
		cin >> d;
		while (d < 0 || d > 31)
		{
			cout << "¬вдеите день от 1 до 31";
			cin >> d;
		}
		if (!d)
			return;
		int m;
		system("cls");
		cout << "¬ведите мес€ц\n"
			<< d << '.';
		cin >> m;
		while (m < 1 || m > 12)
		{
			system("cls");
			cout << "¬вдеите мес€ц от 1 до 12\n"
				<< d << '.';
			cin >> m;
		}
		cout << ".";
		int y;
		system("cls");
		cout << "¬ведите год\n"
			<< d << '.' << m << '.';
		cin >> y;
		while (y < 2020)
		{
			cout << "¬ведите год больше 2020\n"
				<< d << '.' << m << '.';
			cin >> y;
		}
		int d2;
		d2 = d % 10;
		if (d > 9)
		{
			int d1;
			d1 = d / 10 % 10;
			date = d1 + 48;
			date += d2 + 48;
		}
		else
			date += d2 + 48;
		date += '.';
		int m2;
		m2 = m % 10;
		if (m > 9)
		{
			int m1;
			m1 = m / 10 % 10;
			date += m1 + 48;
			date += m2 + 48;
		}
		else
		{
			date += '0';
			date += m2 + 48;
		}
		date += '.';
		int yy[4];
		int x = 1;
		for (int i = 3; i >= 0; i--)
		{
			yy[i] = y / x % 10;
			x *= 10;
		}
		for (size_t i = 0; i < 4; i++)
		{
			date += yy[i] + 48;
		}
	}
	void setDate(string date)
	{
		this->date = date;
	}
	string getDate()
	{
		return date;
	}
	void print()
	{
		cout << date;
	}
};