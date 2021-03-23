#include "wgt.h"
#include "include/mem.h"

// ######## REQUIRED FUNCTIONS ########

unsigned long state0 = 1000;
unsigned long state1 = 2000;

unsigned long rand(void)
{
    unsigned long s1 = state0;
    unsigned long s0 = state1;

    state0 = s0;
    s1 ^= s1 << 23;
    s1 ^= s1 >> 17;
    s1 ^= s0;
    s1 ^= s0 >> 26;
    state1 = s1;

    return state0 + state1;
}

// ######## STUB FUNCTIONS ########

unsigned int kb = 0;

unsigned int kbhit(void) {
    kb++;
    return kb / 500;
}

void getch(void) {
    wait_msec(0x500000);
    kb = 0;
}

// ######## WGT EXAMPLES ########

short randdissolve[513]={ 
256,0,0,9,8,3,11,15,12,12,2,4,2,9,14,0,9,8,1,13,7,1,3,13,14
,5,7,3,14,7,4,11,11,7,11,2,6,13,0,10,5,6,15,0,12,15,4,5,0
,14,9,7,6,5,13,4,4,15,7,2,1,11,15,0,6,5,10,9,3,13,11,12,5
,0,14,2,9,6,3,10,1,11,9,7,13,3,8,11,13,0,2,14,2,9,11,6,8
,6,1,11,7,15,15,7,9,9,6,5,5,1,13,9,0,2,15,1,5,3,5,11,3
,1,10,15,10,4,0,15,0,8,15,1,7,14,6,3,3,9,12,13,4,4,12,4,6
,11,4,11,14,9,9,2,4,12,10,8,4,10,12,4,9,11,0,13,13,1,0,13,8
,1,1,1,11,10,6,7,2,0,4,14,1,14,14,10,10,7,7,9,2,14,3,13,10
,8,5,5,2,4,8,9,7,6,13,2,3,13,2,14,11,8,10,6,4,2,13,3,7
,12,13,12,7,15,1,4,7,11,8,7,0,5,11,12,6,1,4,1,14,8,8,3,10
,6,6,10,2,13,12,6,10,0,8,3,1,9,4,10,13,6,12,6,7,11,6,5,3
,8,13,4,5,3,2,7,14,2,12,4,14,10,8,14,4,12,3,12,9,11,2,8,3
,12,12,14,13,6,11,6,5,3,4,13,6,9,1,2,11,8,14,7,8,4,1,14,5
,9,10,2,8,9,5,7,1,15,2,3,13,15,8,1,2,15,6,4,15,10,3,12,0
,0,5,12,1,2,0,5,1,7,3,6,9,2,7,4,10,1,12,0,1,14,15,7,5
,8,7,10,9,1,6,3,0,8,2,8,9,1,9,10,15,10,14,10,7,12,8,14,12
,13,15,12,14,9,13,6,0,13,9,14,10,10,11,5,4,15,11,11,10,6,2,11,5
,11,1,8,0,10,0,14,8,11,12,8,12,7,10,7,12,7,15,12,15,2,10,0,10
,3,9,3,6,3,15,5,14,3,12,4,13,5,12,1,8,10,4,12,11,5,6,15,14
,14,0,2,2,0,3,8,6,0,11,0,15,15,13,13,1,15,3,13,5,14,7,0,7
,8,11,4,11,6,14,2,14,13,3,2,5,5,15,5,9,15,5,0,13,4,3,9,15
,5,8,15,9,12,4,1,15};

/* this large array was made with dissolve.exe
   run it to create your own patterns. */

short sideways[515]={
257,3,6,0,0,0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0,10
,0,11,0,12,0,13,0,14,0,15,1,0,1,1,1,2,1,3,1,4,1,5,1,6
,1,7,1,8,1,9,1,10,1,11,1,12,1,13,1,14,1,15,2,0,2,1,2,2
,2,3,2,4,2,5,2,6,2,7,2,8,2,9,2,10,2,11,2,12,2,13,2,14
,2,15,3,0,3,1,3,2,3,3,3,4,3,5,3,6,3,7,3,8,3,9,3,10
,3,11,3,12,3,13,3,14,3,15,4,0,4,1,4,2,4,3,4,4,4,5,4,6
,4,7,4,8,4,9,4,10,4,11,4,12,4,13,4,14,4,15,5,0,5,1,5,2
,5,3,5,4,5,5,5,6,5,7,5,8,5,9,5,10,5,11,5,12,5,13,5,14
,5,15,6,0,6,1,6,2,6,3,6,4,6,5,6,6,6,7,6,8,6,9,6,10
,6,11,6,12,6,13,6,14,6,15,7,0,7,1,7,2,7,3,7,4,7,5,7,6
,7,7,7,8,7,9,7,10,7,11,7,12,7,13,7,14,7,15,8,0,8,1,8,2
,8,3,8,4,8,5,8,6,8,7,8,8,8,9,8,10,8,11,8,12,8,13,8,14
,8,15,9,0,9,1,9,2,9,3,9,4,9,5,9,6,9,7,9,8,9,9,9,10
,9,11,9,12,9,13,9,14,9,15,10,0,10,1,10,2,10,3,10,4,10,5,10,6
,10,7,10,8,10,9,10,10,10,11,10,12,10,13,10,14,10,15,11,0,11,1,11,2
,11,3,11,4,11,5,11,6,11,7,11,8,11,9,11,10,11,11,11,12,11,13,11,14
,11,15,12,0,12,1,12,2,12,3,12,4,12,5,12,6,12,7,12,8,12,9,12,10
,12,11,12,12,12,13,12,14,12,15,13,0,13,1,13,2,13,3,13,4,13,5,13,6
,13,7,13,8,13,9,13,10,13,11,13,12,13,13,13,14,13,15,14,0,14,1,14,2
,14,3,14,4,14,5,14,6,14,7,14,8,14,9,14,10,14,11,14,12,14,13,14,14
,14,15,15,0,15,1,15,2,15,3,15,4,15,5,15,6,15,7,15,8,15,9,15,10
,15,11,15,12,15,13,15,14,15,15};

/* and another one */

int x, y;
int oldmode;
block screen1;

void wgt17()
{
  short y;
  block screen1;

  set_clock_rate(get_max_clock());
  mem_init();
  vga256 ();

  screen1 = wnewblock (0, 0, 319, 199);

  wsetscreen (screen1);

  for (y = 0; y < 200; y++)
    {
     wsetcolor (vgapal[y]);
     wline (0, y, 319, y);   /* draw something on another screen */
    }

  wnormscreen ();
  wdissolve (screen1, randdissolve, 2);
  /* screen to dissolve, pattern, speed */

  getch ();
  wsetscreen (screen1);
  wcls (vgapal[0]);
  wnormscreen ();
  wclip (75, 75, 245, 124);	/* works with clipping too */
				/* so you can fade in parts of screens */
  wdissolve (screen1, sideways, 2);
  wclip (0, 0, 319, 199);
  getch ();
  wdissolve (screen1, randdissolve, 2);
  getch ();

  wfreeblock (screen1);	/* remember to free that memory */
}

void main()
{
    wgt17();
    while (1);
}
