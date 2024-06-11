#include<iostream>
#include<fstream>
using namespace std;

//Визначити абстрактний тип Живий організм (поля - назва, вид (рослина чи тварина),  чи зенесений в червону книгу), похідні абстрактні Рослина (поле тип),Тварина (поле клас) .
//Та відповідні похідні   Дерева, Мохи та  Птахи, Комахи.

class LivingOrganism
{
protected:
	string m_name;
    string m_kind;
	string m_is_in_rbook;
	unsigned int m_number;
public:
	LivingOrganism(string name) : m_name(name) {}
	LivingOrganism(string kind) : m_kind(kind) {}
	LivingOrganism(string is_in_rbook) : m_is_in_rbook(is_in_rbook) {}
	LivingOrganism(unsigned int number) : m_number(number) {}
	string getName() { return m_name; }
	virtual void input() = 0;
	virtual void print() = 0;
};

class Plant : public LivingOrganism
{
protected:
	string m_type;

public:
	Plant(string type) : m_type(type) {}
	Plant(string name): LivingOrganism( name){}
	Plant(string kind) : LivingOrganism(kind) {}
	Plant(string is_in_rbook) : LivingOrganism(is_in_rbook) {}
	Plant(unsigned int number) : LivingOrganism( number) {}
	virtual void input() = 0;
	virtual void print() = 0;
};

class Animal: public LivingOrganism
{
protected:
	string m_classes;
public:
	Animal(string classes) : m_classes(classes) {}
	Animal(string name) : LivingOrganism(name) {}
	Animal(string kind) : LivingOrganism(kind) {}
	Animal(string is_in_rbook) : LivingOrganism(is_in_rbook) {}
	Animal(unsigned int number) : LivingOrganism( number) {}
	virtual void input() = 0;
	
	virtual void print() = 0;
};

class Trees : public Plant
{
public:
	Trees(string type) : Plant(type)  {}
	Trees(string name) : Plant(name)  {}
	Trees(string kind) : Plant(kind) {}
	Trees(string is_in_rbook) : Plant(is_in_rbook) {}
	Trees(unsigned int number) : Plant(number) {}
	virtual void input(ifstream& data) 
	{
		data >> m_name >> m_kind >> m_is_in_rbook >> m_number >> m_type;
	}
	virtual void print(ofstream& data) 
	{
		data << m_name << m_kind << m_is_in_rbook << m_number << m_type <<  endl << endl;
	}
};

class Moss : public Plant
{
private:
	Moss(string type) : Plant(type) {}
	Moss(string name) : Plant(name) {}
	Moss(string kind) : Plant(kind) {}
	Moss(string is_in_rbook) : Plant(is_in_rbook) {}
	Moss(unsigned int number) : Plant(number) {}
	virtual void input(ifstream& data)
	{
		data >> m_name >> m_kind >> m_is_in_rbook >> m_number >> m_type;
	}
	virtual void print(ofstream& data)
	{
		data << m_name << m_kind << m_is_in_rbook << m_number << m_type << endl << endl;
	}
};

class Birds : public Animal
{
private:
	Birds(string classes) : Animal( classes) {}
	Birds(string name) : Animal( name) {}
	Birds(string kind) : Animal( kind) {}
	Birds(string is_in_rbook) : Animal( is_in_rbook) {}
	Birds(unsigned int number) : Animal( number) {}
	virtual void input(ifstream& data)
	{
		data >> m_name >> m_kind >> m_is_in_rbook >> m_number >> m_classes;
	}
	virtual void print(ofstream& data)
	{
		data << m_name << m_kind << m_is_in_rbook << m_number << m_classes << endl << endl;
	}
};

class Insects: public Animal
{
private:
	Insects(string classes) : Animal(classes) {}
	Insects(string name) : Animal(name) {}
	Insects(string kind) : Animal(kind) {}
	Insects(string is_in_rbook) : Animal(is_in_rbook) {}
	Insects(unsigned int number) : Animal(number) {}
	virtual void input(ifstream& data)
	{
		data >> m_name >> m_kind >> m_is_in_rbook >> m_number >> m_classes;
	}
	virtual void print(ofstream& data)
	{
		data << m_name << m_kind << m_is_in_rbook << m_number << m_classes << endl << endl;
	}
};


//Ввести дані про 10 живих організмів. Вивести всі дані в алфавітному порядку назв. 
//Також окремо вивести дані про тварини – в порядку зростання кількості та окремо про всіх рослин. 
//Знайти всі тварини, занесені в червону книгу.
//Введення-виведення здійснювати через файл.


int main()
{
	ifstream data;
	ofstream print_file1;
	ofstream print_file2;
	ofstream print_file3;
	ofstream print_file4;
	
	int key;
	//1 Trees
	//2 Moss
	//3 Birds
	//4 Insects
	
	data.open("data.txt");
	print_file1.open("print.txt");
	print_file2.open("print_2.txt");
	print_file3.open("print_3.txt");
	print_file4.open("print_4.txt");

	LivingOrganism** array = new LivingOrganism * [12];
	for (int i = 0; i < 12;i++)
	{
		delete[] array[i];
	}

	delete[] array;

	return 0;
}