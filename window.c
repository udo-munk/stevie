/*
 * STevie - ST editor for VI enthusiasts.    ...Tim Thompson...twitch!tjt...
 */

#include "stevie.h"
#include "stdio.h"
#include "sgtty.h"

windinit()
{
	/* Initialise tty */
	struct sgttyb stty;
	stty.sg_flags = CBREAK | CRMOD;
	ioctl(0, TIOCSETP, &stty);

	Columns=80;
	Rows=24;
	/* Here we want no echo, disable line buffering / erase kill
	   and no newline - curses noecho(), cbreak(), nonl() */
}

windgoto(r,c)
int r,c;
{
	/* Locate cursor */
	printf("\033Y%c%c",r+0x20,c+0x20);
}

windexit(r)
int r;
{
	exit(r);
}

windclear()
{
	/* Clear the screen */
	printf("\014");
}

windgetc()
{
	return(getchar());
}

windstr(s)
char *s;
{
	printf("%s",s);
}

windputc(c)
int c;
{
	putchar(c);
}

windrefresh()
{
	/* Need a redraw here? */
}

beep()
{
	putchar('\007');
}
