#pragma once
#include<iostream>
#include<string>
#include<list>
using namespace std;

class Tag
{
	list<string> tags;
public:
	void addTag()
	{
		while (true)
		{
			if(tags.size())
				cout << "У выбраного дела уже есть такие теги: \n";
			for (auto x : tags)
				cout << x << endl;
			cout << "Введите тег('0' - отмена): \n";
			string tag = "";
			string temp;
			getline(cin, temp);
			if (temp == "0")
				return;
			if (temp[0] != '#')
				tag = "#";
			tag += temp;
			tags.push_back(tag);
			cout << "1 - Добавить еще тег\n"
				<< "0 - Далее\n";
			int x;
			cin >> x;
			while (x < 0 || x > 1)
			{
				cout << "Вы введи не верное число, введите еще раз: \n";
				cin >> x;
			}
			if (!x)
			{
				return;
			}
				
		}
	}
	void addTag(list<string> tag)
	{
		for (auto x : tag)
		{
			tags.push_back(x);
		}
	}
	void delTag()
	{
		cout << "Какой тег вы хотите удалить?\n";
		int i = 1;
		for (auto x : tags)
		{
			cout << i << " - " << x << endl;
		}
		int j;
		cin >> j;
		list<string>::iterator it;
		it = tags.begin();
		for (auto& x : tags)
		{
			if (j == i)
			{
				tags.erase(it);
				//delAll(x);
			}
			it++;
		}
	}
	list<string> getTags()
	{
		return tags;
	}
	void setTags()
	{
		cout << "Выберите тег который хотите редактировать\n";
		int i = 1;
		for (auto x : tags)
		{
			cout << i << " - " << x << endl;
		}
		int j = 1;
		cin >> j;
		auto it = tags.cbegin();
		for (auto& x : tags)
		{
			if (j == i)
			{
				cout << "Введите новый тег: \n";
				string tag = "";
				string temp;
				cin.ignore();
				cin.clear();
				getline(cin, temp);
				if (temp[0] != '#')
					tag = "#";
				tag += temp;
				tags.emplace(it, tag);
				tags.erase(it);
				return;
			}
			it++;
		}
	}
	void print()
	{
		for (auto x : tags)
		{
			cout << x << "  ";
		}
	}


	
};
