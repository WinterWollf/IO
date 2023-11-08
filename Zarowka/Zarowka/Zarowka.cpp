#include <ctime>
#include <thread>
#include <chrono>
#include <string>

#include "Zarowka.h"

Zarowka::Zarowka(bool status) : stan_zapalenia(status) {}

void Zarowka::porcedura() {
    while (true) {
        int aktualna_h = aktualna_godzina();
        int aktualna_min = aktualna_minuta();

        if (!czy_zapalona()) {
            if (godzina_zgaszenia >= godzina_zapalenia) {
                if ((aktualna_h > godzina_zapalenia && aktualna_h < godzina_zgaszenia) || (aktualna_h == godzina_zapalenia && aktualna_min >= minuta_zapalenia) || (aktualna_h == godzina_zgaszenia && aktualna_min < minuta_zgaszenia)) {
                    aktualizacja_stanu();
                }
            }
            else {
                if ((aktualna_h + 24 < godzina_zgaszenia + 24) || (aktualna_h + 24 == godzina_zgaszenia + 24 && aktualna_min < minuta_zgaszenia) || (aktualna_h > godzina_zapalenia && aktualna_h >= godzina_zgaszenia)) {
                    aktualizacja_stanu();
                }
                else if (aktualna_h == godzina_zapalenia  && aktualna_min >= minuta_zapalenia) {
                    aktualizacja_stanu();
                }
            }
        }
        else {
            if (godzina_zgaszenia >= godzina_zapalenia) {
                if ((aktualna_h == godzina_zgaszenia && aktualna_min < minuta_zgaszenia) || (aktualna_h == godzina_zapalenia && aktualna_min < minuta_zapalenia) || (aktualna_h > godzina_zgaszenia) || (aktualna_h < godzina_zapalenia)) {
                    aktualizacja_stanu();
                }
            }
            else {
                if ((aktualna_h <= godzina_zapalenia && aktualna_min < minuta_zapalenia && aktualna_h > godzina_zgaszenia) || (aktualna_h < godzina_zapalenia && aktualna_h >= godzina_zgaszenia && aktualna_min > minuta_zgaszenia) || (aktualna_h < godzina_zapalenia && aktualna_h > godzina_zgaszenia)) {
                    aktualizacja_stanu();
                }
            }
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

bool Zarowka::czy_zapalona() {
    if (stan_zapalenia)
        return true;
    else
        return false;
}

int Zarowka::aktualna_godzina() {
    time_t czas;
    struct tm czasInfo;
    char czasString[3];

    time(&czas);

    if (localtime_s(&czasInfo, &czas) != 0) {
        //TODO: Obsuga bdu - "Bd pobierania czasu.";
    }

    if (strftime(czasString, sizeof(czasString), "%H", &czasInfo) == 0) {
        //TODO: Obsuga bdu - Bd formatowania czasu.";
    }

    return std::stoi(czasString);
}

int Zarowka::aktualna_minuta() {
    time_t czas;
    struct tm czasInfo;
    char czasString[3];

    time(&czas);

    if (localtime_s(&czasInfo, &czas) != 0) {
        //TODO: Obsuga bdu - "Bd pobierania czasu.";
    }

    if (strftime(czasString, sizeof(czasString), "%M", &czasInfo) == 0) {
        //TODO: Obsuga bdu - Bd formatowania czasu.";
    }

    return std::stoi(czasString);
}

void Zarowka::aktualizacja_stanu() {
    stan_zapalenia = !stan_zapalenia;
}