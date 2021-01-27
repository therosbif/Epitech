#include <string>
#include <fstream>
#include <iostream>

int err_out(int code);
void inspection(char *name);

int main(int ac, char **av)
{
    if (ac == 1)
        return err_out(0);
    for (size_t i = 1; i < ac; i++)
        inspection(av[i]);
    return 0;
}

int err_out(int code)
{
    std::cerr << "Je n'ai aucun cadeau... le fouet pour ces elfs" << std::endl;
    return code;
}

void inspection(char *name)
{
    std::string ln;
    std::ifstream cat (name);

    if (!cat.is_open())
        std::cerr << "Oh my "<< name << ", that's it, to the naughty list" << std::endl;
    else
        while (std::getline(cat, ln))
            std::cout << ln.data() << std::endl;
    cat.close();
}