#include <iostream>
#include <string>
using namespace std;
string setNumber(string::iterator itr, string& userInput, int& pos, bool first);
int action(char action, string& num1, string& num2, string& userInput, int pos1, int pos2, string::iterator& itr);
bool isCorrect(string& userInput);

int main()
{
    int result = 0;
    string rightValues = "1234567890+-*/";
    string str = "";
    string userInput = "";
    cout << "Enter an example without brackets: \n";
    getline(cin, userInput);
    str = userInput;
    string::iterator itr = str.begin();

    if (str.find_first_not_of(rightValues) == string::npos) {
       
        if (isCorrect(str) == false)
            return 1;
        string num1;
        string num2;
        char act;
        while (itr != str.end())
        {
            int pos1;
            int pos2;
            if (*itr == '*' || *itr == '/') {
                act = *itr == '*' ? '*' : '/';

                num1 = setNumber(itr, str, pos1, true);

                num2 = setNumber(itr, str, pos2, false);

                result = action(act, num1, num2, str, pos1, pos2, itr);
               
            }
            if (str.find("*") == -1 && str.find("/") == -1) {
                if (*itr == '+' || *itr == '-') {
                    act = *itr == '+' ? '+' : '-';

                    num1 = setNumber(itr, str, pos1, true);

                    num2 = setNumber(itr, str, pos2, false);

                    result = action(act, num1, num2, str, pos1, pos2, itr);
                }
            }
            itr++;
        }   
    }
    else{
        cout << "Incorrect input\n";
    }

    cout << "Result " << userInput << " is " << result << endl;
}

string setNumber(string::iterator itr, string& userInput, int& pos, bool first)
{
    string num;

    if (first) {
        itr--;
        while (true)
        {
            if (itr == userInput.begin()) {
                pos = distance(userInput.begin(), itr);
                num = *itr + num;
                break;
            }
            else if (*itr == '+' || *itr == '-' || *itr == '/' || *itr == '*') {
                pos = distance(userInput.begin(), itr) + 1;
                break;
            }
            else {
                num = *itr + num;
                itr--;
            }
        }
    }
    else {
        itr++;
        while (true)
        {
            if (itr == userInput.end()) {
                pos = distance(userInput.begin(), itr);
                break;
            }
            else if (*itr == '+' || *itr == '-' || *itr == '/' || *itr == '*') {
                pos = distance(userInput.begin(), itr);
                break;
            }
            else {
                num += *itr;
                itr++;
            }
        }
    }

    return num;
}

int action(char action, string& num1, string& num2, string& userInput, int pos1, int pos2, string::iterator& itr)
{
    int result = 0;
    if (action == '*') {
        result = atoi(num1.c_str()) * atoi(num2.c_str());
    }
    if (action == '/') {
        result = atoi(num1.c_str()) / atoi(num2.c_str());
    }
    if (action == '+') {
        result = atoi(num1.c_str()) + atoi(num2.c_str());
    }
    if (action == '-') {
        result = atoi(num1.c_str()) - atoi(num2.c_str());
    }
    num1.clear();
    num2.clear();
    userInput.replace(pos1, pos2 - pos1,to_string(result));
    itr = userInput.begin();
    return result;
}

bool isCorrect(string& userInput)
{
    string::iterator itr = userInput.begin();
    while (itr != userInput.end())
    {
        if (*itr == '+' || *itr == '-' || *itr == '/' || *itr == '*')
            if (*(itr + 1) == '+' || *(itr + 1) == '-' || *(itr + 1) == '/' || *(itr + 1) == '*') {
                cout << "Incorrect input\n";
                return false;
            }
        itr++;
    }

    return true;
}
