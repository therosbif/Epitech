/*
** EPITECH PROJECT, 2021
** B-CPP-300-LYN-3-1-CPPD16-jack.goodall
** File description:
** BF_Translator
*/

#include "BF_Translator.hpp"

BF_Translator::BF_Translator()
{
    _instructions['+'] = "(*arr)++;";
    _instructions['-'] = "(*arr)--;";
    _instructions['>'] = "arr++;";
    _instructions['<'] = "arr--;";
    _instructions['.'] = "write(1, arr, 1);";
    _instructions[','] = "read(0, arr, 1);";
    _instructions['['] = "while (*arr) {";
    _instructions[']'] = "}";
}


int BF_Translator::translate(const std::string &in, const std::string &out)
{
    std::fstream bf;
    std::fstream c;
    char buff;

    bf.open(in, std::ios::in);
    c.open(out, std::ios::out);

    if (!bf || !c) return 1;
    c << "#include <stdlib.h>\n#include <unistd.h>\n\nint main()\n{\n\tchar *arr = calloc(60000, 1);\n\tchar *begin = arr;\n\n";
    while (bf.read(&buff, 1)) {
        c << "\t" << _instructions[buff] << std::endl;
    }
    c << "\tfree(begin);\n\treturn 0;\n}\n";
    bf.close();
    c.close();
    return 0;
}
