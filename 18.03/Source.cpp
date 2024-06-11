#include<iostream>
#include<fstream>
using namespace std;

class ElectronicTools
{
protected:
	string name;
	string firm;
	int price;

public:
	ElectronicTools() 
	{
		this->name = "";
		this->firm = "";
		this->price = 0;
	}

	string GetName()
	{
		return name;
	}

	string GenFirma()
	{
		return firm;
	}

	unsigned int GetPrice()
	{
		return price;
	}

	friend istream& operator>>(istream& in, ElectronicTools& tool)
	{
		in >> tool.name;
		in >> tool.firm;
		in >> tool.price;

		return in;
	}
	friend ostream& operator<<(ostream& out, ElectronicTools& tool)
	{
		out << tool.name << " " << tool.firm << " " << tool.price<<" "<< endl;
		return out;
	}
	virtual void input(ifstream& data)
	{
		data >> name  >> firm >> price;
	}

	virtual void print(ofstream& data)
	{
		data << name <<endl;
		data << firm <<endl;
		data << price <<endl;
		     
	}
	void print_name(ofstream& file)
	{
		file << name << "\t";
	}

	void print_firma(ofstream& file)
	{
		file << firm<< "\t";
	}

	void print_price(ofstream& file)
	{
		file << price << endl;
	}


};

class VacuumCleaner : public ElectronicTools
{
protected:
	int power;
	string color;
public:
	VacuumCleaner(){}
	friend istream& operator>>(istream& in, VacuumCleaner& tool)
	{
		
		in >> tool.power >> tool.color;

		return in;
	}
	friend ostream& operator<<(ostream& out, VacuumCleaner& tool)
	{
		out << tool.power << tool.color << endl;
		return out;
	}
	virtual void input(ifstream& data)
	{
		ElectronicTools::input( data);
		data >> power >> color  ;
	}
	virtual void print(ofstream& data)
	{
		
		data << power<<endl << color<<endl << endl;
	}

};

class WashingMashine : public ElectronicTools
{
protected:
	int number_of_program;
	int volume;
public:
	WashingMashine() 
	{
		this->number_of_program = 0;
		this->volume = 0;
	}
	friend istream& operator>>(istream& in, WashingMashine& tool)
	{
		in >> tool.number_of_program >>tool.volume;

		return in;
	}
	friend ostream& operator<<(ostream& out, WashingMashine& tool)
	{
		out << tool.number_of_program << tool.volume << endl;
		return out;
	}
	virtual void input(ifstream& data)
	{
		ElectronicTools::input(data);
		data >> number_of_program >> volume;
	}
	virtual void print(ofstream& data)
	{

		data << number_of_program<<endl << volume<<endl << endl;
	}

};

class Combine : public ElectronicTools
{
protected:
	int power;
	int number_of_function;
public:
	Combine()
	{
		this->power = 0;
		this->number_of_function = 0;
	}
	friend istream& operator>>(istream& in, Combine& tool)
	{
		in >> tool.power >> tool.number_of_function;

		return in;
	}
	friend ostream& operator<<(ostream& out, Combine& tool)
	{
		out << tool.power << tool.number_of_function << endl;
		return out;
	}
	virtual void input(ifstream& data)
	{
		ElectronicTools::input(data);
		data >> power >> number_of_function;
	}
	virtual void print(ofstream& data)
	{

		data << power <<endl<<number_of_function << endl << endl;
	}

};

int main()
{
	ifstream data;
	ofstream print_file1;
	ofstream print_file2;

	int type;

	data.open("data.txt");
	print_file1.open("print.txt");
	print_file2.open("print_2.txt");

	ElectronicTools** array = new ElectronicTools * [10];

	for (int i = 0; i < 10; i++)
	{
		data >> type;

		switch (type)
		{
		case 1:
			array[i] = new VacuumCleaner;
			break;

		case 2:
			array[i] = new WashingMashine;
			break;

		case 3:
			array[i] = new Combine;
			break;

		default:
			break;
		}

		array[i]->input(data);
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (array[j]->GetName() < array[i]->GetName())
			{
				swap(array[j], array[i]);
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		array[i]->print(print_file1);
	}

	for (int i = 0; i < 10; i++)
	{
		array[i]->print_name(print_file2);
		array[i]->print_firma(print_file2);
		array[i]->print_price(print_file2);
	}

	data.close();
	print_file1.close();
	print_file2.close();

	for (int i = 0; i < 10; i++)
	{
		delete[] array[i];
	}

	delete[] array;

	return 0;
}