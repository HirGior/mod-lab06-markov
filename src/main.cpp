// Copyright 2026

#include <fstream>
#include <iostream>
#include <string>

#include "../include/textgen.h"

int main() {
    TextGenerator generator(2);

    generator.BuildTable("../src/input.txt");

    std::string text = generator.GenerateText(1000);

    std::cout << text << std::endl;

    std::ofstream out("../result/gen.txt");

    out << text;

    out.close();

    return 0;
}
