#include <stdio.h>

int main(){
   float start_price = 35000.0;
   int month = 1;
   while(start_price > 0.0){
      if((month % 12) == 0){
         start_price *= 1.02;
      }
      start_price -= 300;
      month++;
      if(month == 72){
         printf("%f", start_price);
      }
   }
   printf("%d", month);
   printf("%d", month/24);
}
