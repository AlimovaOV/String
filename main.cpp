#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    cout << str << endl;
    string::size_type n = str.find("  "); //удаляем двойные пробелы
    while (n != string::npos)
    {
        str.erase(n, 1);
        n = str.find("  "); // два пробела
    }
    cout << str << endl;
    if (str[0] != ' ')                 //добавляем пробел если нет, необходим если первое слово совпадает с последним
        str = " " + str;
    if (str[str.size() - 1] == ' ')    // удаляем пробел в конце строки
        str.erase(str.size() - 1, 1);
    cout << '|' << str << '|' << endl;  //в строке точно есть пробел перед первым словом и последний символ не пробел
    n = str.rfind(" "); // один пробел   // последний пробел справа, за ним последнее слово
    string lastword = str.substr(n + 1);
    cout << '|' << lastword << '|' << endl;
    lastword = " " + lastword + " ";     //искать слово надо целиком, исключить случаи когда является частью другого слова
    n = str.find(lastword);
    while (n != string::npos)
    {
        str.erase(n, lastword.size() - 1);
        n = str.find(lastword);
    }
    n = str.find(" "); // один пробел  // удалить пробел в начале строки
     if (n == 0)
        str.erase(n, 1);
    cout << '|' << str << '|' << endl;
    return 0;

}
