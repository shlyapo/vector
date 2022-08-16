#include <iostream>
#include <vector>
#include <iterator>
#include <initializer_list>

class Vector
{
private:

public:
    RFive(const char* arg)
        : cstring(new char[std::strlen(arg) + 1])
    {
        std::strcpy(cstring, arg);
    }

    // Деструктор
    ~RFive()
    {
        delete[] cstring;
    }

    // Конструктор копирования
    RFive(const RFive& other)
    {
        cstring = new char[std::strlen(other.cstring) + 1];
        std::strcpy(cstring, other.cstring);
    }

    // Конструктор перемещения, noexcept - для оптимизации при использовании стандартных контейнеров
    RFive(RFive&& other) noexcept
    {
        cstring = other.cstring;
        other.cstring = nullptr;
    }

    // Оператор присваивания копированием (copy assignment)
    RFive& operator=(const RFive& other)
    {
        if (this == &other)
            return *this;

        char* tmp_cstring = new char[std::strlen(other.cstring) + 1];
        std::strcpy(tmp_cstring, other.cstring);
        delete[] cstring;
        cstring = tmp_cstring;
        return *this;
    }

    // Оператор присваивания перемещением (move assignment)
    RFive& operator=(RFive&& other) noexcept
    {
        if (this == &other)
            return *this;

        delete[] cstring;
        cstring = other.cstring;
        other.cstring = nullptr;
        return *this;
    }
};