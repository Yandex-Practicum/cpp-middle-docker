
#include <absl/strings/str_cat.h>
#include <boost/algorithm/string.hpp>
#include <openssl/sha.h>
#include <range/v3/all.hpp>
#include <sqlite3.h>

#include <array>
#include <flat_set>
#include <print>
#include <string>
#include <vector>

namespace rs = std::ranges;
namespace vs = std::views;

int main() {
    std::println("\n\n#################### Test C++23 ####################");
    if (__cplusplus == 202302L)
        std::println("Hello, C++23!");

    std::flat_set<int> fs;
    fs.emplace(1);

    std::println("\n\n#################### Test Abseil ####################");
    std::string a = "Hello", b = "Abseil";
    std::println("Abseil str_cat: {}", absl::StrCat(a, " ", b, "!"));

    std::println("\n\n#################### Test Boost ####################");
    std::string text = "Boost Library Test";
    boost::to_upper(text);
    std::println("Boost to_upper: {}", text);

    std::println("\n\n#################### Test OpenSSL ####################");
    std::array<unsigned char, 12> data = {'O', 'p', 'e', 'n', 'S', 'S', 'L', ' ', 'T', 'e', 's', 't'};
    std::array<unsigned char, SHA256_DIGEST_LENGTH> hash{};
    SHA256(data.data(), data.size(), hash.data());
    std::println("OpenSSL SHA256: 0x{}",
                 vs::join(hash | vs::transform([](auto byte) { return std::format("{:02x}", byte); })) |
                     rs::to<std::string>());

    std::println("\n\n#################### Test SQLite3 ####################");
    sqlite3 *db;
    if (sqlite3_open(":memory:", &db) == SQLITE_OK) {
        std::println("SQLite3 in-memory DB opened successfully.");
        sqlite3_close(db);
    } else {
        std::println("SQLite3 failed to open DB.");
    }

    std::println("\n\n#################### Test range-v3 ####################");
    std::vector<int> nums = {1, 2, 3, 4, 5};
    // Using sliding — not in std::ranges
    auto windows = nums | ranges::views::sliding(3);
    for (auto window : windows) {
        std::print("Window: ");
        for (int n : window)
            std::print("{} ", n);
        std::println("");
    }

    std::println("\n\nAll libraries appear functional. Enjoy!\n");
    return 0;
}
