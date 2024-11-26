
using namespace std;

void updatePrice(List *ls){
    int s_id;
    cout << "Enter Laptop's ID: "; cin >> s_id;
    Element *tmp;
    tmp = ls->head;
    bool found = false;
    while(tmp != NULL){
        if(tmp->id == s_id){
            cout << "Name: " << tmp->name << "'s old price: " << tmp->price << "$" << endl;
            cout << "Enter updata's price: $"; cin >> tmp->price;
            if(tmp->price < 0){
                cout << "Failed to update. Price have to be positive number." << endl;
            }
            else{
                cout << "Price has been updated successfully." << endl;
            }
            found = true;
            break;
        }
        tmp = tmp->next;
    }
    if(!found){
        cout << "Laptop name: " << s_id << ", wasn't existed." << endl;
    }
}

void deleteLaptop(List *ls) {
    if (ls->size == 0) {
        cout << "No data to delete." << endl;
    } else {
        Element *tmp = ls->head;
        Element *prev = NULL;
        bool found = false;
        int id;
        
        cout << "Enter ID to delete Laptop: ";
        cin >> id;
        
        while (tmp != NULL) {
            if (tmp->id == id){
                if(prev == NULL) { 
                    ls->head = tmp->next;
                } 
                else {
                    prev->next = tmp->next;
                }
                if(tmp == ls->tail) {
                    ls->tail = prev;
                }
                cout << "You have deleted this model." << endl;
                cout << "----------------------" << endl;
                cout << "Name: " << tmp->name << endl;
                cout << "Storage: " << tmp->storage << "GB" << endl;
                cout << "Ram: " << tmp->ram << "GB" << endl;
                cout << "Year: " << tmp->year << endl;
                cout << "Price: $" << tmp->price << endl;
                cout << "----------------------" << endl;
                delete tmp;
                ls->size--;
                found = true;
                break; 
            }
            prev = tmp;
            tmp = tmp->next;
        }
        
        if (!found) {
            cout << "Laptop with ID: " << id << " was not found in stock." << endl;
        }
    }
}

void admin_login(List *ls){
    string password;
    int menu_num;
    int num = 1, n;
    system("color C0");

    cout << "\t*** Admin's Page ***" << endl;
    while(true){
        cout << "Enter your password: ";
        n = getch();
        while(n != 13){
            if(n >= 32 && n <= 126){
                password.push_back(n);
                cout << '*';
            }
            else if(n == 8 && !password.empty()){
                password.erase(password.size() - 1);
                cout << "\b \b";
            }
            n = getch();   
        }
        if(password == "admin123"){
            cout << endl;
            loading();
            system("cls");
            cout << "\n=============*** You have been accessing to admin page successfully ***============" << endl;
            while(true){
                display_menu_admin();
                file_stockCSV(ls);
                cout << "Enter menu's number to access to: "; 
                cin >> menu_num;
                if(menu_num == 1){
                    loading();
                    readFile();
                }
                else if(menu_num == 2){
                    updatePrice(ls);
                }
                else if(menu_num == 3){
                    addStock(ls);
                }
                else if(menu_num == 4){
                    import_more(ls);
                }
                else if(menu_num == 5){
                    deleteLaptop(ls);
                }
                else if(menu_num == 6){
                    cout << "You have been exitting from admin's page successfully." << endl;
                    break;
                }
                else{
                    cout << "Invalid input!" << endl;
                }
            }
            break;
        }
        else{
            password = "";
            cout << "\n\tEnter wrong password " << num++ << "/3, Try again";
            if(num == 4){
                num -=3;
                cout << " in next 5 seconds.";
                sleep(5);
            }
            cout << endl;
        }
    }
}
