// list.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"List.h"
#include"Node.h"
using namespace std;
//template<class Type>
int main()
{
	List<int> L;
	Init(&L);
	cout << "Enter 10 integers:" << endl;
	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;
		Push_back(&L,num);
	}
	cout << "The second:" << endl;
	Node<int>* current;
	current = Begin(&L);
	current = Get_next(current);
	cout << Get_data(current) << endl;
	cout << "The first:" << endl;
	current = Begin(&L);
	cout << Get_data(current) << endl;
	cout << "alfter erasing the first" << endl;
	Erase(&L, Begin(&L));
	Display(&L);
	cout << "after erasing the last:" << endl;
	Erase(&L,End(&L));
	Display(&L);
	cout << "The first and the last:" << endl;
	cout << Front_data(&L) << endl << Back_data(&L) << endl;

    return 0;
}

