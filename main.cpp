#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

class shopping
{
private:
    int pcode;
    float price;
    float discount;
    string pname; //p stands for product
public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();// a function to delete products
    void display();
    void receipt();
};

void shopping::menu()
{
    m:              //is a level we put for our goto function
    int choice;
    string email;
    string password;//this will be used for the login purpose
    cout<<"\n";
    cout<<"\t\t\t\t______________________\n";
    cout<<"\t\t\t\t                      \n";
    cout<<GREEN<<"\t\t\t\t    MAIN MENU         \n"<<RESET;
    cout<<"\t\t\t\t                      \n";
    cout<<"\t\t\t\t______________________\n";
    cout<<"\t\t\t\t                      \n";
    cout<<"\t\t\t\t 1)Adiminstrator |\n";
    cout<<"\t\t\t\t                 |    \n";
    cout<<"\t\t\t\t 2)Buyer         |\n";
    cout<<"\t\t\t\t                 |     \n";
    cout<<"\t\t\t\t 3)exit          |\n\n";
    cout<<"\t\t\t\t please select: ";

    cin>>choice;
    system("cls");
    switch(choice)
    {
    case 1:
        cout<<"please login. \n";
        cout<<"Enter Email: ";
        cin>>email;
        cout<<"Password: ";
        cin>>password;

        if(email=="admin@gmail.com"&& password=="AD@12345")
        {
            administrator();
        }
        else
        {
            cout<<RED<<"Invalid email or password."<<RESET;
        }
        break;
    case 2:
        {
            buyer();
            break;
        }
    case 3:
        {
            exit(0);
            break;
        }
    default ://default case will execute if a person selects other than 1,2 or 3
        {
            cout<<"please select from the given options: ";
            goto m;
        }

    }

goto m;//go to is a jump statement ,so it will help us jumping to the main menu again after the completion of the switch case
}


void shopping::administrator()
{
    system("cls");
    m:
    int choice;
    cout<<GREEN<<"\n\n\n\t\t\t Administrator Menu"<<RESET;
    cout<<"\n\t\t\t|____1)Add a product_____|";
    cout<<"\n\t\t\t|                        |";
    cout<<"\n\t\t\t|____2)Modifiy a product_|";
    cout<<"\n\t\t\t|                        |";
    cout<<"\n\t\t\t|____3)Delete a product__|";
    cout<<"\n\t\t\t|                        |";
    cout<<"\n\t\t\t|____4)Back to main menu_|";
    cout<<"\n\t\t\t|                        |";
    cout<<"\n\t\t\t|please enter your choice|";

    cin>>choice;
    system("cls");
    switch(choice)
    {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default :
            cout<<"invalid choice!";
    }
    goto m;
}

void shopping :: buyer()
{
    m:
    int choice;
    cout<<GREEN<<"\t\t\tBuyer \n"<<RESET;
    cout<<" \n\n";
    cout<<"\t\t\t 1)Buy product\n";
    cout<<"\n\n";
    cout<<"\t\t\t 2)Go back\n\n";
    cout<<"\t\t Enter your choice: ";
    cin>>choice;

    system("cls");
    switch(choice)
    {
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default :
            cout<<RED<<"invalid choice!" <<RESET;
    }
    goto m;
}

void shopping ::add()
{
    m:
    system("cls");
    int c;
    string n;
    float p;
    float d;
    fstream data;
    cout << GREEN << "\n\n\t\t\t Add a product  " << RESET;
    cout << "\n\n\t product code of the product : ";
    if (!(cin >> pcode))
    {
        cout << RED << "\nInvalid input. Please try again.\n" << RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    data.open("store.txt", ios::in);
    if (data.is_open())
    {
        while (data >> c >> n >> p >> d)
        {
            if (pcode == c)
            {
                cout << RED << "\nProduct code already exists. Please choose a different code.\n" << RESET;
                data.close();
                return;
            }
        }
        data.close();
    }

    cout << "\n\n\t name of product : ";
    cin >> pname;

    cout << "\n\n\t Price of product :$";
    if (!(cin >> price))
    {
        cout << RED << "\nInvalid input. Please try again.\n" << RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "\n\n\t Discount on product :%";
    if (!(cin >> discount))
    {
        cout << RED << "\nInvalid input. Please try again.\n" << RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    data.open("store.txt", ios::app| ios::out);
    if (!data.is_open())
    {
        cout<<RED<<"\nError Occured\n.";
        data.close();
        goto m;
    }
    else
    {       
        data<<pcode<<" "<<" "<<pname<<" "<<price<<" "<<discount<<endl;
        cout<<GREEN<<"\nRecord inserted.\n"<<RESET;
        data.close();
        administrator();
    }
    system("cls");
    return; 
}

void shopping::edit()
{
    m:
    
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << GREEN << "\n\t\t\t Modify the record" << RESET;
    cout << "\n\t\t\t product code: ";

    if (!(cin >> pkey))
    {
        cout << RED << "\nInvalid input. Please try again.\n" << RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto m;
    }

    data.open("store.txt", ios::in); // Open for reading

    if (!data.is_open())
    {
        cout << RED << "\nFile doesn't exist!\n" << RESET;
        goto m;
    }
    else
    {
        data1.open("temp.txt", ios::out); // Open a temporary file for writing

        while (data >> c >> n >> p >> d)
        {
            if (pkey == c)
            {
                cout << "\n\t\t new product code: ";
                cin >> c;
                cout << "\n\t\t new name of the product: ";
                cin >> n;
                cout << "\n\t\t new price: $";
                cin >> p;
                cout << "\n\t\t new discount: %";
                cin >> d;
                data1 << c << " " << n << " " << p << " " << d << endl;
                cout << GREEN << "\n\t\t Record edited" << RESET;
                token++;
                administrator();
            }
            else
            {
                data1 << c << " " << n << " " << p << " " << d << endl;
            }
        }

        data.close();
        data1.close();

        remove("store.txt");
        rename("temp.txt", "store.txt");

        if (token == 0)
        {
            cout << RED << "\n\n Record not found!" << RESET;
        }
    }
    system("cls");
    goto m;
}


void shopping::rem()
{
    m:
    system("cls");
    fstream data;
    int pkey;
    int token = 0;
    int c;
    string n;
    float p;
    float d;

    cout << GREEN << "\n\t\t\t Delete product" << RESET;
    cout << "\n\t\t\t Product code: ";

    if (!(cin >> pkey))
    {
        cout << RED << "\nInvalid input. Please try again.\n" << RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto m;
    }

    data.open("store.txt", ios::in); // Check if the file exists

    if (!data.is_open())
    {
        cout << RED << "File doesn't exist or cannot be opened!" << RESET;
        administrator();
    }
    else
    {
        ofstream tempFile("temp.txt"); // Create a temporary file for writing

        while (data >> c >> n >> p >> d)
        {
            if (pkey == c)
            {
                cout << GREEN << "\nProduct deleted successfully" << RESET;
                token++;
                administrator();
            }
            else
            {
                tempFile << c << " " << n << " " << p << " " << d << endl;
            }
        }

        data.close();
        tempFile.close();

        if (token == 0)
        {
            cout << RED << "\n\nRecord cannot be found\n" << RESET;
        }
        else
        {
            // Remove the original file and rename the temporary file
            remove("store.txt");
            if (rename("temp.txt", "store.txt") != 0)
            {
                cout << RED << "\nError renaming the file." << RESET;
            }
        }
    }
    goto m;

}


void shopping::display()
{
    system("cls");
    fstream data;
    data.open("store.txt", ios::in);

    cout << "\n\n____________________________________________\n";
    cout << "Product Code\tProduct Name\tPrice\tDiscount\n";
    cout << "____________________________________________\n";

    int c;
    string n;
    float p;
    float d;

    while (data >> c >> n >> p >> d)
    {
        cout << c << "\t\t" << n << "\t\t$" << p << "\t" << d << "%" << endl;
    }

    data.close();
}

void shopping::receipt()
{

    system("cls");
    fstream data;

    int arrc[100]; // Array of product codes
    int arrq[100]; // Array of quantities
    char choice;
    int c = 0;     // Counter for products
    float amount = 0;
    float dis = 0; // Discount
    float total = 0;

    cout << GREEN << "\n\n\t\t\t\t RECEIPT " << RESET;

    data.open("store.txt", ios::in);

    if (!data)
    {
        cout << "\n\n Empty database";
    }
    else
    {
        data.close();
        display(); // Display the list of available products
        cout << "\n___________________________________________\n";
        cout << "\n                                           \n";
        cout << GREEN << "\n        Please place the order             \n" << RESET;
        cout << "\n                                           \n";
        cout << "\n___________________________________________\n";

        do
        {
            m:
            cout << "\n\nEnter product code: ";
            cin >> arrc[c];

            cout << "\n\nEnter product quantity: ";
            cin >> arrq[c];

            if(arrq[c]<=0)
            {
                cout<<RED<<"Invalid quantity."<<RESET;
            }
            // Check for duplicate product codes
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    arrq[i] += arrq[c];
                }
            }

            c++; // Increment the counter for products

            cout << "\n\n Do you want to buy another product? (Press 'y' for yes, 'n' for no): ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
        system("cls");
        cout << "\n\n\t\t\t______________________RECEIPT______________________\n";
        cout << "\n Product Code \t Product Name\t Product Quantity\tPrice\tAmount with Discount\n";

        for (int i = 0; i < c; i++)
        {
            data.open("store.txt", ios::in);
            data >> pcode >> pname >> price >> discount;

            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * discount) / 100;
                    total += dis;

                    cout <<"\t"<< pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t$" << price <<"\t$" << dis << endl;
                }

                data >> pcode >> pname >> price >> discount;
            }

            data.close();
        }

        cout << "\n\n___________________________________________________________";
        cout << "\n Total Amount : $" << total;
        cout << "\n\n___________________________________________________________";
    }
}





int main(){
std::cout << GREEN<< R"(



  ______ ____  _    _ _____    ____   ______   __  __          _____ _______
 |  ____/ __ \| |  | |  __ \  |  _ \ |  ____| |  \/  |   /\   |  __ |__   __|
 | |__ | |  | | |  | | |__) | | |_) || |__    | \  / |  /  \  | |__) | | |
 |  __|| |  | | |  | |  _  /  |  _ < |  __|   | |\/| | / /\ \ |  _  /  | |
 | |   | |__| | |__| | | \ \ _| |_) _| |      | |  | |/ ____ \| | \ \  | |
 |_|    \____/ \____/|_|  \_(_|____(_|_|      |_|  |_/_/    \_|_|  \_\ |_|
^^^!.
    ^!
     7~^^^^^^^^^^^^^^^^^^^^^^
     :7::^7^::!!:::7^::~7::~!
       !^  ~::~!:::7  !~::7:
       !^:^!::^7::^7::^7::!^
       ^!  7^:^7::^! ~!:^!
        ^:^^::::::::^^:^^

        :^^^.        :^^^.

)" <<RESET<< '\n';



shopping s;
s.menu();

return 0;

}