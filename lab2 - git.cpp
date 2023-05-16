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
## Варіант #1
Ваше завдання: визначити список країн-переможців у конкурсі Допобачення-2020.
На вхід подається назва директорії, всередині якої необхідно зчитати всі текстові файли .csv.
Всі всі такі файли в папці з прикладами та вашим варіантом, мають такий формат `Країна, кількість голосів за у країні №1-№20`, наприклад:
```csv
1
Ukraine,78000,6156,495,7,9456460,45645,21213,898...
```
Перший рядок містить кількість країн, що знаходяться в кожному з файлів.
Кожен наступний рядок містить кількість голосів від кожної з країн-учасниць.
У прикладі вище Україна отримала 78000 голосів від країни №1, 6156 голосів від країни №2 тощо.
Країна, що набрала найбільшу кількість голосів (в стовпчику) отримує 12 балів, друге місце – 10, з третього по десяте – 8-1 бал відповідно.
Необхідно порахувати сумарну кількість балів за кожну країну і вивести топ-10 переможців у текстовий файл.

#### Вхідні та вихідні дані
На вхід програми подається назва теки. Вивід – файл results.csv з результатами найкращих десяти країн Допобачення-2020.
Вихідні дані повинні містити єдиний результат виконання для всіх файлів вхідної директорії.
*/
