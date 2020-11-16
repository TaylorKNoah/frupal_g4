// Lawrence Scroggs -- Frupal--
// Wanted to break down the items in a seperate .h file to 
// avoid clutter

#include "entity.h"


class treasure:public item{

  char * treas_type;

}
class tools:public item{

  int power_lvl;

}
class food:public item{

  int energy_provided;

}
