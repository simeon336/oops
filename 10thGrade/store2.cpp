#include <iostream>
#include <string>

using namespace std;

double sumRent();
int checkName(string name);
void resize();
void revision();
void addProduct(string Name, unsigned int Quantity, double Price);
//void addProduct2(Product products);
void restockProduct();
void buyProduct();
double getQuantity(string name);
double getPrice(string name);
void changeProductPrice();
void printShopInfo();
void printMenu();
void changeProductPrice();
void checkProductQuantity();
void checkProductPrice();
//void AddProductMain(Store *store);

class Product{
private:
    string name;
    unsigned int amount;
    double price;

public:
    Product(){
        name = "";
        amount = 0;
        price = 0;
    }
    
    Product(string name, unsigned int amount, double price){
        if(price < 0 || amount < 0){
            printf("the price and amount must have not negative values \n");
        }else{
            this->name = name;
            this->amount = amount;
            this->price = price;
        }
    }

    Product(const Product &pr1){
        this->name = pr1.name;
        this->amount = pr1.amount;
        this->price = pr1.price;
    }

    Product &operator=(const Product &pr1){
        if(this != &pr1){
            this->name.erase();

            this->name = pr1.name;
            this->amount = pr1.amount;
            this->price = pr1.price;
        }
        return *this;
    }

    ~Product(){
        name.erase();
    }

    // setters
    void setName(string x){
        if(name.empty() == false){
            name.erase();
        }
        name = x;
    }
    void setAmount(unsigned int a){
        if(a < 0){
            printf("the amount must have positive value \n");
        }else{
            amount = a;
        }
    }
    void setPrice(double p){
        if(p < 0){
            printf("the price must have positive value \n");
        }else{
            price = p;
        }
    }

    //getters
    string getName()const{
        return name;
    }
    unsigned int getAmount()const{
        return amount;
    }
    double getPrice()const{
        return price;
    }
};

class Property{
private:
    string address;
    double baseRent;
    string type;

public:
    Property(string address, double baseRent, string type){
        if(address.empty() || type.empty()){
            printf("Entered unvalid value to the addres or the type \n");
            return;
        }
        if(baseRent < 1){
            printf("The value of the baseRent must be positive \n");
            return;
        }
        if(type!="supermarket" || type!="pharmacy" || type!="non-stop" || type!="other"){
            printf("Entered unvalid value for the type \n");
            printf("It must be supermarket/pharmacy/non-stop/other \n");
            return;
        }
        this->address = address;
        this->baseRent = baseRent;
        this->type = type;
    }

    Property(const Property &prop){
        this->address = prop.address;
        this->baseRent = prop.baseRent;
        this->type = prop.type;
    }

    Property &operator=(const Property &prop){
        if(this != &prop){
            this->address.erase();
            this->type.erase();

            this->address = prop.address;
            this->baseRent = prop.baseRent;
            this->type = prop.type;
        }
        return *this;
    }

    ~Property(){
        address.erase();
        type.erase();
    }

    double sumRent(){
        double rent;
        if(this->type == "supermarket"){
            rent = this->baseRent + this->baseRent * 0.4;
        }
        else if(this->type == "pharmacy"){
            rent = this->baseRent + this->baseRent * 0.3;
        }
        else if(this->type == "non-stop"){
            rent = this->baseRent + this->baseRent * 0.2;
        }
        else{
            rent = this->baseRent;
        }
        return rent;
    }

    // getters
    string getAddress() const{
        return address;
    }
    string getType() const{
        return type;
    }
};
typedef struct Products{
    Product *products;
    size_t quantity;
    size_t capacity = 0;
} products_2;


class Store : public Property{
private:
    string name;
    products_2 products;

public:

    Store(string name, string address, double baseRent, string type_of_prop) : Property(address, baseRent, type_of_prop){
        if(name.empty()){
            printf("Enter name and try again");
            return;
        }else{
            Property(address, baseRent, type_of_prop);
            this->name = name;
            this->products.quantity = 0;
            this->products.capacity = 2;
            this->products.products = new Product[this->products.capacity]; 
        }
    }

    Store(const Store& other) : Property(other){
        /*this->propertys.setAddress() = other.propertys.getAddress();
        this->propertys->baseRent = other.propertys->baseRent;
        this->propertys->type = other.propertys->type;*/
        
        this->name = other.name;
        this->products.capacity = other.products.capacity;
        this->products.products = new Product[this->products.capacity];
        for (int i = 0; i < this->products.capacity; ++i){
            this->products.products[i] = other.products.products[i];
        }
    }

    Store &operator=(const Store& other){
        if(this != &other){
            Property::operator=(other);
            this->name = other.name;
            this->products.capacity = other.products.capacity;
            this->products.products = new Product[this->products.capacity];
            for (int i = 0; i < this->products.capacity; i++) {
                this->products.products[i] = other.products.products[i];
            }
        }
        return *this;
    }

    ~Store(){
        delete[] this->products.products;
    }

    // Getter
    string getName()const{
        return this->name;
    }

    int checkName(string name){
        for(int i = 0; i < this->products.quantity; i++){
            if(this->products.products[i].getName() == name)
                return i;
        }
        return -1;
    }

    void resize() {
        Product *temp = new Product[this->products.capacity*2];
        for(int i = 0; i < this->products.capacity; ++i){
            temp[i] = this->products.products[i];
        }
        delete[] this->products.products;
        this->products.capacity = this->products.capacity * 2;
        this->products.products = temp;            
    }

    void revision(){
        string names[this->products.capacity];
        for(int i = 0; i < this->products.quantity; ++i){
            if(this->products.products[i].getAmount() < 5){
                names[i] = this->products.products[i].getName();
            }
        }
    }

    void addProduct(string Name, unsigned int Quantity, double Price){
        if(Name.empty()){
            printf("Enter name and try again");
            return;
        }
        int i = checkName(Name);
        if(i == -1){
            printf("Already existing \n");
            return;
        }
        if(Quantity < 1 || Price < 1){
           printf("the values that you give have to be positive numbers");
            return;
        }
        if(this->products.quantity == this->products.capacity){
            this->resize();
        }
        this->products.products[this->products.quantity++] = Product(Name, Quantity, Price);
    }

    void addProduct2(Product products){
        this->products.products[this->products.quantity++] = products;
    }

    void restockProduct(){
        string name;
        int quantity;
        printf("\n Enter product's name:");
        getline(cin, name);
        printf("\n Enter quantity:");
        cin >> quantity;
        if(quantity < 1){
            printf("\n Entered invalid quantity");
            return;
        }
        int i = checkName(name);
        if(i == -1){
            printf("\n Entered invalid name");
        }else{
            this->products.products[i].setAmount(this->products.products[i].getAmount() + quantity);
            printf("\n Successfully restoked %s", this->products.products[i].getName());
        }
    }

    void buyProduct(){
        string name;
        int quantity;
        printf("\n Enter product's name:");
        getline(cin, name);
        printf("\n Enter quantity:");
        cin >> quantity;
        
        if(quantity < 1){
            printf("\n Entered invalid quantity");
            return;
        }
        
        int i = checkName(name);
        if(i != -1){
            if(this->products.products[i].getAmount() >= quantity){
                this->products.products[i].setAmount(this->products.products[i].getAmount() - quantity);
                printf("\n Successfully bought %d %s products", quantity, this->products.products[i].getName());
            }else{
            printf("T\n here aren’t %d %s products in the store!", quantity, this->products.products[i].getName());
            printf("\n Successfully bought %d %s products", this->products.products[i].getAmount(), this->products.products[i].getName());
            this->products.products[i].setAmount(0);
            }
        }else{
            printf("\n Entered invalid name");
        }
    }

    double getQuantity(string name){
        int i = checkName(name);
        if(i != -1){
            return this->products.products[i].getAmount();
        }
        return 0;
    }

    double getPrice(string name){
        int i = checkName(name);
        if(i != -1){
            return this->products.products[i].getPrice();
        }
        return 0;
    }

    void changeProductPrice(){
        string name;
        int price;
        printf("\n Enter product's name:");
        getline(cin, name);
        printf("\n Enter new price:");
        cin >> price;

        int i = checkName(name);
        if(i != -1){
            if (price > 0){
                this->products.products[i].setPrice(price);
                printf("Successfully changed the price of %s", this->products.products[i].getName());
            }else{
                printf("\n Entered invalide value for the price");
            }
        }else{
            printf("\n Entered invalide name");
        }
    }

    void printShopInfo(){
        printf("\n Name: %s", this->getName());
        printf("\n Address: %s", this->getAddress());
        printf("\n Type: %s", this->getType());
        printf("\n Rent: %f", this->sumRent());
        printf("\n Products: %zu", this->products.quantity);
        for(int i = 0; i < this->products.quantity; i++){
            printf("\n Name: %s", this->products.products->getName());
            printf("\n Quantity: %d", this->products.products->getAmount());
            printf("\n Price: %f", this->products.products->getPrice());
        }
    }
};


void printMenu(){
    printf("Write the number of the function you want to use from the list below \n");
    printf("1.Add product \n");
    printf("2.Check product quantity \n");
    printf("3.Check product price \n");
    printf("4.Restock product \n");
    printf("5.Change product price \n");
    printf("6.Buy product \n");
    printf("7.Show shop's information \n");
    printf("8.Revision \n");
    printf("9.Exit \n");
}

void AddProductMain(Store *store){
    string Name;
    double Price;
    unsigned int Quantity;
    printf("\n Enter new product's name:");
    getline(cin >> ws, Name);
    printf("\n Enter new product's quantity:");
    cin >> Quantity;
    printf("\n Enter new product's price:");
    cin >> Price;

    store->addProduct2(Product(Name, Quantity, Price));
}

void checkProductQuantity(){
    string Name;
    printf("Enter product's name:");
    getline(cin, Name);

    int i = checkName(Name);
    if(i != -1){
        double result = getQuantity(Name);
        printf("\n Quantity: %f", result);
    }else{
        printf("\n Entered invalid name");
    } 
    return;
}

void checkProductPrice(){
    string Name;
    printf("Enter product's name:");
    getline(cin, Name);

    int i = checkName(Name);
    if(i != -1){
        double result = getPrice(Name);
        printf("\n Price: %f", result);
    }else{
        printf("\n Entered invalid name");
    } 
    return;
}


int main(){
    string name, address, type;
    double baseRent;
    Store *shop = nullptr;

    printf("Enter the name of your store \n");
    getline(cin >> ws, name);
    printf("Enter the address of your store \n");
    getline(cin >> ws, address);
    printf("Enter the type of your store \n");
    getline(cin >> ws, type);
    printf("Enter the rent of your store \n");
    cin >> baseRent;

    shop = new Store(name, address, baseRent, type);

    int opinion = 0;

    while (opinion <9){
        cout << "\x1B[2J\x1B[H";
        printMenu();
        cin >> opinion;

        switch (opinion){
            case 1:
            AddProductMain(shop);
                break;
            case 2:
                checkProductQuantity();
                break;
            case 3:
                checkProductPrice();
                break;
            case 4:
                shop->restockProduct();
                break;
            case 5:
                shop->changeProductPrice();
                break;
            case 6:
                shop->buyProduct();
                break;
            case 7:
                shop->printShopInfo();
                break;
            case 8:
                shop->revision();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Invalid option");
                break;
        }
    }
}
