#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>

#define IS_SYMB(x) (x != '.' && !isdigit(x))


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

    vector<int> digits;

    void solution()                     // . . . 4
    {                                   // 3 * . 1
                                        // 3 * . .

        for(int i = 0; i < file_str.size(); i++)
        {
            string dig;
            bool flag = false;
            for(int j = 0; j < file_str[i].size(); j++)
            {
                char cur_s = file_str[i][j];            // \* * *
                                                        // \* 2 *
                                                        // \* * *
                
                if(isdigit(cur_s))
                {
                    dig += cur_s;
                    if((j > 0 && IS_SYMB(file_str[i][j-1]))  || (j < file_str.size()-1 && IS_SYMB(file_str[i][j+1])) 
                    || ( i > 0 && IS_SYMB(file_str[i-1][j])) ||  (j > 0 && i < file_str[i].size()-1 && IS_SYMB(file_str[i+1][j-1])) 
                     || (i < file_str.size()-1 && j > 0 && IS_SYMB(file_str[i+1][j-1])) || 
                    (i < file_str.size()-1 && IS_SYMB(file_str[i+1][j])) || (i > 0 && j > 0 && IS_SYMB(file_str[i-1][j-1])) || 
                    (i > 0 && j < file_str[i].size()-1 && IS_SYMB(file_str[i-1][j+1])) || (i < file_str.size()-1 && j < file_str[i].size() && IS_SYMB(file_str[i+1][j+1])) )
                    {
                        flag = true;
                    }
                }
                else 
                {
                    if(!dig.empty() && flag)
                    {
                        // cout << dig << endl;
                        int x = stoi(dig);
                        digits.push_back(x);
                        dig.clear();
                        flag = false;
                    }
                    else
                        dig.clear();
                }
            }
        }
    }

};

int main()
{
    read_file();

    // for(int i = 0; i < file_str.size(); i++)
    // {
    //     cout << file_str[i] << " - ";
    // }
    First *f = new First();
    f->solution();

    for(const auto &x : f->digits)
        cout << x << " " ;

    return 0;
}