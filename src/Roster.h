#ifndef ROSTER_H
#define ROSTER_H

#include <array>
    using std::array;

#include "FenseRoster.h"

class Roster {
    private:
        FenseRoster* offensiveRoster;
        FenseRoster* defensiveRoster;
    public:
        Roster();
        explicit Roster(array<int, 20> the_ami);
        Roster(array<int, 10> o_ami, array<int, 10> d_ami);
        Roster(FenseRoster* the_offensiveRoster, FenseRoster* the_defensiveRoster, bool first_is_offense);
        ~Roster();
        FenseRoster* getOffensiveRoster() const;
        FenseRoster* getDefensiveRoster() const;
        void setOffensiveRoster(FenseRoster* the_offensiveRoster);
        void setDefensiveRoster(FenseRoster* the_defensiveRoster);
        void draftOffensiveAmi(array<int, 10> o_ami);
        void draftDefensiveAmi(array<int, 10> d_ami);
        void draftOffensiveYear(int year, array<int, 2> o_slots);
        void draftOffensiveYear(int year, int o_slot1, int o_slot2);
        void draftDefensiveYear(int year, array<int, 2> d_slots);
        void draftDefensiveYear(int year, int d_slot1, int d_slot2);
        double getOffensiveAverage() const;
        double getDefensiveAverage() const;
        double getOverallAverageFromRosters() const;
        double getOverallAverageFromPlayers() const;
        double getAverage() const;
};

#endif