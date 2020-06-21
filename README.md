# actor-plugin
Vice City Multiplayer (forum.vc-mp.org) Server plugin for creating bots.

Since the author was not acquainted with general layout of this type of plugins, he used another plugin for layout, the latter being called Geo IP by an author Crys.  Hence You can see the name 'Geo IP' in some files.

Functions
```ruby
integer create_actor( string name, integer skinId, float x, float y, float z, float angle );

//parameters SkinId, x, y, z and angle are optional.

set_port(string newport); //default is "8192"

set_actor_angle(  integer actorID,  float angle );         // -3.14 < angle < 3.14

```

[b]Examples[/b]
```ruby
[color=black]create_actor("john");[/color]

[color=purple]create_actor("kevin",5);[/color] will spawn a medic with name 'kevin'

[color=brown]create_actor("Edward",1,-656,756,11.2,0); will spawn a cop at downtown facing north.[/color]

setport("8193"); ( in case your port is not 8192, but 8193 );
```
Notes
1. actorid and playerid are different.
2. create_actor returns an integer which is 0 for 1st bot, 1 for 2nd bot and so on. We can call it actor id.  
3. In the create_actor function, Avoiding skinId and including position leads to an error.
4. create_actor function will take a certain time to create the bot. ( 1 sec or so ). So the codes like set_actor_angle just below this function will not work. 
5. If your server has registration system, you must manually register the bot. Otherwise it is seen that the bot cannot spawn.
