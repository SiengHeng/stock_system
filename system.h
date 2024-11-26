
using namespace std;

void loading(){
    cout << "LOADING... ";
    for(int i = 0; i < 30;i++){
        if(i % 5 == 0){
            usleep(100000);
        }
        else{
            cout << char(178);
        }   
    }
    for(int i = 0; i < 41; i++){
        cout << "\b \b";
    }
    cout << "\t\t==========" << endl;
    cout << "\t\t*  DONE  *" << endl;
    cout << "\t\t==========" << endl;
}

struct Element{
    string name;
    int id;
    float price;
    int stock;
    int storage;
    int ram;
    int year;
    bool available;
    int number;
    Element *next;
};

struct List{
    int size;
    Element *head;
    Element *tail;
};

List* createEmptyList(){
    List *ls;
    ls = new List();

    ls->head = NULL;
    ls->tail = NULL;
    ls->size = 0;

    return ls;
}

void insert_stock(List *ls){
    Element *e1 = new Element{"Asus_a", 101, 500, 25, 128, 8, 2021, true, 0, NULL};
    Element *e2 = new Element{"Asus_b", 102, 600, 25, 256, 16, 2022, true, 0, NULL};
    Element *e3 = new Element{"Asus_c", 103, 700, 25, 512, 16, 2023, true, 0, NULL};
    Element *e4 = new Element{"Asus_d", 104, 800, 25, 512, 32, 2024, true, 0, NULL};
    Element *e5 = new Element{"Dell_a", 105, 550, 25, 128, 8, 2021, true, 0, NULL};
    Element *e6 = new Element{"Dell_b", 106, 650, 25, 256, 16, 2022, true, 0, NULL};
    Element *e7 = new Element{"Dell_c", 107, 750, 25, 512, 16, 2023, true, 0, NULL};
    Element *e8 = new Element{"Dell_d", 108, 850, 25, 512, 32, 2024, true, 0, NULL};
    Element *e9 = new Element{"Mac_a", 109, 1000, 25, 128, 8, 2021, true, 0, NULL};
    Element *e10 = new Element{"Mac_b", 110, 1100, 25, 256, 16, 2022, true, 0, NULL};
    Element *e11 = new Element{"Mac_c", 111, 1200, 25, 512, 16, 2023, true, 0, NULL};
    Element *e12 = new Element{"Mac_d", 112, 1300, 25, 512, 32, 2024, true, 0, NULL};
    ls->head = e1;
    e1->next = e2;
    e2->next = e3;
    e3->next = e4;
    e4->next = e5;
    e5->next = e6;
    e6->next = e7;
    e7->next = e8;
    e8->next = e9;
    e9->next = e10;
    e10->next = e11;
    e11->next = e12;
    ls->tail = e12;
    ls->size = 12;
}

void file_stockCSV(List *ls){
    Element *tmp;
    tmp = ls->head;
    fstream myfile;
    int i = 1;

    myfile.open("stock_laptop.csv", ios::out);
    if(!myfile.is_open()){
        cout << "Failed to open file to store data." << endl;
    }

    myfile << "No.,Name,ID,Price,Stock,Storage,Ram,Year" << endl;
    while(tmp != NULL){
        myfile << i++ << ".,";
        myfile << tmp->name << ",";
        myfile << tmp->id << ",";
        myfile << tmp->price << "$,";
        myfile << tmp->stock << ",";
        myfile << tmp->storage << "GB,";
        myfile << tmp->ram << "GB,";
        myfile << tmp->year << endl;
        tmp = tmp->next;
    }
}

void readFile(){
    fstream myfile;
    string line;
    cout << "\t*** Laptops' stock ***";
    myfile.open("stock_laptop.csv", ios::in);
    if(!myfile.is_open()){
        cout << "Failed to open file to read." << endl;
    }
    cout << "" << endl;
    while(getline(myfile, line)){
        string no, name, id, price, stock, storage, ram, year;
        stringstream ss(line);
        if(getline(ss, no, ',') && getline(ss, name, ',') && getline(ss, id, ',') && getline(ss, price, ',') 
        && getline(ss, stock, ',') && getline(ss, storage, ',') && getline(ss, ram, ',') && getline(ss, year, ',')){
            cout << no << "\t" << name << "\t" << id << "\t" << price <<
            "\t" <<  stock << "\t" << storage << "\t" << ram << "\t" << year << endl;
        }
    }
    myfile.close();
}

void addStock(List *ls){
    int s_id;
    int num;
    cout << "Enter Laptop's ID: "; cin >> s_id;
    Element *tmp;
    tmp = ls->head;
    bool found = false;
    while(tmp != NULL){
        if(tmp->id == s_id){
            cout << tmp->name << "'s old stock: " << tmp->stock << endl;
            cout << "Enter update stock: "; cin >> num;
            if(num <= 0){
                cout << "Number of laptop must be greater than 0." << endl;
            }
            else{
                tmp->stock = tmp->stock + num;
                cout << "Now stock have: " << tmp->stock << endl;
            }
            found = true;
            break;
        }
        tmp = tmp->next;
    }
    if(!found){
        cout << "Laptop name: " << s_id << ", isn't exit." << endl;
    }
}

void import_more(List *ls){
    string name;
    int id;
    float price;
    int stock;
    int storage;
    int ram;
    int year;
    cout << "\tEnter name: ";
    cin.ignore(); 
	getline(cin, name);
    cout << "\tEnter price: $"; cin >> price;
    cout << "\tEnter stock: "; cin >> stock;
    cout << "\tEnter storage: GB"; cin >> storage;
    cout << "\tEnter Ram: GB"; cin >> ram;
    cout << "\tEnter year: "; cin >> year;

    if(stock < 0){
        cout << "Failed to import. Stock must be positive number." << endl;
    }
    else if(price < 0){
        cout << "Failed to import. Price must be positive number." << endl;
    }
    else if(storage < 0){
        cout << "Failed to import. Storage must be positive number." << endl;
    }
    else if(ram < 0){
        cout << "Failed to import. Ram must be positive number." << endl;
    }
    else if(year < 0){
        cout << "Failed to import. Year invalid" << endl;
    } 
    else{
        cout << "\t*** DONE!!!" << endl;
        id = ls->tail->id + 1;
        Element *e = new Element{name, id, price, stock, storage, ram, year , true, 0, NULL};
        ls->tail->next = e;
        ls->tail = e;
        ls->size++;
    }
}
