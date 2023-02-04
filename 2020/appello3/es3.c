#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_COST 1000

typedef struct {
    char name[100];
    int cost;
    int value;
    int type;
    int quantity;
} item_t;

int n, c;
item_t items[MAX_ITEMS];
int types_count;
int max_value;

void read_input() {
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d %d", items[i].name, &items[i].cost, &items[i].value, &items[i].type, &items[i].quantity);
        types_count = types_count > items[i].type ? types_count : items[i].type;
    }
}

int count_types(int mask) {
    int count = 0;
    for (int i = 0; i <= types_count; i++) {
        if (mask & (1 << i)) {
            count++;
        }
    }
    return count;
}

void backtrack(int i, int cost, int value, int mask) {
    if (i == n) {
        if (cost <= c && count_types(mask) == n && value > max_value) {
            max_value = value;
        }
        return;
    }
    for (int j = 0; j <= items[i].quantity; j++) {
        int new_cost = cost + j * items[i].cost;
        int new_value = value + j * items[i].value;
        int new_mask = mask | (1 << items[i].type);
        if (new_cost <= c) {
            backtrack(i + 1, new_cost, new_value, new_mask);
        }
    }
}

int main() {
    read_input();
    backtrack(0, 0, 0, 0);
    printf("Max value: %d\n", max_value);
    return 0;
}
