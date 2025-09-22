#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_FLIGHTS 100
#define MAX_GATES 10
#define MAX_PASSENGERS 500

// Structure pour stocker l'heure
typedef struct {
    int hour;
    int minute;
} Time;

// Structure pour une date
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Énumération pour le statut d'un vol
typedef enum {
    SCHEDULED,
    BOARDING,
    DEPARTED,
    DELAYED,
    CANCELLED,
    LANDED
} FlightStatus;

// Structure pour un vol
typedef struct {
    char flight_number[10]; // e.g., "AF123"
    char airline[30];       // e.g., "Air France"
    char destination[50];   // e.g., "CDG - Paris"
    char origin[50];        // e.g., "JFK - New York"
    Time scheduled_time;    // Heure prévue
    Time estimated_time;    // Heure estimée (en cas de retard)
    Date date;              // Date du vol
    char gate[5];           // Porte d'embarquement, e.g., "A12"
    FlightStatus status;    // Statut du vol
    int passenger_count;    // Nombre de passagers
} Flight;

// Structure pour les statistiques de l'aéroport
typedef struct {
    int total_flights_today;
    int flights_departed;
    int flights_arrived;
    int flights_delayed;
    int flights_cancelled;
    int total_passengers;
} AirportStats;

// Prototypes des fonctions
void initializeSystem(Flight flights[], int *flightCount, AirportStats *stats);
void displayMainMenu();
void addNewFlight(Flight flights[], int *flightCount);
void displayAllFlights(Flight flights[], int flightCount);
void updateFlightStatus(Flight flights[], int flightCount);
void displayFlightByNumber(Flight flights[], int flightCount);
void simulateAirportOperations(Flight flights[], int flightCount, AirportStats *stats);
void displayAirportStats(AirportStats stats);
const char* getStatusString(FlightStatus status);
void manageGates(Flight flights[], int flightCount);
void autoUpdateStatus(Flight flights[], int flightCount);

int main() {
    Flight flights[MAX_FLIGHTS];
    int flightCount = 0;
    AirportStats stats = {0};
    int choice;

    initializeSystem(flights, &flightCount, &stats);
    srand(time(0)); // Pour l'aléatoire

    printf("=========================================\n");
    printf("  SYSTEME DE MANAGEMENT D'AEROPORT (SGI)\n");
    printf("=========================================\n");

    do {
        displayMainMenu();
        printf("\nVotre choix: ");
        scanf("%d", &choice);
        getchar(); // Nettoyer le buffer

        switch(choice) {
            case 1:
                addNewFlight(flights, &flightCount);
                break;
            case 2:
                displayAllFlights(flights, flightCount);
                break;
            case 3:
                displayFlightByNumber(flights, flightCount);
                break;
            case 4:
                updateFlightStatus(flights, flightCount);
                break;
            case 5:
                simulateAirportOperations(flights, flightCount, &stats);
                break;
            case 6:
                displayAirportStats(stats);
                break;
            case 7:
                manageGates(flights, flightCount);
                break;
            case 8:
                autoUpdateStatus(flights, flightCount);
                printf("Mise a jour automatique des statuts terminee.\n");
                break;
            case 0:
                printf("Fermeture du systeme. Bonne journee!\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
        printf("\n");
    } while(choice != 0);

    return 0;
}

void initializeSystem(Flight flights[], int *flightCount, AirportStats *stats) {
    // Ajout de quelques vols initiaux pour la démo
    Flight f1 = {"AF345", "Air France", "CDG - Paris", "JFK - New York", {14, 30}, {14, 30}, {20, 5, 2024}, "A12", SCHEDULED, 180};
    Flight f2 = {"BA982", "British Airways", "LHR - London", "DXB - Dubai", {9, 15}, {9, 45}, {20, 5, 2024}, "B07", DELAYED, 215};
    Flight f3 = {"LH909", "Lufthansa", "FRA - Frankfurt", "SIN - Singapore", {16, 0}, {16, 0}, {20, 5, 2024}, "C03", BOARDING, 190};
    Flight f4 = {"DL456", "Delta Air Lines", "ATL - Atlanta", "MAD - Madrid", {11, 20}, {11, 20}, {20, 5, 2024}, "A05", DEPARTED, 160};

    flights[0] = f1;
    flights[1] = f2;
    flights[2] = f3;
    flights[3] = f4;
    *flightCount = 4;

    // Initialisation des stats
    stats->total_flights_today = 12; // Exemple
    stats->flights_departed = 5;
    stats->flights_arrived = 4;
    stats->flights_delayed = 2;
    stats->flights_cancelled = 1;
    stats->total_passengers = 1850;
}

void displayMainMenu() {
    printf("\n--- MENU PRINCIPAL ---\n");
    printf("1. Ajouter un nouveau vol\n");
    printf("2. Afficher tous les vols\n");
    printf("3. Rechercher un vol par numero\n");
    printf("4. Mettre a jour le statut d'un vol\n");
    printf("5. Simuler les operations (Mise a jour auto)\n");
    printf("6. Afficher les statistiques de l'aeroport\n");
    printf("7. Gerer les portes d'embarquement\n");
    printf("8. Mise a jour auto des statuts\n");
    printf("0. Quitter\n");
}

void addNewFlight(Flight flights[], int *flightCount) {
    if(*flightCount >= MAX_FLIGHTS) {
        printf("Capacite maximale de vols atteinte!\n");
        return;
    }

    Flight newFlight;
    printf("\n--- AJOUT D'UN NOUVEAU VOL ---\n");

    printf("Numero de vol (ex: AF123): ");
    scanf("%s", newFlight.flight_number);
    getchar();

    printf("Compagnie aerienne: ");
    fgets(newFlight.airline, 30, stdin);
    newFlight.airline[strcspn(newFlight.airline, "\n")] = 0; // Remove newline

    printf("Origine: ");
    fgets(newFlight.origin, 50, stdin);
    newFlight.origin[strcspn(newFlight.origin, "\n")] = 0;

    printf("Destination: ");
    fgets(newFlight.destination, 50, stdin);
    newFlight.destination[strcspn(newFlight.destination, "\n")] = 0;

    printf("Heure prevue (HH MM): ");
    scanf("%d %d", &newFlight.scheduled_time.hour, &newFlight.scheduled_time.minute);
    newFlight.estimated_time = newFlight.scheduled_time; // Initialement pareil

    printf("Date (JJ MM AAAA): ");
    scanf("%d %d %d", &newFlight.date.day, &newFlight.date.month, &newFlight.date.year);

    printf("Porte d'embarquement: ");
    scanf("%s", newFlight.gate);

    printf("Nombre de passagers: ");
    scanf("%d", &newFlight.passenger_count);

    newFlight.status = SCHEDULED;

    flights[*flightCount] = newFlight;
    (*flightCount)++;

    printf("Vol ajoute avec succes!\n");
}

void displayAllFlights(Flight flights[], int flightCount) {
    if(flightCount == 0) {
        printf("Aucun vol programme.\n");
        return;
    }

    printf("\n--- LISTE DE TOUS LES VOLS (%d) ---\n", flightCount);
    printf("============================================================================================================\n");
    printf("Vol      | Compagnie       | Origine         | Destination      | H.Prevue | H.Estimee | Porte | Statut      | Pax\n");
    printf("============================================================================================================\n");

    for(int i = 0; i < flightCount; i++) {
        printf("%-8s | %-15s | %-15s | %-16s | %02d:%02d    | %02d:%02d     | %-5s | %-11s | %d\n",
               flights[i].flight_number,
               flights[i].airline,
               flights[i].origin,
               flights[i].destination,
               flights[i].scheduled_time.hour, flights[i].scheduled_time.minute,
               flights[i].estimated_time.hour, flights[i].estimated_time.minute,
               flights[i].gate,
               getStatusString(flights[i].status),
               flights[i].passenger_count);
    }
}

const char* getStatusString(FlightStatus status) {
    switch(status) {
        case SCHEDULED: return "Programme";
        case BOARDING: return "Embarquement";
        case DEPARTED: return "Decolle";
        case DELAYED: return "Retarde";
        case CANCELLED: return "Annule";
        case LANDED: return "Atterri";
        default: return "Inconnu";
    }
}

void updateFlightStatus(Flight flights[], int flightCount) {
    char flightNumber[10];
    int newStatus;
    int found = 0;

    printf("Entrez le numero de vol a mettre a jour: ");
    scanf("%s", flightNumber);

    for(int i = 0; i < flightCount; i++) {
        if(strcmp(flights[i].flight_number, flightNumber) == 0) {
            found = 1;
            printf("Vol trouve: %s de %s a %s\n", flights[i].flight_number, flights[i].origin, flights[i].destination);
            printf("Statut actuel: %s\n", getStatusString(flights[i].status));

            printf("\nNouveau statut:\n");
            printf("0 - Programme\n1 - Embarquement\n2 - Decolle\n3 - Retarde\n4 - Annule\n5 - Atterri\n");
            printf("Choix: ");
            scanf("%d", &newStatus);

            if(newStatus >= 0 && newStatus <= 5) {
                flights[i].status = (FlightStatus)newStatus;
                printf("Statut mis a jour avec succes!\n");

                // Si retard, demander la nouvelle heure
                if(newStatus == DELAYED) {
                    printf("Nouvelle heure estimee (HH MM): ");
                    scanf("%d %d", &flights[i].estimated_time.hour, &flights[i].estimated_time.minute);
                }
            } else {
                printf("Statut invalide!\n");
            }
            break;
        }
    }

    if(!found) {
        printf("Vol non trouve!\n");
    }
}

void displayFlightByNumber(Flight flights[], int flightCount) {
    char flightNumber[10];
    int found = 0;

    printf("Entrez le numero de vol: ");
    scanf("%s", flightNumber);

    for(int i = 0; i < flightCount; i++) {
        if(strcmp(flights[i].flight_number, flightNumber) == 0) {
            found = 1;
            printf("\n--- INFORMATIONS DU VOL %s ---\n", flightNumber);
            printf("Compagnie: %s\n", flights[i].airline);
            printf("Origine: %s\n", flights[i].origin);
            printf("Destination: %s\n", flights[i].destination);
            printf("Date: %02d/%02d/%d\n", flights[i].date.day, flights[i].date.month, flights[i].date.year);
            printf("Heure prevue: %02d:%02d\n", flights[i].scheduled_time.hour, flights[i].scheduled_time.minute);
            printf("Heure estimee: %02d:%02d\n", flights[i].estimated_time.hour, flights[i].estimated_time.minute);
            printf("Porte: %s\n", flights[i].gate);
            printf("Statut: %s\n", getStatusString(flights[i].status));
            printf("Passagers: %d\n", flights[i].passenger_count);
            break;
        }
    }

    if(!found) {
        printf("Vol non trouve!\n");
    }
}

void simulateAirportOperations(Flight flights[], int flightCount, AirportStats *stats) {
    printf("\n--- SIMULATION DES OPERATIONS ---\n");
    printf("Mise a jour aleatoire des statuts...\n");

    for(int i = 0; i < flightCount; i++) {
        // Ne pas modifier les vols déjà annulés ou atterris
        if(flights[i].status == CANCELLED || flights[i].status == LANDED) {
            continue;
        }

        int action = rand() % 10; // 0-9

        if(action < 1 && flights[i].status != DEPARTED) { // 10% chance d'annulation
            flights[i].status = CANCELLED;
            printf("-> Vol %s ANNULE\n", flights[i].flight_number);
            stats->flights_cancelled++;

        } else if(action < 3 && flights[i].status == SCHEDULED) { // 20% chance de retard
            flights[i].status = DELAYED;
            // Ajouter un retard de 15 à 120 minutes
            int delay = 15 + (rand() % 106);
            flights[i].estimated_time.minute += delay;
            if(flights[i].estimated_time.minute >= 60) {
                flights[i].estimated_time.hour += flights[i].estimated_time.minute / 60;
                flights[i].estimated_time.minute %= 60;
            }
            printf("-> Vol %s RETARDE de %d min\n", flights[i].flight_number, delay);
            stats->flights_delayed++;

        } else if(action < 5 && flights[i].status == SCHEDULED) { // Passage à l'embarquement
            flights[i].status = BOARDING;
            printf("-> Vol %s en EMBARQUEMENT\n", flights[i].flight_number);

        } else if(action < 7 && flights[i].status == BOARDING) { // Décollage
            flights[i].status = DEPARTED;
            printf("-> Vol %s DECOLLE\n", flights[i].flight_number);
            stats->flights_departed++;
        }
    }
    printf("Simulation terminee.\n");
}

void displayAirportStats(AirportStats stats) {
    printf("\n--- STATISTIQUES DE L'AEROPORT ---\n");
    printf("Vols totaux aujourd'hui: %d\n", stats.total_flights_today);
    printf("Vols decolles: %d\n", stats.flights_departed);
    printf("Vols arrives: %d\n", stats.flights_arrived);
    printf("Vols retardes: %d\n", stats.flights_delayed);
    printf("Vols annules: %d\n", stats.flights_cancelled);
    printf("Total passagers: %d\n", stats.total_passengers);

    // Calculer quelques pourcentages
    if(stats.total_flights_today > 0) {
        float onTimeRate = 100.0 * (stats.total_flights_today - stats.flights_delayed - stats.flights_cancelled) / stats.total_flights_today;
        printf("Taux de ponctualite: %.1f%%\n", onTimeRate);
    }
}

void manageGates(Flight flights[], int flightCount) {
    printf("\n--- ETAT DES PORTES D'EMBARQUEMENT ---\n");

    // Cette fonction est simplifiée. Une vraie implémentation aurait sa propre structure de données pour les portes.
    printf("Porte | Vol       | Statut\n");
    printf("------|-----------|-------------\n");

    for(int i = 0; i < flightCount; i++) {
        printf("%-5s | %-9s | %s\n",
               flights[i].gate,
               flights[i].flight_number,
               getStatusString(flights[i].status));
    }
}

void autoUpdateStatus(Flight flights[], int flightCount) {
    // Simulation basique de l'évolution automatique des statuts dans le temps
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    int current_minute = tm_info->tm_hour * 60 + tm_info->tm_min;

    for(int i = 0; i < flightCount; i++) {
        int scheduled_minute = flights[i].scheduled_time.hour * 60 + flights[i].scheduled_time.minute;

        // Règles simples pour l'évolution automatique
        if(flights[i].status == SCHEDULED && current_minute >= scheduled_minute - 30) {
            flights[i].status = BOARDING;
        } else if(flights[i].status == BOARDING && current_minute >= scheduled_minute + 5) {
            flights[i].status = DEPARTED;
        }
    }
}
