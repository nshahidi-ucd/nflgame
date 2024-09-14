#ifndef FENSEROSTER_H
#define FENSEROSTER_H

#include <array>
    using std::array;

#include "RosterSlot.h"

class FenseRoster {
    private:
        RosterSlot* y1;
        RosterSlot* y2;
        RosterSlot* y3;
        RosterSlot* y4;
        RosterSlot* y5;
        FenseType fenseType;
    public:
        FenseRoster();
        explicit FenseRoster(FenseType the_fenseType);
        FenseRoster(FenseType the_fenseType, array<int, 10> the_ami);
        ~FenseRoster();
        RosterSlot* getY1() const;
        RosterSlot* getY2() const;
        RosterSlot* getY3() const;
        RosterSlot* getY4() const;
        RosterSlot* getY5() const;
        FenseType getFenseType() const;
        void setY1(RosterSlot* the_y1);
        void setY2(RosterSlot* the_y2);
        void setY3(RosterSlot* the_y3);
        void setY4(RosterSlot* the_y4);
        void setY5(RosterSlot* the_y5);
        void setFenseType(FenseType the_fenseType);
        RosterSlot* getYear(int year) const;
        array<int, 10> getAmi() const;
        void draftYear(int year, array<int, 2> the_ami);
        void draftAmi(array<int, 10> the_ami);
        double getAverage() const;
};

#endif