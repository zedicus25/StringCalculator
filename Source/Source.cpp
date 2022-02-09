#include <iostream>
#include <string>
using namespace std;

int main()
{
    int result = 0;
    string rightValues = "1234567890()+-*/";
    string str = "2+30/10*10+3";
    string::iterator itr = str.begin();
    string::iterator tmpItr = itr;
    int res = 0;

    if (str.find_first_not_of(rightValues) == string::npos) {
        string num1;
        string num2;
        char action;
        while (itr != str.end())
        {
            int pos1;
            int pos2;
            if (*itr == '*' || *itr == '/') {
                action = *itr == '*' ? '*' : '/';
                tmpItr = itr;
                tmpItr--;
                while (true)
                {
                    if (tmpItr == str.begin()) {
                        pos1 = distance(str.begin(), tmpItr);
                        num1 = *tmpItr + num1;
                        break;
                    }
                    else if (*tmpItr == '+' || *tmpItr == '-' || *tmpItr == '/' || *tmpItr == '*') {
                        pos1 = distance(str.begin(), tmpItr) + 1;
                        break;
                    }
                    else {
                        num1 = *tmpItr + num1;
                        tmpItr--;
                    }
                }

                tmpItr = itr;
                tmpItr++;
                while (true)
                {
                    if (tmpItr == str.end()) {
                        pos2 = distance(str.begin(), tmpItr);
                        break;
                    }
                    else if (*tmpItr == '+' || *tmpItr == '-' || *tmpItr == '/' || *tmpItr == '*') {
                        pos2 = distance(str.begin(), tmpItr);
                        break;
                    }
                    else {
                        num2 += *tmpItr;
                        tmpItr++;
                    }
                }

                if (action == '*') {
                    res = atoi(num1.c_str()) * atoi(num2.c_str());
                    num1.clear();
                    num2.clear();
                    str.replace(pos1, pos2 - pos1, std::to_string(res));
                    itr = str.begin();
                }
                if (action == '/') {
                    res = atoi(num1.c_str()) / atoi(num2.c_str());
                    num1.clear();
                    num2.clear();
                    str.replace(pos1, pos2 - pos1, std::to_string(res));
                    itr = str.begin();
                }
            }
            if (str.find("*") == -1 && str.find("/") == -1) {
                if (*itr == '+' || *itr == '-') {
                    action = *itr == '+' ? '+' : '-';
                    tmpItr = itr;
                    tmpItr--;
                    while (true)
                    {
                        if (tmpItr == str.begin()) {
                            pos1 = distance(str.begin(), tmpItr);
                            num1 = *tmpItr + num1;
                            break;
                        }
                        else if (*tmpItr == '+' || *tmpItr == '-' || *tmpItr == '/' || *tmpItr == '*') {
                            pos1 = distance(str.begin(), tmpItr) + 1;
                            break;
                        }
                        else {
                            num1 = *tmpItr + num1;
                            tmpItr--;
                        }
                    }

                    tmpItr = itr;
                    tmpItr++;
                    while (true)
                    {
                        if (tmpItr == str.end()) {
                            pos2 = distance(str.begin(), tmpItr);
                            break;
                        }
                        else if (*tmpItr == '+' || *tmpItr == '-' || *tmpItr == '/' || *tmpItr == '*') {
                            pos2 = distance(str.begin(), tmpItr);
                            break;
                        }
                        else {
                            num2 += *tmpItr;
                            tmpItr++;
                        }
                    }

                    if (action == '+') {
                        res = atoi(num1.c_str()) + atoi(num2.c_str());
                        num1.clear();
                        num2.clear();
                        str.replace(pos1, pos2 - pos1, std::to_string(res));
                        itr = str.begin();
                    }
                    if (action == '-') {
                        res = atoi(num1.c_str()) - atoi(num2.c_str());
                        num1.clear();
                        num2.clear();
                        str.replace(pos1, pos2 - pos1, std::to_string(res));
                        itr = str.begin();
                    }
                }
            }
            itr++;
        }
           
    }
    else{
        cout << "Incorrect input\n";
    }

    cout << res;
}