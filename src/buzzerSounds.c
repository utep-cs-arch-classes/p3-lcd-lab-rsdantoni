int buzzerCycle = 0;

int getBuzzerCycle(char note){
    
    switch(note){
        case 'C':
            buzzerCycle = 7644; //C4
            break;
        case 'D':
            buzzerCycle = 6810; //D4
            break;
        case 'E':
            buzzerCycle = 6067; //E4
            break; 
        case 'F':
            buzzerCycle = 5727;//F4
            break;
        case 'G':
            buzzerCycle = 5102; //G4
            break;
        case 'A':
            buzzerCycle = 4545; //A4 
            break;
        case 'B': 
            buzzerCycle = 4049; //B4
            break;
        case 'O': //C5 (o for octave)
            buzzerCycle = 3822;
    }

    return buzzerCycle;
}