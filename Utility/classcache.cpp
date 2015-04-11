#include "classcache.h"

namespace Utility {
ClassCache::ClassCache()
{

}

ClassCache &ClassCache::instance()
{
    static ClassCache m_instance;
    return m_instance;
}

ClassCache::~ClassCache()
{

}

ClassCreatorBase::ClassCreatorBase()
{

}

ClassCreatorBase::~ClassCreatorBase()
{

}

}
