#pragma once
#include <iostream>
#include "Reader.h"
#include "Parser.h"
#include "Dopobachennia.h"

using namespace std;

int main()
{
    //cout << "Enter the name of directory: ";
    string dir = "C:\\labs\\lab2\\var1";
    //getline(cin, dir);

    Reader reader(dir);
    if (reader.CheckDirectory()) {
        Dopobachennia dp(reader.GetCountriesNum());
        for (int i = 0; i < reader.GetFilesNum(); i++) {
            try {
                Parser parser(reader.ReadFile(), reader.GetCountriesNum(), reader.GetFileName(i));
                parser.ProcessFile();
                dp.AppendTable(parser.GetCountries(), parser.GetPoints(), parser.GetCount());
            }
            catch (string error_messsage) {
                cout << error_messsage;
                exit(1);
            }
        }
        dp.ProcessAll();
        reader.WriteIntoFile(dp.GetTop());
    }
    else {
        cout << "Error with the directory. Try again:(\n";
    }
}


/*
## ������ #1
���� ��������: ��������� ������ ����-���������� � ������� �����������-2020.
�� ���� �������� ����� ��������, �������� ��� ��������� ������� �� ������� ����� .csv.
�� �� ��� ����� � ����� � ���������� �� ����� ��������, ����� ����� ������ `�����, ������� ������ �� � ���� �1-�20`, ���������:
```csv
1
Ukraine,78000,6156,495,7,9456460,45645,21213,898...
```
������ ����� ������ ������� ����, �� ����������� � ������� � �����.
����� ��������� ����� ������ ������� ������ �� ����� � ����-��������.
� ������� ���� ������ �������� 78000 ������ �� ����� �1, 6156 ������ �� ����� �2 ����.
�����, �� ������� �������� ������� ������ (� ���������) ������ 12 ����, ����� ���� � 10, � �������� �� ������ � 8-1 ��� ��������.
��������� ���������� ������� ������� ���� �� ����� ����� � ������� ���-10 ���������� � ��������� ����.

#### ����� �� ������ ���
�� ���� �������� �������� ����� ����. ���� � ���� results.csv � ������������ ��������� ������ ���� �����������-2020.
������ ��� ������ ������ ������ ��������� ��������� ��� ��� ����� ������ ��������.
*/
