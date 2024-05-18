#include <string>
#include <vector>
#include <algorithm>
#include "utils/assertions.hpp"


// Dynamic Programming Solution
// Complexity:
// - memory O(N), where N is the size of the first string
// - time O(N * M), where N is the size of the first string, M is the size of the second string 
std::string lcsDynamic(const std::string &lhs, const std::string &rhs)
{
    std::vector<int> commonSequenceLength(lhs.size(), 0);
    for (size_t lhsFirst = 0; lhsFirst < lhs.size(); ++lhsFirst)
    {
        size_t rhsFirst = 0;
        for (; rhsFirst < rhs.size() && lhs[lhsFirst] != rhs[rhsFirst]; ++rhsFirst);
        for (size_t currentChar = 0;
             lhsFirst + currentChar < lhs.size() &&
             rhsFirst + currentChar < rhs.size() &&
             lhs[lhsFirst + currentChar] == rhs[rhsFirst + currentChar];
             ++currentChar, ++commonSequenceLength[lhsFirst]);
            
    }
    auto max_iterator = std::ranges::max_element(commonSequenceLength);
    if (max_iterator == std::end(commonSequenceLength)) {
        return {};
    }
    const auto iterator_id = std::distance(std::begin(commonSequenceLength), max_iterator);
    return std::string(std::begin(lhs) + iterator_id, std::begin(lhs) + iterator_id + *max_iterator);
}


std::string lcsSuffix(const std::vector<std::string> &strings)
{
    return {};
}

int main()
{

    utils::assertEq(lcsDynamic("abba", "baba"), std::string("ab"), true);
    utils::assertEq(lcsDynamic("ba", "baba"), std::string("ba"), true);
    utils::assertEq(lcsDynamic("baba", "ba"), std::string("ba"), true);
    utils::assertEq(lcsDynamic("badanat", "canadas"), std::string("ana"), true);
    utils::assertEq(lcsDynamic("bananas", "bananas"), std::string("bananas"), true);

    // corner cases
    utils::assertEq(lcsDynamic("c", "da"), std::string(""), true);
    utils::assertEq(lcsDynamic("da", "c"), std::string(""), true);
    utils::assertEq(lcsDynamic("", "c"), std::string(""), true);
    utils::assertEq(lcsDynamic("c", ""), std::string(""), true);
    utils::assertEq(lcsDynamic("", ""), std::string(""), true);
    utils::assertEq(lcsDynamic(" a", "a "), std::string(" "), true);
    utils::assertEq(lcsDynamic(" a ", "a "), std::string("a "), true);
    utils::assertEq(lcsDynamic("Test text with a longer size ", "The longer the text the harder it is"), std::string(" longer "), true);

    return 0;
}