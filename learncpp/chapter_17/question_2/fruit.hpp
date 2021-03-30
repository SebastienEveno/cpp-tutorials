#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <string>

class Fruit
{
private:
    std::string m_name{};
    std::string m_color{};
public:
    Fruit(const std::string& name, const std::string& color) : m_name{name}, m_color{color} {}
    const std::string& getName() const { return m_name; }
    const std::string& getColor() const { return m_color; }
};

class Apple : public Fruit
{
protected:
    Apple(const std::string& name, const std::string& color) : Fruit{ name, color } {}
public:
    Apple(const std::string& color="red") : Fruit{ "apple", color } {}
};

class GrannySmith : public Apple
{
public:
    GrannySmith() : Apple{ "granny smith", "green" } {};
};

class Banana : public Fruit
{
public:
    Banana() : Fruit{ "banana", "yellow" } {}
};

#endif