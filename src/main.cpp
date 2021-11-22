#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef unsigned int ui;

int main(int argc, char const *argv[])
{

    string command = "";

    while (1)
    {
        cin.ignore();
        getline(cin, command);

        vector<string> order;
        size_t i = 0;

        string word = "";

        while (command[i] != '\0')
        {
            word += command[i];
            if (command[i] != ' ')
            {
                order.push_back(word);
                cout << order[i] << endl;
            }
            i++;
        }

        // size_t found1 = command.find("create");
        // if (found1 != string ::npos)
        // {
        //     cout << "Hello\n";
        // }

        // size_t found2 = command.find("add_ip");
        // if (found2 != string ::npos)
        // {
        //     cout << "Hello2\n";
        // }

        // size_t found3 = command.find("renewal");
        // if (found3 != string ::npos)
        // {
        //     cout << "Hello3\n";
        // }

        // size_t found4 = command.find("deposit");
        // if (found4 != string ::npos)
        // {
        //     cout << "Hello4\n";
        // }

        // size_t found5 = command.find("transfer");
        // if (found5 != string ::npos)
        // {
        //     cout << "Hello5\n";
        // }

        // size_t found6 = command.find("withdraw");
        // if (found6 != string ::npos)
        // {
        //     cout << "Hello6\n";
        // }

        // size_t found7 = command.find("add_profits");
        // if (found7 != string ::npos)
        // {
        //     cout << "Hello7\n";
        // }

        // size_t found9 = command.find("get_loan");
        // if (found9 != string ::npos)
        // {
        //     cout << "Hello8\n";
        // }

        // size_t found10 = command.find("pay_loan");
        // if (found10 != string ::npos)
        // {
        //     cout << "Hello9\n";
        // }

        // size_t found11 = command.find("ip");
        // if (found11 != string ::npos)
        // {
        //     cout << "Hello10\n";
        // }

        // size_t found12 = command.find("card_number");
        // if (found12 != string ::npos)
        // {
        //     cout << "Hello10\n";
        // }

        // size_t found13 = command.find("username");
        // if (found13 != string ::npos)
        // {
        //     cout << "Hello10\n";
        // }

        // size_t found14 = command.find("bank");
        // if (found14 != string ::npos)
        // {
        //     cout << "Hello11\n";
        // }
    }

    return 0;
}
