#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct vertex_t_ {
    char label;
    int visited;
} vertex_t;

vertex_t *vertex_list[N];

int adj_matrix[N][N];
int vertex_count = 0;
int stack[N];
int top = -1;

int is_stack_full()
{
    return (top == N);
}

int is_stack_empty()
{
    return (top == -1);
}

void push(int item)
{
    if (!is_stack_full()) {
        stack[++top] = item;
    }
}

int pop()
{
    if (!is_stack_empty()) {
        return(stack[top--]);
    }
}

int peek()
{
    if (!is_stack_empty()) {
        return(stack[top]);
    }
}

void add_vertex(char label)
{
    vertex_t *vertex = (vertex_t *)malloc(sizeof(vertex_t));
    if (vertex != NULL) {
        vertex->label = label;
        vertex->visited = 0;
        vertex_list[vertex_count++] = vertex;
    }
}

void add_edge(int start, int end)
{
    if (start < N && end < N) {
        adj_matrix[start][end] = 1;
        adj_matrix[end][start] = 1;
    }
}

void display_vertex(int vertex_index)
{
    if (vertex_index < N) {
        printf("%c ", vertex_list[vertex_index]->label);
    }
}

void display_adj_matrix()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int get_unvisited_vertex_index(int vertex_index)
{
    int i;
    
    for (i = 0; i < vertex_count; i++) {
        if (adj_matrix[vertex_index][i] == 1 && vertex_list[i]->visited == 0) {
            return i;
        }
    }
    return -1;
}

void depth_first_traversal()
{
    vertex_list[0]->visited = 1;
    display_vertex(0);
    push(0);
    
    while (!is_stack_empty()) {
        int unvisited_vid = get_unvisited_vertex_index(peek());
        
        if (unvisited_vid == -1) {
            pop();
        } else {
            vertex_list[unvisited_vid]->visited = 1;
            display_vertex(unvisited_vid);
            push(unvisited_vid);
        }
    }
    
    for (int i = 0; i < vertex_count; i++) {
        vertex_list[i]->visited = 0;
    }   
}

void main()
{
    add_vertex('S');
    add_vertex('A');
    add_vertex('B');
    add_vertex('C');
    add_vertex('D');
    
    add_edge(0, 1);
    add_edge(0, 3);
    add_edge(0, 4);
    add_edge(1, 2);
    add_edge(2, 3);
    add_edge(2, 4);
    
    printf("Adjacency matrix:\n");
    display_adj_matrix();
    
    printf("Depth first traversal:\n");
    depth_first_traversal();
}

Output:
Adjacency matrix:                                                                                                                              
0 1 0 1 1                                                                                                                                      
1 0 1 0 0                                                                                                                                      
0 1 0 1 1                                                                                                                                      
1 0 1 0 0                                                                                                                                      
1 0 1 0 0                                                                                                                                      
Depth first traversal:                                                                                                                         
S A B C D
