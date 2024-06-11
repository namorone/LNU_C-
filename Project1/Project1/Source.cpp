#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include <algorithm>
using namespace std;

/*В текстовому файлі задано послідовність слів, розділених пропусками.
Ввести слова в контейнер.
Використовуючи алгоритми STL, кожне слово, яке починається і закінчується на одну і ту ж букву перемістити в інший контейнер. 
Утворити контейнер, який міститиме без повторів всі символи, що входять до складу даної послідовності слів.

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