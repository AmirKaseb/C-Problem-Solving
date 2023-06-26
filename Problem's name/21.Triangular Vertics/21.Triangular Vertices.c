#include <stdio.h>
#include <stdlib.h>

int Cmp(const void *a, const void *b) {
   return *(int*)a - *(int*)b;
}

    /* Try to make a triangle fit */
int Triangle(int row[3], int col[3]) {
   int len;

   if (row[0] == row[1]) {
      len = col[1] - col[0];
      return len>0 && col[2] == col[1] && row[2] == row[0]+len;
   } else {
      len = row[1] - row[0];
      return len>0 && col[0]==col[1] && row[2]==row[1] && col[2]==col[1]+len;
   }
}

    /* Try to make a parallelogram fit */
int Parallelogram(int row[4], int col[4]) {
   int len;

   if (row[0] == row[1]) {
      len = col[1] - col[0];
      return len>0 && row[2] == row[3] && col[3]-col[2] == len
	 && row[2]-row[0] == len
	 && (col[2] == col[0] || col[2] == col[1]);
   } else {
      len = row[1] - row[0];
      return len>0 && col[0]==col[1] && col[2]==col[3] && row[1]==row[2]
	 && row[3]-row[2]==len && col[2]-col[1]==len;
   }
}

int Hexagon(int row[6], int col[6]) {
   int len;

   len = col[1] - col[0];

   return len>0 &&
      row[0]==row[1] &&
      col[2]==col[0] && row[2]==row[0]+len &&
      col[3]==col[1]+len && row[3]==row[2] &&
      col[4]==col[1] && row[4]==row[2]+len &&
      col[5]==col[3] && row[5]==row[4];
}

void RowCol(int p, int *row, int *col) {
   int head, inc;

   for (head=1,inc=1; p>=head+inc; head+=inc++);
   *row = inc;
   *col = p - head;
}



int main() {
   char line[100];
   int points[6], row[6], col[6];
   int i, n, isvalid;

   while (gets(line), strlen(line)) {
      n = sscanf(line, "%d %d %d %d %d %d", points, points+1, points+2,
		 points+3, points+4, points+5);

      for (i=0; i<n; i++) printf("%d ", points[i]);
      qsort(points, n, sizeof(int), Cmp);
      for (i=0; i<n; i++) {
	 RowCol(points[i], row+i, col+i);
      }
      isvalid = (n==3) ? Triangle(row, col) :
	        (n==4) ? Parallelogram(row, col) :
		(n==6) ? Hexagon(row, col) :
	        0;
      printf("are %sthe vertices of %s\n",
	     isvalid ? "" : "not ",
	     !isvalid ? "an acceptable figure" :
	     n==3 ? "a triangle" :
	     n==4 ? "a parallelogram" : "a hexagon");
   }

   return 0;
}
