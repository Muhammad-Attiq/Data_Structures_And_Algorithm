#include <iostream>
using namespace std;
void reverse_main_string(string& main_string, int start_main_string, int end_main_string)
{
    if(start_main_string >= end_main_string)
    {
        return;
    }
    swap(main_string[start_main_string], main_string[end_main_string]);
    reverse_main_string(main_string, start_main_string+1, end_main_string-1);
}
int main()
{
    string main_string;
    cout << "enter string: " << endl;
    getline(cin, main_string);
    reverse_main_string(main_string, 0, main_string.length() - 1);
    cout << "reverse string: " << main_string << endl;
    return 0;
}
