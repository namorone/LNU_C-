#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include <algorithm>
using namespace std;

/*� ���������� ���� ������ ����������� ���, ��������� ����������.
������ ����� � ���������.
�������������� ��������� STL, ����� �����, ��� ���������� � ���������� �� ���� � �� � ����� ���������� � ����� ���������. 
�������� ���������, ���� �������� ��� ������� �� �������, �� ������� �� ������ ���� ����������� ���.

*/
void input(ifstream& file)
{

};

int main() 
{
	ifstream infile("Infile.txt");
    list<string> mylist;

    string s;
    while (!infile.eof())
    {
        infile >> s;
        mylist.push_back(s);
    }
	infile.close();
    list<string>mylist2;
    copy(mylist.begin(), mylist.end(), back_inserter(mylist2));
    for (auto el : mylist2)
    {
        cout << el << " ";
    }
    cout << endl; 
    mylist2.unique();
    for (auto el : mylist2)
    {
        cout << el << " ";
    }
    cout << endl;
}