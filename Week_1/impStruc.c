#include<stdio.h>


typedef struct data{
	char ID[15] = {0};
	char Name[40];
	int age;
	int marks[5] = {0};
	int total = 0;
	float per = 0;
	char Grade[];
}data;


int Highest_total = 0;


int main(){
	int N,i;
	printf("\nEnter number of students : ");
	scanf("%d",&N);
	data students[N];

	for(i=0;i<N;i++){
	
	printf("\nEnter ID for student %d: ",(i+1));
	scanf(" %s",&students[i].ID);
	printf("\nEnter Name for student %d: ",(i+1));
	scanf(" %s",&students[i].Name);
	printf("\nEnter age for %s: ",students[i].Name);
	scanf(" %d",&students[i].age);
	
		for(int j =0;j<5;j++){
			printf("\nEnter marks for subject %d: ",j+1);
			scanf(" %d",&students[i].marks[j]);
			students[i].total += students[i].marks[j];
		}
	
	students[i].per = students[i].total/5;

	switch (students[i].per) {
        case 90 ... 100:
            students[i].Grade = "A+";
            break;
        case 80 ... 89: 
            students[i].Grade = "A";
            break; 
        case 70 ... 79:
            students[i].Grade = "B";
            break;
        case 60 ... 69: 
            students[i].Grade = "C";
            break;
        case 50 ... 59:
            students[i].Grade = "D";
            break;
        case 0 ... 50: 
            students[i].Grade = "F";
            break;
	default:
            printf("INVALID range\n");
            break;
        }
	
	if(Total<=Highest_total){
		Highest_total = total;
	}


	}






	for(i=0;i<N;i++){
	
	printf("\nID : %s ",students[i].ID);
	printf("\nName : %s ",students[i].Name);
	printf("\nAge : %d",students[i].age);
	
	for(int j =0;j<5;j++){
		printf("\n Marks for subject %d : %d ",j+1,students[i].marks[j]);
		printf("Total : %d ",students[i].total);
		}
	
	printf("%s",students[i].Grade);
        }
	}









return 0;
}
