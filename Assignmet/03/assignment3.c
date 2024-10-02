#include <stdio.h>
#include <stdbool.h>

#define MAX 100

char maze[MAX][MAX];
int rows, cols;
int startX, startY, endX, endY;

int directionX[] = {0, 1, 0, -1};
int directionY[] = {1, 0, -1, 0};

void read_maze(const char *filename)
{
    FILE *file = fopen(filename, "r");
    rows = 0;
    while (fgets(maze[rows], MAX, file))
    {
        for (int j = 0; maze[rows][j] != '\0'; j++)
        {
            if (maze[rows][j] == 's')
            {
                startX = rows;
                startY = j;
            }
            else if (maze[rows][j] == 'E')
            {
                endX = rows;
                endY = j;
            }
        }
        rows++;
    }
    fclose(file);
}

bool find_path(int x, int y)
{
    if (x == endX && y == endY)
        return true;
    maze[x][y] = '+';

    for (int i = 0; i <= 3; i++)
    {
        int newX = x + directionX[i], newY = y + directionY[i];
        if (maze[newX][newY] == ' ' || maze[newX][newY] == 'E')
        {
            if (find_path(newX, newY))
                return true;
        }
    }

    maze[x][y] = ' ';
    return false;
}

void write_maze(const char *filename)
{
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < rows; i++)
    {
        fputs(maze[i], file);
    }
    fclose(file);
}

int main()
{
    read_maze("MAP01.txt");
    if (find_path(startX, startY))
        write_maze("67010482.txt");

    return 0;
}
