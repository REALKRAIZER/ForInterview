#include <iostream>
#include "sales.h"
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    double vals1[12] =
    {
        1220, 1100, 1122, 2212, 1232, 2334,
        2884, 2393, 3302, 2922, 3002, 3544
    };
    double vals2[12] =
    {
        12, 11, 22, 21, 32, 34,
        28, 29, 33, 29, 32, 35
    };
    Sales sales1(2004, vals1, 12);
    LabeledSales sales2("Blogstar",2005, vals2, 12 );
    cout << "Первый блок try:\n";
    try
    {
        int i;
        cout << "Год = " << sales1.Year() << endl;
        for (i = 0; i < 12; ++i)
        {
            cout << sales1[i] << ' ';
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "Год = " << sales2.Year() << endl;
        cout << "Метка = " << sales2.Label() << endl;
        for (i = 0; i <= 12; ++i)
        {
            cout << sales2[i] << ' ';
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "Конец первого блока try.\n";
    }
    catch(Sales::bad_index & bad)
    {
        try
        {
            LabeledSales::nbad_index & nbad = dynamic_cast<LabeledSales::nbad_index &> (bad);
            cout << nbad.what();
            cout << "Компания: " << nbad.label_val() << endl;
            cout << "Неверный индекс: " << nbad.bi_val() << endl;
        }
        catch (std::bad_cast &)
        {
            cout << bad.what();
            cout << "Неверный индекс: " << bad.bi_val() << endl;
        }
    }
    cout << "\nСледующий блок try:\n";
    try
    {
        sales2[2] = 37.5;
        sales1[20] = 23345;
        cout << "Конец второго блока try.\n";
    }
    catch(Sales::bad_index & bad)
    {
        try
        {
            LabeledSales::nbad_index & nbad = dynamic_cast<LabeledSales::nbad_index &> (bad);
            cout << nbad.what();
            cout << "Компания: " << nbad.label_val() << endl;
            cout << "Неверный индекс: " << nbad.bi_val() << endl;
        }
        catch (std::bad_cast &)
        {
            cout << bad.what();
            cout << "Неверный индекс: " << bad.bi_val() << endl;
        }
    }
    cout << "Готово.\n";
    return 0;
}