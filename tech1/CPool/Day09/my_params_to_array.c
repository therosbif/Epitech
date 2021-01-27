/*
** EPITECH PROJECT, 2019
** params to array
** File description:
** stores params in array
*/

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param *str = malloc(sizeof(struct info_param) * (ac + 1));
    int i = 0;
    
    if (str == 0)
        return (0);
    for ( ; i < ac ; i++) {
        str[i].length = my_strlen(av[i]);
        str[i].str = av[i];
        str[i].copy = my_strdup(av[i]);
        str[i].word_array = my_str_to_word_array(str);
    }
    str[i].str = 0;
    return (str);
}
