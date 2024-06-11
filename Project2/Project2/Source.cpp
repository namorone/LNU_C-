#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Organism
{
public:
    Organism(bool _isanimal, string _name, bool _redbook) : isanimal(_isanimal), name(_name), redbook(_redbook)
    {

    }
    bool isAnimal()
    {
        return isanimal;
    }
    virtual string getClass() = 0;
    virtual int getCount() = 0;
    virtual void fin(ifstream& file) = 0
    {
        file >> name >> redbook;
    }
    virtual void fout(ofstream& file) = 0
    {
        file << name << " " << redbook;
    }
    string getName()
    {
        return name;
    }
    bool Isredbook()
    {
        return redbook;
    }
    void setName(string _new_name)
    {
        name = _new_name;
    }
    void setRedbook(bool _state)
    {
        redbook = _state;
    }
private:
    bool isanimal;
    string name;
    bool redbook;
};


class Animal : public Organism
{
public:
    Animal(string _name, bool _redbook, string _anclass) : Organism(true, _name, _redbook)
    {
        anclass = _anclass;
    }
    virtual void fin(ifstream& file)
    {
        file >> anclass;
        Organism::fin(file);
    }
    virtual void fout(ofstream& file)
    {
        file << anclass << " ";
        Organism::fout(file);
    }
    virtual string getClass()
    {
        return anclass;
    }
private:
    string anclass;
};




class Plant : public Organism
{
public:
    Plant(string _name, bool _redbook, string _pltype) : Organism(false, _name, _redbook)
    {
        pltype = _pltype;
    }
    virtual void fin(ifstream& file)
    {
        file >> pltype;
        Organism::fin(file);
    }
    virtual void fout(ofstream& file)
    {
        file << pltype << " ";
        Organism::fout(file);
    }
    virtual string getClass()
    {
        return pltype;
    }
private:
    string pltype;
};







class Tree : public Plant
{
public:
    Tree(string _name, bool _redbook) : Plant(_name, _redbook, "tree")
    {
        tcount++;
    }
    virtual int getCount()
    {
        return tcount;
    }
    virtual void fInput(ifstream& file)
    {

    }
private:
    static int tcount;
};
int Tree::tcount = 0;




class Moss : public Plant
{
public:
    Moss(string _name, bool _redbook) : Plant(_name, _redbook, "moss")
    {
        mcount++;
    }
    virtual int getCount()
    {
        return mcount;
    }

private:
    static int mcount;
};
int Moss::mcount = 0;




class Bird : public Animal
{
public:
    Bird(string _name, bool _redbook) : Animal(_name, _redbook, "bird")
    {
        bcount++;
    }
    virtual int getCount()
    {
        return bcount;
    }

private:
    static int bcount;
};
int Bird::bcount = 0;



class Insect : public Animal
{
public:
    Insect(string _name, bool _redbook) : Animal(_name, _redbook, "insect")
    {
        icount++;
    }
    virtual int getCount()
    {
        return icount;
    }

private:
    static int icount;
};
int Insect::icount = 0;



int main()
{
    const int SIZE = 10;
    Organism* organisms[SIZE];
    ifstream finput;
    string fipath = "input.txt";
    finput.open(fipath);
    if (!finput.is_open())
    {
        cout << "Error of opening " << fipath << " file" << endl;
        //todo exception
    }
    else
    {
        int i = 0;
        string type = "";
        string name = "";
        bool redbook = 0;
        while (!finput.eof() && i < SIZE)
        {
            type = "";
            name = "";
            redbook = 0;
            finput >> type >> name >> redbook;
            if (type == "tree")
            {
                organisms[i] = new Tree(name, redbook);
            }
            else if (type == "moss")
            {
                organisms[i] = new Moss(name, redbook);
            }
            else if (type == "bird")
            {
                organisms[i] = new Bird(name, redbook);
            }
            else if (type == "insect")
            {
                organisms[i] = new Insect(name, redbook);
            }
            i++;
        }
        finput.close();
    }

    //sorting by alphabet
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (organisms[j]->getName() < organisms[i]->getName()) //exception needed
            {
                swap(organisms[i], organisms[j]);
            }
        }
    }


    ofstream foutput;
    string fopath = "output.txt";
    foutput.open(fopath);
    if (!foutput.is_open())
    {
        cout << "Error of opening " << fopath << " file" << endl;
        //todo exception
    }
    else
    {
        foutput << "\tSorted by the names(2nd column):\n";
        for (int i = 0; i < SIZE; i++)
        {
            organisms[i]->fout(foutput);
            foutput << "\n";
        }


        for (int i = 0; i < SIZE - 1; i++) // Sorting by the object count of each class
        {
            for (int j = i + 1; j < SIZE; j++)
            {
                if (organisms[j]->getCount() < organisms[i]->getCount())
                {
                    swap(organisms[i], organisms[j]);
                }
            }
        }

        foutput << "\n\tAnimals: "; //additional information
        string classBuf = "";
        for (int i = 0; i < SIZE; i++)
        {
            if (organisms[i]->isAnimal() == 1 && organisms[i]->getClass() != classBuf)
            {
                classBuf = organisms[i]->getClass();
                foutput << classBuf << "(" << organisms[i]->getCount() << "), ";
            }
        }
        foutput << ":\n";
        for (int i = 0; i < SIZE; i++)
        {
            if (organisms[i]->isAnimal() == 1)
            {
                organisms[i]->fout(foutput);
                foutput << "\n";
            }
        }

        foutput << "\tPlants: ";  //additional information
        classBuf = "";
        for (int i = 0; i < SIZE; i++)
        {
            if (organisms[i]->isAnimal() == 0 && organisms[i]->getClass() != classBuf)
            {
                classBuf = organisms[i]->getClass();
                foutput << classBuf << "(" << organisms[i]->getCount() << "), ";
            }
        }
        foutput << ":\n";
        for (int i = 0; i < SIZE; i++)
        {
            if (organisms[i]->isAnimal() == 0)
            {
                organisms[i]->fout(foutput);
                foutput << "\n";
            }
        }
        foutput << "\n\tRed book species(3rd column):\n";
        for (int i = 0; i < SIZE; i++)
        {
            if (organisms[i]->Isredbook() == 1)
            {
                organisms[i]->fout(foutput);
                foutput << "\n";
            }
        }
        foutput.close();
    }

    for (int i = 0; i < SIZE; i++) //freeing memory
    {
        if (organisms[i] != nullptr)
        {
            delete organisms[i];
        }
    }


    return 0;
}