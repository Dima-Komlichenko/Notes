#pragma once
#include<iostream>
#include<list>
#include"Task.h"

class Find
{
protected:
	int predmet;
public:
	virtual Task* searchTask(list<Task*> tasks) = 0;
	virtual void printTasks(list<Task*> tasks) = 0;
	virtual void find(list<Task*> tasks, string& temp) = 0;
};

class FindByDate : public Find
{
public:
	void find(list<Task*> tasks, string& temp) override
	{
		cout << "¬ыберите дату которую хотите найти\n";

		list<string> date;
		bool check = false;
		for (auto x : tasks)
		{
			for (auto c : date)
				if (x->getDate() == c)
					check = true;

			if (!check)
				date.push_back(x->getDate());
			else
				check = false;
		}
		int i = 1;
		for (auto x : date)
		{
			cout << i << " - " << x << endl;
			i++;
		}

		int d;
		cin >> d;
		i = 1;
		for (auto x : tasks)
		{
			if (d == i)
				temp = x->getDate();
			i++;
		}
		i = 1;
	}
	void printTasks(list<Task*> tasks) override
	{
		string temp;
		find(tasks, temp);
		system("cls");
		int i = 1;
		for (auto& x : tasks)
		{
			if (temp == x->getDate())
			{
				cout << i << " - ";
				x->print();
				i++;
			}
		}
	}
	Task* searchTask(list<Task*> tasks) override
	{
		string temp;
		find(tasks, temp);
		cout << "¬ыберите задачу которую хотите найти: " << endl;
		printTasks(tasks);
		int i = 1;
		
		for (auto& x : tasks)
		{
			if (temp == x->getDate())
			{
				cout << i << " - ";
				x->print();
				i++;
			}
		}
		int d;
		cin >> d;
		i = 1;
		for (auto& x : tasks)
		{
			if (temp == x->getDate() && d == i)
			{
				i++;
				return x;
			}

		}
	}
};

class FindByTag : public Find
{
public:
	void find(list<Task*> tasks, string& tag) override
	{
		cout << "¬ыберите тег который хотите найти\n";
		list<string> tags;
		bool check = false;
		for (auto x : tasks)
		{
			list<string> AllTags = x->getTags();
			for (auto c : AllTags)
			{
				for (auto v : tags)
				{
					if (c == v)
						check = true;
				}
				if (!check)
					tags.push_back(c);
				else
					check = false;
			}
		}

		int i = 1;
		for (auto x : tags)
		{
			cout << i << " - " << x << endl;
			i++;
		}
		int c;
		cin >> c;
		i = 1;
		for (auto& x : tags)
		{
			if (c == i)
			{
				tag = x;
				break;
			}

			i++;
		}
	}

	void printTasks(list<Task*> tasks) override
	{
		string tag;
		find(tasks, tag);
		system("cls");
		int i = 1;
		for (auto& x : tasks)
		{
			list<string> temp = x->getTags();
			for (auto c : temp)
			{
				if (c == tag)
				{
					cout << i << " - ";
					x->print();
					i++;
				}
			}
		}
	}
	Task* searchTask(list<Task*> tasks) override
	{
		string tag;
		find(tasks, tag);
		cout << "¬ыберите задачу которую хотите найти \n";

		printTasks(tasks);
		int num;
		cin >> num;
		int i = 1;
		for (auto& x : tasks)
		{

			list<string> temp = x->getTags();
			for (auto c : temp)
			{
				if (num == i && c == tag)
					return x;
				i++;
			}
			i = 1;
		}
	}
};

class FindByPriority : public Find
{
public:
	void find(list<Task*> tasks, string& temp) override
	{
		cout << "¬ыберите приоритет который хотите найти\n"
			<< " 1 - '1'\n"
			<< "2 - '2'\n"
			<< "3 - '3'\n";
		int c;
		cin >> c;
		while (c < 1 || c > 3)
			cin >> c;
		temp = c + 48;
	}

	void printTasks(list<Task*> tasks) override
	{
		system("cls");
		string temp;
		find(tasks, temp);
		system("cls");
		int i = 1;
		bool clear = false;
		for (auto& x : tasks)
		{
			int a = x->getPriority();
			int b = (int)temp[0] - 48;
			if (a == b)
			{
				cout << i << " - ";
				x->print();
				i++;
				clear++;
			}
		}
		if (!clear) 
			cout << "Ќет задач  с таким проритетом\n";
		
	}

	Task* searchTask(list<Task*> tasks) override
	{
		string temp;
		find(tasks, temp);
		cout << "¬ыберите задачу которую хотите найти \n";

		printTasks(tasks);
		int d;
		cin >> d;
		int i = 1;
		for (auto& x : tasks)
		{
			int a = x->getPriority();
			int b = (int)temp[0] - 48;
			if (a == b)
				i++;
			if (d = i)
			{
				return x;
			}
		}


	}
};

class Creator
{
protected:
	virtual Find* createRequest() = 0;
public:
	virtual ~Creator() {}
	Find* create()
	{
		Find* request = this->createRequest();
		return request;
	}
};

class DateCreator : public Creator
{
public:
	Find* createRequest() override
	{
		return new FindByDate;
	}
};

class TagCreator : public Creator
{
public:
	Find* createRequest() override
	{
		return new FindByTag;
	}
};

class PriorityCreator : public Creator
{
public:
	Find* createRequest() override
	{
		return new FindByPriority;
	}
};
