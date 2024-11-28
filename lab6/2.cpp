#include <iostream>
#include <bitset>
#include <type_traits>
#include <windows.h>

template <typename T>
class Checksum {
public:
    static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value,
        "Checksum only supports integral or floating-point types.");

    // ����� ��� ���������� ���������� ����
    static int calculate(T value) {
        // ������������ �������� �� ����� �������������
        std::bitset<sizeof(T) * 8> bits(*reinterpret_cast<unsigned long long*>(&value));

        // ��������� ������� ������� � ��������� ���������
        return bits.count();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int intValue = 42;
    double doubleValue = 3.14;

    std::cout << "���������� ���� ��� int: " << Checksum<int>::calculate(intValue) << std::endl;
    std::cout << "���������� ���� ��� double: " << Checksum<double>::calculate(doubleValue) << std::endl;

    return 0;
}
