// Copyright 2026

#pragma once

#include <deque>
#include <map>
#include <string>
#include <vector>

using Prefix = std::deque<std::string>;
using Statetab = std::map<Prefix, std::vector<std::string>>;

class TextGenerator {
 private:
  int npref;
  Statetab statetab;
  Prefix first_prefix;

 public:
  explicit TextGenerator(int prefix_size);

  void build(std::istream& in);

  std::string generate(int max_words);

  void setTable(const Statetab& table, const Prefix& first);

  const Prefix& getFirstPrefix() const;

  const Statetab& getStatetab() const;

  std::string generateString(int max_words);
};