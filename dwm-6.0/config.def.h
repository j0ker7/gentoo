/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]            = "-*-*-medium-r-*-*-12-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#050505";
static const char normbgcolor[]     = "#000000";
static const char normfgcolor[]     = "#bbbbbb";
static const char selbordercolor[]  = "#2ECC71";
static const char selbgcolor[]      = "#000000";
static const char selfgcolor[]      = "#2ECC71";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 6;       /* gap pixel between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const Bool showsystray       = True;     /* False means no systray */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "main", "www", "fm", "editor", "media", "steam", "play", "dev", "misc" };

static const Rule rules[] = {
	/* class          instance    title       tags mask     isfloating   monitor */
	{ "Gimp",            NULL,       NULL,       0,            True,        -1 },
	{ "Firefox",         NULL,       NULL,       1 << 1,       False,       -1 },
	{ "Thunar",          NULL,       NULL,       1 << 2,       False,       -1 },
	{ "VirtualBox",      NULL,       NULL,       1 << 7,       False,       -1 },
	{ "Geany", 	     NULL,       NULL,       1 << 3,       False,       -1 },
	{ "System-config-printer.py", NULL,       NULL,       0,  	    True,       -1 },
	{ "Uget-gtk",        NULL,       NULL,       0,		   True,        -1 },
	{ "Deluge",          NULL,       NULL,       0,		   True,        -1 },
	{ "Viewnior",        NULL,       NULL,       0,		   True,        -1 },
	{ "Xarchiver",       NULL,       NULL,       0,		   True,        -1 },
	{ "Blueman-manager", NULL,       NULL,       0,		   True,        -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },    /* first entry is default */
	{ "[F]",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define SUPER Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", "terminus", "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "urxvt", NULL };
static const char *firefox[]  = { "firefox-bin", NULL };
static const char *fm[]       = { "thunar", NULL };
static const char *gcolor2[]  = { "gcolor2", NULL };
static const char *vbox[]     = { "VirtualBox", NULL };
static const char *geany[]    = { "geany", NULL };
static const char *music[]    = { "urxvt", "-e", "ncmpcpp", NULL };
static const char *tail1[]    = { "urxvt", "-e", "sudo", "tail", "-f", "/var/log/emerge-fetch.log", NULL };
static const char *tail2[]    = { "urxvt", "-e", "sudo", "tail", "-f", "/var/log/emerge.log", NULL };
static const char *volup[]    = { "amixer", "-q", "set", "Master", "5%+", NULL };
static const char *voldw[]    = { "amixer", "-q", "set", "Master", "5%-", NULL };
static const char *volmute[]  = { "amixer", "-q", "set", "Master", "toggle", NULL };
static const char *lightup[]  = { "light", "-A", "5", NULL };
static const char *lightdw[]  = { "light", "-U", "5", NULL };

#include "nextprevtag.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ SUPER,                        XK_Left,   spawn,          {.v = lightdw } },
	{ SUPER,                        XK_Right,  spawn,          {.v = lightup } },
	{ SUPER,                        XK_m,      spawn,          {.v = volmute } },
	{ SUPER,                        XK_Down,   spawn,          {.v = voldw } },
	{ SUPER,                        XK_Up,     spawn,          {.v = volup } },
	{ MODKEY,                       XK_y,      spawn,          {.v = tail2 } },
	{ MODKEY,                       XK_t,      spawn,          {.v = tail1 } },
	{ MODKEY,                       XK_m,      spawn,          {.v = music } },
	{ MODKEY,                       XK_e,      spawn,          {.v = geany } },
	{ MODKEY,                       XK_v,      spawn,          {.v = vbox } },
	{ MODKEY,                       XK_g,      spawn,          {.v = gcolor2 } },
	{ MODKEY,                       XK_a,      spawn,          {.v = fm } },
	{ MODKEY,                       XK_w,      spawn,          {.v = firefox } },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ControlMask,           XK_Right,  pushdown,       {0} },
	{ MODKEY|ControlMask,           XK_Left,   pushup,         {0} },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ ShiftMask,                    XK_Right,  focusstack,     {.i = +1 } },
	{ ShiftMask,                    XK_Left,   focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ ShiftMask|ControlMask,        XK_Left,   setmfact,       {.f = -0.05} },
	{ ShiftMask|ControlMask,        XK_Right,  setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ SUPER,                        XK_1,      setlayout,      {.v = &layouts[0]} },
	{ SUPER,                        XK_2,      setlayout,      {.v = &layouts[1]} },
	{ SUPER,                        XK_3,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_Left,   viewtoleft,     {0} },
	{ MODKEY,                       XK_Right,  viewtoright,    {0} },
	{ MODKEY|ShiftMask,             XK_Left,   tagtoleft,      {0} },
	{ MODKEY|ShiftMask,             XK_Right,  tagtoright,     {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,            0,              Button4,        view_adjacent,     { .i = -1 } },
	{ ClkTagBar,            0,              Button5,        view_adjacent,     { .i = +1 } },
};

