#include "buzzer_sounds_c.h"

int buzzerCycle = 0;

int getBuzzerCycle(int note){
    
    switch(note){
        case 0:
            buzzerCycle = 7644; //C4
            break;
        case 1:
            buzzerCycle = 6810; //D4
            break;
        case 2:
            buzzerCycle = 6067; //E4
            break; 
        case 3:
            buzzerCycle = 5727;//F4
            break;
        case 4:
            buzzerCycle = 5102; //G4
            break;
        case 5:
            buzzerCycle = 4545; //A4 
            break;
        case 6: 
            buzzerCycle = 4049; //B4
            break;
        case 7: 
            buzzerCycle = 3822; //C5
            break;
    }

    return buzzerCycle;
}
