/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrains Mono:size=10", "fontawesome:size=12" };
static const char dmenufont[]       = "JetBrains Mono:size=10";

#include "/home/$USER/.cache/wal/colors-wal-dwm.h"

/* tagging */
static const char *tags[] = { "", "", "" };
/*static const char *tags[] = { "", "", "", "", "", "", "" };*/

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
 	{ "[@]",      spiral },
 	{ "[\\]",      dwindle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont};
static const char *termcmd[]  = { "st", NULL };
/*static const char *web[] = { "firefox", NULL };*/

static Key keys[] = {
        /* modifier                     key        function        argument */
        { MODKEY,                       XK_q,      killclient,     {0} },
      /*{ MODKEY,                       XK_w,      spawn,          {.v = web } },*/
      /*{ MODKEY,                       XK_e,      ,               {0} },*/
      /*{ MODKEY,                       XK_r,      ,               {0} },*/
        { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
        { MODKEY,                       XK_y,      setlayout,      {.v = &layouts[1]} },
        { MODKEY,                       XK_u,      setlayout,      {.v = &layouts[2]} },
        { MODKEY,                       XK_i,      setlayout,      {.v = &layouts[3]} },
      /*{ MODKEY,                       XK_o,      ,               {0} },*/
      /*{ MODKEY,                       XK_p,      ,               {0} },*/
        { MODKEY,                       XK_a,      togglegaps,     {0} },
        { MODKEY|ShiftMask,             XK_a,      defaultgaps,    {0} },
        { MODKEY,                       XK_s,      incnmaster,     {.i = +1 } },
        { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
        { MODKEY,                       XK_f,      zoom,           {0} },
      /*{ MODKEY,                       XK_g,      ,               {0} },*/
        { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
        { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
        { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
        { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
        { MODKEY,                       XK_z,      incrgaps,       {.i = +3 } },
        { MODKEY,                       XK_x,      incrgaps,       {.i = -3 } },
      /*{ MODKEY,                       XK_c,      ,               {0} },*/
      /*{ MODKEY,                       XK_v,      ,               {0} },*/
        { MODKEY,                       XK_b,      togglebar,      {0} },
      /*{ MODKEY,                       XK_n,      ,               {0} },*/
      /*{ MODKEY,                       XK_m,      ,               {0} },*/
        { MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
        { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
        { MODKEY,                       XK_Tab,    view,           {0} },
        { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
        { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
        { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
        { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
        { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
        { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
        TAGKEYS(                        XK_1,                      0)
        TAGKEYS(                        XK_2,                      1)
        TAGKEYS(                        XK_3,                      2)
        { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
      /*{ MODKEY,                     XK_BackSpace,spawn,          SHCMD("pmenu") },*/
      /*{ MODKEY,                       XK_F1,     spawn,          SHCMD("volmute") },*/
      /*{ MODKEY,                       XK_F2,     spawn,          SHCMD("voldown") },*/
      /*{ MODKEY,                       XK_F3,     spawn,          SHCMD("volup") },*/
      /*{ MODKEY,                       XK_F5,     spawn,          SHCMD("brightnessctl set 5%- --min-value=1") },*/
      /*{ MODKEY,                       XK_F6,     spawn,          SHCMD("brightnessctl set +5%") },*/
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
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
};

