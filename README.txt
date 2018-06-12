Y.A.L.P - Yet Another Life Program
Author: Will Cannon 
williamcannon1996@gmail.com

A simplistic implimentation of Conway's Game of Life written in C.  

MANAUL

INTRODUCTION

While this manual isn't here for the purpose of explaining the _whole_ source code,
the source code will still be referenced in a few ways in this document, so
that the user can better understand what they can do to make this program
their own - whether they are a rookie, or a guru.

This program is free - like free speech, as well as like free beer.  The user
is encouraged to change and distribute this program as they see fit, as long
as those same rights are extended to anyone they distribute their changes to.
This is the basic principle of the GNU General Public License (version 2.0)
which is distributed with this program, and (of course) MUST be distributed 

USAGE

Using YALP is simple.  

	$ yalp 

Without any arguments, YALP will generate R_Pentomino.  There are a variety of
different patterns built-in by default.  

	$ yalp thunderbird
	$ yalp glider
	$ yalp r_pentomino

To initialize YALP with a built-in pattern, use the pattern's name as your
argument to YALP.  YALP will only accept one argument, as only one pattern can
be running at a time.  YALP will exit and return 1 for "invalid input" if you
enter more than 1 argument, or if you enter an invalid (non-existent)
argument.

Please note that many methuselah (patterns that take many generations to
stabalize) will not stabalize as expected due to the
limited grid size, which by default is 23x80 in order to comply with the most
common default terminal size (24x80) and allow for an additional line for the
status message.

It is possible to change the definitions of HEIGHT and WIDTH at the top of
life.h to whatever size suits your needs - also note though, that higher
numbers will cause the program to run more slowly.  I personally recommend
commenting out the default values and defining your new values below, so that
you can return to default without having to refer to this manual in case you
forget.  That would look like this:

	//DEFAULTS
	//define HEIGHT 23
	//define WIDTH 80
	define HEIGHT 40
	define WIDTH 100

Rookie tip: you MUST keep the variable names the same when doing this, or else
the program won't compile because it can't refer to the expected variable
names.  They are cAsE sEnSiTiVe.

Additional note on grid size: if you're increasing (or decreasing) the grid size a substantial
amount, you may want to (or it may be necessary to) change the definitions of
any patterns you intend to use.  These are all defined in life.c, they look
like:

	struct Grid make_*(struct Grid grid)

where you replace * with the name of the pattern it defines, with _ instead of
spaces.  Use whatever tricks you like to define your patterns, but the simpest
way is: 
	
	grid.cells[10][10] = 1;
	grid.cells[9][10] = 1;

individually "turning on" each cell you want to be alive in the initial
pattern (generation 0).  If you're used to traditional xy coordinates,
unfortunately the way "for" loops work makes it more convenient for the y
(vertical) value to come first in grid.cells[][] and the x (horizontal) value
to be second.  Also, instead of grid.cells[0][0] being the bottom left of the
grid, as you might typically expect outside of computing, it is the top left
(the first grid cell printed).  Please remember that if you're writing a new
make_ function, it won't work as expected if you don't remember to return
grid;

As well, any make_ function that you create needs to be called somewhere in "main" 
- preferrably in the input handling loop.  Just follow the format you see already 
being used in the file - the relevant argument is argv[1], only one argument is acceptable.

PROBLEMS:

A) "Stitch" the edges of the grid together to create toroidal array.

B) Get the program to detect when a pattern has stabalized and stop
it, presenting the user with the generation at which it stabalized along with
the population at the time.

C) Record the minimum and maximum populations of a pattern, along with
their corresponding generations, and print them when the program is stopped.

D) KEENER BONUS: Create a function (or set of functions) that allow grids to be
written to, or read from .txt files for saving and loading.
