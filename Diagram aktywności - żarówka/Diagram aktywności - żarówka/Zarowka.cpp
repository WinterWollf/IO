#include <ctime>
#include <string>
#include <thread>
#include <chrono>

#include <iostream>

#include "Zarowka.h"

Zarowka::Zarowka(bool status) : stan_zapalenia(status) {}

void Zarowka::porcedura() {
    while (true) {
        if (stan_zapalenia == false) {
            if ((godzina_zapalenia < godzina_zgaszenia && aktualna_godzina() >= godzina_zapalenia)) {
                stan_zapalenia = true;
                std::cout << "ON" << std::endl;
            }
            else {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
        else {
            if ((godzina_zapalenia < godzina_zgaszenia && aktualna_godzina() >= godzina_zgaszenia)) {
                stan_zapalenia = false;
                std::cout << "OFF" << std::endl;
            }
            else {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
    }
}

bool Zarowka::czy_zapalona() const {
	if (stan_zapalenia == true)
		return true;
	else
		return false;
}

int Zarowka::aktualna_godzina() const {
    time_t czas;
    struct tm czasInfo;
    char czasString[3];

    time(&czas);

    if (localtime_s(&czasInfo, &czas) != 0) {
        //TODO: Obs³uga b³êdu - "B³¹d pobierania czasu.";
    }

    if (strftime(czasString, sizeof(czasString), "%H", &czasInfo) == 0) {
        //TODO: Obs³uga b³êdu - B³¹d formatowania czasu.";
    }

    return std::stoi(czasString);
}

int Zarowka::aktualna_minuta() const {
    time_t czas;
    struct tm czasInfo;
    char czasString[3];

    time(&czas);

    if (localtime_s(&czasInfo, &czas) != 0) {
        //TODO: Obs³uga b³êdu - "B³¹d pobierania czasu.";
    }

    if (strftime(czasString, sizeof(czasString), "%M", &czasInfo) == 0) {
        //TODO: Obs³uga b³êdu - B³¹d formatowania czasu.";
    }

    return std::stoi(czasString);
}