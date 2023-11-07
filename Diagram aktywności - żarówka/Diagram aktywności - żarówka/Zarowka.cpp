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

    std::ofstream plik("test.txt", std::ios_base::app);
    if (plik.is_open()) {
        std::cout << "Plik dziala" << std::endl;
    }
    else {
        std::cout << "Nie mo¿na otworzyæ pliku";
    }

    while (true) {
        if (czy_zapalona() == false) {
            if (godzina_zgaszenia >= godzina_zapalenia) {
                if (
                    (aktualna_godzina() > godzina_zapalenia && aktualna_godzina() < godzina_zgaszenia)
                    || 
                    (aktualna_godzina() == godzina_zapalenia && aktualna_minuta() >= minuta_zapalenia)
                    ||
                    (aktualna_godzina() == godzina_zgaszenia && aktualna_minuta() < minuta_zgaszenia)
                   ) {
                    //plik << "ON";
                    std::cout << "ON" << std::endl;
                    aktualizacja_stanu();
                }
            }
            else {
                if (aktualna_godzina() + 24 <= godzina_zgaszenia + 24 && aktualna_minuta() < minuta_zgaszenia) {
                    //plik << "ON";
                    std::cout << "ON" << std::endl;
                    aktualizacja_stanu();
                }
                else if (aktualna_godzina() > godzina_zapalenia ) {
                    //plik << "ON";
                    std::cout << "ON" << std::endl;
                    aktualizacja_stanu();
                }
            }
        }
        else {
            std::cout << "Nie" << std::endl;
        }
        //std::this_thread::sleep_for(std::chrono::milliseconds(1));
        //plik.flush();
        std::cout << "Obrot petli" << std::endl;
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

void Zarowka::aktualizacja_stanu() {
    stan_zapalenia = !stan_zapalenia;
}
