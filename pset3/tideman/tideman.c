#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
// Max number of candidates
#define MAX 9


// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];


// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];


// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;


// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];


int pair_count;
int candidate_count;


// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool iscycle(int winner, int loser);
void print_winner(void);


int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }


    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }


    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }


    pair_count = 0;
    int voter_count = get_int("Number of voters: ");


    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];


        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);


            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }


        record_preferences(ranks);


        printf("\n");
    }


    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}


// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
     int cmp;
    for(int i = 0; i < candidate_count; i++)
    {
        cmp = strcmp(candidates[i],name);
        if(cmp == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}






// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for(int i = 0; i < (candidate_count - 1); i++)
    {
        for(int j = i; j <candidate_count; j ++)
        if(i == j)
        {
            preferences[i][j] = 0;
        }
        else
        {
        preferences[ranks[i]][ranks[(j)]]++;
        }
    }
    return;
}


// Record pairs of candidates where one is preferred over the other
    void add_pairs(void)
{
    int cont=0;
    for(int i = 0; i < (candidate_count-1); i++)
    {
        for(int j = i+1; j < candidate_count;j++)
        {
            if(preferences[i][j] > preferences[j][i])
            {
            pair_count++;
            pairs[cont].winner = i;
            pairs[cont].loser = j;
            cont++;
            }
            else if(preferences[j][i] > preferences[i][j])
            {
            pair_count++;
            pairs[cont].winner = j;
            pairs[cont].loser = i;
            cont++;
            }
        }
    }
}


// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int aux1, aux2, cont;
    for(int i = 0; i < pair_count; i++)
    {
        cont = 0;
        for(int j = 0 ; j < pair_count - i - 1 ; j++)
        {
            if((preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner]) < (preferences[pairs[j+1].winner][pairs[j+1].loser] - preferences[pairs[j+1].loser][pairs[j+1].winner]))
            {
                cont++;
                aux1 = pairs[j+1].winner;
                aux2 = pairs[j+1].loser;
                pairs[j+1].winner = pairs[j].winner;
                pairs[j+1].loser = pairs[j].loser;
                pairs[j].winner = aux1;
                pairs[j].loser = aux2;
            }
        }
        if(cont = 0)
        {
            return;
        }
    }

    return;
}




// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    int winner, loser;
    for(int i = 0; i < pair_count; i++)
    {
        winner = pairs[i].winner;
        loser = pairs[i].loser;
        if(!iscycle(winner,loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }

    }
    return;
}



// Print the winner of the election
void print_winner(void)
{


    int c, winner;
    for(int j = 0; j < candidate_count;j++)
    {
        c = 0;
        for(int i = 0; i < candidate_count; i++)
        {
            if(locked[i][j])
            {
                c++;
                break;
            }
        }
        if(c == 0)
        {
            printf("%s\n",candidates[j]);
            return;
        }
    }
    return;
}

bool iscycle(int winner, int loser)
{
    if(winner == loser)
    {
        return true;
    }
    for(int i = 0; i < candidate_count;i++)
    {
        if(locked[loser][i])
        {
            if(iscycle(winner,i))
                {
                    return true;
                }
        }
    }
    return false;
}


