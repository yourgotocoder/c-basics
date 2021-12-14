#include "include/database.h"

void Database::write(vector<vector<string>> mainList)
{
    ofstream db;
    db.open("db/lists.sl");
    if (db.is_open())
    {
        for (int userIndex = 0; userIndex < (int)mainList[userIndex].size(); userIndex++)
        {
            for (int listIndex = 0; listIndex < (int)mainList[userIndex][listIndex].size(); listIndex++)
            {
                db << mainList[userIndex][listIndex] << "\n";
            }
        }
    }
    else
    {
        cout << "Cannot open file for writing. \n";
    }
    db.close();
}

vector<vector<string>> Database::read()
{
    string line;
    ifstream db;

    vector<string> userList;
    db.open("db/lists.sl");
    if (db.is_open())
    {
        while (getline(db, line, '\n'))
        {
            if (line.front() == '#')
            {
                cout << "Found a hashtag: " << line << "\n";
                line.erase(line.begin());
                userList.push_back(line);
            }
            else if (line.front() == '%')
            {
                cout << "Found a percentage: " << line << "\n";
                mainList.push_back(userList);
                userList.clear();
            }
            else
            {
                cout << "Found an Item: " << line << "\n";
                userList.push_back(line);
            }
        }
    }
    else
    {
        cout << "Cannot open file for reading. \n";
    }
    db.close();
    return mainList;
}