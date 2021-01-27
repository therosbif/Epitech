/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include "my_ls.h"

DIR *my_open(char *path)
{
    DIR *dirp = opendir(path);
    struct stat buf;

    if (dirp == NULL) {
        stat(path, &buf);
        if (S_ISREG(buf.st_mode)) {
            my_putstr(path);
            write(1, "\n", 1);
            return NULL;
        } else {
            write(2, "ERROR: Invalid path\n", 22);
            exit(84);
        }
    }
    return dirp;
}

int my_ls(char **av, char *path)
{
    flags_t *flags = set_flags(av);
    DIR *dirp = my_open(path);
    struct dirent *dir = (dirp) ? readdir(dirp) : NULL;
    char *buff = "\0";
    char **array = NULL;
    struct stat buf;

    if (dir == NULL)
        return 0;
    for (; dir; dir = readdir(dirp)) {
        buff = my_strcat(buff, dir->d_name, 0);
        lstat(dir->d_name, &buf);
        flags->total += (dir->d_name[0] != '.' || flags->a)? buf.st_blocks : 0;
    }
    flags->total /= 2;
    array = sort_array(str_to_array(array, buff), flags, path, NULL);
    my_show_word_array(array, flags, av, path);
    closedir(dirp);
    return 0;
}

int main(int ac, char **av)
{
    int path_flag = 0;

    my_ac = ac;
    for (int i = 1; i < ac; i++){
        if (av[i][0] != '-'){
            my_ls(av, av[i]);
            path_flag = 1;
        }
    }
    if (!path_flag)
        my_ls(av, ".");
    return 0;
}
