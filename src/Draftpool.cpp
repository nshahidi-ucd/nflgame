#include <array>
    using std::array;

#include <vector>
    using std::vector;

#include "Draftpool.h"

Draftpool::Draftpool() {}

Draftpool::Draftpool(int (*rand_func)()) {
    this->populatePool(rand_func);
}

vector<int> Draftpool::getPool() const {
    return this->pool;
}

bool Draftpool::getIsPopulated() const {
    return this->isPopulated;
}

void Draftpool::setPool(vector<int> the_pool) {
    this->pool = the_pool;
}

void Draftpool::setIsPopulated(bool is_populated) {
    this->isPopulated = is_populated;
}

void Draftpool::populatePool(int (*rand_func)()) {
    if (this->isPopulated) return;
    vector<int> ji_pool;
    for (int i0 (0); i0 < 101; ++ i0)
        for (size_t j0 (0); j0 < 7; ++ j0)
            ji_pool.push_back(i0);
    for (int i1 (101); i1 < 121; ++ i1)
        for (size_t j1 (0); j1 < 4; ++ j1)
            ji_pool.push_back(i1);
    for (int i2 (130); i2 < 191; i2 += 10)
        ji_pool.push_back(i2);
    for (int i3 (200); i3 < 301; i3 += 25)
        ji_pool.push_back(i3);
    for (int i4 (0); i4 < 20; ++ i4)
        for(size_t j2 (0); j2 < 2; ++ j2)
            ji_pool.push_back(i4);
    for (size_t j3 (0); j3 < 6; ++ j3)
        ji_pool.push_back(0);
    for (int i5 (80); i5 < 101; ++ i5)
        ji_pool.push_back(i5);
    for (size_t j4 (0); j4 < 2; ++ j4)
        ji_pool.push_back(500);
    do {
        size_t rand_index = rand_func() % ji_pool.size();
        int rand_player = ji_pool[rand_index];
        this->pool.push_back(rand_player);
        ji_pool.erase(ji_pool.begin() + rand_index);
    } while (ji_pool.size());
    this->isPopulated = true;
}

int Draftpool::randomPlayer(int (*rand_func)()) {
    size_t rand_index = rand_func() % this->pool.size();
    int rand_player = this->pool[rand_index];
    this->pool.erase(this->pool.begin() + rand_index);
    return rand_player;
}

array<int, 2> Draftpool::draftYear(int (*rand_func)()) {
    array<int, 2> drafted_year;
    drafted_year[0] = this->randomPlayer(rand_func);
    drafted_year[1] = this->randomPlayer(rand_func);
    return drafted_year;
}

array<int, 10> Draftpool::draftRoster(int (*rand_func)()) {
    array<int, 10> drafted_roster;
    for(size_t i (0); i < 10; ++ i)
        drafted_roster[i] = this->randomPlayer(rand_func);
    return drafted_roster;
}

array<int, 20> Draftpool::draftRosters(int (*rand_func)()) {
    array<int, 20> drafted_rosters;
    for(size_t i (0); i < 20; ++ i)
        drafted_rosters[i] = this->randomPlayer(rand_func);
    return drafted_rosters;
}

void Draftpool::returnPlayer(int (*rand_func)(), int player) {
    size_t rand_index = rand_func() % this->pool.size();
    this->pool.insert(this->pool.begin() + rand_index, player);
}

void Draftpool::returnPlayers(int (*rand_func)(), vector<int> players) {
    for (int player : players)
        this->returnPlayer(rand_func, player);
}