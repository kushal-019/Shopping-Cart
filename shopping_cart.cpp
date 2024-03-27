#include <bits/stdc++.h>
#include <unistd.h>
#include <iostream>
using namespace std;

class product
{
public:
    string name;
    float price;
    int quantity;

    void adding_in_cart()
    {
        
            cout << "product added to cart" << endl
                 << endl;
            quantity--;
        
       
        return;
    }

    void print()
    {
        cout <<"product name : "<< name << endl;
        cout <<"price of "<<name<<" : "<<price << endl;
        cout <<"quantity available : " <<quantity << endl;
        cout << endl;
    }
};

class cart
{
public:
    string name;
    int quantity;
    int price;

    void print()
    {
        cout <<"product name : "<< name << endl;
        cout <<"price of "<<name<<" : "<<price << endl;
        cout <<"quantity added in cart : " <<quantity << endl;
        cout << endl;
    }
    void add(string name, int quant, int amount)
    {
        this->name = name;
        this->quantity = quant;
        this->price = amount;
    }
};

int main()
{
    product product[100];
    cart cart[100];
    int total_price = 0;
    int total_quant = 0;
    int item_purchase = 0;

    while (true)
    {
        int x;
        cout << "<------       welcome to our shopping store          -------------->" << endl;
        cout << "<------       choose the service your want to use    -------------->" << endl
             << endl;
        sleep(1);
        cout << "------>       1-Add item to cart                     <------" << endl;
        cout << "------>       2-remove a product from cart           <------" << endl;
        cout << "------>       3-list a new product                   <------" << endl;
        cout << "------>       4-search for a product                 <------" << endl;
        cout << "------>       5-check all products available         <------" << endl;
        cout << "------>       6-show items in cart                   <------" << endl;
        cout << "------>       0-exit store                           <------" << endl
             << endl;
        cout << "select service :  ";
        cin >> x;
        cin.ignore();

        cout << endl;

        if (x == 1)
        {
            cout<<"You chose to add a product in the cart"<<endl<<endl;
            string name;
            int quant;
            cout << "enter product name : ";
            getline(cin, name);
            cout << "enter quantity : ";
            cin >> quant;
            cout<<endl;
            int flag = 0;
            for (int i = 0; i < total_quant; i++)
            {
                if (product[i].name == name)
                {
                    flag = 1;
                    if (product[i].quantity >= quant)
                    {
                        product[i].quantity -= quant;
                        cart[item_purchase].add(name, quant,  product[i].price * quant);
                        total_price +=  product[i].price * quant;
                        item_purchase++;
                        cout << "item added to cart "<<endl<<endl;
                        break;
                    }
                    else
                    {
                        cout << "quantity available is : " << product[i].quantity << endl
                             << endl;
                        break;
                    }
                }
            }
            if (!flag)
            {
                cout << "product not available" << endl
                     << endl;
            }
        }

        else if (x == 2)
        {
            cout<<"You chose to remove a product from the cart"<<endl<<endl;
            string name;
            int quant;
            int flag = 0;
            cout << "enter product name : ";
            getline(cin, name);
            
            for (int i = 0; i < item_purchase; i++)
            {
                if (cart[i].name == name)
                {
                    flag = 1;
                    cout << "enter quantity : ";
                    cin >> quant;
                    if (quant > cart[i].quantity){
                        cout<<"quantity to be removed is higher than quantity present in cart !!! "<<endl<<endl;
                        break;
                    }
                    else if (quant == cart[i].quantity)
                    {
                    for (int j = i; j < item_purchase - 1; j++)
                        {
                            cart[j] = cart[j + 1];
                            
                        }
                        item_purchase--;
                    }
                    else
                        {
                            int pri = cart[i].price/cart[i].quantity;
                            cart[i].quantity -= quant;
                            cart[i].price -= pri* quant;
                        }
                    
                    
                    for (int j = 0; j < total_quant; j++)
                    {
                        if (product[j].name == name)
                        {
                            product[j].quantity += quant;
                            total_price -= product[j].price * quant;
                            break;
                        }
                    }
                    

                    cout << "item removed succesfully" << endl
                         << endl;
                         break;
                }
            }
            if (!flag)
            {
                cout << "item was not present in cart" << endl
                     << endl;
            }
        }

        else if (x == 3)
        {
            cout<<"You chose to add a product in the store"<<endl<<endl;
            int j = total_quant;

            cout << "name of item :  " << endl;
            cin >> product[j].name;
            cout << "price of item :  " << endl;
            cin >> product[j].price;
            cout << "quantity of item :  " << endl;
            cin >> product[j].quantity;

            total_quant++;
            cout << "item listed sucessfully" << endl
                 << endl;
        }

        else if (x == 4)
        {
            cout << "You chose to search a product in the store" << endl<<endl;
            string name;
            cout << "enter the name of product you want to search : ";
            getline(cin, name);
            cout<<endl;
            for (int i = 0; i < total_quant; i++)
            {
                if (product[i].name == name)
                {
                    product[i].print();
                }
                cout << endl;
            }
        }

        else if (x == 5)
        {
            cout << "You chose to display all products in the store" << endl<<endl;
            for (int i = 0; i < total_quant; i++)
            {
                product[i].print();
            }
            cout << endl;
        }

        else if (x == 6)
        {
            cout << "You chose to display all products of your cart" << endl<<endl;
            for (int i = 0; i < item_purchase; i++)
            {
                cart[i].print();
            }
            cout << endl;
            cout << "***********  your total amount will be : Rs " << total_price<<"  ***********" << endl
                 << endl;
        }
        else if (x == 0)
        {
            cout<<"***********  thanks for visiting , visit again  ***********"<<endl;
            cout<<"***********  exits store ***********"<<endl<<endl;
            return 0;
        }
        else
        {
            cout << "invalid choice" << endl
                 << endl;
        }
        sleep(1);
    }
}
   