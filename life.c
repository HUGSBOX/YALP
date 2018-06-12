#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "life.h"

struct Grid make_glider(struct Grid grid)
{
	grid.cells[5][60] = 1;
	grid.cells[4][60] = 1;
	grid.cells[3][60] = 1;
	grid.cells[5][61] = 1;
	grid.cells[4][62] = 1;
	return grid;
}

struct Grid make_r_pentomino(struct Grid grid)
{
	grid.cells[HEIGHT/2][WIDTH/2] = 1;
	grid.cells[(HEIGHT/2)-1][WIDTH/2] = 1;
	grid.cells[(HEIGHT/2)-2][WIDTH/2] = 1;
	grid.cells[(HEIGHT/2)-1][(WIDTH/2)-1] = 1;
	grid.cells[(HEIGHT/2)-2][(WIDTH/2)+1] = 1;
	return grid;
}

struct Grid make_thunderbird(struct Grid grid)
{
	grid.cells[HEIGHT/2][WIDTH/2] = 1;
	grid.cells[(HEIGHT/2)+1][WIDTH/2] = 1;
	grid.cells[(HEIGHT/2)+2][WIDTH/2] = 1;
	grid.cells[(HEIGHT/2)-2][WIDTH/2] = 1;
	grid.cells[(HEIGHT/2)-2][(WIDTH/2)+1] = 1;
	grid.cells[(HEIGHT/2)-2][(WIDTH/2)-1] = 1;
	return grid;
}

struct Grid make_herschel(struct Grid grid)
{
	grid.cells[HEIGHT/2][WIDTH/2] = 1;
	grid.cells[HEIGHT/2][(WIDTH/2)+1] = 1;
	grid.cells[HEIGHT/2][(WIDTH/2)-1] = 1;
	grid.cells[(HEIGHT/2)+1][(WIDTH/2)-1] = 1;
	grid.cells[(HEIGHT/2)-1][(WIDTH/2)-1] = 1;
	grid.cells[(HEIGHT/2)+1][(WIDTH/2)+1] = 1;
	grid.cells[(HEIGHT/2)+2][(WIDTH/2)+1] = 1;
	return grid;
}

struct Grid empty_grid(struct Grid grid)
{
	for(int i = 0; i < HEIGHT; i++){
		for(int n = 0; n < WIDTH; n++){
			grid.cells[i][n] = 0;
		}
	}
	return grid;
}

void print_grid(struct Life life)
{
	for(int i = 0; i < HEIGHT; i++){
		for(int n = 0; n < WIDTH; n++){
			printf("%d",life.grid.cells[i][n]);
		}
		printf("\n");
	}
	life.population = count_population(&life);
	printf("Generation: %d  Population: %d",life.generation,life.population);
	sleep(1);
	printf("\n\n");
	return;
}

struct Life new_life(struct Life life)
{
	life.grid = empty_grid(life.grid);
	life.trans_grid = empty_grid(life.trans_grid);
	life.generation = 0;
	life.min = 0;
	life.max = 0;
	return life;
}

int count_neighbors(struct Grid grid, int y, int x)
{
	int neighbors = 0;
	if(grid.cells[y][x+1] == 1){
		neighbors++;
	}
	if(grid.cells[y][x-1] == 1){
		neighbors++;
	}
	if(grid.cells[y+1][x] == 1){
		neighbors++;
	}
	if(grid.cells[y-1][x] == 1){
		neighbors++;
	}
	if(grid.cells[y+1][x+1] == 1){
		neighbors++;
	}
	if(grid.cells[y+1][x-1] == 1){
		neighbors++;
	}
	if(grid.cells[y-1][x-1] == 1){
		neighbors++;
	}
	if(grid.cells[y-1][x+1] == 1){
		neighbors++;
	}
	return neighbors;
}

int count_population(struct Life *life)
{
	int population = 0;
	for(int i = 0; i < HEIGHT; i++){
		for(int n = 0; n < WIDTH; n++){
			if(life->grid.cells[i][n] == 1){
				population++;
			}
		}
	}
	if(life->generation == 0){
		life->min = population;
		life->max = population;
	}
	else if(population < life->min){
		life->min = population;
	}
	else if(population > life->max){
		life->max = population;
	}
	return population;
}

struct Life next_generation(struct Life life)
{
	life.trans_grid = life.grid;
	for(int i = 0; i < HEIGHT; i++){
		for(int n = 0; n < WIDTH; n++){
			int neighbors = count_neighbors(life.grid, i, n);
			if(life.grid.cells[i][n] == 1 && neighbors < 2){
				life.trans_grid.cells[i][n] = 0;
				continue;
			}
			if(life.grid.cells[i][n] == 1 && (neighbors == 2 || neighbors == 3)){
				continue;
			}
			if(life.grid.cells[i][n] == 1 && neighbors > 3){
				life.trans_grid.cells[i][n] = 0;
				continue;
			}
			if(life.grid.cells[i][n] == 0 && neighbors == 3){
				life.trans_grid.cells[i][n] = 1;
				continue;
			}
		}
	}
	life.grid = life.trans_grid;
	life.generation++;
	return life;
}
