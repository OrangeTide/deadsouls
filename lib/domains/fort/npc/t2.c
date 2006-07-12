#include <lib.h>

inherit  LIB_TEACHER;
void create(){
    teacher::create();
    SetKeyName("trainer");
    SetId("generic trainer");
    SetGender("male");
    SetRace("human");
    SetShort("a generic trainer");
    SetLong("This is a person whose job it is to teach you things. "+
      "For example, 'ask trainer "+
      "to teach Malkierien' would prompt him to begin teaching a Malkierien "+
      "lesson to you, if he knows the language and you have "+
      "earned sufficient training points. If you lack training points, then "+
      "do some adventuring and earn a level promotion. You will "+
      "then be awarded training points."); 
    SetLevel(1);
    AddTeachingLanguages( ({"Malkierien"}));
}
void init() {
    ::init();
}
