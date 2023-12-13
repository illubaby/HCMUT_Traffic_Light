```mermaid
stateDiagram-v2
    AutomaticMode-->Manual_Mode: Button 1 Pressed
    %% Manual_Mode --> TuningMode : 

     TuningMode-->Manual_Mode: Button 1 Pressed
    TuningMode -->AutomaticMode: Button 1 pressed

    AutomaticMode --> PedestrianScramble : Pedestrian Button Pressed
    PedestrianScramble --> AutomaticMode : immediately change (after 20 seconds without \n press Button 3, turn off the pedestrian led 

    Manual_Mode-->AutomaticMode: After a ... time
    state Manual_Mode{
        Red_State --> Yellow_State : Button 1 Pressed
        Yellow_State --> Green_State : Button 1 Pressed
        Green_State --> Red_State : Button 1 Pressed
        Red_State --> Tuning_Red : Button 2 Pressed
        Yellow_State --> Tuning_Yellow : Button 2 Pressed
        Green_State --> Tuning_Green : Button 2 Pressed
    }
    state TuningMode{

        Tuning_Red  --> Tuning_Red : Button 3 Pressed
        Tuning_Yellow  --> Tuning_Yellow: Button 3 Pressed
        Tuning_Green  --> Tuning_Green: Button 3 Pressed 

    }
    note right of TuningMode : Button 2 to increase value \n 

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
