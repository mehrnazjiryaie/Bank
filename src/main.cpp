#include <iostream>
#include <vector>
#include <string>
#include "Bank.h"

using namespace std;

// std::vector<std::string> usernames; // a vector for save all of accounts names
// bool is_Empty = true;

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
            command += str[i]; // create command word
            i++;
        }

        i++;

        while (str[i] != ':' && str[i])
        {
            username += str[i]; // create username word
            i++;
        }

        i++;

        while (str[i] != ':' && str[i])
        {
            ip += str[i]; // create ip
            i++;
        }

        i++;

        string s;
        while (str[i] != ':' && str[i])
        {
            s += str[i];
            i++;
        }
        i++;

        if (command == "create")
        {
            try
            {
                customer account(username, ip); // create an object of class customer
                moshtari.push_back(account);
                cout << "Your account has created successfully!!\n";
                int op;
                int exp;
                cout << "enter opening date and expiration date :\n";
                cin >> op;
                cin >> exp;
                account.set_opening_date(op);
                account.set_expiration_date(exp);

                // usernames.push_back(username);
            }
            catch (int num)
            {
                cerr << "Invalid username!! - username must start with a letter.\n";
            }

            catch (char ch)
            {
                cout << "Invalid username!! - username must include upper case or lower case or unsigned integer numbers.\n";
            }

            catch (float f)
            {
                cout << "Invalid ip - each part of ip must be between 0 and 255.\n";
            }

            catch (double d)
            {
                cout << "Invalid ip - ip must include for parts and exactly 3 dots.\n";
            }
        }

        if (command == "add_ip")
        {
            add_ip(username, moshtari, ip);

            if (s == "another")
            {
                string new_ip;
                while (str[i])
                {
                    new_ip += str[i];
                    i++;
                }
                add_ip(username, moshtari, new_ip);
            }
        }

        if (command == "renewal")
        {
            for (size_t i = 0; i < moshtari.size(); i++)
            {
                if (username == moshtari[i].get_username())
                {
                    try
                    {
                        moshtari[i].check_expiration_date();
                        char ch;
                        cout << "Do you wanna renewal your account?\n";
                        cin >> ch;
                        if (ch == 'y' || ch == 'Y')
                        {
                            moshtari[i].get_balance() = moshtari[i].get_balance() - 5000;
                        }
                        else if(ch == 'n' || ch == 'N')
                        {
                            break;
                        }
                        
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }
            }
        }

        if (command == "deposit")
        {
        }
    }
    return 0;
}
