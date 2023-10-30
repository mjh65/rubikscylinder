
#include <iostream>
#include "puzzle.h"

int main(int argc, char **argv)
{
    Puzzle start("RRGGB- -GORR- OOOXY- -BYXB- XYGBY-");

    // test some wrong initialisers
    //Puzzle e1("RRGGB- -GORR- OOOXY- -BYXB- XYGBY- XXXXXX");
    //Puzzle e2("RRGGB- -GORR- OOOXY- -BYXB-");
    //Puzzle e3("RRGGBX -GORR- -OOXY- -BYXB- XYGBY-");
    //Puzzle e4("RRG-BO -GORR- -OOXYG -BYXB- XYGBY-");
    //Puzzle e5("-GORR- OOOXY- -BYXB- XYGBY- RRGGB-");






    start.Print();

    return 0;
}

