//  $Id: tuxkart.h,v 1.16 2004/08/01 00:13:28 grumbel Exp $
//
//  TuxKart - a fun racing game with go-kart
//  Copyright (C) 2004 Steve Baker <sjbaker1@airmail.net>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef HEADER_TUXKART_H
#define HEADER_TUXKART_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#ifdef WIN32
#ifdef __CYGWIN__
#include <unistd.h>
#endif
#include <windows.h>
#include <io.h>
//#include <direct.h>
#else
#include <unistd.h>
#endif
#include <math.h>

#ifdef HAVE_LIBSDL
#include "sdldrv.h"
#else
#include "pwdrv.h"
#endif

#include "guNet.h"
#include "constants.h"
#include "utils.h"

class GFX ;
class GUI ;
class SoundSystem ;
class Track ;
class Level ;

extern GFX         *gfx   ;
extern GUI         *gui   ;
extern SoundSystem *sound ;
extern Track       *track ;
extern Level        level ;
extern ulClock     *fclock ;

extern int      game_state ;

extern ssgRoot *scene           ;
extern char    *tuxkart_datadir ;

void tuxKartMainLoop () ;
void shutdown() ;
void initMaterials   () ;
ssgBranch *process_userdata ( char *data ) ;

#define NUM_KARTS        8
#define NUM_TRAFFIC      2
#define NUM_PROJECTILES  8
#define NUM_EXPLOSIONS   6

#define MAX_HOME_DIST  50.0f
#define MAX_HOME_DIST_SQD  (MAX_HOME_DIST * MAX_HOME_DIST)

#define DEFAULT_NUM_LAPS_IN_RACE 5

#ifndef TUXKART_DATADIR
#define TUXKART_DATADIR "/usr/local/share/games/tuxkart"
#endif

extern int num_karts ;
extern int num_laps_in_race ;
extern int finishing_position ;
extern bool paused ;
extern bool show_fps ;

class KartDriver;
class Projectile;
class Explosion;

extern KartDriver *kart       [ NUM_KARTS       ] ;
extern Projectile *projectile [ NUM_PROJECTILES ] ;
extern Explosion   *explosion [ NUM_EXPLOSIONS  ] ;

extern int tuxkartMain ( int nl, int mirror, int reverse, 
                         char *track, int numPlayers ) ;


#endif

/* EOF */
