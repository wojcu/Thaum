#ifndef UTILITY
#define UTILITY

#include <QSharedPointer>
#include <QWeakPointer>

#define SHAREDPTRS(x) typedef QSharedPointer<x> Shared##x;\
    typedef QWeakPointer<x> Weak##x;
#define SHAREDCONSTRUCTOR(type) static QSharedPointer<type> newShared##type() {\
        return QSharedPointer<type>(new type());\
    }

#endif // UTILITY

