#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
string winners[MAX];
int winner_position;

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1; //argc is number of arguments
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)//candidate count already set to number of arguments
    {
        candidates[i].name = argv[i + 1];//populates array from command line arguments
        candidates[i].votes = 0;//sets votes to 0 and keeps it at that for now for each candidate
    }

    int voter_count = get_int("Number of voters: ");//prompts user for number of voters/votes in total

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)//allows users to cast their votes
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
        else
        {
            vote(name);
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes ++;
            return true;
        }
    }
    // TODO
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    winners[0] = candidates[0].name;
    //going through candidates
    for (int i = 1; i < candidate_count; i++)
    {
        //find the highest scorer
        if (candidates[i].votes > candidates[i - 1].votes)
        {
            winners[0] = candidates[i].name;
            winner_position = i;
        }
    }
    int n = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        //check for any ties. just comparing names right now - need to compare scores
        if (candidates[i].votes == candidates[winner_position].votes)
        {
            winners[n] = candidates[i].name;
            n++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", winners[i]);
    }

    // TODO
    return;
}

