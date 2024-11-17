#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    string a = ".",b="/", c="%",inp,rel;
    char ac = '.', bc = '/', cc = '%';
    cin >> inp;
    if (inp.empty()) {
        cout << "出错";
        return 0;
    }
    int size = inp.size(), where = 0;

    char inp_c[100];
   
    for (int i = 0; i <size; i++)
        inp_c[i] = inp[i];
    inp_c[size] = '\0';

    string::size_type idx;
    bool is_can3 = false;

    string left, right, left_rel, right_rel;
    char left_c, right_c, left_rel_c, right_rel_c;


    idx = inp.find(a);//在a .
    if (idx == string::npos){}//bcz
    else
    { 
        is_can3 = true;
        for (int i = 0; i < size; i++) {
            if (inp[i] == ac) {
                where = i;
                break;
            }
        }

        left.resize(where);
        left_rel.resize(where);
        right_rel.resize(size - where - 1);

        for (int i = 0; i < where; i++) {
            left_rel[i] = inp[where - 1 - i];
        }

        for (int j = 0; j < size - where-1; j++) {
            right_rel[j] = inp[size -1-j];
        }

        rel = left_rel + a + right_rel;
        cout << rel;
        return 0;
    }

    idx = inp.find(b);//在b /
    if (idx == string::npos) {}//bcz
    else
    {
        is_can3 = true;
        for (int i = 0; i < size; i++) {
            if (inp[i] == bc) {
                where = i;
                break;
            }
        }

        left.resize(where);
        left_rel.resize(where);
        right_rel.resize(size - where - 1);

        for (int i = 0; i < where; i++) {
            left_rel[i] = inp[where - 1 - i];
        }

        for (int j = 0; j < size - where - 1; j++) {
            right_rel[j] = inp[size - 1 - j];
        }

        rel = left_rel + b + right_rel;
        cout << rel;
        return 0;
    }

    idx = inp.find(c);//在c %
    if (idx == string::npos) {}//bcz
    else
    {
        is_can3 = true;
        for (int i = 0; i < size; i++) {
            if (inp[i] == cc) {
                where = i;
                break;
            }
        }

        left.resize(where);
        left_rel.resize(where);
        right_rel.resize(size - where - 1);

        for (int i = 0; i < where; i++) {
            left_rel[i] = inp[where - 1 - i];
        }

        for (int j = 0; j < size - where - 1; j++) {
            right_rel[j] = inp[size - 1 - j];
        }

        rel = left_rel + c + right_rel;
        cout << rel;
        return 0;
    }

   
    reverse(inp.begin(),inp.end());
    int size_tt= inp.find_first_not_of('0');
    rel.resize(size - size_tt);

    reverse(inp.begin(), inp.end());
    for (int i = 0; i < size - size_tt ; i++) {
        rel[i] = inp[i];
    }

    cout << rel;
    return 0;
}
