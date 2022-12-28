female(pam).
female(liz).
female(pat).
female(ann).
female(karen).
male(bob).
male(tom).
male(sean).
male(harry).
male(jimmy).

parent(bob,liz).
parent(pam,liz).
parent(bob,tom).
parent(pam,tom).
parent(liz,jimmy).
parent(tom,sean).

grandson(X,Y):- parent(Y,Z), parent(Z,X), male(X).

firstCousins(X,Y):- parent(GParent,Parent), parent(Parent,X),
    parent(GParent,Parent2), parent(Parent2,Y),
    not(X=Y), not(Parent1=Parent2).
    
third([_,_,Y],Y).
firstPair([A,A]). 
del3([A,B,C],[A,B]).