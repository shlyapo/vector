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

    // ����������
    ~RFive()
    {
        delete[] cstring;
    }

    // ����������� �����������
    RFive(const RFive& other)
    {
        cstring = new char[std::strlen(other.cstring) + 1];
        std::strcpy(cstring, other.cstring);
    }

    // ����������� �����������, noexcept - ��� ����������� ��� ������������� ����������� �����������
    RFive(RFive&& other) noexcept
    {
        cstring = other.cstring;
        other.cstring = nullptr;
    }

    // �������� ������������ ������������ (copy assignment)
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

    // �������� ������������ ������������ (move assignment)
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