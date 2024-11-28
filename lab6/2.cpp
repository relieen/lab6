#include <iostream>
#include <bitset>
#include <type_traits>
#include <windows.h>

template <typename T>
class Checksum {
public:
    static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value,
        "Checksum only supports integral or floating-point types.");

    // Метод для обчислення контрольної суми
    static int calculate(T value) {
        // Перетворюємо значення на бітове представлення
        std::bitset<sizeof(T) * 8> bits(*reinterpret_cast<unsigned long long*>(&value));

        // Повертаємо кількість одиниць у машинному зображенні
        return bits.count();
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int intValue = 42;
    double doubleValue = 3.14;

    std::cout << "Контрольна сума для int: " << Checksum<int>::calculate(intValue) << std::endl;
    std::cout << "Контрольна сума для double: " << Checksum<double>::calculate(doubleValue) << std::endl;

    return 0;
}
