#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <string> // std::string
#include <vector>
#include <deque>

#include "player.h"

class Snake{
private:
    int m_lives;
    int m_size = 1;
    bool m_isAlive = true;
    std::pair<int, int> m_headLocation;
    std::vector<std::pair<int, int>> m_visitedLocations;
    Direction m_headFacing;
    std::deque<std::pair<int, int>> m_body;

public:
    // Constructor
    Snake(int r, int c, Direction d)
        : m_headLocation(r, c), m_headFacing(d) {
        // Initial body can be empty or contain the head location
        m_body.push_back(m_headLocation);
    }
    int get_lives(){return m_lives;}
    int get_size(){return m_size;}
    bool get_isAlive(){return m_isAlive;}
    std::pair<int, int> get_headLocation(){return m_headLocation;}
    std::vector<std::pair<int, int>> get_visitedLocations() {return m_visitedLocations;}
    Direction get_headFacing(){return m_headFacing;}
    std::deque<std::pair<int, int>> get_body(){return m_body;}

    void set_lives(int l){m_lives = l;}
    void set_lenght(int l){m_size = l;}

    bool check_coord_in_body(std::pair<int, int> coord);
    bool snake_ate_check();
    void update_snake_isAlive();
    void move_snake();
};

#endif