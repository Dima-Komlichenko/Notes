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
				cout << "� ��������� ���� ��� ���� ����� ����: \n";
			for (auto x : tags)
				cout << x << endl;
			cout << "������� ���('0' - ������): \n";
			string tag = "";
			string temp;
			getline(cin, temp);
			if (temp == "0")
				return;
			if (temp[0] != '#')
				tag = "#";
			tag += temp;
			tags.push_back(tag);
			cout << "1 - �������� ��� ���\n"
				<< "0 - �����\n";
			int x;
			cin >> x;
			while (x < 0 || x > 1)
			{
				cout << "�� ����� �� ������ �����, ������� ��� ���: \n";
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
		cout << "����� ��� �� ������ �������?\n";
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
		cout << "�������� ��� ������� ������ �������������\n";
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
				cout << "������� ����� ���: \n";
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
