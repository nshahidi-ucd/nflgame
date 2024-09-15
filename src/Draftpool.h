#ifndef DRAFTPOOL_H
#define DRAFTPOOL_H

#include <vector>
    using std::vector;

#include <array>
    using std::array;

class Draftpool {
    private:
        vector<int> pool;
        bool isPopulated {false};
    public:
        Draftpool();
        explicit Draftpool(int (*rand_func)());
        ~Draftpool() = default;
        vector<int> getPool() const;
        bool getIsPopulated() const;
        void setPool(vector<int> the_pool);
        void setIsPopulated(bool is_popuated);
        void populatePool(int (*rand_func)());
        int randomPlayer(int (*rand_func)());
        array<int, 2> draftYear(int (*rand_func)());
        array<int, 10> draftRoster(int (*rand_func)());
        array<int, 20> draftRosters(int (*rand_func)());
        void returnPlayer(int (*rand_func)(), int player);
        void returnPlayers(int (*rand_func)(), vector<int> players);
};

#endif