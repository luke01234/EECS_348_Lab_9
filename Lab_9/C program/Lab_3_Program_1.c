#include <stdio.h>
#include <stdlib.h>

void Print_By_Month(FILE *file, float list[])
{
    fputs("MONTH\t\t\tSALES\n", file);
    char months[12][10]={"January  ","February ","March    ","April    ","May      ","June     ","July     ","August   ","September","October  ","November ","December "};
    int i;
    for (int i=0; i<=11;i++)
    {  
        float numb = list[i];
        char strnumb = (char)numb;
        fputs(months[i], file);
        fputs("\t\t",file);
        fprintf(file,"%.2f",numb);
        fputs("\n",file);
    }
    fputs("\n==========================================================\n\n",file);
}
void Sales_Summary(FILE *file, float list[])
{
    char months[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    float min = list[0];
    int minMonth;
    float max = list[0];
    int maxMonth;
    float mean = 0;
    int i = 0;
    fputs("Sales summary: \n\n",file);
    for (int i=0; i<=11;i++)
    {
        if (list[i] >= max)
        {
            max = list[i];
            maxMonth = i;
        }
        if (list [i] <= min)
        {
            min = list[i];
            minMonth = i;
        }
        mean+=list[i];
    }
    mean/=12;
   
    fputs("Minimum sales:\t\t", file);
    fprintf(file,"%.2f",min);
    fputs(" (",file);
    fputs(months[minMonth], file);
    fputs(")",file);
    fputs("\n",file);
    fputs("Maximum sales:\t\t", file);
    fprintf(file,"%.2f",max);
    fputs(" (",file);
    fputs(months[maxMonth], file);
    fputs(")",file);
    fputs("\n",file);
    fputs("Average sales:\t\t", file);
    fprintf(file,"%.2f",mean);
    fputs("\n\n",file);
}

void Six_Month_Summary(FILE *file, float list[])
{
  char months[12][10]={"January  ","February ","March    ","April    ","May      ","June     ","July     ","August   ","September","October  ","November ","December "};
  int i = 0;
  for (int i=0; i<=6;i++)
  {
    int j = 0;
    int finMonth=0;
    fputs(months[i],file);
    fputs("\t-\t",file);
    float mean = 0;
    for (int j=0; j<=5;j++)
    {
      mean += list[j+i];
      if (j>finMonth)
      {
        finMonth=j;
      }
      
    }
    mean/=6;
    fputs(months[i+finMonth],file);
    fputs("\t$",file);
    fprintf(file,"%.2f",mean);
    fputs("\n",file);
  }
  fputs("\n",file);
  fputs("==========================================================\n\n",file);
}

void Highest_To_Lowest(FILE *file, float list[])
{
  fputs("Sales Report (Highest to Lowest):\n\n", file);
  fputs("Month\t\tSales\n\n", file);
  char months[12][10]={"January  ","February ","March    ","April    ","May      ","June     ","July     ","August   ","September","October  ","November ","December "};
  float max = 0;
  for (int i=0; i<=11;i++)
  {
    float max = 0;
    int month;
    for (int j=0; j<=11;j++)
    {
      if (list[j]>=max)
      {
        max=list[j];
        month=j;
      }
    }
    list[month]=0;
    fputs(months[month],file);
    fputs("\t$", file);
    fprintf(file,"%.2f",max);
    fputs("\n",file);
    
  }
}



int main(void)
{
    FILE *inputfile = fopen("inputfile.txt", "r");
    FILE *outputfile = fopen("outputfile.txt", "w");

    if(inputfile == NULL)
    {
        perror("Unable to open file! Please create an input file of name 'infputfile.txt' in this directory.");
        exit(1);
    }

    char chunk[20];
    float vals[12];
    int index = 0;


    while(fgets(chunk, sizeof(chunk), inputfile) != NULL)
    {
        //fputs(chunk, stdout);
        //fputs("|*\n", stdout);  // marker string used to show where the content of the chunk array has ended
        vals[index]=atof(chunk);
        index++;
    }
    float pls = vals[11];
    //printf("val of pls: %.2f\n", pls);
    Print_By_Month(outputfile, vals);
    Sales_Summary(outputfile, vals);
    Six_Month_Summary(outputfile, vals);
    Highest_To_Lowest(outputfile, vals);
    fclose(inputfile);

    printf("Your Output File Has Been Created.");
}