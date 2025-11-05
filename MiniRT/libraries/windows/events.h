#ifndef EVENTS_H
# define EVENTS_H

// ====== Events

# define KeyPress 02
# define KeyRelease 03
# define ButtonPress 04 
# define ButtonRelease 05
# define MotionNotify 06
# define EnterNotify 07
# define LeaveNotify 08
# define FocusIn 09
# define FocusOut 10
# define KeymapNotify 11
# define Expose 12
# define GraphicsExpose 13
# define NoExpose 14
# define VisibilityNotify 15
# define CreateNotify 16
# define DestroyNotify 17
# define UnmapNotify 18
# define MapNotify 19
# define MapRequest 20
# define ReparentNotify 21
# define ConfigureNotify 22
# define ConfigureRequest 23
# define GravityNotify 24
# define ResizeRequest 25

// ====== Masks

# define NoEventMask 0L
# define KeyPressMask 1L<<0
# define KeyReleaseMask 1L<<1
# define ButtonPressMask 1L<<2  
# define ButtonReleaseMask 1L<<3  
# define EnterWindowMask 1L<<4
# define LeaveWindowMask 1L<<5
# define PointerMotionMask 1L<<6
# define PointerMotionHintMask 1L<<7
# define Button1MotionMask 1L<<8
# define Button2MotionMask 1L<<9
# define Button3MotionMask 1L<<10
# define Button4MotionMask 1L<<11
# define Button5MotionMask 1L<<12
# define ButtonMotionMask 1L<<13
# define KeymapStateMask 1L<<14
# define ExposureMask 1L<<15
# define VisibilityChangeMask 1L<<16
# define StructureNotifyMask 1L<<17
# define ResizeRedirectMask 1L<<18
# define SubstructureNotifyMask 1L<<19
# define SubstructureRedirectMask 1L<<20
# define FocusChangeMask 1L<<21
# define PropertyChangeMask 1L<<22
# define ColormapChangeMask 1L<<23
# define OwnerGrabButtonMask 1L<<24

// ====== Keys

# define K_a 97
# define K_w 119
# define K_s 115
# define K_d 100
# define K_m 109
# define K_maj 65505
# define K_UP 65362
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_DoWN 65364
# define K_1 49
# define K_2 50
# define K_3 51
# define K_4 52
# define K_5 53
# define K_6 54
# define K_7 55
# define K_8 56
# define K_9 57
# define K_0 48
# define ESC 65307

# endif
