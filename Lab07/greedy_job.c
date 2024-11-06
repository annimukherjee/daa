#include<stdio.h>

// #define n 6
#define n 7

struct Job
{
    int id;
    int deadline;
    int profit;
};


int main()
{
    struct Job jobs[n];


    // First example ---------------
    // jobs[0].id = 1;
    // jobs[0].deadline = 5;
    // jobs[0].profit = 200;

    // jobs[1].id = 2;
    // jobs[1].deadline = 3;
    // jobs[1].profit = 180;

    // jobs[2].id = 3;
    // jobs[2].deadline = 3;
    // jobs[2].profit = 190;

    // jobs[3].id = 4;
    // jobs[3].deadline = 2;
    // jobs[3].profit = 300;

    // jobs[4].id = 5;
    // jobs[4].deadline = 4;
    // jobs[4].profit = 120;

    // jobs[5].id = 6;
    // jobs[5].deadline = 2;
    // jobs[5].profit = 100;

    // ------------------------------------------------------------

    jobs[0].id = 1;
    jobs[0].deadline = 1;
    jobs[0].profit = 3;
    
    jobs[1].id = 2;
    jobs[1].deadline = 3;
    jobs[1].profit = 5;

    jobs[2].id = 3;
    jobs[2].deadline = 4;
    jobs[2].profit = 20;

    jobs[3].id = 4;
    jobs[3].deadline = 3;
    jobs[3].profit = 18;

    jobs[4].id = 5;
    jobs[4].deadline = 2;
    jobs[4].profit = 1;

    jobs[5].id = 6;
    jobs[5].deadline = 1;
    jobs[5].profit = 6;

    jobs[6].id = 7;
    jobs[6].deadline = 2;
    jobs[6].profit = 30;




    struct Job sorted_jobs[n];

    // int profits[n];

    struct Job temp;

    for (int i = 0; i < n-1; i++) {
        
        for (int j = 0; j < n-i-1; j++) {
            
            
            if (jobs[j].profit < jobs[j+1].profit) {


                temp.deadline = jobs[j].deadline;
                temp.profit = jobs[j].profit;
                temp.id = jobs[j].id;

                jobs[j] = jobs[j+1];
                jobs[j+1] = temp;
                
            }

        }
    }
    

    // sorted_jobs[0] = jobs[3];
    // sorted_jobs[1] = jobs[0];
    // sorted_jobs[2] = jobs[2];
    // sorted_jobs[3] = jobs[1];
    // sorted_jobs[4] = jobs[4];
    // sorted_jobs[5] = jobs[5];

    printf("The sorted jobs are: \n");
    for (int i = 0; i < n; i++)
    {
        printf("\nID: %d\n", jobs[i].id);
        printf("Profit: %d\n", jobs[i].profit);
        printf("Deadline: %d\n", jobs[i].deadline);
    }
    printf("\n---------\n");
    

    

    int profit_total = 0;
    int count = 0;
    int dmax = 0;

    for (int i = 0; i < n; i++)
    {
        if (jobs[i].deadline > dmax)
        {
            dmax = jobs[i].deadline;
        }
        
    }

    printf("The max deadline is: %d\n", dmax);

    int slot[dmax];

    for (int i = 0; i < dmax; i++)
    {
        slot[i] = -1;
    }

    printf("Initially all the slots are:\n");
    
    for (int i = 0; i < dmax; i++)
    {
        printf("%d ", slot[i]);
    }
    printf("\n------------\n\n");


    for (int i = 0; i < n; i++)
    {
        printf("\n==========\nChecking job %d\n=========\n", i);
        for (int r = jobs[i].deadline - 1; r >= 0; r--)
        {
            if (slot[r] == -1)
            {
                printf("\nFound slot=-1 at r = %d\nSo JID %d with deadline %d, in slot[%d]\n", r,jobs[i].id, jobs[i].deadline, r);
                slot[r] = jobs[i].id;
                profit_total += jobs[i].profit;
                count+=1;
                break;
            }
            
        }

        if(count==dmax)
            break;
        
    }

    printf("\nFinal Sequence\n");

    for (int i = 0; i < dmax; i++)
    {
        printf("%d ", slot[i]);
    }

    printf("\nFinal Profit: %d-", profit_total);

    printf("\n");

}

