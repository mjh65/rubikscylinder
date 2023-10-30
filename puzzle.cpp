
#include "puzzle.h"
#include <iostream>

Puzzle::Puzzle(std::string init)
{
    // the string provides initialisation details for the puzzle
    // '-' is an empty location. there must be 1 of these in rows 1,3,5 and 2 of these in  rows 2,4, only at the ends
    // 'X' is a black ball. there must be 3 of these.
    // 'B', 'G', 'Y', 'O', 'R' are the five colours (blue, green, yellow, orange, red). there must be 4 each of these.
    // spaces are ignored.

    std::string smap("-BGYOR         X"); // exactly 16 characters long
    int colour_count[16];
    int ball_count[5];

    for (int z = 0; z < 16; ++z)
    {
        colour_count[z] = 0;
        if (z < 5) { row[z] = 0; ball_count[z] = 0; }
    }

    int r = 0, p = 1;
    for (auto i = init.begin(); i < init.end(); ++i)
    {
        if (*i == ' ') continue;
        auto j = smap.find(*i);
        if (j == std::string::npos) throw std::runtime_error(std::string("Invalid initialiser character: ") + *i);

        if (r > 4) throw std::runtime_error(std::string("Initialiser string is too long"));
        ++colour_count[j];
        if (j) ++ball_count[r];
        row[r] |= (j << (4 * p));
        ++p;
        if (p > 6) { ++r; p = 1; }
    }

    if ((r != 5) || (p != 1)) throw std::runtime_error(std::string("Initialiser string is too short"));

    if (colour_count[0] < 7) throw std::runtime_error(std::string("Initialiser string error - too few blanks (7 x '-')"));
    if (colour_count[0] > 7) throw std::runtime_error(std::string("Initialiser string error - too many blanks (7 x '-')"));
    if (colour_count[1] < 4) throw std::runtime_error(std::string("Initialiser string error - too few blue (4 x 'B')"));
    if (colour_count[1] > 4) throw std::runtime_error(std::string("Initialiser string error - too many blue (4 x 'B')"));
    if (colour_count[2] < 4) throw std::runtime_error(std::string("Initialiser string error - too few green (4 x 'G')"));
    if (colour_count[2] > 4) throw std::runtime_error(std::string("Initialiser string error - too many green (4 x 'G')"));
    if (colour_count[3] < 4) throw std::runtime_error(std::string("Initialiser string error - too few yellow (4 x 'Y')"));
    if (colour_count[3] > 4) throw std::runtime_error(std::string("Initialiser string error - too many yellow (4 x 'Y')"));
    if (colour_count[4] < 4) throw std::runtime_error(std::string("Initialiser string error - too few orange (4 x 'O')"));
    if (colour_count[4] > 4) throw std::runtime_error(std::string("Initialiser string error - too many orange (4 x 'O')"));
    if (colour_count[5] < 4) throw std::runtime_error(std::string("Initialiser string error - too few red (4 x 'R')"));
    if (colour_count[5] > 4) throw std::runtime_error(std::string("Initialiser string error - too many red (4 x 'R')"));
    if (colour_count[15] < 3) throw std::runtime_error(std::string("Initialiser string error - too few black (4 x 'X')"));
    if (colour_count[15] > 3) throw std::runtime_error(std::string("Initialiser string error - too many black (4 x 'X')"));

    if (ball_count[0] != 5) throw std::runtime_error(std::string("Initialiser string error - row 1 must have 5 balls"));
    if (ball_count[1] != 4) throw std::runtime_error(std::string("Initialiser string error - row 2 must have 4 balls"));
    if (ball_count[2] != 5) throw std::runtime_error(std::string("Initialiser string error - row 3 must have 5 balls"));
    if (ball_count[3] != 4) throw std::runtime_error(std::string("Initialiser string error - row 4 must have 4 balls"));
    if (ball_count[4] != 5) throw std::runtime_error(std::string("Initialiser string error - row 5 must have 5 balls"));

    // check there are no blanks in positions 2,3,4,5
    for (int z = 0; z < 5; ++z)
    {
        for (int y = 8; y < 24; y += 4)
        {
            if ((row[z] & (0xf << y)) == 0) throw std::runtime_error(std::string("Initialiser string error - blank in illegal position"));
        }
    }

    // check there are no balls in rows 2 and 4, positions 1 and 6 (this check is probably redundant)
    if (row[1] & 0x0f0000f0) throw std::runtime_error(std::string("Initialiser string error - ball in illegal position in row 2"));
    if (row[3] & 0x0f0000f0) throw std::runtime_error(std::string("Initialiser string error - ball in illegal position in row 4"));

    // puzzle can start with shifter in left or right position. assume row 1, position 1 is the indicator, then check
    // everything else is consistent.
    bool shifter_down = ((row[0] & 0x000000f0) != 0);
    if (shifter_down)
    {
        if (row[2] & 0x0f000000) throw std::runtime_error(std::string("Initialiser string error - row 3 and row 1 are inconsistent"));
        if (row[4] & 0x0f000000) throw std::runtime_error(std::string("Initialiser string error - row 5 and row 1 are inconsistent"));
    }
    else
    {
        if (row[2] & 0x000000f0) throw std::runtime_error(std::string("Initialiser string error - row 3 and row 1 are inconsistent"));
        if (row[4] & 0x000000f0) throw std::runtime_error(std::string("Initialiser string error - row 5 and row 1 are inconsistent"));
    }
}

void Puzzle::Print()
{
    std::string smap("-BGYOR         X"); // exactly 16 characters long
    for (int i=0; i<5; ++i)
    {
        int r = row[i];
        for (int j = 0; j < 8; ++j)
        {
            int c = r & 0xf;
            r >>= 4;
            std::cout << ' ' << smap[c];
        }
        std::cout << std::endl;
    }

}
