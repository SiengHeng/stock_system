
using namespace std;

void searchLaptop(List *ls){
    Element *tmp = ls->head;
    int id_s;
    bool found = false;

    cout << "Enter id to search: "; cin >> id_s;
    while(tmp != NULL){
        if(tmp->id == id_s){
            found = true;
            cout << "Laptop is found." << endl;
            cout<< "----------------------" << endl;
            cout << "Name: " << tmp->name << endl;
            cout << "ID: " << tmp->id << endl;
            cout << "Storage: " << tmp->storage << "GB" << endl;
            cout << "Ram: " << tmp->ram << "GB" << endl;
            cout << "Price: $" << tmp->price << endl;    
            cout << "Year: " << tmp->year << endl;
            cout<< "----------------------" << endl;
            break;
        }
        tmp = tmp->next;
    }
    if(!found){
        cout << "Laptop is not found in stock." << endl;
    }
}

void employee_login(List *ls){
    int id_emp;
    int input_emp;
    string name;
    system("color 9f");
    system("cls");
    cout << "\t===============*** Employee's Page ***=================" << endl;
    while(true){
        cout << "Enter employee's ID: "; cin >> id_emp;
        if(id_emp == 1001 ||  id_emp == 1002){
            if(id_emp == 1001){
                name = "Jonh";
            }
            if(id_emp == 1002){
                name = "Jecop";
            }
            loading();
            cout << "Employee name's " << name << ", have access to page." << endl;
            while(id_emp == 1001 ||  id_emp == 1002){
                file_stockCSV(ls);
                display_menu_employee();
                cout <<"Enter menu's number to access to: ";
                cin>>input_emp;
                if(input_emp == 1){
                    cout << "You have now log off as " << name << endl;
                    break;
                }
                else if(input_emp == 2){
                    loading();
                    readFile();
                }
                else if(input_emp == 3){
                    import_more(ls);
                }
                else if (input_emp == 4){
                    addStock(ls);
                }
                else if(input_emp == 5){
                    searchLaptop(ls);
                }
                else if(input_emp == 6){
                    cout<<"you have exit the program"<<endl;
                    break;
                }
                else{
                    cout<<"please try again"<<endl;
                }
            }

        }
        else {
      cout << "\t***Employee ID's " << id_emp << ", doesn't exit." << endl;
        }
        if(input_emp == 6){break;}
    }
};