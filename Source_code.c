#include <LiquidCrystal.h>

// Initialize LCD
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

// Define contestant buttons
const int pushbuttons[] = {2, 3, 4, 5};
const int players = 4;

// Game variables
int points[4] = {0, 0, 0, 0};
int fastestfinger[4] = {-1, -1, -1, -1};
int curr_player = 0;
int total_round = 0;

void setup() {
    lcd.begin(16, 2);
    delay(1000);

    for (int i = 0; i < players; i++) {
        pinMode(pushbuttons[i], INPUT_PULLUP);
    }
}

void loop() {
    if (total_round < 5) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Fastest Finger");
        lcd.setCursor(0, 1);
        lcd.print("Round " + String(total_round + 1));

        // Detect fastest finger
        detectFastestFinger();

        // Award point
        awardPoint();

        total_round++;
        resetGame();
    } else {
        declareWinner();
    }
}

// Detect button press order
void detectFastestFinger() {
    int sum = 0;
    curr_player = 0;
    while (1) {
        delay(1);
        if (digitalRead(curr_player + 2) == LOW && fastestfinger[curr_player] == -1) {
            fastestfinger[curr_player] = millis();
            sum++;
        }
        if (sum == 4) break;
        curr_player = (curr_player + 1) % 4;
    }
    print_order();
}

// Award points to correct player
void awardPoint() {
    int sum = 0;
    curr_player = 0;
    lcd.setCursor(0, 0);
    lcd.print("Increment: ");
    while (1) {
        delay(1);
        if (digitalRead(curr_player + 2) == LOW) {
            points[curr_player] += 1;
            sum++;
        }
        if (sum == 1) break;
        curr_player = (curr_player + 1) % 4;
    }
}

// Print order of players
void print_order() {
    int sorted_order[4][2];
    for (int i = 0; i < 4; i++) {
        sorted_order[i][0] = i + 1;
        sorted_order[i][1] = fastestfinger[i];
    }
    for (int i = 0; i < players - 1; i++) {
        for (int j = i + 1; j < players; j++) {
            if (sorted_order[i][1] > sorted_order[j][1]) {
                int temp0 = sorted_order[i][0], temp1 = sorted_order[i][1];
                sorted_order[i][0] = sorted_order[j][0];
                sorted_order[i][1] = sorted_order[j][1];
                sorted_order[j][0] = temp0;
                sorted_order[j][1] = temp1;
            }
        }
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Winner list: ");
    lcd.setCursor(0, 1);
    for (int i = 0; i < 4; i++) {
        lcd.print(String(sorted_order[i][0]) + String(" "));
    }
}

// Reset game for next round
void resetGame() {
    for (int i = 0; i < players; i++) {
        fastestfinger[i] = -1;
    }
    lcd.clear();
}

// Declare final winner
void declareWinner() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Game Over! Scores:");
    lcd.setCursor(0, 1);
    for (int i = 0; i < 4; i++) {
        lcd.print(String(i + 1) + ":" + String(points[i]) + " ");
    }
    delay(3000);

    int maxi = 0, maxp = points[0];
    for (int i = 1; i < players; i++) {
        if (maxp < points[i]) {
            maxi = i;
            maxp = points[i];
        }
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(String("Winner!!! ") + String(maxi + 1));
    lcd.setCursor(0, 1);
    lcd.print(String("Points: ") + String(maxp));

    delay(5000);
    for (int i = 0; i < players; i++) {
        points[i] = 0;
    }
    total_round = 0;
}
