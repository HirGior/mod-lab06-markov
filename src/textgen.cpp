#include "../include/textgen.h"

#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

TextGenerator::TextGenerator(int prefSize)
{
    prefixSize = prefSize;
    srand(time(nullptr));
}

void TextGenerator::BuildTable(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
        return;

    Prefix prefix;
    std::string word;

    for (int i = 0; i < prefixSize; i++)
        prefix.push_back("");

    while (file >> word)
    {
        stateTable[prefix].push_back(word);

        prefix.pop_front();
        prefix.push_back(word);
    }

    stateTable[prefix].push_back("");
}

std::string TextGenerator::GenerateText(int maxWords)
{
    Prefix prefix;

    for (int i = 0; i < prefixSize; i++)
        prefix.push_back("");

    std::string result;

    for (int i = 0; i < maxWords; i++)
    {
        auto it = stateTable.find(prefix);

        if (it == stateTable.end())
            break;

        const std::vector<std::string>& suffixes = it->second;

        int index = rand() % suffixes.size();

        std::string nextWord = suffixes[index];

        if (nextWord == "")
            break;

        result += nextWord + " ";

        prefix.pop_front();
        prefix.push_back(nextWord);
    }

    return result;
}

const std::map<Prefix, std::vector<std::string>>& TextGenerator::GetTable() const
{
    return stateTable;
}

void TextGenerator::setTable(
    const std::map<Prefix, std::vector<std::string>>& table,
    const Prefix& first)
{
    stateTable = table;
    firstPrefix = first;
}

const Prefix& TextGenerator::getFirstPrefix() const
{
    return firstPrefix;
}

const std::map<Prefix, std::vector<std::string>>&
TextGenerator::getStatetab() const
{
    return stateTable;
}

std::string TextGenerator::generateString(int maxWords)
{
    Prefix prefix = firstPrefix;

    std::string result;

    for (const auto& word : prefix)
        result += word + " ";

    for (int i = prefixSize; i < maxWords; i++)
    {
        auto it = stateTable.find(prefix);

        if (it == stateTable.end())
            break;

        const auto& suffixes = it->second;

        int index = rand() % suffixes.size();

        std::string next = suffixes[index];

        result += next + " ";

        prefix.pop_front();
        prefix.push_back(next);
    }

    return result;
}