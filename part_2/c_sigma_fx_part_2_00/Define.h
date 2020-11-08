#ifndef __DEFINE_H__
#define	__DEFINE_H__

typedef unsigned int	dword;
typedef unsigned int	udword;
typedef			 int	sdword;

typedef unsigned short	uword;
typedef			 short	sword;

typedef unsigned char	ubyte;
typedef			 char	sbyte;
typedef			 char	boolean;

#define	true			1
#define	false			0
#define	null			0

#define	RAND(x)		(rand()%(x))

#define	SAFE_FREE( x )			{ if ( x ) { free( x ); ( x ) = null; } }
#define	SAFE_RELEASE( x )		{ if ( x ) { ( x )->Release( x ); ( x ) = null; } }
#define	SAFE_RELEASE_VT( x )	{ if ( x ) { ( x )->lpVtbl->Release( x ); ( x ) = null; } }

#endif // !__DEFINE_H__
