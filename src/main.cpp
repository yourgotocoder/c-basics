#include "include/list.h"
#include "include/database.h"

int main(int arg_count, char *args[])
{
    List simpleList;
    Database database;
    if (arg_count > 1)
    {

        simpleList.name = string(args[1]);
        simpleList.mainList = database.read();
        simpleList.find_userList();
        simpleList.print_menu();
        // database.write(simpleList.list);
        // database.read();
    }
    else
    {
        cout << "Username not supplied.. exiting the program" << endl;
    }
    return 0;
}
