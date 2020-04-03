#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int A[4][4],P[4][4],I,J,x1,x2,x3,y1,y2,y3,say1,say2,say3,
	eleman1,eleman2,eleman3,gameover,win,score,prevscore,highscore,sayac,move,sure,anykey;
	char kaydir;
	
	highscore=0;
	
	// Game restarts from this line when user resets:
	RESET:			
					 
	//	Creating a matrix that has all elements are 0:
	for(I=0;I<4;I++){				
		for(J=0;J<4;J++){
			A[I][J]=0;
		}		
	}
	win=0;
	gameover=0;
	score=0;
			
	//	Generate two random coordinates to initialize 2 elements:
	srand(time(NULL));
	y1 = rand() % 4;	
	x2 = rand() % 4;	
	y2 = rand() % 4;
	if(x1==x2 && y1==y2){
		while(x1==x2 && y1==y2){
			x2 = rand() % 4;
			y2 = rand() % 4;
		}		
	}	
	
	//	Determines that new element is 2 or 4 (Generates a new element after each move)
	//	Probablity of generating 4: %20 | Probablity of generating 2: %80
	say1 = rand() % 5;			
	say2 = rand() % 5;
	if(say1==1){				
		eleman1=4;
	}
	else{
		eleman1=2;
	}
	if(say2==1){
		eleman2=4;
	}
	else{
		eleman2=2;
	}
	A[x1][y1]=eleman1;
	A[x2][y2]=eleman2;
	
	BACKUP:
	
	// Printing the matrix:
	printf("CURRENT STATE:\n ---- ---- ---- ---- \n");					
	for(I=0;I<4;I++){
		if(I!=0){
			printf("|\n ---- ---- ---- ---- \n");					
		}					
		for(J=0;J<4;J++){
			if(A[I][J]!=0){
				printf("|%4d",A[I][J]);
			}
			else{
				printf("|    ");
			}
		}		
	}
	printf("|\n ---- ---- ---- ---- \n\n");
	printf("YOUR SCORE: %d\nHIGHEST SCORE: %d\n\nUse 'W','A','S','D' to slide blocks.",score,highscore);	
	
	
	while(gameover==0){								
		
		//	Taking input for next move:
		kaydir=getch();
		
		if(kaydir=='r'||kaydir=='R'){
			for(I=0;I<4;I++){
				for(J=0;J<4;J++){
					A[I][J]=P[I][J];
				}
			}	
			score=prevscore;
			if(score==highscore){
				highscore=prevscore;
			}			
			goto SKIP;	
		}
		
		if(kaydir=='e'||kaydir=='E'){
			printf("\nAre you sure do you want to exit? (Y/N)\n");
			sure=getch();
			if(sure=='y'||sure=='Y'){		
				goto EXIT;
			}
		}
		
		if(kaydir=='x'||kaydir=='X'){
			printf("\nAre you sure do you want to restart game? (Y/N)\n");
			sure=getch();			
			if(sure=='y'||sure=='Y'){
				system("CLS");
				goto RESET;
			}
		}
		
		//	Storing the previous state in another matrix:
		for(I=0;I<4;I++){								
			for(J=0;J<4;J++){
				P[I][J]=A[I][J];
			}
		}
			
		prevscore=score;
		move=0;
	
		if(kaydir=='w'||kaydir=='W'){
			for(J=0;J<4;J++){
				for(I=1;I<4;I++){
					while(A[I][J]!=0 && A[I-1][J]==0 && I!=0){
						A[I-1][J]=A[I][J];
						A[I][J]=0;
						I--;
						move++;
					}
					while(A[I][J]!=0 && A[I-1][J]==A[I][J] && I!=0){
						A[I-1][J]=A[I-1][J]+A[I][J];
						A[I][J]=0;
						score=score+A[I-1][J];
						if(A[I-1][J]==2048){
							win=1;
						}
						move++;						
					}
				}			
			}
		}
		if(kaydir=='s'||kaydir=='S'){
			for(J=0;J<4;J++){
				for(I=2;I>=0;I--){
					while(A[I][J]!=0 && A[I+1][J]==0 && I!=3){
						A[I+1][J]=A[I][J];
						A[I][J]=0;
						I++;
						move++;
					}
					while(A[I][J]!=0 && A[I][J]==A[I+1][J] && I!=3){
						A[I+1][J]=A[I+1][J]+A[I][J];
						A[I][J]=0;
						score=score+A[I+1][J];
						if(A[I+1][J]==2048){
							win=1;
						}
						move++;
					}
				}
			}		
		}
		if(kaydir=='a'||kaydir=='A'){
			for(I=0;I<4;I++){
				for(J=1;J<4;J++){
					while(A[I][J]!=0 && A[I][J-1]==0 && J!=0){
						A[I][J-1]=A[I][J];
						A[I][J]=0;
						J--;
						move++;
					}
					while(A[I][J]!=0 && A[I][J-1]==A[I][J]){
						A[I][J-1]=A[I][J-1]+A[I][J];
						A[I][J]=0;
						score=score+A[I][J-1];
						if(A[I][J-1]==2048){
							win=1;
						}
						move++;						
					}
				}
			}		
		}
		if(kaydir=='d'||kaydir=='D'){	
			for(I=0;I<4;I++){
				for(J=2;J>=0;J--){
					while(A[I][J]!=0 && A[I][J+1]==0 && J!=3){
						A[I][J+1]=A[I][J];
						A[I][J]=0;
						J++;
						move++;
					}
					while(A[I][J]!=0 && A[I][J+1]==A[I][J]){
						A[I][J+1]=A[I][J+1]+A[I][J];
						A[I][J]=0;
						score=score+A[I][J+1];
						if(A[I][J+1]==2048){
							win=1;
						}
						move++;						
					}
				}
			}
		}	

		// Generating a random element after the move:
		if(move!=0){
			say3 = rand() % 5;								
			if(say3==1){
				eleman3=4;
			}
			else{
				eleman3=2;
			}
				x3 = rand() % 4;
				y3 = rand() % 4;
				
			while(A[x3][y3]!=0){				
				x3 = rand() % 4;
				y3 = rand() % 4;
			}	
		A[x3][y3]=eleman3;	
		}
	
		SKIP:
		
		if(score>highscore){
			highscore=score;
		}
		
		//	Checking if game is over:
		sayac=0;                    											
		for(I=0;I<4;I++){
			for(J=0;J<4;J++){
				if(A[I][J]!=0 && I==0 && J!=0 && J!=3 && A[I][J]!=A[I][J-1] && A[I][J+1] && A[I][J]!=A[I+1][J]){
					sayac++;
				}
				if(A[I][J]!=0 && I==0 && J==0 && A[I][J]!=A[I+1][J] && A[I][J]!=A[I][J+1]){
					sayac++;
				}
				if(A[I][J]!=0 && I==0 && J==3 && A[I][J]!=A[I+1][J] && A[I][J]!=A[I][J-1]){
					sayac++;
				}
				if(A[I][J]!=0 && I==3 && J!=0 && J!=3 && A[I][J]!=A[I][J-1] && A[I][J+1] && A[I][J]!=A[I-1][J]){
					sayac++;
				}
				if(A[I][J]!=0 && I==3 && J==0 && A[I][J]!=A[I-1][J] && A[I][J]!=A[I][J+1]){
					sayac++;
				}
				if(A[I][J]!=0 && I==3 && J==3 && A[I][J]!=A[I-1][J] && A[I][J]!=A[I][J-1]){
					sayac++;
				}
				if(A[I][J]!=0 && I!=0 && I!=3 && J!=0 && J!=3 && A[I][J]!=A[I-1][J] && A[I][J]!=A[I+1][J] && A[I][J]!=A[I][J-1] && A[I][J]!=A[I][J+1]){
					sayac++;
				}
				if(A[I][J]!=0 && I!=0 && I!=3 && J==0 && A[I][J]!=A[I][J+1] && A[I][J]!=A[I+1][J] && A[I][J]!=A[I-1][J]){
					sayac++;
				}
				if(A[I][J]!=0 && I!=0 && I!=3 && J==3 && A[I][J]!=A[I][J-1] && A[I][J]!=A[I-1][J] && A[I][J]!=A[I+1][J]){
					sayac++;
				}
			}
		}
		if(sayac==16){
			gameover=1;
		}				
			
		system("CLS");
		
		//	Printing the matrix:
		printf("CURRENT STATE:\n");
		printf(" ---- ---- ---- ---- \n");
			for(I=0;I<4;I++){
			if(I!=0){
				printf("|\n ---- ---- ---- ---- \n");						
			}					
			for(J=0;J<4;J++){
				if(A[I][J]!=0){
					if(I==x3 && J==y3){
						printf("|%3d*",A[I][J]);
					}
					else{
						printf("|%4d",A[I][J]);
					}					
				}
				else{
					printf("|    ");
				}
			}	
		}
		printf("|\n ---- ---- ---- ---- \n\n");
		printf("YOUR SCORE: %d\nHIGHEST SCORE: %d\n\n\n",score,highscore);		
		
		//	Printing the previous state matrix:
		printf("PREVIOUS STATE:\n");						
		printf(" ---- ---- ---- ---- \n");
			for(I=0;I<4;I++){
			if(I!=0){
				printf("|\n ---- ---- ---- ---- \n");						
			}					
			for(J=0;J<4;J++){
				if(P[I][J]!=0){
					printf("|%4d",P[I][J]);
				}
				else{
					printf("|    ");
				}
			}	
		}
		printf("|\n ---- ---- ---- ---- \n\nPress 'E' to exit.\nPress 'X' to restart game.\nPress 'R' to go back to previous state.\n");

		//	If game is over:
		if(gameover==1){
			printf("\nGAME OVER\n\nYOUR SCORE: %d\nHIGHEST SCORE: %d\nPress any key to start new game.",score,highscore);
			anykey=getch();
			system("CLS");
			goto RESET;
		}
		
		//	If player wins:
		if(win==1){	
			printf("\nYOU WIN!\nYOUR SCORE: %d\nHIGHEST SCORE: %d\nPress any key to start new game.",score,highscore);
			anykey=getch();
			system("CLS");
			goto RESET;
		}		
	}	
	EXIT:
	return 0;
}
