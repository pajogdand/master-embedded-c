#include <stdio.h>
#include <stdlib.h>


void half_pyramid(int level);
void reverse_half_pyramid(int level);
void pyramid(int level);
void reverse_pyramid(int level);
void pyramid_number(int level);

int main() {
   int level = 5;
   // half_pyramid(level);
   // reverse_half_pyramid(level);
   // pyramid(level);
   // reverse_pyramid(level);
   pyramid_number(level);

   exit(0);
}

void half_pyramid(int level)
{   
   int star_count = 0;
   for(int line=0;line<level;line++)
   {
      for(int col=0;col<level;col++)
      {
         if((line <= star_count) && (col <= star_count) ) 
            printf("*\t");
      }
      star_count++;
      printf("\n");      
   }
}

void reverse_half_pyramid(int level)
{  
   int star_count = 0;
   for(int line=0;line<level;line++)
   {
      for(int col=0;col<level;col++)
      {
         if((line >= star_count) && (col >= star_count) ) 
            printf("*\t");
      }
      star_count++;
      printf("\n");      
   }
}

void pyramid(int level)
{      
   int max_len = level + (level-1) ;
   int start = max_len/2;
   int end   = max_len/2;
   int number =  1;
   for(int line=0;line<level;line++)
   {
      for(int col=0;col<max_len;col++)
      {
         if((col >= start) && (col <= end) ) 
            printf("*\t" );
         else
            printf("\t");
      }
      start--;
      end++;
      printf("\n");      
   }
}

void reverse_pyramid(int level)
{      
   int max_len = level + (level-1) ;
   int start = 0;
   int end   = max_len-1;
   for(int line=0;line<level;line++)
   {
      for(int col=0;col<max_len;col++)
      {
         if((col >= start) && (col <= end) ) 
            printf("*\t");
         else
            printf("\t");
      }
      start++;
      end--;
      printf("\n");      
   }
}

void pyramid_number(int level)
{      
   int max_len = level + (level-1) ;
   int start = max_len/2;
   int end   = max_len/2;
   int number = 1;
   
   for(int line=0;line<level;line++)
   {
      int is_start =1;
      for(int col=0;col<max_len;col++)
      {
         if((col >= start) && (col <= end) ) 
         {
            {
               if(col == start || col == end)
               {
                  printf("1\t");   
               }
               else
               {
                  printf("%d\t",number++);
               }
               
            }
         }
         else
         {
            printf("\t");
         }
      }
      is_start =0;
      start--;
      end++;
      printf("\n");      
   }
}