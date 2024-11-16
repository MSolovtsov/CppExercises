#include "Nicknames.h"

string Nicknames::randNickname(){
    switch ((Nicks)rand() % 8) {
        case Archie: return "Archie";
        case Baron: return "Baron";
        case Bolt: return "Bolt";
        case Gorik: return "Gorik";
        case Shatik: return "Shatik";
        case Sherkhan: return "Sherkhan";
        case Spike: return "Spike";
        case Tyson: return "Tyson";
    }
}
