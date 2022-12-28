ordered([]).
ordered([_]).
ordered([First,Second|Rest]):-First>=Second,ordered([Second|Rest]).
