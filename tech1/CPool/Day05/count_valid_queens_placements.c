/*
** rosbif
** Day05
** File description:
** count_valid_queens_placements
*/

#define X coords[0]
#define Y coords[1]

int is_valid(int size, int coords[], char *board[])
{
    int edge = 0;

    for (int i = 0; i < size; i++) {
        if ((board[i][Y] && i != X) ||
            (board[X][i] && i != Y))
            return 0;
    }
    for (int i = 1; 1; i++) {
        if ((X + i < size && Y + i < size && board[X + i][Y + i]) ||
            (X + i < size && Y - i >= 0   && board[X + i][Y - i]) ||
            (X - i >= 0   && Y + i < size && board[X - i][Y + i]) ||
            (X - i >= 0   && Y + i >= 0   && board[X - i][Y - i]))
                return 0;
        if (i > size) break;
    }
    return 1;
}

int queen_rec(int size, int n, int coords[], char *board[])
{
    int cnt = 0;
    int valid = is_valid(size, coords, board);
    int next[2];

    if (n == 0) return 1;
    if (Y == size) return 0;
    if (valid)
        board[X][Y] = 1;
    next[0] = (X == size - 1) ? 0 : X + 1;
    next[1] = (X == size - 1) ? Y + 1 : Y;
    cnt += queen_rec(size, n - valid, next, board);
    board[X][Y] = 0;
    cnt += queen_rec(size, n, next, board);
    return cnt;
}

int count_valid_queens_placements(int n)
{
    char board[n][n];
    int coords[2] = {0, 0};

    return queen_rec(n, n, coords, board);
}
#include <stdio.h>

int main()
{
    printf("%d\n", count_valid_queens_placements(1));
    return 0;
}
