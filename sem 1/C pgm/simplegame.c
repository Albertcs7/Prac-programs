#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ===========================
// STRUCT DEFINITIONS
// ===========================
typedef struct {
    char name[30];
    int hp;
    int attack;
    int defense;
    int healed; // track if fighter has healed already
} Fighter;

typedef struct node {
    Fighter data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

// ===========================
// QUEUE FUNCTIONS
// ===========================
void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, Fighter f) {
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = f;
    newNode->next = NULL;
    if (q->rear == NULL)
        q->front = q->rear = newNode;
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

Fighter dequeue(Queue *q) {
    Node *temp;
    Fighter f;
    f = q->front->data;
    temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return f;
}

// ===========================
// UTILITY FUNCTIONS
// ===========================
Fighter makeFighter(char name[], int hp, int attack, int defense) {
    Fighter f;
    strcpy(f.name, name);
    f.hp = hp;
    f.attack = attack;
    f.defense = defense;
    f.healed = 0;
    return f;
}

void displayFighter(Fighter f) {
    printf("%-10s | HP: %3d | ATK: %2d | DEF: %2d\n", f.name, f.hp, f.attack, f.defense);
}

void displayTeam(Queue q, char teamName[]) {
    Node *temp;
    printf("\n=== %s ===\n", teamName);
    temp = q.front;
    while (temp != NULL) {
        displayFighter(temp->data);
        temp = temp->next;
    }
}

// ===========================
// BATTLE MECHANICS
// ===========================
void playerTurn(Queue *playerTeam, Queue *enemyTeam) {
    Fighter attacker, defender;
    int choice, variance, damage, healAmount;

    if (isEmpty(playerTeam) || isEmpty(enemyTeam))
        return;

    attacker = dequeue(playerTeam);
    defender = dequeue(enemyTeam);

    printf("\n?? Your Turn — %s!\n", attacker.name);
    printf("1. Attack\n2. Defend\n3. Heal\nEnter your choice: ");
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        variance = rand() % 6;
        damage = (attacker.attack + variance) - (defender.defense / 2);
        if (damage < 0) damage = 0;
        defender.hp -= damage;
        printf("\n??  %s attacks %s for %d damage!\n", attacker.name, defender.name, damage);
    } else if (choice == 2) {
        attacker.defense += 5;
        printf("\n???  %s defends and increases defense to %d temporarily!\n", attacker.name, attacker.defense);
    } else if (choice == 3) {
        if (attacker.healed == 0) {
            healAmount = 15 + rand() % 10;
            attacker.hp += healAmount;
            if (attacker.hp > 150) attacker.hp = 150;
            attacker.healed = 1;
            printf("\n??  %s heals for %d HP (Now %d HP)!\n", attacker.name, healAmount, attacker.hp);
        } else {
            printf("\n??  %s already used heal once! Turn wasted.\n", attacker.name);
        }
    } else {
        printf("\n? Invalid choice! Turn skipped.\n");
    }

    // Check if enemy survived
    if (defender.hp > 0) {
        enqueue(enemyTeam, defender);
    } else {
        printf("??  %s is defeated!\n", defender.name);
    }

    // Reset defense if defended
    if (choice == 2) attacker.defense -= 5;

    enqueue(playerTeam, attacker);
}

void enemyTurn(Queue *enemyTeam, Queue *playerTeam) {
    Fighter attacker, defender;
    int action, variance, damage;

    if (isEmpty(enemyTeam) || isEmpty(playerTeam))
        return;

    attacker = dequeue(enemyTeam);
    defender = dequeue(playerTeam);

    action = rand() % 2; // 0 = attack, 1 = defend
    if (action == 0) {
        variance = rand() % 6;
        damage = (attacker.attack + variance) - (defender.defense / 2);
        if (damage < 0) damage = 0;
        defender.hp -= damage;
        printf("\n?? %s attacks %s for %d damage!\n", attacker.name, defender.name, damage);
    } else {
        attacker.defense += 5;
        printf("\n?? %s defends and raises defense temporarily!\n", attacker.name);
    }

    if (defender.hp > 0)
        enqueue(playerTeam, defender);
    else
        printf("??  %s is defeated!\n", defender.name);

    if (action == 1) attacker.defense -= 5;

    enqueue(enemyTeam, attacker);
}

void startBattle(Queue *playerTeam, Queue *enemyTeam) {
    int round;
    round = 1;

    while (!isEmpty(playerTeam) && !isEmpty(enemyTeam)) {
        printf("\n==================== ROUND %d ====================\n", round++);
        playerTurn(playerTeam, enemyTeam);
        if (isEmpty(enemyTeam))
            break;

        enemyTurn(enemyTeam, playerTeam);
        if (isEmpty(playerTeam))
            break;

        printf("\n--------------------------------------------------\n");
        displayTeam(*playerTeam, "Your Team");
        displayTeam(*enemyTeam, "Enemy Team");
        printf("==================================================\n");

        printf("\nPress ENTER to continue...");
        getchar();
    }

    if (isEmpty(playerTeam))
        printf("\n?? You Lost the Battle!\n");
    else
        printf("\n?? You Won the Battle!\n");
}

// ===========================
// MAIN FUNCTION
// ===========================
int main() {
    Queue playerTeam, enemyTeam;
    int numFighters, i;
    Fighter f;
    char *enemyNames[] = {"Orc", "Goblin", "Troll", "Vampire", "Bandit"};
    int enemyCount;
    char *name;
    int hp, atk, def;

    srand(time(NULL));

    initQueue(&playerTeam);
    initQueue(&enemyTeam);

    printf("??  Welcome to the Interactive Battle Simulator ??\n");
    printf("How many fighters in your team (1–3)? ");
    scanf("%d", &numFighters);
    getchar();

    i = 0;
    while (i < numFighters) {
        printf("\nEnter name for Fighter %d: ", i + 1);
        fgets(f.name, sizeof(f.name), stdin);
        f.name[strcspn(f.name, "\n")] = 0;

        printf("Enter HP (60–150): ");
        scanf("%d", &f.hp);
        printf("Enter Attack (15–30): ");
        scanf("%d", &f.attack);
        printf("Enter Defense (5–15): ");
        scanf("%d", &f.defense);
        f.healed = 0;
        getchar();

        enqueue(&playerTeam, f);
        i++;
    }

    enemyCount = numFighters;
    i = 0;
    while (i < enemyCount) {
        name = enemyNames[rand() % 5];
        hp = 70 + rand() % 60;
        atk = 18 + rand() % 10;
        def = 6 + rand() % 8;
        enqueue(&enemyTeam, makeFighter(name, hp, atk, def));
        i++;
    }

    printf("\n? Your Team:");
    displayTeam(playerTeam, "Player Team");

    printf("\n?? Enemy Team Generated:");
    displayTeam(enemyTeam, "Enemy Team");

    printf("\nPress ENTER to begin battle...");
    getchar();

    startBattle(&playerTeam, &enemyTeam);

    printf("\n?? Game Over! Thanks for playing!\n");
    return 0;
}

