#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;
int cur_size = 0;
int buf_size = 0;

struct flat {
	int flat_number: 9, rooms: 4, area: 9;
	void print() {
		cout << flat_number << " " << rooms << " "<<area << endl;
	}
};

//int main()
//{
//	cout << sizeof(flat) << endl;
//	flat f;
//	cin >> f.flat_number;
//
//
//
//
//	system("Pause");
//}
struct home
{
	char home_no[30];
	int flat_amount : 9;
	flat* fs=NULL;
	void print()
	{
		cout << home_no << endl;
		if (fs!=NULL)
		{
			for (int i = 0; i < flat_amount; i++)
			{
				fs[i].print();
			}
		}
	}
};

template<typename T>
void add(T*&fs, T el) {
	if (buf_size==0)
	{
		buf_size = 4;
		fs = new T[buf_size];
	}
	else
	{
		if (cur_size==buf_size)
		{
			buf_size *= 2;
			T* tmp = new T[buf_size];
			for (int i = 0; i < cur_size; i++)
			{
				tmp[i] = fs[i];
			}
			delete[]fs;
			fs = tmp;
		}
	}
	fs[cur_size++] = el;
}
//int main()
//{
//	int tmp;
//	flat el;
//	ifstream in_file("in.txt");
//	
//	flat* fs = 0;
//	while (!in_file.eof())
//	{
//		in_file >> tmp;
//		el.flat_number = tmp;
//		in_file >> tmp;
//		el.rooms = tmp;
//		in_file >> tmp;
//		el.area = tmp;
//	}
//	for (int i = 0; i < cur_size; i++)
//	{
//		fs[i].print();
//	}
//
//	system("pause");
//}

int main()
{
	int tmp;
	flat el;
	home home_el;
	home* hs = 0;
	ifstream in_file("in.txt");
	
	flat* fs = 0;
	while (!in_file.eof())
	{
		in_file >> home_el.home_no >> tmp;
		home_el.flat_amount;
		home_el.fs = new flat[tmp];
		for (int i = 0; i < home_el.flat_amount; i++)
		{
			in_file >> tmp;
			home_el.fs[i].flat_number = tmp;

			in_file >> tmp;
			home_el.fs[i].rooms = tmp;

			in_file >> tmp;
			home_el.fs[i].area= tmp;
		}
		add(hs, home_el);
	}
	for (int i = 0; i < cur_size; i++)
	{
		hs[i].print();
	}





	system("pause");
}