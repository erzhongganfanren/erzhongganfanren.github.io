#include<iostream>
#include<random>
#include<fstream>
#include<string>
#pragma once

#define wordlist "wordlist.txt"//���ʱ�ĵ�ַ�������޸ģ�����
#define reset "\033[0m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define size 10
#define cishu 5//��Ϸ�����������޸ģ�����
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

void get_random_number(int& a)
{
	mt19937 rng(random_device{}());
	uniform_real_distribution<double>dist(1, 45797);
	a = dist(rng);
}
void open_file(char* a,int& b,string& line)
{
	ifstream file(wordlist);
	if (!file)
	{
		cerr << "�޷��򿪸��ļ�" << endl;
		exit(1);
	}
	int linenumber = 1;
	get_random_number(linenumber);
	int currentline = 1;
	while (getline(file, line))
	{
		if (currentline == linenumber)
		{
			b=line.length();
			strcpy_s(a,sizeof(line), line.c_str());
			break;
		}
		currentline++;
	}
	file.close();
}
int compare(char* c,char* d,int& e)
{
	int f = 0;
	for (int i = 0; i < e; i++)
	{
		int b = 0;
		for (int a = 0; a < e; a++)
		{
			if (c[i] == d[a] && a == i)
			{
				b += 2;
				f += 2;
				break;
			}
		}
		for (int a = 0; a < e; a++)
		{
			if (c[i] == d[a] && a != i)
			{
				b += 1;
				break;
			}
		}
		if (b >= 2)
			cout << green << c[i] << reset;
		else if (b == 1)
			cout << yellow << c[i] << reset;
		else
			cout << red << c[i] << reset;
	}
	if (f == 2 * e)
		return 1;
	else
		return 2;
}
int main()
{
	cout << "��ӭ�����µ�����Ϸ������ܼ򵥣��ҾͲ�˵�ˣ���" << endl;
	string line="���~~��~~��Ӵ";
	char* danci1 = new char[size];
	char* danci=new char[size];
	int changdu=10;
	open_file(danci1,changdu,line);
	cout << "������һ������Ϊ" << changdu << "��Ӣ�ĵ���"<<endl;
	int f = 1;
	while (f <= 5)
	{
		cin.getline(danci,changdu+1);
		if (compare(danci, danci1, changdu) == 1)
		{
			cout << "��Ȼ�³����ˣ������������";
			return 0;
		}
		else
		{
			if(f!=5)
				cout << "�����ޣ�����������һ�ΰ�" << endl;
			else
				cout<< "�ð��������𰸰ɣ���ȷ����" << green << line << reset;
		}
		f++;
	}
}
