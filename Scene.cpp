#include "Scene.h"
#include "Vector3.h"

Scene& Scene::get(){
    if(!instance) instance = new Scene();
    return *instance;
}

Scene::Scene(){
    camera = Camera(Vector3());
}