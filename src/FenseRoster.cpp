#include <array>
    using std::array;

#include "RosterSlot.h"
#include "FenseRoster.h"
#include "Enums.h"

FenseRoster::FenseRoster() {
    this->y1 = nullptr;
    this->y2 = nullptr;
    this->y3 = nullptr;
    this->y4 = nullptr;
    this->y5 = nullptr;
}

FenseRoster::FenseRoster(FenseType the_fenseType) : fenseType {the_fenseType} {
    this->y1 = new RosterSlot(1, the_fenseType);
    this->y2 = new RosterSlot(2, the_fenseType);
    this->y3 = new RosterSlot(3, the_fenseType);
    this->y4 = new RosterSlot(4, the_fenseType);
    this->y5 = new RosterSlot(5, the_fenseType);
}

FenseRoster::FenseRoster(FenseType the_fenseType, array<int, 10> the_ami) : fenseType {the_fenseType} {
    this->y1 = new RosterSlot(1, the_fenseType, the_ami[0], the_ami[1]);
    this->y2 = new RosterSlot(2, the_fenseType, the_ami[2], the_ami[3]);
    this->y3 = new RosterSlot(3, the_fenseType, the_ami[4], the_ami[5]);
    this->y4 = new RosterSlot(4, the_fenseType, the_ami[6], the_ami[7]);
    this->y5 = new RosterSlot(5, the_fenseType, the_ami[8], the_ami[9]);
}

FenseRoster::~FenseRoster() {
    delete this->y1;
    this->y1 = nullptr;
    delete this->y2;
    this->y2 = nullptr;
    delete this->y3;
    this->y3 = nullptr;
    delete this->y4;
    this->y4 = nullptr;
    delete this->y5;
    this->y5 = nullptr;
}

RosterSlot* FenseRoster::getY1() const {
    return this->y1;
}

RosterSlot* FenseRoster::getY2() const {
    return this->y2;
}

RosterSlot* FenseRoster::getY3() const {
    return this->y3;
}

RosterSlot* FenseRoster::getY4() const {
    return this->y4;
}

RosterSlot* FenseRoster::getY5() const {
    return this->y5;
}

FenseType FenseRoster::getFenseType() const {
    return this->fenseType;
}

void FenseRoster::setY1(RosterSlot* the_y1) {
    this->y1 = y1;
}

void FenseRoster::setY2(RosterSlot* the_y2) {
    this->y2 = y2;
}

void FenseRoster::setY3(RosterSlot* the_y3) {
    this->y3 = y3;
}

void FenseRoster::setY4(RosterSlot* the_y4) {
    this->y4 = y4;
}

void FenseRoster::setY5(RosterSlot* the_y5) {
    this->y5 = y5;
}

void FenseRoster::setFenseType(FenseType the_fenseType) {
    this->fenseType = the_fenseType;
}

RosterSlot* FenseRoster::getYear(int year) const {
    switch (year) {
        case 1: return this->y1;
        case 2: return this->y2;
        case 3: return this->y3;
        case 4: return this->y4;
        case 5: return this->y5;
        default: return nullptr;
    }
}

array<int, 10> FenseRoster::getAmi() const{
    array<int, 10> ami;
    for(int year = 0; year < 5; ++year) {
        RosterSlot* the_slot = this->getYear(year + 1);
        ami[year * 2] = the_slot->getSlot1();
        ami[year * 2 + 1] = the_slot->getSlot2();
    }
    return ami;
}

void FenseRoster::draftYear(int year, array<int, 2> the_ami) {
    RosterSlot* the_slot = this->getYear(year);
    if(the_slot != nullptr) the_slot->setAmi(the_ami);
}

void FenseRoster::draftAmi(array<int, 10> the_ami) {
    for(int year = 0; year < 5; ++year) {
        RosterSlot* the_slot = this->getYear(year + 1);
        the_slot->setAmi(the_ami[year * 2], the_ami[year * 2 + 1]);
    }
}

double FenseRoster::getAverage() const {
    int player_sum (0);
    array<int, 10> the_ami = this->getAmi();
    for(int player : the_ami) player_sum += player;
    return player_sum / 10;
}