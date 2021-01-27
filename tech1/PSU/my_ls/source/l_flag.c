/*
** EPITECH PROJECT, 2019
** project
** File description:
** .
*/

#include "my_ls.h"

int my_nlen(int n)
{
    int i = 0;

    for (; n; n /= 10, i++);
    return i;
}

void my_puttime(char *time)
{
    time += 4;
    for (int colon = 0; *time != ':' || !colon; time++){
        (*time == ':') ? colon = 1 : 1;
        my_putchar(*time);
    }
}

void l_prefix2(struct stat buf)
{
    struct passwd *pwd = getpwuid(buf.st_uid);
    struct group *gp = getgrgid(buf.st_gid);

    my_put_nbr((int)buf.st_nlink);
    my_putchar(' ');
    my_putstr(pwd->pw_name);
    my_putchar(' ');
    my_putstr(gp->gr_name);
    my_putchar(' ');
    for (int i = 0; i > my_nlen(buf.st_size) - 5; my_putchar(' '), i--);
    my_put_nbr(buf.st_size);
    my_putchar(' ');
    my_puttime(ctime(&buf.st_mtime));
    my_putchar(' ');
}

void l_prefix(char *file, char *path)
{
    struct stat buf;

    lstat(my_strcat(my_strdup(path), file, 1), &buf);
    (S_ISDIR(buf.st_mode)) ? my_putchar('d') : 1;
    (S_ISREG(buf.st_mode)) ? my_putchar('-') : 1;
    (S_ISLNK(buf.st_mode)) ? my_putchar('l') : 1;
    my_putchar((buf.st_mode & S_IRUSR) ? 'r' : '-');
    my_putchar((buf.st_mode & S_IWUSR) ? 'w' : '-');
    my_putchar((buf.st_mode & S_IXUSR) ? 'x' : '-');
    my_putchar((buf.st_mode & S_IRGRP) ? 'r' : '-');
    my_putchar((buf.st_mode & S_IWGRP) ? 'w' : '-');
    my_putchar((buf.st_mode & S_IXGRP) ? 'x' : '-');
    my_putchar((buf.st_mode & S_IROTH) ? 'r' : '-');
    my_putchar((buf.st_mode & S_IWOTH) ? 'w' : '-');
    my_putchar((buf.st_mode & S_IXOTH) ? 'x' : '-');
    my_putchar(' ');
    l_prefix2(buf);
}
