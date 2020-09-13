#include <iostream>
#include <string>
#include <cctype>
#include <stack>
#include <queue>

using namespace std;

void print(void);
string palindromeText(string text);
int palindromeNumber(int num);
bool sentencePalindrome(string str);

int main()
{
    stack<string> Stack;
    queue<string> Queue;
    string text;
    int num;

    print();
    cout << " Examples of palindrome words are: Madam, Radar, Level, Kayak.\n";
    cout << endl;
    cout << " Examples of palindrome numbers are: 123321, 879978, 1221.\n"<< endl;
    print();

    cout << "  Enter a line of text: ";
    getline(cin, text);
    cout << endl;
    for(int i = 0; i < text.length(); i++)
    {
       text[i] = tolower(text[i]);
    }

    Stack.push(text);
    Queue.push(text);

    sentencePalindrome(text);
    if (sentencePalindrome(text))
        cout << "\n     " <<text << " is palindrome.";
    else
        cout << "\n     " <<text << " is not palindrome.";
        cout << endl << endl;
    print();
    //cout << endl;
    palindromeNumber(num);
    cout << endl;
    print();

return 0;
}
/*
**************************
Definitions of Functions
**************************
*/
void print(void)
{
     for (int i=1;i<63;i++)
     cout<<"*";
     cout<<"\n\n";
}
int palindromeNumber(int num)
{
    int reverse = 0,remainder, temp;

    cout << "  Enter the number: ";
    cin >> num;

    temp = num;

    while( temp != 0)
    {
      remainder = temp % 10;
      reverse = reverse * 10 + remainder;
      temp = temp / 10;
    }
    cout << "  Reversed number: " << reverse << endl;

    if (num == reverse)
      cout << "\n     " << num << " is a palindrome number." << endl;
    else
      cout << "\n     " << num << " is not a palindrome number." << endl;
   return 0;
}
bool sentencePalindrome(string str)
{
    int l = 0, h = str.length();

    // Lowercase string
    for (int i = 0; i < h; i++)
        str[i] = tolower(str[i]);

    // Compares character until they are equal
    while (l <= h) {

        // If there is another symbol in left
        // of sentence
        if (!(str[l] >= 'a' && str[l] <= 'z'))
            l++;

        // If there is another symbol in right
        // of sentence
        else if (!(str[h] >= 'a' && str[h] <= 'z'))
            h--;

        // If characters are equal
        else if (str[l] == str[h])
            l++, h--;

        // If characters are not equal then
        // sentence is not palindrome
        else
            return false;
    }

    // Returns true if sentence is palindrome
    return true;
}
