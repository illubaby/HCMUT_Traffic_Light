```mermaid

stateDiagram-v2
    AutomaticMode-->Manual_Mode: Button 1 Pressed
    AutomaticMode --> TuningMode : Button 2 Pressed

    TuningMode-->AutomaticMode: Button 2 Pressed

    AutomaticMode --> PedestrianScramble : Pedestrian Button Pressed
    PedestrianScramble --> AutomaticMode : immediately change (after 20 seconds without \n press Button 3, turn off the pedestrian led 

    Manual_Mode-->AutomaticMode: Immediately change 
    state Manual_Mode{
        Red_State --> Yellow_State : Button 1 Pressed
        Yellow_State --> Green_State : Button 1 Pressed
        Green_State --> Red_State : Button 1 Pressed
    }
    state TuningMode{

        Tuning_Red --> Tuning_Yellow : Button 2 Pressed
        Tuning_Yellow --> Tuning_Green : Button 2 Pressed
        Tuning_Green --> Tuning_Red : Button 2 Pressed 

    }
    note right of TuningMode : Button 1 to increase value \n Button 3 to set value

    state AutomaticMode {
        [*] --> Red
        Red --> Yellow : Timer
        Yellow --> Green : Timer
        Green --> Red : Timer
    }

    state PedestrianScramble {
        PedestrianGreen --> PedestrianRed : Timer
        PedestrianRed --> PedestrianGreen : Timer
    }
