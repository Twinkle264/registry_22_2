#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, int> registry;
    string surname;

    while (cin >> surname) {
        if (surname == "Next") {
            if (!registry.empty() or registry.find(surname)->second != 0) {
                std::cout << "Next: " << registry.begin()->first << std::endl;
                registry.begin()->second--;
                if (registry.begin()->second == 0) {
                    registry.erase(registry.begin());
                }
            } else {
                std::cout << "Queue is empty." << std::endl;
            }
        } else {
            if (registry.find(surname) == registry.end()) {
                registry.insert(make_pair(surname, 1));
            } else {
                registry.find(surname)->second++;
            }
        }
    }
    return 0;
}
