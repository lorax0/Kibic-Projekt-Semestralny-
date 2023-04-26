#include <ctime>
#include <memory>
#include <stdlib.h>
#include "Manager.h"




int main() {
    srand( time( NULL ) );
    Manager manager;

    manager.Menu();

    return 0;
}