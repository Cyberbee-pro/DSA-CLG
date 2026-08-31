#include<stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct data{
	char ID[15] ;
	char Name[40];
	int age;
	int marks[5];
	int total;
	float per;
	char Grade[3];
}data;




int main(){
	int Highest_total = 0;
  int N,i;
	data *Highest = calloc(1,sizeof(data));
  printf("\nEnter number of students : ");
	scanf("%d",&N);
	data *students =calloc(N,sizeof(data));

	for(i=0;i<N;i++){
	
	printf("\nEnter ID for student %d: ",(i+1));
	scanf(" %s",students[i].ID);
	printf("\nEnter Name for student %d: ",(i+1));
	scanf(" %39[^\n]",students[i].Name);
	printf("\nEnter age for %s: ",students[i].Name);
	scanf(" %d",&students[i].age);
	
		for(int j =0;j<5;j++){
			printf("\nEnter marks for subject %d: ",j+1);
			scanf(" %d",&students[i].marks[j]);
			students[i].total += students[i].marks[j];
		}
	
	students[i].per = students[i].total/5.0f;

	if(students[i].per > 90 && students[i].per <= 100){
            strcpy(students[i].Grade,"A+");
    }else if(students[i].per > 80 && students[i].per < 89){ 
            strcpy(students[i].Grade,"A");
    }else if( students[i].per > 70 && students[i].per < 79){
            strcpy(students[i].Grade,"B");
    }else if(students[i].per > 60 && students[i].per < 69){ 
            strcpy(students[i].Grade,"C");
    }else if(students[i].per > 50 && students[i].per < 59){
            strcpy(students[i].Grade,"D");
    }else if(students[i].per > 0 && students[i].per < 50){ 
            strcpy(students[i].Grade,"F");
    }else{
            printf("INVALID range\n");
            break;
    }
	
	if(students[i].total>=Highest_total){
		Highest_total = students[i].total;
	  *Highest = students[i];
  }


	}





  printf("\n=============TOPPER===================");	
	printf("\nID   : %s ",Highest->ID);
	printf("\nName : %s ",Highest->Name);
	printf("\nAge  : %d",Highest->age);
	
	for(int j =0;j<5;j++){
		printf("\n Marks for subject %d : %d ",j+1,Highest->marks[j]);
  }

	printf("\n Grade : %s",Highest->Grade);
  printf("\nTotal               : %d ",Highest->total);
	
  printf("\n======================================");	
	for(i=0;i<N;i++){
  printf("\n======================================");	
	printf("\nID   : %s ",students[i].ID);
	printf("\nName : %s ",students[i].Name);
	printf("\nAge  : %d",students[i].age);
	
	for(int j =0;j<5;j++){
		printf("\n Marks for subject %d : %d ",j+1,students[i].marks[j]);
  }
	
	printf("\nGrade : %s",students[i].Grade);
  printf("\nTotal               : %d ",students[i].total);
  printf("\n======================================");	
  }


free(students);
free(Highest);
return 0;
}
