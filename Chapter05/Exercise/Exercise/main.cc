#include <algorithm>
#include <filesystem>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

#include "utils.h"

namespace fs = std::filesystem;

using WordVector = std::vector<std::string>;
using WordCountPair = std::pair<std::string, std::size_t>;
/**
 * map that shows word distribution.
 *
 * has details.
 */
using CountedWordsMap = std::map<std::string, std::size_t>;

WordVector split_text(const std::string &text);

CountedWordsMap count_words(const WordVector &words);

std::vector<std::string> resplit(const std::string &s, const std::regex &sep_regex = std::regex{"(\\s+|\\.|,)"}) {
    std::sregex_token_iterator iter(s.begin(), s.end(), sep_regex, -1);
    return {iter, (std::sregex_token_iterator())};
}

int main() {
    auto strings=std::vector<std::string>{"hallo", "allemaal"};

    std::string x{"hoi"};
    strings.push_back(x);
    std::cout << x << std::endl;

    auto current_path = fs::current_path();
    current_path /= "text.txt";

    auto text = readFile(current_path.string());
    // std::cout << text << '\n' << '\n';

    const auto splitted_text = split_text(text);
    // print_vector(splitted_text);

    auto counted_words = count_words(splitted_text);
    print_map(counted_words);

    return 0;
}

WordVector split_text(const std::string &text) {
    auto words = WordVector{};
    auto iss = std::istringstream{text};
    auto line = std::string{};

    while (std::getline(iss, line)) {
        auto line_words = resplit(line);
        std::ranges::copy_if(line_words, std::back_inserter(words), [](const auto &word) {
            return !word.empty();
        });
    }
    return words;
}

CountedWordsMap count_words(const WordVector &words) {
    auto map = CountedWordsMap{};
    for (const auto &word: words) map[word]++;
    return map;
}
