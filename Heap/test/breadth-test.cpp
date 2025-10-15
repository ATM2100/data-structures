#include "unity.h"
#include "maze.hpp"


int** convert(int *maze, int w, int h) {
    int **ret = new int*[w];
    for (int i = 0; i < w; i++) {
        ret[i] = new int[h];
    }

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            ret[i][j] = *(maze + i * w + j);
        }
    }

    return ret;
}

void free_maze(int **maze, int w) {
    for (int i = 0; i < w; i++) {
        delete [] maze[i];
    }

    delete [] maze;
}


void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_simple(void) {
    // This is NOT a int**
    int open[10][10] = {
        { O, O, O, O, O, O, O, O, O, O },
        { O, O, O, O, O, O, O, O, O, O },
        { O, O, O, O, O, O, O, O, O, O },
        { O, O, O, O, O, O, O, O, O, O },
        { O, O, O, O, O, O, O, O, O, O },
        { O, O, O, O, O, O, O, O, O, O },
        { O, O, O, O, O, O, O, O, O, O },
        { O, O, O, O, O, O, O, O, O, O },
        { O, O, O, O, O, O, O, O, O, O },
        { O, O, O, O, O, O, O, O, O, O },
    };
    int **the_maze = convert((int*)open, 10, 10);

    TEST_ASSERT(shortest_path_length(the_maze, 10, 10, 0, 0, 9, 9) == 18);

    free_maze(the_maze, 10);
}

void test_walls(void) {
    // This is NOT a int**
    int walls[10][10] = {
        { O, O, O, W, O, O, O, O, O, O },
        { O, O, O, W, O, O, O, O, O, O },
        { O, W, O, W, O, O, O, W, O, W },
        { W, W, O, W, O, O, W, O, O, W },
        { O, O, O, W, O, O, W, O, W, W },
        { O, O, W, W, O, O, W, O, W, W },
        { O, O, W, O, O, O, W, O, W, W },
        { O, O, O, O, W, W, W, O, W, O },
        { O, O, W, W, W, W, O, O, W, O },
        { O, O, W, W, O, O, O, O, O, O },
    };
    int **the_maze = convert((int*)walls, 10, 10);

    TEST_ASSERT(shortest_path_length(the_maze, 10, 10, 0, 0, 9, 9) == 34);

    free_maze(the_maze, 10);
}

void test_blocked(void) {
    // This is NOT a int**
    int walls[10][10] = {
        { O, O, O, W, O, O, O, O, O, O },
        { O, O, O, W, O, O, O, O, O, O },
        { O, W, O, W, O, O, O, W, O, W },
        { W, W, O, W, O, O, W, O, O, W },
        { O, O, O, W, O, O, W, O, W, W },
        { O, O, W, W, O, O, W, O, W, W },
        { O, O, W, O, O, O, W, O, W, W },
        { O, O, O, O, W, W, W, O, W, O },
        { O, O, W, W, W, W, O, O, W, O },
        { O, O, W, W, O, O, O, O, W, O },
    };
    int **the_maze = convert((int*)walls, 10, 10);

    TEST_ASSERT(shortest_path_length(the_maze, 10, 10, 0, 0, 9, 9) == -1);

    free_maze(the_maze, 10);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_simple);
    RUN_TEST(test_walls);
    RUN_TEST(test_blocked);
    return UNITY_END();
}
