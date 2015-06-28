#ifndef PROJECT_TRIPLET_H
#define PROJECT_TRIPLET_H


class Triplet {
    float v[3];
public:
    Triplet (float v0, float v1, float v2);
    float first();
    float second();
    float third();
};


#endif //PROJECT_TRIPLET_H
