
#include <string>

class Puzzle
{
public:
    Puzzle(std::string init);

    // move the puzzle balls by one operation
    // the opcode is one of 'S' (shift) or 'L', 'l', 'R', r' (rotate left/right up/down)
    void Move(char opcode);

    // estimate how good this arrangement is 1=solved, 0=random
    float Score();

    void Print();

private:
    // the puzzle is represented as 5 rows (numbered 1-5, indexed 0:4)
    // each row has 6 positions, which are represented using 4 bits per position
    // a position can contain a coloured ball (1-5), a black ball (15), or empty (0)
    // positions 2-5 (8:23) represent the 2 rotatable cylinders, containing 2 balls each.
    // these positions always contain balls (ie are never empty) and each cylinder can be
    // rotated independently to move balls between rows.
    // rows 1, 3 and 5 have shifters which enable balls to be moved along rows. the shifters
    // work in unison, and toggle between left and right states. when the shifter is in
    // the left state there will be a ball in position 1 and position 6 will be empty.
    // when the shifter is in the right state position 1 will be empty and position 6 will
    // contain a ball.
    int row[5];

    // score for this arrangement (<0 if not yet calculated)
    float score;

};
