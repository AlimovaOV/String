#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    cout << str << endl;
    string::size_type n = str.find("  "); //������� ������� �������
    while (n != string::npos)
    {
        str.erase(n, 1);
        n = str.find("  "); // ��� �������
    }
    cout << str << endl;
    if (str[0] != ' ')                 //��������� ������ ���� ���, ��������� ���� ������ ����� ��������� � ���������
        str = " " + str;
    if (str[str.size() - 1] == ' ')    // ������� ������ � ����� ������
        str.erase(str.size() - 1, 1);
    cout << '|' << str << '|' << endl;  //� ������ ����� ���� ������ ����� ������ ������ � ��������� ������ �� ������
    n = str.rfind(" "); // ���� ������   // ��������� ������ ������, �� ��� ��������� �����
    string lastword = str.substr(n + 1);
    cout << '|' << lastword << '|' << endl;
    lastword = " " + lastword + " ";     //������ ����� ���� �������, ��������� ������ ����� �������� ������ ������� �����
    n = str.find(lastword);
    while (n != string::npos)
    {
        str.erase(n, lastword.size() - 1);
        n = str.find(lastword);
    }
    n = str.find(" "); // ���� ������  // ������� ������ � ������ ������
     if (n == 0)
        str.erase(n, 1);
    cout << '|' << str << '|' << endl;
    return 0;

}
