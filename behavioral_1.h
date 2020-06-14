#ifndef VAR2_LAB11_BEHAVIORAL_H
#define VAR2_LAB11_BEHAVIORAL_H

#include <iostream>
#include <memory>

using namespace std;


class Order_12
{
    int id;
public:

    explicit Order_12(int id_): id(id_)
    {

    }

    void Send()
    {
        this->Update_database();
        this->Dlivery();
    }

private:
    virtual void Dlivery() = 0;

    void Update_database()
    {
        cout << "Method Dlivery of abstract class" << endl;
    }
};

class Order_single_product : public Order_12
{
public:
    explicit Order_single_product(int id_) : Order_12 (id_)
    {

    }

    void Dlivery() override
    {
        cout << "Searching for available delivery man!" << endl << endl;
    }
};

class Order_package : public Order_12
{
public:
    explicit Order_package(int id_) : Order_12 (id_)
    {

    }

    void Dlivery() override
    {
        cout << "Searching for available delivery transport" << endl << endl;
    }
};

class Gross_order : public Order_12
{
public:
    explicit Gross_order(int id_) : Order_12 (id_)
    {

    }

    void Dlivery() override
    {
        cout << "Searching for delivery truck!" << endl << endl;
    }
};


void Behavioral_1()
{

    std::unique_ptr<Order_12> order1 (new Order_single_product(1));
    std::unique_ptr<Order_12> order2 (new Order_package(2));
    std::unique_ptr<Order_12> order3 (new Gross_order(2));

    cout << "Order_single_product object:" << endl;
    order1->Send();
    cout << "Order_package object:" << endl;
    order2->Send();
    cout << "Gross_order object:" << endl;
    order3->Send();
}


#endif //VAR2_LAB12_BEHAVIORAL_H
