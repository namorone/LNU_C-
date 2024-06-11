#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename V>
void fnc(vector<V> vec, V elem)
{
    int count_of_elem_in_arr = 0;
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        if (elem == *it)
        {
            count++;
        }
    }
    if (count > 2)
    {
        vec.clear();
    }
    if (count < 2)
    {
        auto it1 = vec.end();
        it1--;
        *it1 = elem;

    }
    if (count == 2)
    {
        auto it1 = vec.end();
        it1--;
        *it1 = elem;
        auto it2 = vec.end();
        it2--;
        it2--;
        it2 = elem;
    }
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << it << " ";
    }
    cout << endl;
}
void main()
{
    vector<double> double_vec = { 5.3, 6.2, 6.3, 4.6, 2.3, 4.6 };
    vector<string> string_vec = { "qwe", "qwe", "rew", "asd", "fgd", "dsa" };

    fnc(double_vec, 4.6);

    fnc(string_vec, string_vec[0]);

}