#ifndef ROSTERSLOT_H
#define ROSTERSLOT_H

#include <array>
    using std::array;

#include "Enums.h"

class RosterSlot {
    private:
        int slot1 {0};
        int slot2 {0};
        int durationYear;
        FenseType fenseType;
    public:
        RosterSlot();
        explicit RosterSlot(int the_durationYear);
        RosterSlot(int the_durationYear, FenseType the_fenseType);
        RosterSlot(int the_durationYear, FenseType the_fenseType, int the_slot1, int the_slot2);
        ~RosterSlot() = default;
        int getSlot1() const;
        int getSlot2() const;
        int getDurationYear() const;
        FenseType getFenseType() const;
        void setSlot1(int the_slot1);
        void setSlot2(int the_slot2);
        void setDurationYear(int the_durationYear);
        void setFenseType(FenseType the_fenseType);
        array<int, 2> getAmi() const;
        void setAmi(array<int, 2> the_ami);
        void setAmi(int the_slot1, int the_slot2);
};

#endif