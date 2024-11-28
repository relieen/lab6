#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>

template <typename T>
void selectionSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(static_cast<unsigned int>(time(0)));

    int nInt;
    cout << "Введіть розмір масиву з цілими числами: ";
    cin >> nInt;
    vector<int> arrInt(nInt);
    cout << "Введіть мінімальне значення для масиву з цілими числами: ";
    int minInt, maxInt;
    cin >> minInt;
    cout << "Введіть максимальне значення для масиву з цілими числами: ";
    cin >> maxInt;
    for (int i = 0; i < nInt; ++i) {
        arrInt[i] = minInt + rand() % (maxInt - minInt + 1);
    }

    selectionSort(arrInt);

    cout << "Відсортований масив з цілими числами: ";
    for (const auto& element : arrInt) {
        cout << element << " ";
    }
    cout << endl;

    int nDouble;
    cout << "Введіть розмір масиву з числами типу double: ";
    cin >> nDouble;
    vector<double> arrDouble(nDouble);
    cout << "Введіть мінімальне значення для масиву з числами типу double: ";
    double minDouble, maxDouble;
    cin >> minDouble;
    cout << "Введіть максимальне значення для масиву з числами типу double: ";
    cin >> maxDouble;
    for (int i = 0; i < nDouble; ++i) {
        arrDouble[i] = minDouble + static_cast<double>(rand()) / RAND_MAX * (maxDouble - minDouble);
    }

    selectionSort(arrDouble);

    cout << "Відсортований масив з числами типу double: ";
    for (const auto& element : arrDouble) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}


