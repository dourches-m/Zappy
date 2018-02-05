/*
** debug.h for zappy in /home/anthony/repository/zappy/debug.h
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  lun. juin 19 23:01:05 2017 Anthony LECLERC
** Last update lun. juin 19 23:01:05 2017 Anthony LECLERC
*/

#ifndef 	ZAPPY_DEBUG_H
# define 	ZAPPY_DEBUG_H

# include	<stdio.h>

# define 	SLOG_FORMAT(x)		"[ " x " ] ==> "
# define 	STRUCT_SIZE(x)		(sizeof(x))

# define	SERVLOG(x, ...)
# define	CMDLOG(x, ...)
# define	DPLOG(x, ...)
# define	EGGLOG(x, ...)
# ifndef	NDEBUG
#  include	<stdarg.h>
#  define	CALLDEBUG(x)		(x)
#  define	DLOG(x, ...)		fprintf(stdout, (x), ##__VA_ARGS__)
#  ifdef	GDEBUG
#   define	GDLOG(x, ...)		DLOG(x, ##__VA_ARGS__)
#  else
#   define	GDLOG(x, ...)
#  endif
#  define	DPRINT_ARGUMENTS(x)	print_arguments(x)
#  define	LOG_STRUCTSIZE(x)	DLOG("Struct: %zu\n", STRUCT_SIZE(x))
#  ifdef	CMDDEBUG
#   undef	CMDLOG
#   define	CMDLOG(x, ...)		DLOG(x, ##__VA_ARGS__)
#  endif
#  ifdef	EGGDEBUG
#   undef	EGGLOG
#   define	EGGLOG(x, ...)		DLOG(x, ##__VA_ARGS__)
#  endif
#  ifdef	SERVDEBUG
#   undef	SERVLOG
#   define	SERVLOG(x, ...)		DLOG(x, ##__VA_ARGS__)
#  endif
#  ifdef	PLAYERDEBUG
#   undef	DPLOG
#   define	DPLOG(x, ...)	DLOG(x, ##__VA_ARGS__)
#  endif
# else
#  define	CALLDEBUG(x)
#  define	DLOG(x, ...)
#  define	GDLOG(x, ...)
#  define	DPRINT_ARGUMENTS(x)
#  define	LOG_STRUCTSIZE(x)
# endif

#endif /* ZAPPY_DEBUG_H */
