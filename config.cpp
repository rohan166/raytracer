/* Created by rray on 6/27/15.
 * Parse the config file in the project's base directory and generate a description of the world in memory.
 */

#include <stdio.h>
#include <string>
#include "config.h"

#define NUM_OBJECTS 2

using namespace std;

Scene * parse_config (Config *config) {
    Primitive *shapes[NUM_OBJECTS];
    unsigned int height, width, counter = 0;
    FILE *in_config = fopen("config");
    string directive(100, '\0'), value(100, '\0');

    while (fscanf(in_config, "%s: %s", &directive[0], &value[0])) {
        if (directive.compare("height"))
            height = (unsigned int) stoi(directive, nullptr);
        else if (directive.compare("width"))
            width = (unsigned int) stoi(directive, nullptr);
        else if (directive.compare("camera"))
            shapes[counter++] = new Camera(value);
        else if (directive.compare("sphere"))
            shapes[counter++] = new Sphere(value);
    }
    return new Scene(height, width, shapes);
}
