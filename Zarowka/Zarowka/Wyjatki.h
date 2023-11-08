#pragma once
#include <exception>

class KomunikacjaNieudana : public std::exception {
public:
	KomunikacjaNieudana() noexcept = default;
	~KomunikacjaNieudana() = default;
	virtual const char* what() const noexcept {
		return "Komunikacja z kontrolerem nieudana! Przechodzenie w tryb awaryjny!";
	}
};

class BledneDane : public std::exception {
public:
	BledneDane() noexcept = default;
	~BledneDane() = default;
	virtual const char* what() const noexcept {
		return "Odebrano bledne dane! Przechodzenie w tryb awaryjny!";
	}
};

class BledneFormatowanieCzasu : public std::exception {
public:
	BledneFormatowanieCzasu() noexcept = default;
	~BledneFormatowanieCzasu() = default;
	virtual const char* what() const noexcept {
		return "Wystapil blad formatowania czasu! Przechodzenie w tryb awaryjny!";
	}
};

class BladPobieraniaAktualnegoCzasu : public std::exception {
public:
	BladPobieraniaAktualnegoCzasu() noexcept = default;
	~BladPobieraniaAktualnegoCzasu() = default;
	virtual const char* what() const noexcept {
		return "Wystapil blad pobierania aktualnego czasu! Przechodzenie w tryb awaryjny!";
	}
};