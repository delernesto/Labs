
#ifndef VAR2_LAB13_BEHAVIORAL_2_H
#define VAR2_LAB13_BEHAVIORAL_2_H

#include <iostream>
#include <memory>
#include <utility>


using namespace std;


class Production
{
private:
    int product_resources;
    int human_resources;
    int delivery_resources;

public:
    Production(int product_resources_, int human_resources_, int delivery_resources_) :
            product_resources(product_resources_), human_resources(human_resources_),
            delivery_resources(delivery_resources_)
    {

    }

    int getProduct_resources() const
    {
        return product_resources;
    }

    int getHuman_resources() const
    {
        return human_resources;
    }

    int getDelivery_resources() const
    {
        return delivery_resources;
    }

};


class Order_13
{
private:
    int product_requirements;
    int human_requirements;
    int delivery_requirements;
    unsigned int id;

public:
    int getProduct_requirements() const
    {
        return product_requirements;
    }

    int getHuman_requirements() const
    {
        return human_requirements;
    }

    int getDelivery_requirements() const
    {
        return delivery_requirements;
    }

    unsigned int getId() const
    {
        return id;
    }

    explicit Order_13(unsigned int id_, int product_requirements_, int human_requirements_, int delivery_requirements_)
            : id(id_), product_requirements(product_requirements_), human_requirements(human_requirements_),
              delivery_requirements(delivery_requirements_)
    {

    }
};


class Order_availability
{
protected:
    Order_availability *next = nullptr;

public:
   Order_availability *Set_next(Order_availability *next_)
    {
        next = next_;
        return next;
    }


    virtual bool Check_order_availability(Order_13 *order, Production *production) = 0;
};


class Check_product_resources : public Order_availability
{
public:
    bool Check_order_availability(Order_13 *order, Production *production) override
    {
        if (production->getProduct_resources() >= order->getProduct_requirements())
        {
            if (next != nullptr) {
                return next->Check_order_availability(order, production);
            }
            return true;
        }

        cout << "Not enough of product resources for in-time production and delivery! Order denied." << endl;
        return false;
    }
};

class Check_human_resources : public Order_availability
{
public:
    bool Check_order_availability(Order_13 *order, Production *production) override
    {
        if (production->getHuman_resources() >= order->getHuman_requirements())
        {
            if (next != nullptr) {
                return next->Check_order_availability(order, production);
            }
            return true;
        }
        cout << "Not enough of human resources for in-time production and delivery! Order denied." << endl;
        return false;
    }
};


class Check_delivery_resources : public Order_availability
{
public:
    bool Check_order_availability(Order_13 *order, Production *production) override
    {
        if (production->getDelivery_resources() >= order->getDelivery_requirements())
        {
            if (next != nullptr) {
                return next->Check_order_availability(order, production);
            }
            return true;
        }
        cout << "Not enough of delivery resources for in-time delivery! Order denied." << endl;
        return false;
    }
};


void Order_availability(Order_13 *order, Production *production)
{

    auto products = new Check_product_resources;
    auto humans = new Check_human_resources;
    auto deliveries = new Check_delivery_resources;


    products->Set_next(humans)->Set_next(deliveries);

    if (products->Check_order_availability(order, production)) {
        cout << "Order accepted!" << endl;
    } else
    {
        cout << "Order denied!" << endl;
    }
}

void Behavioral_2()
{
    auto order = new Order_13(1, 10, 20, 70);
    auto production= new Production(100, 200, 150);

    Order_availability(order, production);
}


#endif //VAR2_LAB13_BEHAVIORAL_2_H
