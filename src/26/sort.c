#include <stdio.h>
#include <stdlib.h>
#include "queue.h"



void procedure (queue* q, int d)
{
  if (qSize(q) == 0){
    qPush(q, d);
  }else if (d < qTop(q)){
		qPush(q, d);
		while (d != qTop(q)){
			qPush(q, qTop(q));
		  qPop(q);
		}
	}else{
	
    int one = qTop(q);
		while (qTop(q) <= d){
			qPush(q, qTop(q));
			qPop(q);
			if (one == qTop(q)){
				break;
			}
		}
		qPush(q, d);

		while (qTop(q) != one){
			qPush(q, qTop(q));
			qPop(q);
		}
	
	}	
}

void Qsort(queue* q)
{
  queue w;
  qCreate(&w);
  while(qSize(q) > 0){
    int d = qTop(q);
    qPop(q);
    procedure(&w, d);
    }

  while(qSize(&w) > 0){
    qPush(q, qTop(&w));
    qPop(&w);
  }   

}
//void procedure(queue* q, int i, int one)
//{
 //     int lol;  
        
  //    if (Top(q) < one){
   //       lol = Top(q);
    //      Pop(q);
     //     while (Top(q) != one){
      //      Push(q, Top(q));
       //     Pop(q);
        //  }
         // Push(q, lol);
          //one = lol;
      //}else if (Top(q) > one){
       //   lol = Top(q);
        //  Pop(q);
         // while(Top(q) != one){
          //  Push(q,Top(q));
           // Pop(q);
         // }
          //for (int j = 0; j < i; j++)
          //{
           //if (lol > Top(q)){
           //  Push(q, Top(q));
          //   Pop(q);
           //}
          //}
          //Push(q, lol);
      // }
      // while(Top(q) != one){
      //   Push(q, Top(q));
       //   Pop(q);
       // }


//    }


//void sort(queue* q)
//{
   
   // for (int i = 0; i < Size(q); i++){
      //for with push pop
      //int one = Top(q); 
      //for(int k = 0; k < i; k++){
        //Push(q, Top(q));
        //Pop(q);
      //}
    //  procedure(q, i, one);
     
  //  }

//}