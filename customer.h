
using namespace std;

void addToCart(List* ls) {  
    int id;
    int num;
    while (true) {
        cout << "Enter ID to add to cart(enter 0 to exit): ";
        cin >> id;
        
        if (id == 0) {
            cout << "Exiting addToCart..." << endl;
            break;
        }

        Element *e;
        e = ls->head;
        bool found = false;
        while (e != NULL) {
            if (e->id == id && e->stock > 0) {
                e->available = false;
                found = true;
                cout << "Enter number of laptop you want to buy: "; cin >> num;
                if(num <= 0){
                    cout << "Number of laptop must be greater than 0!!!" << endl;
                    break;
                }
                else{
                    e->number += num;
                    cout << "----------------------" << endl;
                    cout << "\t*** Add to cart ***" << endl;
                    cout << "Name: " << e->name << endl;
                    cout << "ID: " << e->id << endl;
                    cout << "Storage: " << e->storage << "GB" << endl;
                    cout << "Ram: " << e->ram << "GB" << endl;
                    cout << "Year: " << e->year << endl;
                    cout << "Number: " << e->number << endl;
                    cout << "Price Per Laptop: $" << e->price << endl;
                    cout << "Total: $" << e->price*num << endl;
                    cout << "----------------------" << endl;
                    break;
                }
            }
            e = e->next;
        }
        if (!found) {
            cout << "Laptop " << id << " is not available." << endl;
        }
    }
}

void removeFromCart(List* ls, int id) {
    int num;
    Element *e;
    e = ls->head;
    bool found = false;

    while (e != NULL) {
        if (e->id == id && e->number > 0) {
            cout << "Enter number you want to remove: ";
            cin >> num;
            found = true;
            if(num < 0){
                cout << "Number of remove must be positive number!" << endl;
                break;
            }
            else{
                e->number -= num;
                cout << "----------------------" << endl;
                cout << "Name: " << e->name << endl;
                cout << "ID: " << e->id << endl;
                cout << "Storage: " << e->storage << " GB" << endl;
                cout << "Ram: " << e->ram  << " GB" << endl;
                cout << "Year: " << e->year << endl;
                cout << "Number left: " << e->number << endl;
                cout << "Price: $" << e->price << endl;
                cout << "Total: $" << e->price*e->number << endl;
                cout << "----------------------" << endl;
                break;
            }
        }
        e = e->next;
    }
    if (!found) {
        cout << "Laptop " << id << " is not found in the cart." << endl;
    }
}

void viewCart(List* ls) {
    Element *e;
    e = ls->head;
    bool found = false;

    while (e != NULL) {
        if (!e->available) {
            if(e->number <= 0){
                found = false;
            }
            else{
                cout << "Name: " << e->name << endl;
                cout << "ID: " << e->id << endl;
                cout << "Storage: " << e->storage << " GB" << endl;
                cout << "Ram: " << e->ram << " GB" << endl;
                cout << "Year: " << e->year << endl;
                cout << "Number: " << e->number << endl;
                cout << "Price: $" << e->price << endl;
                cout << "Total: $" << e->price*e->number << endl;
                cout << "----------------------" << endl;
                found = true;
            }
        }
        e = e->next;
    }
    if (!found) {
        cout << "Your cart is empty." << endl;
    }
}

void buyLaptop(List* ls, string name) {
    Element *e;
    e = ls->head;
    bool found = false;
    int n = 0;
    loading();

    while (e != NULL) {
        if (!e->available && e->number > 0) {
            found = true;
            if (e->stock >= e->number) {
                e->stock -= e->number;
                if(n==0){
                    cout << "*** " << name << ", You have bought these items from our store: \n";
                    cout << "----------------------" << endl;
                }
                n++;
                cout << "Name: " << e->name << endl;
                cout << "ID: " << e->id << endl;
                cout << "Storage: " << e->storage << "GB" << endl;
                cout << "Ram: " << e->ram << "GB" << endl;
                cout << "Year: " << e->year << endl;
                cout << "Number: " << e->number << endl;
                cout << "Price Per Laptop: $" << e->price << endl;
                cout << "Total: $" << e->price*e->number << endl;                
                cout<< "----------------------" << endl;
                e->number = 0;
                if (e->stock == 0) {
                    e->available = false;
                }
            } else if(e->stock > 0 && e->stock < e->number){
                if(n == 0){
                    cout << "*** " << name << ", You have bought these items from our store: \n";
                    cout << "----------------------" << endl;
                }
                n++;
                cout << "!!!Laptop name's: " << e->name << ", stock only left: " << e->stock << endl;
                cout << "And cann't buy other: " << e->number - e->stock << endl;
                cout << "Name: " << e->name << endl;
                cout << "ID: " << e->id << endl;
                cout << "Storage: " << e->storage << "GB" << endl;
                cout << "Ram: " << e->ram << "GB" << endl;
                cout << "Year: " << e->year << endl;
                cout << "Number: " << e->stock << endl;
                cout << "Price: $" << e->price << endl;
                cout << "Total: $" << e->price*e->stock << endl;
                cout << "----------------------" << endl;
                e->stock = 0;
                e->number = 0;
                if (e->stock == 0) {
                    e->available = false;
                }
            }
            else{
                cout << "The laptop " << e->name << " is out of stock." << endl;
            }
        }
        e = e->next;
    }

    if (!found) {
        cout << "Your cart is empty." << endl;
    }
}

void customer_login(List* ls) {
    string name;
    int choice;
    int id;
    system("cls");
    system("color E0");
    cout << "\t===============*** Customer's Page ***==============" << endl;
    cout << "Enter your name: ";
    cin.ignore(); 
	getline(cin, name);
    cout << "Hello! " << name << ", welcome to our store." << endl;
    
    while (true) {
        file_stockCSV(ls);
        display_menu_customer();
        cout << "Choose number from menu: ";
        cin >> choice;
        if (choice == 1) {
            loading();
            readFile();
        } else if (choice == 2) {
            addToCart(ls);
        } else if (choice == 3) {
            while(true){
                cout << "Enter ID to remove from cart(enter 0 to exit): ";
                cin >> id;
                if(id == 0){
                    cout << "Exit menu!!!" << endl;
                    break;
                }
                else{
                    removeFromCart(ls, id);
                }
            }
        } else if (choice == 4) {
            viewCart(ls);
        } else if (choice == 5) {
            buyLaptop(ls, name);
        } else if (choice == 6) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
