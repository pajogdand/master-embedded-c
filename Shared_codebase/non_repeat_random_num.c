/**************************************************************************************************
 * Program to Generate Non reapeted random number upto given limit                                *
 * 1. create an api to return non-repeative random number                                         *
 * 2. every call to api should return unique random number till limit                             *
 * 3. after number call to api exceeds given limit, then api allowed return the previously sent   *
 *    random numbers                                                                              *
 *                                                                                                *
 * Notes: 1. Used of rand() and srand(), to randomise the data                                    *
 *        2. (limit+1) used for accomodate enough space hold generated data. for example          *
 *           say limit is 10, then random number can be any from 0 to 10 (i.e. total 11)          *
 *                                                                                                *
 * Author: Kishor H. Bhoite date: 25th June 2019                                                  *
 **************************************************************************************************/
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

enum Flag {Reset=0, Set};

struct Data
{
    int limit;
    int *rand_arr;
};
struct Data nData={0};

// Randomize the gen data
void randomize_data()
{
    srand(time(NULL));
    for(int i=0; i<(nData.limit+1); i++)
    {
        int rand_idx=rand()%(nData.limit+1);
        if(rand_idx != i)
        {
            int temp = nData.rand_arr[i];
            nData.rand_arr[i] = nData.rand_arr[rand_idx];
            nData.rand_arr[rand_idx] = temp;
        }
    }
}

// print random data, debug
void print_data()
{
    for(int i=0; i<(nData.limit+1); i++)
    {
        printf("%d ", nData.rand_arr[i]);
    }
    printf("\n");
}

// cleanup the data
void free_data()
{
    free(nData.rand_arr);
    nData.rand_arr=NULL;
}

// generate data
void gen_data(int limit)
{
    enum Flag rflag;
    if (nData.limit != 0 && nData.limit != limit)
    {
        nData.limit = limit;
        nData.rand_arr= (int *) realloc(nData.rand_arr, (nData.limit+1)*sizeof(int));
        if(nData.rand_arr)
        {
            rflag=Set;
        }
    }
    else
    {
        nData.limit = limit;
        nData.rand_arr= (int *) calloc((nData.limit+1), sizeof(int));
        if(nData.rand_arr)
        {
            rflag=Set;
        }
    }
    if(rflag)
    {
        for( int i=0; i < (nData.limit+1); i++)
        {
            nData.rand_arr[i]=i;
        }
    }
}

int get_rand_num(int limit)
{
    static int count = 0;
    int num = 0;

    if (nData.limit != limit)
    {
        gen_data(limit);
        randomize_data();
    }

    if (count >= (limit+1))
    {
        count = 0;
        randomize_data();
    }
    if(nData.rand_arr != NULL)
    {
        num = nData.rand_arr[count];
    }
    count++;
    return num;
}

// Driver code
int main()
{
    int num;
    printf("Please enter the Number Limit\n");
    scanf("%d", &num);

    // Test code to verify all conditions
    for (int i=0; i < ((num+1)*3); i++)
    {
        printf("%d Random Num: %d\n",(i+1), get_rand_num(num));
    }
    free_data();

    return 0;
}