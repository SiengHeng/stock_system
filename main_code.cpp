#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <sstream>

#include "display.h"
#include "system.h"
#include "admin.h"
#include "employee.h"
#include "customer.h"
using namespace std;

void display_menu_login();
void display_menu_admin();
void display_menu_employee();
void display_menu_customer();

// System
void loading();
struct Element;
struct List;
List* createEmptyList();

void insert_stock(List *ls);
void file_stockCSV(List *ls);

// Admin page
void readFile();
void updatePrice(List *ls);
void addStock(List *ls);
void import_more(List *ls);
void deleteLaptop(List *ls);
void admin_login(List *ls);

// Employee page
void readFile();
void import_more(List *ls);
void addStock(List *ls);
void searchLaptop(List *ls);
void employee_login(List *ls);

// Customer page
void readFile();
void addToCart(List* ls);
void removeFromCart(List* ls, int id);
void viewCart(List* ls);
void buyLaptop(List* ls, string name);
void customer_login(List* ls);

int main(){
    List *ls;
    ls = createEmptyList();
    insert_stock(ls);
    int login;
    while(true){
        system("color 70");
        system("cls");
        display_menu_login();
        cout << "You are trying to access as: "; cin >> login;
        if(login == 1){
            admin_login(ls);
        }
        else if(login == 2){
            employee_login(ls);
        }
        else if(login == 3){
            customer_login(ls);
        }
        else if(login == 4){
            system("color 07");
            system("cls");
            cout << "\t===================================================" << endl;
            cout << "\t* You have been exitting the program successfully *" << endl;
            cout << "\t===================================================" << endl;
            break;
        }
        else{
            cout << "Invalid input." << endl; 
        }
    }
}