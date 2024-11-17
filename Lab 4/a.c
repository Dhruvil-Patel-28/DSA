#include <stdio.h>

int main() {
    int t;
    int e = -1;  // Output -1 if membership can't be bought
    scanf("%d", &t);  // Number of test cases

    for (int i = 0; i < t; i++) {
        int d, x, y;  // D = discount per session, X = membership cost, Y = budget
        int s = 0;  // Number of sessions

        // Read D (discount per session), X (membership cost), and Y (budget)
        scanf("%d %d %d", &d, &x, &y);

        // If Chef's current budget already covers the membership cost
        if (x <= y) {
            printf("%d\n", s);  // No sessions are needed
            continue;
        }

        int xx = x;  // Store original membership cost

        // Maximum number of sessions Chef can afford
        int max_sessions = y;

        // Use a loop to determine the number of sessions required
        while (s <= max_sessions) {
            s++;  // Increment session count (each session costs 1 coin)
            int remaining_budget = y - s;

            // Apply discount based on the number of sessions
            x = (xx * (100 - (d * s))) / 100;

            // Check if the discounted membership cost is now affordable
            if (x <= remaining_budget) {
                printf("%d\n", s);  // Output the number of sessions
                break;
            }
        }

        // If after the loop, Chef still can't afford the membership
        if (s > max_sessions || x > (y - s)) {
            printf("%d\n", e);  // Output -1 if it's impossible to buy the membership
        }
    }

    return 0;
}
