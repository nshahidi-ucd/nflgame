#include <array>
    using std::array;

#include "Enums.h"

#include "RosterSlot.h"

RosterSlot::RosterSlot() {}

RosterSlot::RosterSlot(int the_durationYear) : durationYear{the_durationYear} {}

RosterSlot::RosterSlot(int the_durationYear, FenseType the_fenseType) : durationYear{the_durationYear}, fenseType{the_fenseType} {}

RosterSlot::RosterSlot(int the_durationYear, FenseType the_fenseType, int the_slot1, int the_slot2) : durationYear{the_durationYear}, fenseType{the_fenseType}, slot1{the_slot1}, slot2{the_slot2} {}

int RosterSlot::getSlot1() const {
    return this->slot1;
}

int RosterSlot::getSlot2() const {
    return this->slot2;
}

int RosterSlot::getDurationYear() const {
    return this->durationYear;
}

FenseType RosterSlot::getFenseType() const {
    return this->fenseType;
}

void RosterSlot::setSlot1(int the_slot1){
    this->slot1 = the_slot1;
}

void RosterSlot::setSlot2(int the_slot2){
    this->slot2 = the_slot2;
}

void RosterSlot::setDurationYear(int the_durationYear){
    this->durationYear = the_durationYear;
}

void RosterSlot::setFenseType(FenseType the_fenseType){
    this->fenseType = the_fenseType;
}

array<int, 2> RosterSlot::getAmi() const {
    array<int, 2> ami = {this->slot1, this->slot2};
    return ami;
}

void RosterSlot::setAmi(array<int, 2> the_ami) {
    this->slot1 = the_ami[0];
    this->slot2 = the_ami[1];
}

void RosterSlot::setAmi(int the_slot1, int the_slot2) {
    this->slot1 = the_slot1;
    this->slot2 = the_slot2;
}