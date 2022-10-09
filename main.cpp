#include <iostream>
#include <fstream>

using namespace std;

class shopping
{

private:
    int productCode;
    float price;
    float discount;
    string productName;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void remov();
    void list();
    void receipt();
};

void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t____________________________\n";
    cout << "\t\t\t\t|                          |\n";
    cout << "\t\t\t\t|   SuperMarket Main Menu  |\n";
    cout << "\t\t\t\t|                          |\n";
    cout << "\t\t\t\t|__________________________|\n";
    cout << "\t\t\t\t                            \n";

    cout << "\t\t\t\t| 1) Administrator         |\n";
    cout << "\t\t\t\t| 2) Buyer                 |\n";
    cout << "\t\t\t\t| 3) Exit                  |\n";

    cout << "\n\t\t\t\t Please Select";
    cin >> choice;

    switch (choice)
    {

    case 1:
        cout << "\t\t\t Please Login \n";
        cout << "\t\t\t Enter Email \n";
        cin >> email;
        cout << "\t\t\t Enter Password \n";
        cin >> password;

        if (email == "md@email.com" && password == "hlw@123")
        {
            administrator();
        }
        else
        {
            cout << "Invalid Email/Password.";
        }
        break;

    case 2:
    {
        buyer();
    }

    case 3:
    {
        exit(0);
    }

    default:
    {
        cout << "Please select from the given options";
    }
    }

    goto m;
}

void shopping ::administrator()
{
m:
    int choice;
    cout << "\n\n\n\t\t\t  Administrator Menu";
    cout << "\n\t\t\t|  1) Add the product     |";
    cout << "\n\t\t\t|                         |";
    cout << "\n\t\t\t|  2) Modify the product  |";
    cout << "\n\t\t\t|                         |";
    cout << "\n\t\t\t|  3) Delete the product  |";
    cout << "\n\t\t\t|                         |";
    cout << "\n\t\t\t|  4) Back to main menu   |";

    cout << "\n\n\t Please enter your choice ";
    cin >> choice;

    switch (choice)
    {

    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        remov();
        break;

    case 4:
        menu();
        break;

    default:
        cout << "Invalid choice";
    }
    goto m;
}

void shopping ::buyer()
{
m:
    int choice;
    cout << "\t\t\t      Buyer         \n";
    cout << "\t\t\t                    \n";
    cout << "\t\t\t|  1) Buy Product  |\n";
    cout << "\t\t\t|                  |\n";
    cout << "\t\t\t|  2) Go Back      |\n";

    cout << "\t\t\t Enter your choice: ";
    cin >> choice;

    switch (choice)
    {

    case 1:
        receipt();
        break;

    case 2:
        menu();

    default:
        cout << "Invalid choice";
    }

    goto m;
}

void shopping ::add()
{
m:
    fstream data;
    int c; // product code
    int token = 0;
    float p;  // price of product
    float d;  // discount on product
    string n; // name of product

    cout << "\n\n\t\t\t Add new product";
    cout << "\n\n\t Product code of the product ";
    cin >> productCode;
    cout << "\n\n\t Name of the product ";
    cin >> productName;
    cout << "\n\n\t Price of the product ";
    cin >> price;
    cout << "\n\n\t Discount on the product ";
    cin >> discount;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << productCode << " " << productName << " " << price << " " << discount << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;

        while (!data.eof())
        {

            if (c == productCode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
        {
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << productCode << " " << productName << " " << price << " " << discount << "\n";
            data.close();
        }
    }

    cout << "\n\n\t\t\t Record inserted!";
}

void shopping ::edit()
{
    fstream data1, data2;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code: ";
    cin >> pkey;

    data1.open("database1.txt", ios::in);
    if (!data1)
    {
        cout << "\n\n File doesn't exist!";
    }
    else
    {
        data2.open("database2.txt", ios::app | ios::out);

        data1 >> productCode >> productName >> price >> discount;

        while (!data1.eof())
        {
            if (pkey == productCode)
            {
                cout << "\n\t\t Product new code : ";
                cin >> c;
                cout << "\n\t\t Name of the product : ";
                cin >> n;
                cout << "\n\t\t Price : ";
                cin >> p;
                cout << "\n\t\t Discount : ";
                cin >> d;

                data2 << " " << c << "" << n << "" << p << "" << d << "\n";
                cout << "\n\t\t Record edited!";
                token++;
            }
            else
            {
                data2 << "" << productCode << "" << productName << "" << price << "" << discount << "\n";
            }
            data1 >> productCode >> productName >> price >> discount;
        }
        data1.close();
        data2.close();

        remove("database1.txt");
        rename("database2.txt", "database1.txt");

        if (token == 0)
        {
            cout << "\n\n Sorry! Record not found.";
        }
    }
}

void shopping ::remov()
{
    fstream data, data1;
    int pkey;
    int token = 0;

    cout << "\n\n\t Delete Product";
    cout << "\n\n\t Product code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "File doesn't exist";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> productCode >> productName >> price >> discount;

        while (!data.eof())
        {
            if (productCode == pkey)
            {
                cout << "\n\n\t Product deleted successfully";
                token++;
            }
            else
            {
                data1 << "" << productCode << "" << productName << "" << price << "" << discount << "\n";
            }
            data >> productCode >> productName >> price >> discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found.";
        }
    }
}

void shopping ::list()
{

    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|__________________________________________________\n";
    cout << "ProNo\ttName\t\tPrice\n";
    cout << "\n\n|__________________________________________________\n";
    data >> productCode >> productName >> price >> discount;

    while (!data.eof())
    {
        cout << productCode << "\t\t" << productName << "\t\t" << price << "\n";
        data >> productCode >> productName >> price >> discount;
    }
    data.close();
}

void shopping ::receipt()
{
m:
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t RECEIPT";
    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "\n\n Empty database";
    }
    else
    {
        data.close();
        list();

        cout << "\n_________________________________\n";
        cout << "\n                                 \n";
        cout << "\n     Please Place the order      \n";
        cout << "\n                                 \n";
        cout << "\n_________________________________\n";

        do
        {
            cout << "\n\n Enter the Product name : ";
            cin >> arrc[c];
            cout << "\n\n Enter the Product quantity : ";
            cin >> arrq[c];

            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate productcode. Please try again";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product? If yes then press Y else N";
            cin >> choice;
        } while (choice == 'y');

        cout << "\n\n\t\t\t________________Receipt__________________\n";
        cout << "\n Product No. \t Product Name \t Product quantity \t Price \t Amount \t Amount with discount \n";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);

            data >> productCode >> productName >> price >> discount;

            while (!data.eof())
            {
                if (productCode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * discount / 100);
                    total = total + dis;

                    cout << "\n"
                         << productCode << "\t\t" << productName << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << discount;
                }

                data >> productCode >> productName >> price >> discount;
            }
        }
        data.close();
    }

    cout << "\n\n_________________";
    cout << "\n Total Amount : " << total;
}

int main()
{
    shopping s;
    s.menu();
}