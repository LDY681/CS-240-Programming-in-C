
#include <stdio.h>
#include <stdlib.h>

#include "rpn.h"

#define MAXCOLS 80
#define MAXROWS 40

char plot[MAXROWS][MAXCOLS];
void clearPlot()
{
  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLS; j++) {
      plot[i][j] = ' ';
    }
  }
}
void printPlot()
{
  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLS; j++) {
      printf("%c", plot[i][j]);
    }
    printf("\n");
  }
}


void plotXY(int x, int y, char c) {
  if ( x <0 || x>=MAXCOLS || y < 0 || y >=MAXROWS) return;
  plot[y][x]=c;
}

void createPlot( char * funcFile, double minX, double maxX) {
  clearPlot();

  //Define arrays
  int nvals = MAXCOLS;
  double xx[MAXCOLS], yy[MAXCOLS];	//X and Y-axis
  double x, y;	//XandY value
  double minY, maxY;	//Local min and local max
  minY = maxY = 0;	//Initialize local min&max

  //Comput xx[i] & yy[i]
  int i;
  for (i = 0; i < MAXCOLS-1; ++i){
  	x = minX + (maxX - minX) * i / MAXCOLS;	//X-value

	// Evaluate function and store in vector yy
	y = rpn_eval(funcFile, x);	//Y-value
	xx[i] = x;
	yy[i] = y;
	
	//Compute maximum and minimum y in vector yy
	if (y < minY){
		minY = y;
	}
	if (y > maxY){
		maxY = y;
	}

  }

  //plot the x and y-axis using plotXY
  for ( i = 0; i < MAXCOLS-1;++i){	//plot x-axis
  	plotXY(i, MAXROWS - 1 - (int) (-minY * MAXROWS / (maxY - minY)), '_');	//Editted
  }
  
  for ( i = 0; i < MAXROWS-1;++i){	//plot x-axis
  	plotXY(MAXCOLS/2, i, '|');
  }
  // Plot function. Use scaling.
  // minX is plotted at column 0 and maxX is plotted ar MAXCOLS-1
  // minY is plotted at row 0 and maxY is plotted at MAXROWS-1
	
  for (i = 0; i < MAXCOLS-1; ++i){
  	int x1 = i ; //x plotted value
	int y1 = (int)(( yy[i]-minY ) * MAXROWS /(maxY - minY));	//Y plotted value
	y1 = MAXROWS - 1 - y1;	//flip on x-axis
	plotXY(x1, y1, '*');
  }
  printPlot();

}

int main(int argc, char ** argv)
{
  printf("RPN Plotter.\n");
  
  if (argc < 4) {
    printf("Usage: plot func-file xmin xmax\n");
    exit(1);
  }

  // Get arguments
  char *funcName = argv[1];	//funcName
  double minX = atof(argv[2]);	//The first column in the plot
  double maxX = atof(argv[3]);	//The last column in the plot

  //createPlot(funcName, xmin, xmax);
  createPlot(funcName, minX, maxX);
	
  return 0;  
}

