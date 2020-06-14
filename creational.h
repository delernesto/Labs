#ifndef VAR2_LAB11_CREATIONAL_H
#define VAR2_LAB11_CREATIONAL_H

#pragma once

#include <iostream>
#include <memory>

void showFactoryMethodPatern();

class AbstractPosition
{
public:

    virtual void dataBaseInteraction() = 0;
};

class AbstractCreator
{
public:

    virtual AbstractPosition *factoryMethod() = 0;
};

class ProducerPosition : public AbstractPosition
{
public:

    void dataBaseInteraction() override
    {
        std::cout << "I can only change manufacture data" << std::endl;
    }

};

class ProducerCreator : public AbstractCreator
{
public:

    AbstractPosition *factoryMethod() override
    {
        return new ProducerPosition;
    }
};

class AccountantPosition : public AbstractPosition
{
public:

    void dataBaseInteraction() override
    {
        std::cout << "I can only change records of goods data" << std::endl;
    }
};

class AccountantCreator : public AbstractCreator
{
public:

    AbstractPosition *factoryMethod() override
    {
        return new AccountantPosition;
    }

};

class AdminPosition : public AbstractPosition
{
public:

    void dataBaseInteraction() override
    {
        std::cout << "I can change any info" << std::endl;
    }
};

class AdminCreator : public AbstractCreator
{
public:

    AbstractPosition *factoryMethod() override
    {
        return new AdminPosition;
    }

};




void Creational()
{
    ProducerCreator producerCreator;
    std::unique_ptr<AbstractPosition> producerPosition(producerCreator.factoryMethod());
    producerPosition->dataBaseInteraction();

    AccountantCreator accountantCreator;
    std::unique_ptr<AbstractPosition> accountantPosition(accountantCreator.factoryMethod());
    accountantPosition->dataBaseInteraction();

    AdminCreator adminCreator;
    std::unique_ptr<AbstractPosition> adminRole(adminCreator.factoryMethod());
    adminRole->dataBaseInteraction();
}

#endif //VAR2_LAB11_CREATIONAL_H
