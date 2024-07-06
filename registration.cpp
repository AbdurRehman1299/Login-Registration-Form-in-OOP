#include <iostream>
#include <fstream>
// #include<windows.h> -> using in Windows for (Sleep) function
#include <unistd.h> //  -> using in Mac for (sleep) function
using namespace std;
class Form
{
private:
    string userName, email, password;
    string searchName, searchEmail, searchPassword;
    fstream formFile;
    char formChoice;

public:
    Form()
    {
        userName = "";
        email = "";
        password = "";
        searchName = "";
        searchEmail = "";
        searchPassword = "";
    }
    void createAccount();
    void login();
    void forgetPassword();
    void showMenu()
    {
        // system("cls"); -> For Windows
        system("clear"); //-> For Mac
        cout << "---------------------------------------------------\n\n";
        cout << "    Welcome to User Registration and Login Form    \n\n";
        cout << "---------------------------------------------------\n\n";
        cout << "1. Create an Account\n";
        cout << "2. Login into Account\n";
        cout << "3. Forget Password\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
    Form:
        cin >> formChoice;
        switch (formChoice)
        {
        case '1':
            createAccount();
            break;
        case '2':
            login();
            break;
        case '3':
            forgetPassword();
            break;
        case '4':
            cout << "Exiting the program...\n";
            // Sleep(2000); -> For Windows
            sleep(2); // -> For Mac
            exit(0);
        default:
            cout << "Invalid choice. Please try again: ";
            goto Form;
        }
    }
};
int main()
{
    Form userForm;
    userForm.showMenu();
    return 0;
}
void Form::createAccount()
{
    // system("cls"); -> For Windows
    system("clear"); //-> For Mac
    cout << "---------------------------------------------------\n\n";
    cout << "                 Creating an Account               \n\n";
    cout << "---------------------------------------------------\n\n";
    cout << "Enter your username: ";
    cin.ignore();
    getline(cin, userName);
    cout << "Enter your email: ";
    getline(cin, email);
    cout << "Enter your password: ";
    getline(cin, password);
    formFile.open("userData.txt", ios::app);
    formFile << userName << "|" << email << "|" << password << "\n";
    formFile.close();
    cout << "\nAccount created successfully.\n";
    // Sleep(2000); -> For Windows
    sleep(2); // -> For Mac
    showMenu();
}
void Form::login()
{
    // system("cls"); -> For Windows
    system("clear"); //-> For Mac
    cout << "---------------------------------------------------\n\n";
    cout << "                  Login into Account               \n\n";
    cout << "---------------------------------------------------\n\n";
    cout << "Enter your username: ";
    cin.ignore();
    getline(cin, searchName);
    cout << "Enter your password: ";
    getline(cin, searchPassword);
    formFile.open("userData.txt", ios::in);
    getline(formFile, userName, '|');
    getline(formFile, email, '|');
    getline(formFile, password, '\n');
    while (!formFile.eof())
    {
        if (userName == searchName && password == searchPassword)
        {
            cout << "\nLogin successful.\n";
            // Sleep(2000); -> For Windows
            sleep(2); // -> For Mac
        }
        getline(formFile, userName, '|');
        getline(formFile, email, '|');
        getline(formFile, password, '\n');
        if (formFile.eof() && userName != searchName && password != searchPassword)
        {
            cout << "\nInvalid credentials. Please try again.\n";
            // Sleep(2000); -> For Windows
            sleep(2); // -> For Mac
            formFile.close();
            login();
        }
    }
    formFile.close();
}
void Form::forgetPassword()
{
    // system("cls"); -> For Windows
    system("clear"); //-> For Mac
    cout << "---------------------------------------------------\n\n";
    cout << "                Forgetting Password                \n\n";
    cout << "---------------------------------------------------\n\n";
    cout << "Enter your username: ";
    cin.ignore();
    getline(cin, searchName);
    formFile.open("userData.txt", ios::in);
    getline(formFile, userName, '|');
    getline(formFile, email, '|');
    getline(formFile, password, '\n');
    while (!formFile.eof())
    {
        if (userName == searchName)
        {
            cout << "\nYour password is: " << password << "\n";
            // Sleep(2000); -> For Windows
            sleep(2); // -> For Mac
            showMenu();
        }
        getline(formFile, userName, '|');
        getline(formFile, email, '|');
        getline(formFile, password, '\n');
        if (formFile.eof() && userName != searchName)
        {
            cout << "\nUser not found. Please try again.\n";
            // Sleep(2000); -> For Windows
            sleep(2); // -> For Mac
            formFile.close();
            forgetPassword();
        }
    }
    formFile.close();
}