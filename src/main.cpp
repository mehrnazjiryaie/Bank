#include <iostream>
#include <vector>
#include <string>
#include "Bank.h"
//#include <sstream>
using namespace std;

typedef unsigned int ui; // convert unsigned int into ui

int main(int argc, char const *argv[])
{
    cout << "WELCOME TO GHOZAH BANK\n"; //بانك قُــزَه
    vector<customer> moshtari;          // costumer is a class(user defined type)

    while (1)
    {
        string str = "";
        string command = "";  // customer request
        string username = ""; // account username
        string ip = "";       // account ip

        cout << "Enter your request:\n";
        getline(cin, str);
        size_t i = 0;

        while (str[i] != ' ' && str[i])
        {
            command += str[i];
            i++;
        }

        i++;

        while (str[i] != ':' && str[i])
        {
            username += str[i];
            i++;
        }

        i++;

        while (str[i])
        {
            ip += str[i];
            i++;
        }

        // cout << "command:" << command << endl;
        // cout << "username :" << username << endl;
        // cout << "ip :" << ip << endl;

        if (command == "create")
        {
            try
            {
                customer account(username, ip); // create an object of class customer
                cout << "hello\n";
                moshtari.push_back(account);
            }
            catch (int num)
            {
                cerr << "Invalid username!! - username must start with a letter.\n";
            }

            catch (...)
            {
                cout << "Invalid username!! - username must include upper case or lower case or unsigned integer numbers\n";
            }
        }
        for (size_t i = 0; i < moshtari.size(); i++)
        {
            cout << moshtari[i].get_username() << endl;
        }

        // string command;
        // getline(cin, command);

        // istringstream iss(command);
        // string word;

        // while (iss >> word)
        // {
        //     if (word == "create")
        //     {
        //         cout <<
        //     }

        // }

        // getline(cin, command);
        // cin.ignore();
        // cout << command << endl;

        // vector<string> order;
        // size_t i = 0;
        // size_t j = 0;

        // string word = "";
        // while (command[i] != '\0')
        // {
        //     word += command[i];
        //     cout << command << endl;
        //     if (command[i] == ' ')
        //     {
        //         order.push_back(word);
        //         cout << order[j] << endl;
        //         j++;
        //         word = "";
        //     }
        //     i++;
        // }

        // if (order[0] == "create ")
        // {
        //     cout << "hello\n";
        // }

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
