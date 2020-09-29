#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include"Date.h"
#include"Tag.h"
#include<fstream>
using namespace std;

class Task
{
	string text;
	int priority;
	Tag* tags = nullptr;
	Date* date = nullptr;
public:
	Task() : text(""), priority(0)
	{
		tags = new Tag();
		date = new Date();
	}
	~Task()
	{
		delete tags;
		delete date;
	}

	Task* getTask() { return this; }
	string getText() { return text; }
	int getPriority() { return priority; }
	list<string> getTags() { return tags->getTags(); }
	string getDate() { return date->getDate(); }

	void init()
	{
		system("cls");
		setText();
		if (text == "0")
			return;
		setPriority();
		if (priority == 0)
			return;
		addTag();
		list<string> temp = tags->getTags();
		if (tags->getTags().size() == 0)
			return;
		setDate();
	}
	void setText()
	{
		cout << "Введите задачу('0' - отмена):\n";
		cin.ignore();
		getline(cin, text);
	}
	void setPriority()
	{
		cout << "Введите приоритет от 1 до 3('0' - отмена): " << endl;
		cin >> priority;
		while (priority < 0 || priority > 3)
			cin >> priority;
		cin.ignore();
	}
	void setTag()
	{
		tags->setTags();
	}
	void setDate()
	{
		date->setDate();
	}
	void setDate(string dat)
	{
		date->setDate(dat);
	}
	void setText(string t)
	{
		text = t;
	}
	void setPriority(int p)
	{
		priority = p;
	}
	void addTag(list<string> t)
	{
		tags->addTag(t);
	}
	void addTag()
	{
		tags->addTag();
	}
	void setDate(Date *d)
	{
		date = d;
	}

	void print()
	{
		
		cout << "----------\n\nТеги: ";
		tags->print();
		cout << endl;
		date->print();
		cout << endl;
		cout << "Приоритет: " << priority << endl << text << endl;
	}
	friend ofstream& operator<< (ofstream& out, Task* task);
	friend ifstream& operator>> (ifstream& in, Task* task);

};

ofstream& operator<< (ofstream& out, Task* task)
{
	string text;
	int priority;
	list<string> tags;
	string date;

	text = task->getText();
	priority = task->getPriority();
	tags = task->getTags();
	date = task->getDate();

	out << text << " TEXTEND " << priority << " ";

	for (auto x : tags)
		out << x << " ";

	out << " TAGSEND ";
	out << date;
	return out;
}

ifstream& operator>> (ifstream& in, Task* task)
{
	string text = "";
	int priority;
	list<string> tags;
	string date;


	string temp;
	in >> temp;
	text += temp;
	in >> temp;
	while (temp != "TEXTEND")
	{
		text += " " + temp;
		in >> temp;
	}


	in >> priority;
	in >> temp;
	string temp2;
	while (temp != "TAGSEND")
	{
		tags.push_back(temp);
		in >> temp;
		
	}
	in >> date;
	task->setText(text);
	task->setPriority(priority);
	task->addTag(tags);
	task->setDate(date);
	return in;
}