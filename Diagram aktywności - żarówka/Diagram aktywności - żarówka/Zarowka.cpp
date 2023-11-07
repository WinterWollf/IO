#include <ctime>
#include <string>
#include <thread>
#include <chrono>

#include <iostream>

#include "Zarowka.h"

#include <fstream>
#include <string>

Zarowka::Zarowka(bool status) : stan_zapalenia(status) {}

void Zarowka::porcedura() {

    std::ofstream plik("test.txt");
    if (plik.is_open()) {
        std::cout << "Plik dziala" << std::endl;
    }
    else {
        std::cout << "Nie mo¿na otworzyæ pliku";
    }

    while (true) {
        if (stan_zapalenia == false) {
            if (aktualna_godzina() == godzina_zapalenia && aktualna_minuta() == minuta_zapalenia) {
                stan_zapalenia = true;
                plik << "ON" << std::endl;
            }
            else {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
        else {
            if (aktualna_godzina() == godzina_zgaszenia && aktualna_minuta() == minuta_zgaszenia) {
                stan_zapalenia = false;
                plik << "OFF" << std::endl;
            }
            else {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
    }
    plik.close();
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