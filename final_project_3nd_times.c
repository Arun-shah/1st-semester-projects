#include<stdio.h>
#include<windows.h>
	int i,j,k;
	int sub[10][10],sum[10][10],temp[10][10];
    void input(int input[10][10],int *prow, int *pcol)
    {
   		 for(i = 0; i < *prow; i++)
   			{
  			      for(j = 0; j < *pcol; j++)
   				    {
   				    	printf("\t");
   				         scanf("%d", &input[i][j]);
 				    }
    		}
	}

	void addition(int (*pa)[10], int (*pb)[10], int (*psum)[10],int *prow,int *pcol)
		{
			for(i = 0; i < *prow; i++)
   			{
     		   	for(j = 0; j < *pcol; j++)
     	  		{
            		psum[i][j] = pa[i][j] + pb[i][j];
        		}
    		}		
		}

	void Subtraction(int (*pa)[10], int (*pb)[10],int (*psub)[10],int *prow, int *pcol)
		{
			for(i = 0; i < *prow; i++)
   			{
     		   	for(j = 0; j < *pcol; j++)
     	  		{
            		psub[i][j] = pa[i][j] - pb[i][j];
        		}
    		}		
		}

	void matrixdisplay(int (*ptemp1)[10], int *prow, int *pcol, FILE *fptr)
	{
    	for(i = 0; i < *prow; i++)
   			{
       			for(j = 0; j < *pcol; j++)
      				{
            			printf("\t\t%d\t", ptemp1[i][j]);
            			if (fptr != NULL) 
						{
                			fprintf(fptr, "\t\t%d\t", ptemp1[i][j]);
            			}
       				}
        		printf("\n");
        		if (fptr != NULL)
				{
            		fprintf(fptr, "\n");
        		}
    		}
	}	

	void multiplication (int (*pa)[10],int (*pb)[10],int *prow,int *pcol,int *pcol1)
	{
	// multiplication logic
	    for(i = 0; i < *prow; i++)
		{

	        for(j = 0; j < *pcol1; j++) 
				{
					temp[i][j] = 0;
        		    for(k = 0; k < *pcol; k++) 
					{
    	    	        temp[i][j] += pa[i][k] * pb[k][j];
           			}
        		}
    	}
	}

	void transpose(int (*pa)[10],int *prow,int *pcol)
	{
		// transpose
	    for(i = 0; i < *prow; i++) 
			{
    		    for(j = 0; j < *pcol; j++) 
					{
    			        temp[j][i] = pa[i][j];
    			    }
    		}
	}

	void header()
{
    system("cls");   // Screen clear
    printf("\t*======================================*\n");
    printf("\t||                                     ||\n");
    printf("\t||   MATRIX OPERATION SYSTEM           ||\n");
    printf("\t||                                     ||\n");
    printf("\t*======================================*\n\n");

}

	void color(int c)
	{
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	}

	void showHistory()
{
    FILE *fptr = fopen("matrix.txt", "r");
    char ch;
    if (fptr == NULL)
    {
        printf("\tNo history found!\n");
        return;
    }
    printf("\n\t========================================= MATRIX HISTORY =========================================\n");
    while ((ch = fgetc(fptr)) != EOF)
    {
        printf("%c", ch);
    }
    
    
    fclose(fptr);
}
void check(int *num, char name[])
{
    int ch;
    while (1)
    {
        printf("\n\tEnter %s (1-20): ", name);
        if (scanf("%d", num) != 1)
        {
            printf("\tInvalid input! Please enter a number.\n");
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        if (*num >= 1 && *num <= 20)
        {
            break;
        }
        printf("\t%s must be between 1 and 20.\n", name);
    }
}
int main()
{
	int c,row, col,row1, col1;
   int a[10][10], b[10][10];

	int choice=0;
	
	int *prow;
	int *pcol;
	int *prow1;
	int *pcol1;
	int *pchoice;

	prow=&row;
	pcol=&col;
	prow1=&row1;
	pcol1=&col1;
    pchoice=&choice;
  
    int (*pa)[10]=a;
    int (*pb)[10]=b;
    int (*psum)[10]=sum;
    int (*ptemp)[10]=temp;
    int (*psub)[10]=sub;
	

	start:
	color(2);
	header();
	color(4);
	printf("\t\tMenu\t");
	color(9);
	printf("\n\t1.Addition");
	printf("\n\t2.Subtraction");
	printf("\n\t3.Multiplication");
	printf("\n\t4.Transpose");
	printf("\n\t5.History");
	printf("\n\t6.Exit");
	printf("\n\tEnter Your Choice: ");
	scanf("%d",pchoice);


	FILE *fptr = fopen("matrix.txt", "a+");
    if (fptr == NULL) 
	{
        printf("\tUnable to open file!\n");
        return 1;
    }
	switch (*pchoice)
	{
	case 1:
	{
	color(2);
	header();
	color(7);
    check(prow, "rows");
    check(pcol, "columns");
   	printf("\tEnter elements of Matrix A:\n");
	input(pa,prow,pcol);
    printf("\tEnter elements of Matrix B:\n");
    input(pb,prow,pcol);


    addition(pa,pb,psum,prow,pcol); //fuunction call

    printf("\n\tMatrix A:\n");  //display inputs
    fprintf(fptr, "\n\tMatrix A:\n");
    matrixdisplay(pa,prow,pcol,fptr);
	printf("\n\tMatrix B:\n");
    fprintf(fptr, "\tMatrix B:\n");
    matrixdisplay(pb,prow,pcol,fptr);


    // display result
     printf("\n\tAddition Matrix:\n");

    fprintf(fptr, "\tAddition Matrix:\n");
     matrixdisplay(psum,prow,pcol,fptr);
	fprintf(fptr, "\n\t======================================================================================================\n");

		break ;
		}
	case 2:
	{
		color(2);
		header();
		color(7);
    	check(prow, "rows");
	    check(pcol, "columns");
	    printf("\tEnter elements of Matrix A:\n");
	    input(pa,prow,pcol);
	    printf("\tEnter elements of Matrix B:\n");
	    input(pb,prow,pcol);

		//display inputs
	    Subtraction(pa,pb,psub,prow,pcol);
	    printf("\n\tMatrix A:\n");
	    fprintf(fptr, "\n\tMatrix A:\n");
	    matrixdisplay(pa,prow,pcol,fptr);
		printf("\n\tMatrix B:\n");
	    fprintf(fptr, "\tMatrix B:\n");
	    matrixdisplay(pb,prow,pcol,fptr);

	    // display result
	    printf("\n\tSubtraction Matrix:\n");
	    fprintf(fptr, "\tSubtraction Matrix: \n");
		matrixdisplay(psub,prow,pcol,fptr);
		fprintf(fptr, "\n\t======================================================================================================\n");

		break ;
}

	case 3:
		{
	color(2);
	header();
	color(7);	    
    check(prow, "rows of first matrix");
    check(pcol, "columns of first matrix");  
    check(prow1, "rows of second matrix");
    check(pcol1, "columns of second matrix");

    // Check condition
    if(*pcol != *prow1)
	{
    printf("\tMatrix multiplication not possible!\n");
    fclose(fptr);
    return 0;
	}

    printf("\tEnter elements of first matrix:\n");
    input(pa,prow,pcol);
    printf("\tEnter elements of second matrix:\n");
    input(pb,prow1,pcol1);

   //call
	multiplication(pa,pb, prow, pcol, pcol1);

    // display inputs
    printf("\tmatrix A is\n");
	fprintf(fptr, "\n\tMatrix A:\n");
    matrixdisplay(pa,prow,pcol,fptr);

    printf("\tmatrix B is\n");
	fprintf(fptr, "\tMatrix B:\n");
    matrixdisplay(pb,prow1,pcol1,fptr);

    //display reuslt
    printf("\tMultiplication matrix is \n");
	fprintf(fptr, "\tMultiplication matrix is:\n");
    matrixdisplay(ptemp,prow,pcol1,fptr);
 
	fprintf(fptr, "\n\t======================================================================================================\n");

	break ;

		}

	case 4:
		{
		color(2);
		header();
		color(7);

    
    check(prow, "rows");
    check(pcol, "columns");
    printf("\tEnter elements of matrix:\n");
    input(pa,prow,pcol);
    printf("\n\tOriginal Matrix:\n");
	fprintf(fptr, "\n\tOriginal Matrix:\n");
    matrixdisplay(pa,prow,pcol,fptr);
    transpose(pa, prow, pcol);

    printf("\n\tTranspose Matrix:\n");// display result
	fprintf(fptr, "\tTranspose Matrix:\n");
    matrixdisplay(ptemp,pcol,prow,fptr);
	fprintf(fptr, "\n\t======================================================================================================\n");
	break ;
		}

	case 5:
	{
		color(2);
		header();
		color(7);
		showHistory();
		break;
	}

	case 6:
		{
			break;
		}
	}
      
	fclose(fptr);	
	
if(choice!=6)
	{ 
		
		while (getchar() != '\n');
		printf("\tInvalid choice! \n");
		system("pause");
		goto start;
	}
	

	return 0;

}
