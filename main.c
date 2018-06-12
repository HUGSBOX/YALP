/*
 * Program: main.c
 * Y.A.L.P - Yet Another Life Program
 * A simplistic C implimentation of Conway's Game of Life.
 * Made to be easy to understand, modify, and extend.
 * 	Author: Will Cannon - 11/6/2018
 * 	williamcannon1996@gmail.com
 * 	Feel free to email with questions, comments, or improved versions
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "life.h"

#define TRUE 1

int main(int argc, char *argv[])
{
	struct Life life;
	
	life = new_life(life);
	
	if(argc > 2){
		printf("Input error: only accepts 1 argument.\n");
		return 1;
	}
	else if(argc == 2){
		if(strcmp(argv[1],"glider") == 0){
			life.grid = make_glider(life.grid);
		}
		else if(strcmp(argv[1],"r_pentomino") == 0){
			life.grid = make_r_pentomino(life.grid);
		}
		else if(strcmp(argv[1],"thunderbird") == 0){
			life.grid = make_thunderbird(life.grid);
		}
		else if(strcmp(argv[1],"herschel") == 0){
			life.grid = make_herschel(life.grid);
		}
		else{
			printf("Input error: no such argument\n");
			return 1;
		}
	}
	else{
		life.grid = make_r_pentomino(life.grid);
	}
	
	life.trans_grid = life.grid;

	printf("Welcome to Y.A.L.P - Yet Another Life Program.\n");
	printf("Please feel free to change the source code as you please - it should have been distributed with this program.\n");
	printf("For more information, have a look at the README.txt file that came with this executable.\n");
	printf("Press CTRL+C when you want to quit the program.\n");
	printf("PRESS ENTER TO CONTINUE\n");
	getchar();//waits for return key
	
	while(TRUE){
		print_grid(life);//print current grid
		life = next_generation(life);//generate next grid
	}
	return 0;
}
