#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    config *draw;
    gridworld *world = parse_config(draw);
    draw_world(world, argc, argv);
    return 0;
}