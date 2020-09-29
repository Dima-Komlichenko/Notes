#pragma once
#include<iostream>
#include<list>
#include"Search.h"

using namespace std;


class Notes
{
	list<Task*> tasks;


	Find* factoryMethod()
	{
		Creator* creator = new DateCreator;
		Find* request;

		cout << "Как вы хотите искать задачу?\n"
			<< "1 - По дате\n"
			<< "2 - По тегу\n"
			<< "3 - По приоритету\n";
		int i;
		cin >> i;
		while (i < 1 || i > 3)
			cin >> i;
		string predmet;
		switch (i)
		{
		case 1:
			creator = new DateCreator;
			break;
		case 2:
			creator = new TagCreator;
			break;
		case 3:
			creator = new PriorityCreator;
			break;
		}
		request = creator->create();
		return request;
	}

	void printTasks()
	{
		system("cls");
		Find* request = factoryMethod();
		system("cls");
		request->printTasks(tasks);
		system("pause");
		system("cls");
	}

	Task* searchTask()
	{
		Find* request = factoryMethod();
		return request->searchTask(tasks);
	}


public:
	void menu()
	{
		importOfFile();
		while (true)
		{
			system("cls");
			cout << "1 - Показать задачи\n"
				<< "2 - Создать задачу\n"
				<< "3 - Удалить задачу\n"
				<< "4 - Редактировать задачу\n"
				<< "5 - Выход\n";
			int i;
			cin >> i;
			while (i < 1 || i > 6)
				cin >> i;
			switch (i)
			{
			case 1:
				printTasks();
				break;
			case 2:
				addTask();
				system("pause");
				system("cls");
				break;
			case 3:
				delTask();
				system("pause");
				system("cls");
				break;
			case 4:
				redactTask();
				system("pause");
				system("cls");
				break;
			case 5:
				exportInFile();
				return;
			}
		}
		exportInFile();
	}


	void addTask()
	{
		Task* task = new Task;
		task->init();
		if (task->getText() == "0" ||task->getPriority() == 0 || 
			task->getDate() == "" || task->getTags().size() == 0)
			delete task;
		else
			tasks.push_back(task);
	}
	void addTask(Task* task)
	{
		tasks.push_back(task);
	}
	void delTask()
	{
		list<Task*>::iterator it = tasks.begin();
		Task* _task = searchTask();
		for (auto& x : tasks)
		{
			string s1 = _task->getText();
			string s2 = x->getText();
			if (!s1.compare(s2))
			{
				tasks.remove(*it);
				return;
			}
			it++;

		}

	}
	void redactTask()
	{
		Task* task = searchTask();
		cout << "Что вы хотите редактировать?\n"
			<< "1 - Текст\n"
			<< "2 - Дату\n"
			<< "3 - Тег\n"
			<< "4 - Приоритет\n";
		int i;
		cin >> i;
		while (i < 1 || i > 4)
			cin >> i;
		switch (i)
		{
		case 1:
			task->setText();
			break;
		case 2:
			task->setDate();
			break;
		case 3:
			task->setTag();
			break;
		case 4:
			task->setPriority();
			break;
		}
	}

	

	void exportInFile()
	{
		ofstream out("Tasks.txt");
		int i = 0;
		for (auto& x : tasks)
		{
			if (i == 0)
				out << x;
			else
			{
				out << endl;
				out << x;
			}
			i++;
		}
	}
	void importOfFile()
	{
		ifstream in("Tasks.txt");

		while (true)
		{
			while (!in.eof())
			{
				Task* temp = new Task;
				in >> temp;
				addTask(temp);
			}
			return;
		}
	}
};
