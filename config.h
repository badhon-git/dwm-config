/* rubya akter badhon */

/* arch dual boot setup */
/* main ssd */

/* don't forget ************* $sudo make clean install ************* */

/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 20;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 30;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=12" };
static const char dmenufont[]       = "JetBrainsMono Nerd Font:size=12";
static const char col_gray1[]       = "#1e1e1e";
static const char col_gray2[]       = "#3c3c3c";
static const char col_gray3[]       = "#b0b0b0";
static const char col_gray4[]       = "#b0b0b0";
static const char col_cyan[]        = "#000000";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* Audio and Brightness */

#include <X11/XF86keysym.h>

static const char *volup[]   = { "/home/badhon/.local/bin/volctl.sh", "up", NULL };
static const char *voldown[] = { "/home/badhon/.local/bin/volctl.sh", "down", NULL };
static const char *volmute[] = { "/home/badhon/.local/bin/volctl.sh", "mute", NULL };

static const char *brightup[]   = { "brightnessctl", "-d", "amdgpu_bl1", "set", "10%+", NULL };
static const char *brightdown[] = { "brightnessctl", "-d", "amdgpu_bl1", "set", "10%-", NULL };

/* Screenshot */
static const char *screenshot[] = { "/home/badhon/.local/bin/screenshot.sh", NULL };

/* Bluetooth */
/*static const char *btmenu[] = { "/home/badhon/.local/bin/bt-menu.sh", NULL };*/
static const char *btgui[] = { "blueman-manager", NULL };

/* window management (xdotool) */
static const char *floatmoveleft[]  = { "/bin/sh", "-c", "xdotool getactivewindow windowmove --relative -- -20 0", NULL };
static const char *floatmoveright[] = { "/bin/sh", "-c", "xdotool getactivewindow windowmove --relative -- 20 0", NULL };
static const char *floatmoveup[]    = { "/bin/sh", "-c", "xdotool getactivewindow windowmove --relative -- 0 -20", NULL };
static const char *floatmovedown[]  = { "/bin/sh", "-c", "xdotool getactivewindow windowmove --relative -- 0 20", NULL };

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class             instance      title      tags mask       isfloating    monitor */
	{ "Gimp",              NULL,       NULL,       0,                1,           -1 },
	{ "Firefox",           NULL,       NULL,       1 << 8,           0,           -1 },
    { "Blueman-manager",   NULL,       NULL,       0,                1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
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

/*shutdown*/
static const char *powermenucmd[] = { "/home/badhon/.local/bin/powermenu.sh", NULL };

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
/* static const char *termcmd[]  = { "alacritty", NULL }; */
static const char *termcmd[] = { "kitty", NULL };

/* my regular keybindings */

static const Key keys[] = {
	/* modifier                    key        function        argument */
    { MODKEY,                       XK_Escape, spawn,          SHCMD("xkill") },
    { MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_d,      spawn,          SHCMD("rofi -show drun") },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
    { MODKEY|ShiftMask,             XK_b,      spawn,          {.v = btgui } },
    { MODKEY|Mod1Mask,              XK_h,      spawn,          {.v = floatmoveleft } },
    { MODKEY|Mod1Mask,              XK_l,      spawn,          {.v = floatmoveright } },
    { MODKEY|Mod1Mask,              XK_k,      spawn,          {.v = floatmoveup } },
    { MODKEY|Mod1Mask,              XK_j,      spawn,          {.v = floatmovedown } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_minus,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_equal,  setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY|Mod1Mask,              XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_i,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_o,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_6,      incrihgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_7,      incrivgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_8,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_9,      incrovgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ Mod1Mask|ShiftMask,           XK_q,      quit,           {0} },


    { MODKEY,                       XK_p,      spawn,          SHCMD("pcmanfm")},
    { MODKEY,                       XK_l,      spawn,          SHCMD("betterlockscreen -l")},
    { MODKEY,                       XK_x,      spawn,          {.v = powermenucmd } },
    { MODKEY,                       XK_w,      spawn,          SHCMD("google-chrome-stable")},
    { MODKEY|ShiftMask,             XK_t,      spawn,          SHCMD("qbittorrent")},

	{ 0,             XF86XK_AudioRaiseVolume,  spawn,          {.v = volup} },
    { 0,             XF86XK_AudioLowerVolume,  spawn,          {.v = voldown} },
    { 0,             XF86XK_AudioMute,         spawn,          {.v = volmute} },
	{ 0,             XF86XK_MonBrightnessUp,   spawn,          {.v = brightup} },
    { 0,             XF86XK_MonBrightnessDown, spawn,          {.v = brightdown} },
    { MODKEY|ShiftMask,             XK_a,      spawn,          SHCMD("pavucontrol") },
    { MODKEY|ShiftMask,          XK_Print,     spawn,          {.v = screenshot} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
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
