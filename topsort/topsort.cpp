#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAXL 100
#define MINL 3

typedef struct maze {
    int row;
    int col;
    int x;
    int y;
    int **map;
} maze;

using namespace std;

//§ ---------------- Maze TypeDef ----------------
maze *initMaze(int row, int col) {
    maze *m = (maze *) malloc(sizeof(maze));
    m->row = row;
    m->col = col;
    m->x = 0;
    m->y = 0;
    m->map = (int **) malloc(sizeof(int *) * row);
    for (int i = 0; i < row; i++) {
        m->map[i] = (int *) malloc(sizeof(int) * col);
    }
    return m;
}

void freeMaze(maze *m) {
    for (int i = 0; i < m->row; i++) {
        free(m->map[i]);
    }
    free(m->map);
    free(m);
}

maze *readInput() {
    //? Init Maze with size
    int row, col;
    scanf("%d %d", &row, &col);
    if (row < MINL || row > MAXL || col < MINL || col > MAXL) {
        return NULL;
    }
    maze *m = initMaze(row, col);

    //? Build maze
    for (int i = 0; i < row; i++) {
        int cell = 0;
        for (int j = 0; j < col; j++) {
            scanf("%d", &cell);
            m->map[i][j] = cell;
        }
    }

    //? Get start point
    scanf("%d %d", &m->x, &m->y);
    return m;
}

/// @brief Print maze to stdout.
/// DEBUG purpose only
/// @param m The maze to print
void printMaze(maze *m) {
    printf("Maze: %d %d\n", m->row, m->col);
    printf("Start: %d %d\n", m->x, m->y);
    for (int i = 0; i < m->row; i++) {
        for (int j = 0; j < m->col; j++) {
            printf("%d ", m->map[i][j]);
        }
        printf("\n");
    }
}

//§ ---------------- Maze Solver ----------------

/// @brief Solve the maze
/// @param m The maze to solve
/// @return 0 if solved, 1 if not
int solveMaze(maze *m) {
    //µ Topological sort
    //? DFS
    
}

//§ ---------------- Testing ----------------

int main() {
    maze *m = readInput();
    if (m == NULL) {
        printf("Invalid input\n");
        return 1;
    }
    printf("--- Maze ---\n");
    printMaze(m);
    freeMaze(m);
    return 0;
}