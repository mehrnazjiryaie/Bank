#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Bank.h"


using namespace std;

// std::vector<std::string> usernames; // a vector for save all of accounts names
// bool is_Empty = true;

int main(int argc, char const *argv[])
{
    cout << "WELCOME TO GHOZAH BANK\n"; //بانك قُــزَه
    vector<customer> moshtari;          // costumer is a class(user defined type)
    // std::vector<customer>::iterator it;

    while (1)
    {
        string str = "";
        string command = "";  // customer request
        string username = ""; // account username
        string ip = "";       // account ip

        cout << "Enter your request:\n";

        getline(cin, str);
        fflush(stdin);
        // cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
        cout << "s :" << s << endl;

        i++;

        int transfer_money = 0;
        string payment = "";

        if (str[i])
        {
            while (str[i])
            {
                payment += str[i];
                i++;
            }
            cout << "payment : " << payment << endl;
            transfer_money = convert(payment);
            cout << "ts : " << transfer_money << endl;
        }

        if (command == "create")
        {
            try
            {
                customer account(username, ip); // create an object of class customer
                int op;
                int exp;
                cout << "enter opening date and expiration date :\n";
                cin >> op;
                cin >> exp;
                account.set_opening_date(op);
                account.set_expiration_date(exp);
                moshtari.push_back(account);
                cout << "Your account has created successfully!!\n";

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
            cout << "hello\n";
            for (size_t i = 0; i < moshtari.size(); i++)
            {
                cout << "hello\n";
                if (username == moshtari[i].get_username() && moshtari[i].get_ips(ip))
                {
                    cout << "hello\n";
                    try
                    {
                        moshtari[i].check_expiration_date_for_renewal();
                        renewal(moshtari, i);
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }
                else
                {
                    cout << "There is no such account with this username or ip!\n";
                }
            }
        }

        if (command == "deposit")
        {
            for (size_t i = 0; i < moshtari.size(); i++)
            {
                if (username == moshtari[i].get_username() && moshtari[i].get_ips(ip))
                {
                    try
                    {
                        moshtari[i].check_expiration_date_for_transaction();
                        renewal(moshtari, i);
                    }
                    catch (const std::exception &e)
                    {
                        e.what();
                    }

                    int added_balance = 0;
                    added_balance = convert(s);

                    moshtari[i].set_balance(moshtari[i].get_balance() + added_balance);
                }
                else
                {
                    cout << "There is no such account with this username or ip!\n";
                }
            }
        }

        if (command == "transfer")
        {
            for (size_t i = 0; i < moshtari.size(); i++)
            {
                if (username == moshtari[i].get_username() && moshtari[i].get_ips(ip)) // for beginning account
                {
                    try
                    {
                        check_existance_account(moshtari, s);
                        //transaction transition(moshtari[i].get_username(), s, transfer_money);
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }
                else
                {
                    cout << "The beginning account doesn`t exist with these username or ip!\n";
                }
            }
        }
    }
    return 0;
}
