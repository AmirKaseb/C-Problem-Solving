#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 25
#define InsMAX 25

int block_record[MAX] = {-1};
int block_pos[MAX][MAX];

void move_load(int src, int pos_src)
{
   int i, j, k;
   for(i = 0; i < MAX; i++)
   {
      if(block_pos[pos_src][i] == src)break;
   }
   for(j = i+1; j < MAX; j++)
   {
      if(block_pos[pos_src][j] == -1)break;
      for(k = 0; k < MAX; k++)
      {
         if(block_pos[ block_pos[pos_src][j] ][k] == -1)
         {
            block_pos[ block_pos[pos_src][j] ][k] = block_pos[pos_src][j];
            block_record[ block_pos[pos_src][j] ] = block_pos[pos_src][j];
            break;
         }
      }
      block_pos[pos_src][j] = -1;
   }
}

void move(int src, int pos_des)
{
   int i, j, k;
   int pos_src = block_record[src];
   for(i = 0; i < MAX; i++)
   {
      if(block_pos[pos_src][i] == src)break;
   }
   for(j = i; j < MAX; j++)
   {
      if(block_pos[pos_src][j] == -1)break;
      for(k = 0; k < MAX; k++)
      {
         if(block_pos[pos_des][k] == -1)
         {
            block_pos[pos_des][k] = block_pos[pos_src][j];
            block_record[ block_pos[pos_src][j] ] = pos_des;
            break;
         }
      }
      block_pos[pos_src][j] = -1;
   }
}

void move_onto(int a, int b)
{
   int pos_a = block_record[a];
   int pos_b = block_record[b];
   move_load(a, pos_a);
   move_load(b, pos_b);
   move(a, pos_b);
}

void move_over(int a, int b)
{
   int pos_a = block_record[a];
   int pos_b = block_record[b];
   move_load(a, pos_a);
   move(a, pos_b);
}

void pile_onto(int a, int b)
{
   int pos_a = block_record[a];
   int pos_b = block_record[b];
   move_load(b, pos_b);
   move(a, pos_b);
}

void pile_over(int a, int b)
{
   int pos_a = block_record[a];
   int pos_b = block_record[b];
   move(a, pos_b);
}

int main()
{
   /*declartion & initialization*/
   int num, a, b;
   scanf("%d", &num);
   int i, j;

   for(i = 0; i < MAX; i++)
   {
      for(j = 0; j < MAX; j++)block_pos[i][j] = -1;
   }
   for(i = 0; i < num; i++)block_record[i] = i;  //initialize position
   for(i = 0; i < num; i++)block_pos[i][0] = i;

   char instruction[InsMAX];
   char movement[InsMAX];
   char position[InsMAX];
   gets(instruction);    //take away "\n"

   /*get instruction*/

   while(gets(instruction))
   {
      if(strcmp(instruction, "quit") == 0)break;
      sscanf(instruction, "%s %d %s %d", movement, &a, position,&b);
      //***************check error
      if(a == b || block_record[a]==block_record[b])continue;

      if(strcmp(movement, "move") == 0 && strcmp(position, "onto") == 0)
      {
         move_onto(a, b);
      }
      else if(strcmp(movement, "move") == 0 && strcmp(position, "over") == 0)
      {
         move_over(a, b);
      }
      else if(strcmp(movement, "pile") == 0 && strcmp(position, "onto") == 0)
      {
         pile_onto(a, b);
      }
      else if(strcmp(movement, "pile") == 0 && strcmp(position, "over") == 0)
      {
         pile_over(a, b);
      }
      else
      {
         return 1;
      }
   }

   /*print all*/
   for(i = 0; i < num; i++)
   {
      printf("%d:", i);
      for(j = 0; j < MAX; j++)
      {
         if(block_pos[i][j] == -1)
         {
            printf("\n");
            break;
         }
         printf(" ");
         printf("%d", block_pos[i][j]);
      }
   }
   //system("pause");
   return 0;
}
