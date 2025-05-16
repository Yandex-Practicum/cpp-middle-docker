#include <flat_set>
#include <print>

int main() {
    if (__cplusplus == 202302L) std::println("Hello, C++23!");

    std::flat_set<int> fs;
    fs.emplace(1);
}
