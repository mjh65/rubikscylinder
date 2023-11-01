
#include <iostream>
#include "puzzle.h"

int main(int argc, char **argv)
{
    time_t t = time(0);
    srand((unsigned int)t);

    Puzzle p("RRGGB- -GORR- OOOXY- -BYXB- XYGBY-");

    // test some wrong initialisers
    //Puzzle e1("RRGGB- -GORR- OOOXY- -BYXB- XYGBY- XXXXXX");
    //Puzzle e2("RRGGB- -GORR- OOOXY- -BYXB-");
    //Puzzle e3("RRGGBX -GORR- -OOXY- -BYXB- XYGBY-");
    //Puzzle e4("RRG-BO -GORR- -OOXYG -BYXB- XYGBY-");
    //Puzzle e5("-GORR- OOOXY- -BYXB- XYGBY- RRGGB-");

    p.Print();

    // generate a random sequence of moves, apply them and show the result

    std::string opt("SLlRr");
    for (int i=0; i<20; ++i)
    {
        int m = rand() % 5;
        char move = opt[m];
        std::cout << std::string("Move ") + move << std::endl;
        p.Move(opt[m]);
        p.Print();
    }

    return 0;
}

