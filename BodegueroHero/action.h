#ifndef ACTION_H
#define ACTION_H

class Action
{
public:
    static int Empty(){return 0;}
    static int Down(){return 1;}
    static int Left(){return 2;}
    static int Right(){return 3;}
    static int One(){return 4;}
    static int Two(){return 5;}
    static int Three(){return 6;}
    static int Four(){return 7;}
    static int Actions[28];
private:
    Action();    
};

#endif // ACTION_H
