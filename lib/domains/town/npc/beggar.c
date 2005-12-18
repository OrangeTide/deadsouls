#include <lib.h>

inherit LIB_SENTIENT;

static void create() {
    sentient::create();
    SetKeyName("beggar");
    SetId(({"beggar"}));
    SetAdjectives(({"dirty"}));
    SetShort("a dirty beggar");
    SetLong("This beggar has something strangely noble about his aspect. "
      "He certainly doesn't look like he has always been a beggar.");
    SetInventory(([
	"/domains/town/obj/map" : 1,
      ]));
    SetLevel(1);
    SetRace("human");
    SetGender("male");
    SetMaxHealthPoints(40);
}

int GiveMap(object ob){
    object map;
    if(present(ob->GetKeyName(),environment(this_object()))){
	eventForce("say here, you might need this");
	eventForce("give my first map to "+ob->GetKeyName());
    }
    if(map = present("map",this_object())) {
	map->eventDestruct(); 
	eventForce("shrug");
    }
    return 1;
}

int SayHi(object ob){
    if(present(ob->GetKeyName(),environment(this_object())))
	eventForce("say Hi, "+this_player()->GetName());
    return 1;
}

void init(){
    ::init();
    call_out((: SayHi, this_player() :), 1);
    if(!present("town map",this_player())){
	new("/domains/town/obj/map")->eventMove(this_object());
	call_out((: GiveMap, this_player() :), 4);
    }
}
