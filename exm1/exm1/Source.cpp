
/*¬изначити абстрактний тип л≥тальний апарат, та два пох≥дних типи Ц л≥так та пов≥тр€на кул€.
 лас л≥тальний апарат м≥стить поле вид л≥тального апарату та максимальну висоту, на €ку в≥н може п≥дн€тис€,
клас л≥так - поле швидк≥сть, клас пов≥тр€на кул€ Ц поле максимальний час польоту.
¬ текстовому файл≥ задано дан≥ про дек≥лька л≥тальних апарат≥в. 
¬вести дан≥ у один контейнер ≥ а) вивести у ≥нший файл т≥ л≥тальн≥ апарати, €к≥ можуть п≥дн€тис€ на висоту x.
б) ¬изначити дл€ кожного л≥така за ск≥льки часу в≥н долетить з  иЇва до Ћьвова (600 км)*/
#include <iostream> 
#include <string>
#include <fstream>
#include<algorithm>

using namespace std;


class Flying_Apparat {
public:
    Flying_Apparat(string _type, int _max_distance)
    {
        type = _type;
        max_distance = _max_distance;
    }
    string type;
    int max_distance;

    virtual void fin(ifstream& file) = 0
    {
        file >> type >> max_distance;
    }
    virtual void fout(ofstream& file) = 0
    {
        file << type << " " << max_distance;
    }
    string getType() {
        return type;
    }
    int getMax_Distance() {
        return max_distance;
    }
    virtual int getSpeed() = 0;
};

class Plain : public Flying_Apparat {
public:
    int speed;
    Plain(string _type, int _max_distance, int _speed) : Flying_Apparat(_type, _max_distance)
    {
        speed = _speed;
    }
    virtual void fin(ifstream& file)
    {
        file >> speed;
        Flying_Apparat::fin(file);
    }
    virtual void fout(ofstream& file)
    {
        Flying_Apparat::fout(file);
        file << " " << speed << " ";
    }

    int getSpeed() {
        return speed;
    }
};

class Air_Bubble : public Flying_Apparat {
public:
    int max_time_of_flying;
    Air_Bubble(string _type, int _max_distance, int _max_time_of_flying) : Flying_Apparat(_type, _max_distance)
    {
        max_time_of_flying = _max_time_of_flying;
    }
    virtual void fin(ifstream& file)
    {
        file >> max_time_of_flying;
        Flying_Apparat::fin(file);
    }
    virtual void fout(ofstream& file)
    {
        Flying_Apparat::fout(file);
        file << " " << max_time_of_flying << " ";
    }

    int getSpeed() {
        return max_time_of_flying;
    }
};


void main() {

    const int SIZE = 7;
    Flying_Apparat* flyApparats[SIZE];
    ifstream finput;
    string fipath = "Text.txt";
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
        int max_dist = 0;
        int temp = 0;
        while (!finput.eof() && i < SIZE)
        {
            type = "";
            max_dist = 0;
            temp = 0;
            finput >> type >> max_dist >> temp;
            if (type == "plane")
            {
                flyApparats[i] = new Plain(type, max_dist, temp);
            }
            else if (type == "air_bubble")
            {
                flyApparats[i] = new Air_Bubble(type, max_dist, temp);
            }
            i++;
        }
        finput.close();
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
        int height = 0;
        cout << "Please, enter height (for example 32)= ";
        cin >> height;
        foutput << "Flying apparats than can be on " << height << " height:\n";

        for (int i = 0; i < SIZE; i++)
        {
            if (flyApparats[i]->getMax_Distance() == height)
            {
                flyApparats[i]->fout(foutput);
                foutput << "\n";
            }
        }

        foutput << "Time for every plane:\n";
        float time = 0;
        for (int i = 0; i < SIZE; i++) {
            if (flyApparats[i]->getType() == "plane") {
                flyApparats[i]->fout(foutput);
                time = 600. / (flyApparats[i]->getSpeed());
                foutput << "\nFor plane with " << flyApparats[i]->getSpeed() << " speed, time from Kyiv to Lviv = " << time << " hours\n";
                //flyApparats[i]->fout(foutput);
            }
        }

        foutput.close();
    }

}