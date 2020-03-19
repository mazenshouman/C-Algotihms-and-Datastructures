#include <stdio.h>
#include <Hanoi.h>

void TowerOfHanoi(int NumberOfBlocks , int start , int finish  , int temp){
  if(NumberOfBlocks>0){
    /*move all blocks above the current block to the temp pool and then move the wanted block to the finish after that move all the block to the finish using   start*/
    TowerOfHanoi(NumberOfBlocks-1 , start , temp , finish);
    printf("Move Block %d from %d To %d" , NumberOfBlocks , start , finish);
    TowerOfHanoi(NumberOfBlocks-1 , temp , finish , start);    
  }  
}