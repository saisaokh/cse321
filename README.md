
cd /web/faculty/bina/cse321/fall2016/

xinu-status
mips-console brylow
mips-console brylow1

mips-console bina
mips-console bina1

mips-console stump
mips-console stump1

mips-console daekeun
mips-console daekeun1

mips-console ashish
mips-console ashish1

mips-console waggonner
mips-console waggonner1

mips-console hartnett
mips-console hartnett1

mips-console moiz
mips-console moiz1

mips-console russell
mips-console russell1

xinu-status


qrecitation cse321 10/24 (Mon)
xinu <=> 

in xinu
make file is in complie -> ls, make (works) 
xinu.boot #flash the xinu.boot onto one of the routers
xinu-status
mips-console bina #took 3 -4 sec
$xsh: #in shell

1) tar xinu_mips….
2) cd compile & make
3) xinu-status
4) mips-console

#once in routers, linux cmd not work 
but ctrl space to change mode

SHELL COMMAND (PLAINDORME)
cd to shell

xinu semaphores 

#look at pic taken (10_24)



#fork learning source provide by TA
http://beej.us/guide/bgipc/output/html/multipage/fork.html


recitation cse321(10_31_2016)

xinu shell command implementation 
Echo functionality (Appendix B) # need to change in plaindorme 

look at archeticture recitiaont note on 10_31

ssh to nexos
untar xin agian , cd to xinu get default new

echo func: (mean in the )


jmips-console brylow
if time > 5s, use different router

echo blahblahblah 
q
pwd => inside compile
cd to main default pj dir router

1) 	to update the file shell .h in include dir
2)	to update in the shell dir i.e shell.c
3)	to add file xsh_echo.c to shell dir
4)	to change/update Makefile

#expanding in xinu the best way possible, to implement to new command
1)	cd include/ # go to vim shell.h
line 12 struct #importatnt strucure when implenting new funciton centry, 
some basic representation (in xinu case)

SHELL BANNER #ln 59  
add command xsh_echo (ushort, ushort, ushort, ushort,  char*[]); //add for xsh_echo.c
#added a def of new cmd 

2) cd shell/ ls => vim shell.c
struct centry #cmd table array add def of new comand
add at ln31in shell.c {“echo”, FALSE, xsh_echo}, => wq

3) cp xsh_help.c xsh_echo.c (in shell directory)
vim xsh_echo.c #delet unecessary,  line 24 command  replace xsh_echo

int i;
//help funcationality for the echo command implementation
command xsh)echo (ushort s…….*args[]){
if (nargs ==2 && strncmp(args[1], “..help”, 6) ==0)
{
	fprintf(stdout, “USage: clear \n”;
	fprintf(stdout, ‘Clear the terminal. \n))
}

//implementation of the echo command
for (i=1, 1 <naargs; i++){
	fprintf (stdout, “%s”, args[i]);
}

fprint ()stdout, “\n”);
return OK;

}#same as in appendix

4) update makefile cd to compile Makefile alt it
Make file for view 

#implenmet new shell cmd
@ln 34 in the line SHL  xsh_echo.c
complie, 1st make clean, then make (if no error good)
flush it to one of route  mips-console brylow
echo alkdfjsad repeat as it is
———————————— 
expected in pj description 

implement the function palindorm 

palindrome radar
it’s a palindrome

palindrome oobbc

its not a palindrome

#after this part read description, 
start chat program or go implenet in real time schedule (this first as it’s easir than chat)
xinu console
xinu boot atuo get falsh to hardware, open terminal and xinu-console bryo

echo functionality

#check pic from recitaoint on oct 31 imessage
—————————— —————————— —————————— 
# Friday cse321 recitation (Nov 4 friday)
http://www.cse.buffalo.edu/~bina/cse321/fall2015/demos/thread3.c

rc = pthread_create(&thread[t], &attr, BusyWork, (void *)t);
#run the program
—————————— —————————— —————————— 

recitation cse321(11_7_2016 monday)
Xinu Cyclic Execution (30 pts)

cyclicexe
mips-console brylow

in xinu cyclicexe #show if codes running(printing) get full pts 
fprintf(stdout, “….”);#in unix everyitning is fiile/learning of kernel
fprintf = file print f #man fprintf

scheduler #infinite loop run cmd scheduler in xinu

void task(int period){
fprintf(stdout, “Task1 at period %d”, period);

}
#codes provided by bina edit something to make it work
#check flowchart on paper (11/6/2016)

implementation
to do cyclic functionality
-> create a process: create();
-> Ready the process: ready(); #happen in main drive function
-> Schedule the process:

section 3.7
ti , ri, ei , pi Di (eg from midterm)
final value/answer as in midterm
hardcode schedule in driver
table -> data structure( 2D array table) need to be done in driver

#80 lines of code,understand how kernel design
void schedule [frame_no ][task_no ]={
#schedule is desing for 1 hyperperiod, then call schedule over and over agin 
in infinite loop
{t1, t1,t2}
{t2,b,b}
{t2,t3,t1}
}
#memory layout of c/c++ program look?
eg: Java
char{ String n = new String(“XYZ”);// require new for java and same as c/c++
sys.out.print(ln);
}

C/C++
declaration scheduler fun as global
definition
> when declare table memory already assgined to that, 
   so should use ptr



#in infinte loop call this table# Driver 20 lines of code
-> DRIVER #main fun scheduler will be in driver to invoke and complete individual tasks

i= frame_no
j= task_no
for (;;){ 
	(*schedule[i][j]) (); #i, j can’t be increase infinite because of hperperiod
}

#table has for infinite for loop
void task1(){
	fprintf(stdout, “Executing Task1”);
	sleep(1000);
}

#study pointer to the function 
http://www.cprogramming.com/tutorial/function-pointers.html

*****************************************************************************
Friday recitation cse321(11_11_2016)

*****************************************************************************
2 terminals


mips-console brylow
chat
user1
pass1

xinu-console brylow1
chat
user2
pass2



//put program on both of them


chat #implemented 
run chat program
chatuser1 and user2

2 programs distinguished

- - - - - -  - -- - - - - -  - -- - - - - -  - -- - - - - -  - -- - - - - -  - -- - - - - -  - -
palindrome part
- - - - - -  - -- - - - - -  - -- - - - - -  - -- - - - - -  - -- - - - - -  - -- - - - - -  - -
1 cd /include/shell.h
command xsh_palindrome (ushort, ushort, ushort, ushort,  char*[]); //add for xsh_palindrome.c

2 cd shell/shell.c
{“palindrome”, FALSE, xsh_palindrome},

3 cd shell/
cp xsh_help.c xsh_palindrome.c 
vim xsh_palindrome.c 

4 cd compile/Makefile
vim Makefile
//add xsh_palindrome.c to SHL =….

- - - - - -  - -- - - - - -  - -- - - - - -  - -- - - - - -  - -- - - - - -  - -- - - - - -  - -
cycExe part
- - - - - -  - -- - - - - -  - -- - - - - -  - -- - - - - -  - -- - - - - -  - -- - - - - -  - -
1 cd /include/shell.h
command xsh_cycExe (ushort, ushort, ushort, ushort,  char*[]); //add for xsh_cycExe.c

2 cd shell/shell.c
{“cycExe”, FALSE, xsh_cycExe}, //change ‘’

3 cd shell/
cp xsh_help.c xsh_palindrome.c 
vim xsh_palindrome.c 

4 cd compile/Makefile
vim Makefile
//add xsh_palindrome.c to SHL =….

*****************************************************************************
Monday recitation cse321(11_14_2016)

*****************************************************************************
check img on date
XINU CHAT IMPLEMENTATION (30 pts)

implemented on xinu
120 lines of code
30% formatting representation
70% focus on debugging ()

implement chat functioinality (accomende more than 2 users but use 3 usr)

usr1
pass1

usr2 
pass2

*****************************************************************************
Monday recitation cse321(11_21_2016)

*****************************************************************************
AGENDA 
xinu Q&A, F&Q

*****************************************************************************
Monday recitation cse321(11_28_2016)

*****************************************************************************
spinlock(os) or semaphore (300 level)












