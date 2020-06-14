#ifndef VAR2_LAB11_STRUCTURAL_PATTERNS_H
#define VAR2_LAB11_STRUCTURAL_PATTERNS_H


#include <iostream>
#include <string>
#include <memory>

#define NDS 0.2

class Order_profit
{
private:
    double payment;
    double production;

public:
    Order_profit(double payment_, double production_) : payment(payment_), production(production_)
    {

    }

    virtual double Get_payment()
    { return payment; }

    virtual double Get_production()
    { return production; }

    virtual double Calculate_profit()
    { return payment - production; }
};

class Profit_adapter : public Order_profit
{
public:
    explicit Profit_adapter(Order_profit *order_profit_) : Order_profit(order_profit_->Get_payment(),
                                                                        order_profit_->Get_production())
    {

    }

    double Calculate_profit() override
    { return (this->Get_payment() - this->Get_production()) * (1 - NDS); }
};

class Order_11
{
private:
    int id;
    std::string name;

public:
    Order_11(int id_, std::string name_) : id(id_), name(name_)
    {

    }

    static double Calculate_profit(Order_profit *worker)
    {
        return worker->Calculate_profit();
    }
};


void Structural()
{
    auto *order_profit = new Order_profit(240, 120);
    auto *profit_adapter = new Profit_adapter(order_profit);

    //Order payment(1, "customer 1");
    std::cout << Order_11::Calculate_profit(order_profit) << std::endl;
    std::cout << Order_11::Calculate_profit(profit_adapter) << std::endl;


    delete order_profit;
    delete profit_adapter;
}

#endif //VAR2_LAB11_STRUCTURAL_PATTERNS_H
