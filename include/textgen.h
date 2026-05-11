#pragma once

#include <string>
#include <deque>
#include <map>
#include <vector>

typedef std::deque<std::string> Prefix;

class TextGenerator
{
private:
    int prefixSize;

    Prefix firstPrefix;

    std::map<Prefix, std::vector<std::string>> stateTable;

public:
    TextGenerator(int prefSize);

    void BuildTable(const std::string& filename);

    std::string GenerateText(int maxWords);

    const std::map<Prefix, std::vector<std::string>>& GetTable() const;

    void setTable(
        const std::map<Prefix, std::vector<std::string>>& table,
        const Prefix& first);

    const Prefix& getFirstPrefix() const;

    const std::map<Prefix, std::vector<std::string>>& getStatetab() const;

    std::string generateString(int maxWords);
};