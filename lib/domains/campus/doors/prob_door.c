#include <lib.h>

inherit LIB_DOOR;

static void create() {
    door::create();

    SetSide("south", (["id" : ({ "door leading south", "door", "south door" }),
                "short" : "a door leading south",
                "long" : "This is the north side of a door leading south.",
                "lockable" : 1 ]) );
    SetKeys("south", ({"prob_door_key"}) );

    SetSide("north", (["id" : ({ "door leading north", "door", "north door" }),
                "short" : "a door leading north",
                "long" : "This is the south side of a door leading north.",
                "lockable" : 1 ]) );
    SetKeys("north", ({"prob_door_key"}) );

    SetClosed(1);
    SetLocked(1);
}
void init(){
    ::init();
}
