#ifndef LIFE_H
#define LIFE_H

//DEFAULT VALUES
#define HEIGHT 23
#define WIDTH 80

//#define HEIGHT 50
//#define WIDTH 100

struct Grid{
	int cells[HEIGHT][WIDTH];
};

struct Life{
	struct Grid grid;
	struct Grid trans_grid;
	int generation;
	int population;
	int min;
	int max;
};

struct Grid make_glider(struct Grid grid);

struct Grid make_r_pentomino(struct Grid grid);

struct Grid make_thunderbird(struct Grid grid);

struct Grid make_herschel(struct Grid grid);

struct Grid empty_grid(struct Grid grid);

void print_grid(struct Life life);

struct Life new_life(struct Life life);

int count_neighbors(struct Grid grid, int y_pos, int x_pos);

int count_population(struct Life *life);

struct Life next_generation(struct Life life);

#endif
