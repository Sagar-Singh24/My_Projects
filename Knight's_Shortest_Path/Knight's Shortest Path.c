#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define N 8

// Directions a knight can move
int knightMoves[8][2] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

// Structure to represent a cell in the chessboard
typedef struct {
    int x, y;
    int dist;
} Cell;

// Function to check if a position is within the chessboard
bool isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// Function to find the shortest distance using Dijkstra's algorithm
int knightShortestPath(int startX, int startY, int endX, int endY) {
    // Distance array to store the minimum distance to each cell
    int dist[N][N];
    bool visited[N][N] = {false};

    // Initialize distances to infinity
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dist[i][j] = INT_MAX;

    // Starting position
    dist[startX][startY] = 0;

    // Create a queue to store cells to be processed
    Cell *queue = (Cell *)malloc(N * N * sizeof(Cell));
    int front = 0, rear = 0;

    // Enqueue the starting cell
    queue[rear++] = (Cell){startX, startY, 0};

    while (front < rear) {
        // Dequeue the cell with the minimum distance
        Cell current = queue[front++];
        int x = current.x;
        int y = current.y;

        // If we reached the destination
        if (x == endX && y == endY) {
            free(queue);
            return dist[x][y];
        }

        // Mark the cell as visited
        visited[x][y] = true;

        // Explore all possible knight moves
        for (int i = 0; i < 8; i++) {
            int newX = x + knightMoves[i][0];
            int newY = y + knightMoves[i][1];

            if (isValid(newX, newY) && !visited[newX][newY]) {
                // If the new distance is shorter, update it
                if (dist[x][y] + 1 < dist[newX][newY]) {
                    dist[newX][newY] = dist[x][y] + 1;
                    // Enqueue the new cell
                    queue[rear++] = (Cell){newX, newY, dist[newX][newY]};
                }
            }
        }
    }

    free(queue);
    return -1; // If the end position is not reachable
}

int main() {
    int startX, startY, endX, endY;

    // Prompt user for starting position
    printf("Enter starting position for knight (x y) (0-7 for both): ");
    scanf("%d %d", &startX, &startY);
    
    // Validate starting position
    if (!isValid(startX, startY)) {
        printf("Invalid starting position! Please enter values between 0 and 7.\n");
        return 1;
    }

    // Prompt user for ending position
    printf("Enter ending position for knight (x y) (0-7 for both): ");
    scanf("%d %d", &endX, &endY);
    
    // Validate ending position
    if (!isValid(endX, endY)) {
        printf("Invalid ending position! Please enter values between 0 and 7.\n");
        return 1;
    }

    // Calculate the shortest distance
    int distance = knightShortestPath(startX, startY, endX, endY);
    if (distance != -1) {
        printf("Shortest distance: %d\n", distance);
    } else {
        printf("Destination not reachable!\n");
    }

    return 0;
}