#include <array>
    using std::array;

#include "FenseRoster.h"
#include "Enums.h"

#include "Roster.h"

Roster::Roster() {
    this->offensiveRoster = new FenseRoster(FenseType::OFFENSE);
    this->defensiveRoster = new FenseRoster(FenseType::DEFENSE);
}

Roster::Roster(array<int, 20> the_ami) {
    array<int, 10> o_ami;
    array<int, 10> d_ami;
    for(size_t i = 0; i < 10; i++){
        o_ami[i] = the_ami[i];
        d_ami[i] = the_ami[i + 10];
    }
    this->offensiveRoster = new FenseRoster(FenseType::OFFENSE, o_ami);
    this->defensiveRoster = new FenseRoster(FenseType::DEFENSE, d_ami);
}

Roster::Roster(array<int, 10> o_ami, array<int, 10> d_ami) {
    this->offensiveRoster = new FenseRoster(FenseType::OFFENSE, o_ami);
    this->offensiveRoster = new FenseRoster(FenseType::DEFENSE, d_ami);
}

Roster::Roster(FenseRoster* the_offensiveRoster, FenseRoster* the_defensiveRoster, bool first_is_offense) {
    if(first_is_offense) {
        this->offensiveRoster = the_offensiveRoster;
        this->defensiveRoster = the_defensiveRoster;
    } else {
        this->offensiveRoster = the_defensiveRoster;
        this->defensiveRoster = the_offensiveRoster;
    }
}

Roster::~Roster() {
    delete this->offensiveRoster;
    this->offensiveRoster = nullptr;
    delete this->defensiveRoster;
    this->defensiveRoster = nullptr;
}

FenseRoster* Roster::getOffensiveRoster() const {
    return this->offensiveRoster;
}

FenseRoster* Roster::getDefensiveRoster() const {
    return this->defensiveRoster;
}

void Roster::setOffensiveRoster(FenseRoster* the_offensiveRoster) {
    this->offensiveRoster = the_offensiveRoster;
}

void Roster::setDefensiveRoster(FenseRoster* the_defensiveRoster) {
    this->defensiveRoster = the_defensiveRoster;
}

void Roster::draftOffensiveAmi(array<int, 10> o_ami) {
    this->offensiveRoster->draftAmi(o_ami);
}

void Roster::draftDefensiveAmi(array<int, 10> d_ami) {
    this->defensiveRoster->draftAmi(d_ami);
}

void Roster::draftOffensiveYear(int year, array<int, 2> o_slots) {
    this->offensiveRoster->draftYear(year, o_slots);
}

void Roster::draftOffensiveYear(int year, int o_slot1, int o_slot2) {
    this->offensiveRoster->getYear(year)->setAmi(o_slot1, o_slot2);
}

void Roster::draftDefensiveYear(int year, array<int, 2> d_slots) {
    this->defensiveRoster->draftYear(year, d_slots);
}

void Roster::draftDefensiveYear(int year, int d_slot1, int d_slot2) {
    this->defensiveRoster->getYear(year)->setAmi(d_slot1, d_slot2);
}

double Roster::getOffensiveAverage() const {
    return this->offensiveRoster->getAverage();
}

double Roster::getDefensiveAverage() const {
    return this->defensiveRoster->getAverage();
}

double Roster::getOverallAverageFromRosters() const {
    double o_avr = this->getOffensiveAverage();
    double d_avr = this->getDefensiveAverage();
    return (o_avr + d_avr) / 2;
}

double Roster::getOverallAverageFromPlayers() const {
    int player_sum (0);
    for (int o_player : this->offensiveRoster->getAmi()) player_sum += o_player;
    for (int d_player : this->defensiveRoster->getAmi()) player_sum += d_player;
    return player_sum / 20;
}

double Roster::getAverage() const {
    return (this->getOverallAverageFromRosters() + this->getOverallAverageFromPlayers()) / 2;
}