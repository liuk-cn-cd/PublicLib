#ifndef SYSTEM15_GLOBAL_H
#define SYSTEM15_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef SYSTEM15_LIB
# define SYSTEM15_EXPORT Q_DECL_EXPORT
#else
# define SYSTEM15_EXPORT Q_DECL_IMPORT
#endif

#endif // SYSTEM15_GLOBAL_H
