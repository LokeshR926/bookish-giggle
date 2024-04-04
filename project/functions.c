/*The functions file for the chess game.*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<limits.h>
#include"header.h"
// The function to create the file to start the game.
void startGame(char mat[8][8]){
	FILE *file;
	int i,j;
	file=fopen("game.txt","w+");
	if(file==NULL){
		puts("**********Unable to open the file.********");
		return;
	}
	else{
			fprintf(file,"\n\t\t\t\t\t   1  2  3  4  5  6  7  8");
			fprintf(file,"\n\t\t\t\t\t1 [%c][%c][%c][%c][%c][%c][%c][%c]",mat[0][0],mat[0][1],mat[0][2],mat[0][3],mat[0][4],mat[0][5],mat[0][6],mat[0][7]);
			fprintf(file,"\n\t\t\t\t\t2 [%c][%c][%c][%c][%c][%c][%c][%c]",mat[1][0],mat[1][1],mat[1][2],mat[1][3],mat[1][4],mat[1][5],mat[1][6],mat[1][7]);
			fprintf(file,"\n\t\t\t\t\t3 [%c][%c][%c][%c][%c][%c][%c][%c]",mat[2][0],mat[2][1],mat[2][2],mat[2][3],mat[2][4],mat[2][5],mat[2][6],mat[2][7]);
			fprintf(file,"\n\t\t\t\t\t4 [%c][%c][%c][%c][%c][%c][%c][%c]",mat[3][0],mat[3][1],mat[3][2],mat[3][3],mat[3][4],mat[3][5],mat[3][6],mat[3][7]);
			fprintf(file,"\n\t\t\t\t\t5 [%c][%c][%c][%c][%c][%c][%c][%c]",mat[4][0],mat[4][1],mat[4][2],mat[4][3],mat[4][4],mat[4][5],mat[4][6],mat[4][7]);
			fprintf(file,"\n\t\t\t\t\t6 [%c][%c][%c][%c][%c][%c][%c][%c]",mat[5][0],mat[5][1],mat[5][2],mat[5][3],mat[5][4],mat[5][5],mat[5][6],mat[5][7]);
			fprintf(file,"\n\t\t\t\t\t7 [%c][%c][%c][%c][%c][%c][%c][%c]",mat[6][0],mat[6][1],mat[6][2],mat[6][3],mat[6][4],mat[6][5],mat[6][6],mat[6][7]);
			fprintf(file,"\n\t\t\t\t\t8 [%c][%c][%c][%c][%c][%c][%c][%c]",mat[7][0],mat[7][1],mat[7][2],mat[7][3],mat[7][4],mat[7][5],mat[7][6],mat[7][7]);
	}
	fclose(file);
}
// The function to display the file.
void display(void){
	FILE *file;
	char ch;
	file=fopen("game.txt","r");
	if(file==NULL){
		puts("********Unable to access the file, sorry************");
		return;
	}
	/*while(!feof(file)){		printf("erro");
		//fgets(s,1,file);
		fscanf(file,"%s",s);
		printf("%s\n",s);
	}*/
	while((ch=fgetc(file))!=EOF){
		//if(ch=='P'){
		//	printf("♙");
		//}
		//else
			putchar(ch);
	}
	printf("\n♔");
	fclose(file);
}
// The function for the matrix input first time.
void matrix(char mat[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i==1)    mat[i][j]='P';
            else if(i==6)   mat[i][j]='p';
            else    mat[i][j]=' ';
        }
    }
    mat[0][0]='R';//white pieces.
    mat[0][1]='N';
    mat[0][2]='B';
    mat[0][3]='Q';
    mat[0][4]='K';
    mat[0][5]='B';
    mat[0][6]='N';
    mat[0][7]='R';
    //blackpieces.
    mat[7][0]='r';
    mat[7][1]='n';
    mat[7][2]='b';
    mat[7][3]='q';
    mat[7][4]='k';
    mat[7][5]='b';
    mat[7][6]='n';
    mat[7][7]='r';
}

// The function to move the white soilder.
int P_soilder(int r, int c, int i, int j, char mat[8][8]){
	
	if(j==c&&i>r){
		if(r==1&&(i==2||i==3)){
			if(!islower(mat[i][j]))
        		return 1;
		}
		else if(i==r+1){
			if(!islower(mat[i][j]))
				return 1;
		}
	}
	
	if((j==c+1||j==c-1)&&i==r+1){
		if(mat[i][j]!=' '){
			return 1;
		}
	}
	else{
		return 0;
	}
}

// The function to move the black soilder.
int p_soilder(int r, int c, int i, int j, char mat[8][8]){

	if(j==c&&i<r){
		if(r==6&&(i==5||i==4)){
			if(!isupper(mat[i][j]))
        		return 1;
		}
		else if(i==r-1){
			if(!isupper(mat[i][j]))
				return 1;
		}
	}
	
	if((j==c-1||j==c+1)&&i==r-1){
		if(mat[i][j]!=' '){
			return 1;
		}
	}
	else{
		printf("invalid position to move");
		return 0;
	}
}
// The function to move the rock.
int R_rock(int r,int c, int i, int j, char mat[8][8]){
	int k;
	if(i==r){
		if(j>c){
			k=c+1;
			while(k<j){
				if(isupper(mat[r][k]||islower(mat[r][k]))){
					printf("1");
					return 0;
				}k++;
			}
			if(islower(mat[i][j])||mat[i][j]==' ')
				return 1;
		}
		if(j<c){
			k=c-1;
			while(k>j){
				if(isupper(mat[r][k])||islower(mat[r][k])){
					printf("2");
					return 0;
				}k--;
			}
			if(islower(mat[i][j])||mat[i][j]==' ')
				return 1;
		}
	}
	else if(j==c){
			if(i>r){
				for(k=r+1;k<i;k++){
					if(isupper(mat[k][c])||islower(mat[k][c])){
						printf("3");
						return 0;
					}
				}
				if(islower(mat[i][j])||mat[i][j]==' ')
					return 1;
			}
			else if(i<r){
					k=r-1;
					while(k>i){
						if(isupper(mat[k][c])||islower(mat[k][c])){
							printf("4");
							return 0;
						}
						k--;
					}
					if(islower(mat[i][j])||mat[i][j]==' ')
						return 1;
				}
		}
	else 
		printf("error:::::::");	
		return 0;
}
// The to move the black rock.
int r_rock(int r,int c, int i, int j,char mat[8][8]){
	int k;
	
	if(i==r){
		if(j>c){
			k=c+1;
		while(k<j){
			if(islower(mat[i][k])||isupper(mat[i][k])){
				return 0;
			} k++;
		}
		if(isupper(mat[i][j])||mat[i][j]==' ')
			return 1;
		}
		else if(j<c){
			k=c-1;
			while(k>j){
				if(islower(mat[i][k])||isupper(mat[i][k])){
					return 0;
				}k--;
			}
			if(isupper(mat[i][j])||mat[i][j]==' ')
				return 1;
		}
	}
	else if(j==c){
		if(i>r){
			k=r+1;
			while(k<i){
				if(islower(mat[k][j])||isupper(mat[k][j])){
					return 0;
				}k++;
				
			}
			if(isupper(mat[i][j])||mat[i][j]==' ')
				return 1;
		}
		if(i<r){
			k=r-1;
			while(k>i){
				if(islower(mat[k][j])||isupper(mat[k][j])){
					return 0;
				}k--;
			}
			if(isupper(mat[i][j])||mat[i][j]==' ')
				return 1;
		}
	}
	else 
			return 0;
}
// The function to check the move of the bishop.
int B_bishop(int r, int c, int i, int j, char mat[8][8]){
	int l,m;
	if(r>i){
		if(i<=j){
			l=r-1;m=c+1;
			while(l>i){
				if(isupper(mat[l][m])||islower(mat[l][m])){
					printf("1");
					return 0;
				}
				else
					{l--; m++;}
			}
			if(islower(mat[i][j])||mat[i][j]==' '){
				printf("b1");
				return 1;}
		}
		else if(i>=j){
			m=c-1;l=r-1;
			while(l>i){
				if(isupper(mat[l][m])||islower(mat[l][m])){
					printf("2");
					return 0;
				}
				else{
					l--;
					m--;
				}
			}
			if(islower(mat[i][j])||mat[i][j]==' '){
				printf("b2");
				return 1;}
		}
	}
	else if(r<i){
		//printf("a");
		if(i>=j){
			//printf("b");
			m=c+1;l=r+1;
			while(l<i){
				if(isupper(mat[l][m])||islower(mat[l][m])){
					//printf("3");
					return 0;
				}
				else{
				l++;
				m--;
				}
			}
			if(islower(mat[i][j])||mat[i][j]==' '){
				printf("b3");
				return 1;}
		}
		else if(i<=j){
			//printf("c");
			m=c+1; l=r+1;
			while(l<i){
				if (isupper(mat[l][m])||islower(mat[l][m])){
					//printf("4");
					return 0;
				}
				else{ 
					l++; m++;
				}
			}
			if(islower(mat[i][j])||mat[i][j]==' '){
				printf("b4");
				return 1;}
		}
	}
	//printf("5");
	return 0;
}
// The function to check the move of the black bishop.
int b_bishop(int r, int c, int i, int j, char mat[8][8]){
	int l,m;
	if(r>i){
		if(i<=j){
			l=r-1;m=c+1;
			while(l>i){
				if(islower(mat[l][m])||isupper(mat[l][m])){
					return 0;
				}
				else{
					l--; m++;
				}
			}
			if(isupper(mat[i][j])||mat[i][j]==' ')
				return 1;
		}
		else if(i>=j){
			m=c-1;l=r-1;
			while(l>i){
				if(islower(mat[l][m])||isupper(mat[l][m])){
					return 0;
				}
				else{
					l--;m--;}
			}
			if(isupper(mat[i][j])||mat[i][j]==' ')
				return 1;
		}
	}
	else if(r<i){
		if(i>=j){
			m=c+1;l=r+1;
			while(l<i){
				if(islower(mat[l][m])||isupper(mat[l][m])){
					return 0;
				}
				else {
				l++;
				m++;
				}
			}
			if(isupper(mat[i][j])||mat[i][j]==' ')
				return 1;
		}
		else if(i<=j){
			m=c-1; l=r+1;
			while(l<i){
				if (islower(mat[l][m])||isupper(mat[l][m])){
					return 0;
				}
				else {
					l++; m--;
				}
			}
			if(isupper(mat[i][j])||mat[i][j]==' ')
				return 1;
		}
	}
	return 0;
	
}
//The function to check the move of the queen.
int Q_queen(int r, int c, int i, int j, char mat[8][8]){
	int ch=0;
	if(R_rock(r,c,i,j,mat) || B_bishop(r,c,i,j,mat)){
		return 1;
	}
	else 
		return 0;
}
//The function to check the move of the queen.
int q_queen(int r, int c, int i, int j, char mat[8][8]){
	int ch=0;
	if(r_rock(r,c,i,j,mat) || b_bishop(r,c,i,j,mat)){
		return 1;
	}
	else 
		return 0;
}

// The function to check the white knights move.
int N_knights(int r,int c, int i, int j, char mat[8][8]){
	int ch;
	/*if((abs(r-i)<=2)&&(abs(c-j)<=2)){
		printf("1");
		ch=Q_queen(r,c,i,j,mat);
		printf("%d",ch);
		if(ch==0){
			return 1;
		}
	}*/
	if(((i==r-1||i==r+1)&&(j==c+2||j==c-2))||((i==r+2||i==r-2)&&(j==c+1||j==c-1)))
	{
		printf("g");
		if(isupper(mat[i][j]))
			return 0;
		else	
			return 1;
	}
	return 0;
}
// The function to check the  black knights move.
int n_knights(int r,int c, int i, int j, char mat[8][8]){
	int ch;
	/*if((abs(r-i)<=2)&&(abs(c-j)<=2)){
		ch=q_queen(r,c,i,j,mat);
		if(ch==0){
			return 1;
		}
	}*/
	if(((i==r-1||i==r+1)&&(j==c+2||j==c-2))||((i==r+2||i==r-2)&&(j==c+1||j==c-1)))
	{
		if(islower(mat[i][j]))
			return 0;
		else	
			return 1;
	}
	return 0;
}
// The function to move the king.
int K_king(int r, int c, int i, int j, char mat[8][8]){
	if((i==r+1||i==r-1||i==r)&&(j==c+1||j==c-1||j==c))
		return 1;
	return 0;
}
// The function to move black king.
int k_king(int r, int c, int i,int j, char mat[8][8]){
	if((i==r+1||i==r-1||i==r)&&(j==c+1||j==c-1||j==c))
		return 1;
	return 0;
}

//The function to check weather move is check or not.
int check(int r, int c,char mat[8][8]){
	int a,b;
	if(isupper(mat[r][c])){
		// check the position of the k_king and find the path is true or false.
		for (a=0;a<8; a++)
		{
			for(b=0;b<8;b++){
				if(mat[a][b]=='k')
					break;
			}
		}
		switch(mat[r][c]){
			case 'P':
					if(P_soilder(r,c,a,b,mat))
						return 1;
					else
						return 0;
					break;
			case 'R':
					 if(R_rock(r,c,a,b,mat))
					 	return 1;
					else
						return 0;
					break;
			case 'B':
					 if(B_bishop(r,c,a,b,mat))
					 	return 1;
					else
						return 0;
					break;
			case 'N':
						if(N_knights(r,c,a,b,mat))
							return 1;
						else
							return 0;
						break;
			case 'Q':
						if(Q_queen(r,c,a,b,mat))
							return 1;
						else 
							return 0;
						break;
		}
		
		//if true then it is check.
	}
	if(islower(mat[r][c])){
		//same but the opposite king.
		for (a=0;a<8; a++)
		{
			for(b=0;b<8;b++){
				if(mat[a][b]=='K')
					break;
			}
		}
		switch(mat[r][c]){
			case 'p':
					if(p_soilder(r,c,a,b,mat))
						return 1;
					else
						return 0;
					break;
			case 'r':
					 if(r_rock(r,c,a,b,mat))
					 	return 1;
					else
						return 0;
					break;
			case 'b':
					 if(b_bishop(r,c,a,b,mat))
					 	return 1;
					else
						return 0;
					break;
			case 'n':
						if(n_knights(r,c,a,b,mat))
							return 1;
						else
							return 0;
						break;
			case 'q':
						if(q_queen(r,c,a,b,mat))
							return 1;
						else 
							return 0;
						break;
		}
	}
}
// The to choose the pwon to be moved.
int choice(mat){
	int r,c;
	printf("Select the position to be move:........");
	scanf("%d %d",&r,&c);
	r=r-1; c=c-1;
}
// The function to take input from the user.
void input(char mat[8][8]){
	char ch;
	int r,c,i,j,check=0,a,b;
	a=r; b=c;
	printf("Select the position to be moved:......");
	scanf("%d %d", &r,&c);
	getchar();
	if((0<r&&r<9)&&(0<c&&c<9)){
		exit;
	}
	r=r-1; c=c-1;// a=r; b=c;
	ch=mat[r][c];
	printf("you have selected %c",mat[r][c]);
	if(isupper(ch)){
		switch(ch){
			case 'P':
				do{
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=P_soilder(r,c,i,j,mat);
						if(check){
								
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							if(check(a,b))
							startGame(mat);
						}
						else
							printf("***************invalid move**********");
					}
					}while(!check);
				break;
			case 'R':
				do{
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=R_rock(r,c,i,j,mat);
						if(check){
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							startGame(mat);
						}
						else
							printf("***************invalid move**********");
					}
				}while(!check);
				break;
			case 'N':
				while(!check){
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=N_knights(r,c,i,j,mat);
						if(check){
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							startGame(mat);
						}
					}
				}		
			case 'B':
				while(!check){
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=B_bishop(r,c,i,j,mat);
						if(check){
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							startGame(mat);
						}
					}
				}
			case 'Q':
				while(!check){
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=Q_queen(r,c,i,j,mat);
						if(check){
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							startGame(mat);
						}
					}
				}
			case 'K':
				while(!check){
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						check=K_king(r,c,i,j,mat);
						if(check){
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							startGame(mat);
						}
					}
				}
		}
	}
	else if(islower(ch)){
		switch(ch){
			case 'p':
				do{
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					i=i-1; j=j-1;
					if((0<i&&i<9)&&(0<j&&j<9)){
						check=p_soilder(r,c,i,j,mat);
						if(check){
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							startGame(mat);
						}
					}
					else	printf("***************invalid move**********");
				}while(!check);
				break;
			case 'r':
				while(!check){
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=r_rock(r,c,i,j,mat);
						if(check){
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							startGame(mat);
						}
					}
				}
			case 'n':
				while(!check){
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=n_knights(r,c,i,j,mat);
						if(check){
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							startGame(mat);
						}
					}
				}		
			case 'b':
				while(!check){
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=b_bishop(r,c,i,j,mat);
						if(check){
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							startGame(mat);
						}
					}
				}
			case 'q':
				while(!check){
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=q_queen(r,c,i,j,mat);
						if(check){
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							startGame(mat);
						}
					}
				}
			case 'k':
				while(!check){
					printf(":.:The position to be moved to :....");
					scanf("%d %d",&i,&j);
					getchar();
					if((0<i&&i<9)&&(0<j&&j<9)){
						i=i-1; j=j-1;
						check=k_king(r,c,i,j,mat);
						if(check){
							mat[i][j]=mat[r][c];
							mat[r][c]=' ';
							startGame(mat);
						}
					}
				}
		}
	}				
}