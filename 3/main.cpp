#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string>file_str;

void read_file()
{
    ifstream file("text.txt");
    if(file.is_open())
    {
        string line;
        while(getline(file,line))
        {
            // cout << line << endl;
            file_str.push_back(line);
        }
    }
    file.close();
}

class First
{
public:
    void solution()                     // . . . 4
    {                                   // 3 * . 1
                                        // 3 * * .
    }

};

int main()
{
    read_file();

    for(int i = 0; i < file_str.size(); i++)
    {
        cout << file_str[i] << " ";
    }
    return 0;
}