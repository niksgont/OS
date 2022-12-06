#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
#define m 3 // Number of resource classes
#define n 5 // Number of processes

typedef struct process_struct
{
    int id, terminated, C[m], R[m];
} process_entry;

int E[m], A[m];
process_entry process[n];
void read_input_file(char *filename)
{
    FILE *inp_file;
    inp_file = fopen(filename, "r");

    if (inp_file == NULL)
    {
        printf("Error to open the file\n");
        return;
    }

    for (int i = 0; i < m; i++)
        fscanf(inp_file, "%d", &E[i]);
    for (int i = 0; i < m; i++)
        fscanf(inp_file, "%d", &A[i]);

    for (int PID = 0; PID < n; PID++)
    {
        process[PID].id = PID;
        process[PID].terminated = FALSE;
        for (int i = 0; i < m; i++)
        {
            fscanf(inp_file, "%d", &process[PID].C[i]);
        }
    }
    for (int PID = 0; PID < n; PID++)
        for (int i = 0; i < m; i++)
            fscanf(inp_file, "%d", &process[PID].R[i]);
}

void print_state(int verdict, int counter)
{
    if (verdict == TRUE)
        printf("\nVERDICT (STATE [%d]):\n", counter);
    else
        printf("\nSTATE [%d]:\n", counter);

    printf("Existing recource vector: (");
    for (int i = 0; i < m; i++)
    {
        printf("%d", E[i]);

        if (i + 1 == m)
            printf(")\n");
        else
            printf(", ");
    }

    printf("Available recource vector: (");
    for (int i = 0; i < m; i++)
    {
        printf("%d", A[i]);

        if (i + 1 == m)
            printf(")\n");
        else
            printf(", ");
    }

    for (int PID = 0; PID < n; PID++)
    {
        printf("Process %d ", process[PID].id);

        if (verdict == TRUE)
        {
            if (process[PID].terminated == FALSE)
                printf("- deadlocked.\n");
            else
                printf("- terminated.\n");
        }
        else
        {
            if (process[PID].terminated == FALSE)
            {
                printf("- not finished. Requires (");
                for (int i = 0; i < m; i++)
                {
                    printf("%d", process[PID].R[i]);

                    if (i + 1 == m)
                        printf(") requests more.\n");
                    else
                        printf(", ");
                }
            }
            else
                printf("- terminated.\n");
        }
    }
}
int find_suitable_process()
{
    for (int PID = 0; PID < n; PID++)
    {
        if (process[PID].terminated == TRUE)
            continue;

        for (int i = 0; i < m; i++)
        {
        
            if (process[PID].R[i] > A[i])
                break;

            if (i + 1 == m)
                return PID;
        }
    }
    return -1;
}
void release_resources(int PID)
{
    for (int i = 0; i < m; i++)
    {
        A[i] += process[PID].C[i];
        process[PID].C[i] = 0;
        process[PID].R[i] = 0;
        process[PID].terminated = TRUE;
    }
}
int main()
{
    read_input_file("input.txt");
    int state_counter = 0;
    while (TRUE)
    {
        print_state(FALSE, state_counter);
        state_counter++;
        int current_candidate = find_suitable_process();
        if (current_candidate == -1)
            break;
        printf("\nCurrent candidate's PID: %d\n", current_candidate);

        release_resources(current_candidate);
    }
    print_state(TRUE, state_counter);
    return 0;
}
