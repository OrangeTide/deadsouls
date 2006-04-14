#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

int cmd(string str) {
    object ob;

    if( !str || str == "" ) {
	write("Unsnoop whom?\n");
    }
    else if(!(ob=find_player(str=lower_case(str))))
	write(str+": no such player.\n");
    else
	SNOOP_D->RemoveWatcher(this_player()->GetKeyName(), str);
    write("The snoop daemon has received your request.");
    return 1;
}

int help()
{
    write( @EndText
Syntax: unsnoop <user>
Effect: Stops snooping the specified user.
See also: snoop, monitor, unmonitor
EndText
    );
    return 1;
}
