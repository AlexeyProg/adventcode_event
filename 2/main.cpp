#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <list>
#include <unordered_map>

using namespace std;

const int MAX_RED = 12;
const int MAX_BLUE = 14;
const int MAX_GREEN = 13;

struct Approach{
    int blue = 0;
    int red = 0;
    int green = 0;
};

class First
{
public:
    void read_file(string filename)
    {
        ifstream file(filename);
        if(file.is_open())
        {
            string line;
            while(getline(file,line))
            {
                file_strings.push_back(line);
            }
            file.close();
        }
    }

    void test(vector<string>&v)
    {
        int counter_games = 1;
        for(int i = 0; i < v.size(); i++)
        {
            string word;
            int key;
            list<Approach*>app_list;
            Approach *app = new Approach;
            for(int j = 7; j <= v[i].size(); j++)
            {
                if(j == v[i].size() || (!isalnum(tolower(v[i][j])) && !isdigit(v[i][j])))
                {
                    try
                    {
                        key = stoi(word);
                    }
                    catch(invalid_argument)
                    {
                        if(word == "red")
                            app->red = key;
                        else if(word == "blue")
                            app->blue = key;
                        else if(word == "green")
                            app->green = key;
                    }
                    if(v[i][j] == ';')
                    {
                        app_list.push_back(app);
                        app = new Approach;
                    }
                    word.clear();
                }
                else
                    word += v[i][j];
            }
            mp.insert({counter_games, app_list});
            counter_games++;
        }
    }

    int sum_ids()
    {
        int sum = 0;
        for(auto &it : mp) // game1 , game2, game3 
        {
            bool flag = true;
            for(auto lit = it.second.begin(); lit != it.second.end(); lit++) // game - list<app>
            {
                if((*lit)->red > MAX_RED || (*lit)->blue > MAX_BLUE || (*lit)->green > MAX_GREEN)
                {   //BAD GAMES
                    flag = false;
                    cout << it.first << " : " << (*lit)->red << " - " << (*lit)->blue << " - " << (*lit)->green << endl;
                    break;
                }   // ya summary wront games, need to change 
            }
            if(flag)
                sum += it.first;
        }

        //need to clear all dynamic pointers
        // for(auto &it :mp)
        // {
        //     for(auto lit = it.second.begin(); lit != it.second.end(); lit++)
        //     {
        //         delete lit;
        //     }
        // }
        return sum;
    }

    vector<string>file_strings;
    unordered_map<int,list<Approach*>>mp;

};

int main()
{
    First *f = new First;
    f->read_file("text.txt");

    // for(const auto &x : f->file_strings)
    // {
    //     cout << x << endl;
    // }


    f->test(f->file_strings);

    // for(auto &it : f->mp)
    // {
    //     cout << "Game " << it.first << " : ";
    //     for(auto lit = it.second.begin(); lit != it.second.end(); lit++)
    //     {
    //         cout << (*lit)->blue << " " << (*lit)->red << " " << (*lit)->green << endl;
    //     }
    // }

    int result = f->sum_ids();
    cout << result << " - result " << endl;

    return 0;
}
