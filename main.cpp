//
//  main.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 12/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include <iostream>
#include "Utils.hpp"
#include "Goalkeeper.hpp"


int main(int argc, const char * argv[]) {
    
    Goalkeeper jp("jp", Date(6, 9, 1985), 178);
    
    cout << jp.getPosition() << endl;
    
    return 0;
}
