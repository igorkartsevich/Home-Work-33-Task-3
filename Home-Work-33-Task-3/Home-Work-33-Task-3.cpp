#include <iostream>
#include <map>

template<typename T1, typename T2>
class Data {
public:
    void add(T1 key, T2 value) {
        data.emplace(std::make_pair(key, value));
    }

    void remove(T1 key) {
        data.erase(data.find(key));
    }

    void print(T1 key) {
        for (auto element : data)
            if (element.first == key)
                std::cout << "Element: " << element.first << ", value: " << element.second << std::endl;

        std::cout << std::endl;
    }

    void find(T1 key) {
        int counter = 0;
        for (auto element : data)
            if (element.first == key) ++counter;

        if (counter != 0) {
            std::cout << "Element was found in data base!" << " Quantity: " << counter << std::endl;
            print(key);
        }
        else std::cout << "Element was not found!\n";
    }

private:
    std::multimap<T1, T2> data;

};

int main()
{
    Data<int, int> data_int;
    data_int.add(100, 100);
    data_int.add(100, 100);
    data_int.add(200, 200);
    data_int.find(100);
    data_int.remove(100);
    data_int.find(100);
    data_int.print(200);
    data_int.find(500);

    std::cout << std::endl;
    Data<double, double> data_double;
    data_double.add(100.5, 100.5);
    data_double.add(100.5, 100.5);
    data_double.add(200.5, 200.5);
    data_double.find(100.5);
    data_double.remove(100.5);
    data_double.find(100.5);
    data_double.print(200.5);
    data_double.find(500.5);

    std::cout << std::endl;
    Data<std::string, double> data_string;
    data_string.add("milk", 100.5);
    data_string.add("milk", 100.5);
    data_string.add("sugar", 200.5);
    data_string.find("milk");
    data_string.remove("milk");
    data_string.find("milk");
    data_string.print("sugar");
    data_string.find("bread");
}